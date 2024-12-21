#ifndef _R16_8BIT_SOFT_ISP_V01_
#define _R16_8BIT_SOFT_ISP_V01_

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>


typedef struct ImageInfo { // data information for a mono sensor raw image
    uint32_t height;
    uint32_t width;
    uint32_t channels;  // 1 is expected in current implementation
    uint32_t step;  // when memory space is not continuous, it specifies data amount for storing each row

    // bit depth in bits, 8 for 8-bit images (max. value 255)
    uint32_t bit_depth;

    // number of bits allocated for each raw value.
    // Normally, it's the same value as `bit_depth` but could be different.
    // For example, a 10-bit raw image may use 2 bytes (thus 16 bits) for each raw value.
    uint32_t storage_width;
} ImageInfo;


typedef struct ProcessingParams { // some parameters used for image processing
    /*ROI selection for image processing*/
    float line_k;  // k and b value for calculating line ROI
    float line_b;  // k and b value for calculating line ROI
    uint32_t start_row;  // starting row when setting ROI (for processing)
    uint32_t start_col;  // starting column when setting ROI (for processing)
    uint32_t end_row;    // ending row when setting ROI (for processing)
    uint32_t end_col;    // ending column when setting ROI (for processing)

    /*ROI selection for brightness calculation*/
    uint32_t br_start_row;  // starting row when setting ROI (for processing)
    uint32_t br_start_col;  // starting column when setting ROI (for processing)
    uint32_t br_end_row;    // ending row when setting ROI (for processing)
    uint32_t br_end_col;    // ending column when setting ROI (for processing)

    uint8_t br_low_thresh;   // for checking if an image is "very dark"
    uint8_t br_hight_thresh; // for checking if an image is "very bright"
    uint32_t br_low_accu; // minimum accumulation for low brightness
    uint32_t br_high_accu; // minimum accumulation for high brightness

    /*module selection*/
    bool ae_enabled;      // whether to apply auto exposure strategy
    bool gamma_enabled;   // whether to apply gamma correction
    bool lsc_enabled;     // whether to apply lens shading correction
    bool sharpen_enable;  // whether to apply sharpening (over horizontal direction)
    bool smoothen_enabled;// whether to apply smoothening (over vertical direction)

    /*black level subtraction*/
    uint8_t sensor_offset;  // "black level" (in 8-bit)

    /*auto exposure*/
    uint8_t ae_target;   // target average intensity (in 8-bit) of image ROI for auto exposure
    uint8_t ae_tolerance_lower;  // ABSOLUTE value difference (in 8-bit) for AE tolerance at the lower end
    uint8_t ae_tolerance_upper;  // ABSOLUTE value difference (in 8-bit) for AE tolerance at the upper end
    float ae_damping_coeff;      // a value to prevent too frequent changes, greater values reduces exposure changes further
} ProcessingParams;


// Gamma lookup table for brightness enhancement
static const uint8_t GAMMA_LUT_bf3901[256] = {
    0,  6, 13, 19, 25, 30, 34, 38, 43, 47, 53, 59, 67, 75, 81, 87,   /*index 15*/
    91, 95, 99, 104, 107, 111, 114, 118, 120, 123, 126, 128, 130, 132, 134, 136, /*index 31*/
    138, 139, 141, 143, 145, 146, 148, 150, 151, 153, 154, 156, 157, 159, 161, 162, /*index 47*/
    163, 165, 166, 168, 169, 171, 172, 173, 175, 176, 177, 178, 180, 181, 182, 183, /*index 63*/
    184, 185, 187, 188, 189, 190, 191, 192, 193, 194, 195, 195, 196, 197, 198, 199, /*index 79*/
    200, 201, 201, 202, 203, 204, 204, 205, 206, 206, 207, 208, 208, 209, 210, 210, /*index 95*/
    211, 211, 212, 212, 213, 213, 214, 214, 215, 215, 216, 216, 217, 217, 218, 218, /*index 111*/
    219, 219, 220, 220, 221, 221, 222, 222, 223, 223, 224, 224, 224, 225, 225, 226, /*index 127*/
    226, 227, 227, 227, 228, 228, 229, 229, 229, 230, 230, 230, 231, 231, 231, 231, /*index 143*/
    232, 232, 232, 233, 233, 233, 233, 234, 234, 234, 234, 235, 235, 235, 236, 236, /*index 159*/
    236, 236, 237, 237, 237, 237, 238, 238, 238, 239, 239, 239, 239, 240, 240, 240, /*index 175*/
    240, 241, 241, 241, 241, 241, 242, 242, 242, 242, 242, 242, 243, 243, 243, 243, /*index 191*/
    243, 244, 244, 244, 244, 244, 245, 245, 245, 245, 245, 246, 246, 246, 246, 246, /*index 207*/
    247, 247, 247, 247, 247, 248, 248, 248, 248, 248, 248, 249, 249, 249, 249, 249, /*index 223*/
    249, 250, 250, 250, 250, 250, 250, 251, 251, 251, 251, 251, 251, 252, 252, 252, /*index 239*/
    252, 252, 253, 253, 253, 253, 253, 253, 254, 254, 254, 254, 254, 255, 255, 255, /*index 255*/
};


// Lens shading compensation coefficients (base value: 1024)
// Ideally, the max. number would not exceed 4096 (e.g. 4x compensation) in the data array.
// The full size of sensor output is 240x320. LSC block size is 10x10, thus there are 24x32 = 768 coefficients in total.
// However, 20 columns are cut at each side to make the total bandwidth requirement smaller, which make image resolution 200x320.
// As a result, there are 640 coefficients in total
static const uint32_t LSC_FACTOR_bf3901[640] = {
    /*3115,2917,*/2703, 2500, 2394, 2276, 2201, 2106, 2053, 2019, 1965, 1960, 1919, 1934, 1960, 1971, 2008, 2059, 2143, 2241, 2364, 2442, /*2683,2849,*/
    /*2743,2607,*/2394, 2234, 2143, 2031, 1950, 1914, 1842, 1838, 1775, 1771, 1725, 1784, 1746, 1797, 1828, 1890, 1924, 2014, 2131, 2241, /*2356,2535,*/
    /*2483,2341,*/2162, 2071, 1939, 1851, 1810, 1734, 1705, 1644, 1615, 1601, 1608, 1601, 1641, 1652, 1667, 1709, 1775, 1833, 1924, 2019, /*2168,2326,*/
    /*2269,2118,*/1976, 1866, 1784, 1742, 1633, 1584, 1551, 1519, 1491, 1497, 1482, 1491, 1503, 1531, 1554, 1584, 1626, 1686, 1771, 1847, /*1955,2100,*/
    /*2065,1955,*/1847, 1721, 1659, 1598, 1525, 1482, 1467, 1430, 1397, 1384, 1384, 1397, 1419, 1411, 1438, 1476, 1519, 1571, 1619, 1713, /*1810,1914,*/
    /*1914,1806,*/1694, 1608, 1544, 1467, 1436, 1403, 1354, 1319, 1324, 1308, 1296, 1301, 1312, 1336, 1351, 1389, 1419, 1461, 1525, 1594, /*1686,1784,*/
    /*1806,1686,*/1577, 1512, 1441, 1403, 1339, 1334, 1310, 1274, 1258, 1258, 1244, 1244, 1258, 1263, 1285, 1315, 1346, 1384, 1441, 1509, /*1574,1667,*/
    /*1697,1594,*/1494, 1441, 1366, 1331, 1287, 1254, 1250, 1209, 1199, 1205, 1189, 1183, 1197, 1193, 1217, 1231, 1287, 1303, 1359, 1422, /*1503,1567,*/
    /*1605,1522,*/1427, 1374, 1317, 1263, 1246, 1201, 1174, 1170, 1154, 1141, 1156, 1145, 1157, 1159, 1182, 1201, 1213, 1263, 1303, 1351, /*1424,1482,*/
    /*1506,1441,*/1376, 1301, 1265, 1227, 1189, 1163, 1138, 1127, 1110, 1108, 1110, 1100, 1120, 1125, 1143, 1152, 1185, 1213, 1258, 1294, /*1356,1436,*/
    /*1488,1408,*/1324, 1285, 1233, 1199, 1156, 1143, 1124, 1102, 1095, 1087, 1071, 1084, 1100, 1090, 1110, 1117, 1141, 1174, 1237, 1263, /*1334,1397,*/
    /*1438,1382,*/1308, 1252, 1183, 1168, 1145, 1110, 1102, 1084, 1071, 1053, 1054, 1065, 1059, 1074, 1090, 1094, 1124, 1163, 1178, 1237, /*1292,1356,*/
    /*1427,1351,*/1274, 1231, 1182, 1159, 1124, 1097, 1079, 1064, 1051, 1042, 1047, 1042, 1054, 1056, 1082, 1092, 1113, 1141, 1170, 1219, /*1276,1317,*/
    /*1397,1324,*/1274, 1213, 1176, 1145, 1113, 1090, 1071, 1062, 1039, 1045, 1038, 1044, 1038, 1051, 1062, 1078, 1110, 1129, 1161, 1225, /*1258,1308,*/
    /*1376,1312,*/1254, 1209, 1157, 1131, 1100, 1092, 1062, 1054, 1038, 1036, 1032, 1026, 1041, 1044, 1068, 1078, 1103, 1127, 1163, 1205, /*1250,1308,*/
    /*1382,1298,*/1246, 1189, 1159, 1145, 1107, 1081, 1059, 1044, 1032, 1038, 1026, 1038, 1034, 1039, 1059, 1071, 1092, 1127, 1167, 1197, /*1239,1296,*/
    /*1384,1310,*/1250, 1199, 1163, 1122, 1108, 1074, 1068, 1051, 1051, 1039, 1038, 1024, 1041, 1053, 1062, 1067, 1100, 1120, 1163, 1189, /*1244,1280,*/
    /*1371,1317,*/1250, 1209, 1156, 1131, 1113, 1082, 1073, 1045, 1047, 1041, 1041, 1036, 1042, 1048, 1076, 1074, 1094, 1141, 1163, 1201, /*1248,1315,*/
    /*1397,1327,*/1263, 1209, 1189, 1148, 1107, 1095, 1062, 1059, 1048, 1041, 1047, 1048, 1053, 1065, 1073, 1097, 1102, 1139, 1167, 1221, /*1267,1317,*/
    /*1400,1329,*/1285, 1237, 1195, 1161, 1136, 1113, 1087, 1067, 1067, 1045, 1062, 1051, 1056, 1081, 1081, 1103, 1125, 1157, 1195, 1231, /*1292,1341,*/
    /*1438,1374,*/1308, 1256, 1205, 1182, 1141, 1138, 1100, 1074, 1076, 1070, 1068, 1081, 1087, 1094, 1113, 1125, 1152, 1167, 1219, 1248, /*1312,1366,*/
    /*1470,1408,*/1341, 1296, 1250, 1205, 1178, 1163, 1138, 1127, 1107, 1100, 1089, 1103, 1112, 1113, 1124, 1152, 1168, 1201, 1233, 1294, /*1334,1411,*/
    /*1544,1467,*/1384, 1329, 1280, 1254, 1227, 1201, 1165, 1156, 1138, 1138, 1136, 1134, 1143, 1152, 1165, 1180, 1205, 1250, 1280, 1344, /*1382,1473,*/
    /*1605,1519,*/1447, 1379, 1317, 1303, 1263, 1231, 1213, 1189, 1185, 1174, 1170, 1172, 1183, 1197, 1211, 1225, 1256, 1292, 1329, 1395, /*1433,1531,*/
    /*1686,1594,*/1525, 1441, 1408, 1341, 1308, 1285, 1258, 1246, 1219, 1231, 1229, 1229, 1235, 1248, 1256, 1280, 1310, 1359, 1397, 1447, /*1534,1605,*/
    /*1758,1670,*/1571, 1522, 1476, 1419, 1369, 1341, 1308, 1310, 1298, 1285, 1280, 1287, 1274, 1308, 1336, 1327, 1392, 1413, 1467, 1525, /*1612,1678,*/
    /*1919,1775,*/1690, 1605, 1538, 1500, 1458, 1413, 1395, 1366, 1366, 1351, 1354, 1346, 1359, 1364, 1397, 1438, 1467, 1509, 1538, 1619, /*1709,1815,*/
    /*2042,1934,*/1802, 1701, 1667, 1612, 1534, 1491, 1476, 1453, 1424, 1436, 1408, 1447, 1438, 1473, 1488, 1522, 1551, 1598, 1663, 1734, /*1828,1945,*/
    /*2255,2076,*/1971, 1838, 1771, 1721, 1652, 1601, 1564, 1541, 1522, 1515, 1528, 1544, 1557, 1571, 1608, 1623, 1682, 1725, 1802, 1899, /*1992,2137,*/
    /*2450,2312,*/2162, 2053, 1955, 1875, 1806, 1780, 1721, 1674, 1652, 1670, 1655, 1663, 1674, 1690, 1725, 1788, 1802, 1890, 1976, 2088, /*2207,2356,*/
    /*2723,2561,*/2418, 2283, 2156, 2088, 1987, 1955, 1899, 1824, 1833, 1819, 1802, 1824, 1842, 1880, 1894, 1939, 2019, 2088, 2221, 2312, /*2475,2625,*/
    /*3128,2917,*/2753, 2544, 2483, 2326, 2255, 2188, 2118, 2100, 2059, 2031, 2031, 2076, 2042, 2088, 2156, 2207, 2290, 2356, 2509, 2625, /*2774,3000*/
};


// Image processing for an 8-bit image (flattened data in a 1-D array)
// Args:
//   input_image: pointer to input data array
//   output_image: pointer to PRE-ALLOCATED output data array
//   total_pixels: for compatible with previous UART_TEST version only
bool interpolate_image_bf3901(uint8_t *input_image, uint8_t *output_image,
                              uint32_t total_pixels);


// Raw image description
static const ImageInfo image_info_bf3901 = {
    .height = 320,
    .width = 200,
    .channels = 1,
    .step = 200,

    .bit_depth = 8,
    .storage_width = 8,
};


// default parameters for image processing
static const ProcessingParams soft_isp_param_bf3901 = {
    .line_k = 0.0f,  // TODO: to read from HSLIGHT bin file
    .line_b = 0.0f,  // TODO: to read from HSLIGHT bin file

    .start_row = 0,
    .start_col = 85,  // TODO: process max. 40 columns near the ground line should be enough
    .end_row = 320,
    .end_col = 155,

    .br_start_row = 0,
    .br_start_col = 85,
    .br_end_row = 320,
    .br_end_col = 155,

    .br_low_thresh = 25,
    .br_hight_thresh = 120,
    .br_low_accu = 260,
    .br_high_accu = 300,

    .ae_enabled = false,
    .gamma_enabled = false,
    .lsc_enabled = false,
    .sharpen_enable = true,
    .smoothen_enabled = true,

    .sensor_offset = 0,  // already handled at sensor level for BF3901

    .ae_target = 120,  // weighted average image intensity
    .ae_tolerance_lower = 10,
    .ae_tolerance_upper = 10,
    .ae_damping_coeff = 0.6f,
};

#endif  // _R16_8BIT_SOFT_ISP_V01_
