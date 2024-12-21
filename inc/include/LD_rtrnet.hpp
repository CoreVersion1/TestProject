/**
 * @file rtrnet.h
 * @author LDRobot (support@ldrobot.com)
 * @brief  LiDAR data protocol processing App
 *         This code is only applicable to LDROBOT LiDAR
 * products sold by Shenzhen LDROBOT Co., LTD
 * @version 0.1
 * @date 2022-05-27
 *
 * @copyright Copyright (c) 2021  SHENZHEN LDROBOT CO., LTD. All rights
 * reserved. Licensed under the MIT License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of the
 * License in the file LICENSE Unless required by applicable law or agreed to in
 * writing, software distributed under the License is distributed on an "AS IS"
 * BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied. See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef _R_TR_NET_H
#define _R_TR_NET_H

#include <iostream>
#include <fstream>
#include <sstream> // 包含此文件以使用 std::stringstream
#include <chrono>

#include "LD_cmd_interface_linux.hpp"
#include "LD_sslbf.hpp"
#include "LD_trnet.hpp"
#include "LD_pointdata.hpp"

namespace ldlidar_ssl {

typedef enum {
	STATE_BOOT						= 0x01,
	STATE_APP						= 0x02,
	STATE_NONE						= 0xFF,
}SSLStateDef;

typedef enum {
	SSL_20L							= 0x01,
	SSL_20N							= 0x02,
	LD07N							= 0x03,
	SSL_20P							= 0x04,
	SSL_20PL						= 0x05,
	SSL_20LB2						= 0x06,
	SSL_20NB2						= 0x07,
	LD07BH							= 0x08,
	SSL_20PT1						= 0x09,
	SSL_20L2						= 0x0A,
	SSL_20N2						= 0x0B,
}SSLTypeDef;

typedef enum {
	PACK_NULL						= 0x00,
	PACK_GET_VIDEO					= 0x01,		/*Frame ID of video data*/
	PACK_GET_DISTANCE 				= 0x02,		/*Frame ID of distance data*/
	PACK_LASER_TOGGLE				= 0x05,		/*Frame ID of laser control*/
	PACK_UPGRADE_START 				= 0x0A,		/*Frame ID of start upgrade*/
    PACK_UPGRADE_TRANSMIT_DATA 		= 0x0B,		/*Frame ID of upgrade transmit data*/
    PACK_UPGRADE_COMPLETE 			= 0x0C,		/*Frame ID of upgrade complete*/
	PACK_RESET_SYSTEM			 	= 0x0D,		/*Frame ID of distance reset system*/
	PACK_STOP 						= 0x0F,		/*Frame ID of stop distance data transmission*/
	PACK_COE_INTERPOLATION 			= 0x0E,		/*使能角度标定参数插值*/
	PACK_ACK 						= 0x10,		/*Frame ID of ACK*/
	PACK_CONFIG_REGISTER			= 0x11,		/*Frame ID of configure register*/
	PACK_GET_COE 					= 0x12,		/*Frame ID of Get parameters*/
	PACK_VERSION 					= 0x14,		/*Frame ID of Get Machine version*/
	PACK_VIDEO_SIZE 				= 0x15,		/*Frame ID of Get camera resolution*/
	PACK_CONFIG_ADDRESS				= 0x16,		/*Frame ID of Configure address*/
	PACK_TRANSMISSION_MODE			= 0x1E,
	PACK_GET_SN						= 0x21,		/*Frame ID of Get SN*/
	PACK_GET_DISTANCE_TRIG_MODE 	= 0x26,     /*Frame ID of trig distance data*/
	PACK_SET_GROUND_DISTANCE 		= 0x28,		/*Frame ID of set ground distance*/
	PACK_SYNC 						= 0x2A,		/*Frame ID of set soft sync*/	

}PackageIDTypeDef;

#define LIDAR_DEVICE_01 			0x01		// b0001
#define LIDAR_DEVICE_02 			0x02		// b0010

#define	BAUD_RATE					921600

#define	SN_LEN						17
#define	SN_TOTAL_LEN				32

#define PACK_VERSION_BOOT_LEN		0x38 /* Boot  PACK_VERSION command data length */
#define PACK_VERSION_APP_LEN		0x58 /* APP  PACK_VERSION command data length */

#define PACK_STRING_LEN 			16
#define THIS_DEVICE_ADDREESS 		0x01 /*Device address*/

struct TRData {
	uint8_t device_address;
	uint8_t pack_id;
	uint16_t chunk_offset;
	std::vector<uint8_t> data;
};

struct LidarInfo
{
	uint16_t firmware_version;
	uint16_t ssl_type;
	int32_t pitch;
	int32_t roll;
	uint8_t sn[SN_LEN];
	char type_name[20];
	SSLStateDef ssl_state;
};

class RTRNet {
public:
	RTRNet();
	~RTRNet();
	
	std::string GetSdkPackVersionNumber(void);
	bool SetProductType(LDType type_number);
	LDType GetProductType(void);
	double GetFovAngleVal(void);
	double GetTotalPointNumberVal(void);

	bool SendCmd(CmdInterfaceLinux* port, uint8_t address, uint8_t id);
	bool sendbytes(CmdInterfaceLinux* port, uint8_t address, uint8_t id, uint8_t *data, uint32_t len, uint16_t offset);
	bool sendWords(CmdInterfaceLinux* port, uint8_t address, uint8_t id, uint32_t *data, uint32_t len, uint16_t offset);
	bool controlLaser(CmdInterfaceLinux* port, uint8_t address, bool data);
	bool controlExposure(CmdInterfaceLinux* port, uint8_t address, uint16_t exposure, uint8_t gain);
	bool controlExposureLevel(CmdInterfaceLinux* port, uint8_t address, uint8_t level);
	bool WaitAck(uint32_t delay_ms, uint32_t cmd_id);
	bool SendStopDistanceTransmitCmd(CmdInterfaceLinux* port);
	void ResetFrameReady(void);
	bool IsFrameReady(void); 
	void ResetParametersReady(void);
	bool IsParametersReady(void);
	bool IsSNReady(void);
	void GetSNData(uint8_t *data, uint8_t sn_len);
	bool IsVERSIONReady(void);
	bool IsCmdAckReady(void);
	void ResetCmdAckReady(void); 
	void ResetVERSIONReady(void);
	bool GetCmdAckData(uint32_t* cmd, uint32_t* ack);
	bool Pack(const TRData &in, std::vector<uint8_t> &out);
	bool FindLeadingCode(const uint8_t *buff); //make sure buffer size bigger than 4
	uint32_t GetParseDataLen() { return parse_data_len_; }
	bool UnpackData(const uint8_t *data, uint32_t len);
	bool GetComErrFlag(void);
	void SetComErrFlag(bool flag);
	bool FirmwareUpdate(CmdInterfaceLinux* port, uint8_t address, const char* path) ;
	bool GetRealTime(long *time_ms);
	void GetLidarInfo(ldlidar_ssl::LidarInfo* info, uint8_t address);
	/**
   * @brief 串口通讯接收回调处理， serial communication read callback
  */
  void CommReadCallback(const char *byte, size_t len);
	/**
	 * @brief 获取激光雷达扫描一帧的点云数据
	*/
	Points2D GetLaserScanData(void);

	void SetDistanceModule(uint8_t data);
	uint8_t GetDistanceModule();	
	
	void SetFilter(bool filter);
	bool GetFilter();	
	/**
		* @brief 获得图像大小参数
	*/
	uint32_t GetVideoSize(uint8_t address);
	uint32_t GetVideowidth(uint8_t address);
	uint32_t GetVideoHeight(uint8_t address);

	/**
		* @brief 获取图像
	*/
	bool GetPictureStart(uint8_t address, std::vector<std::vector<uint8_t>>& data);
	bool GetPictureEnd(uint8_t address);
	uint16_t GetPictureStatus(uint8_t address);
	bool GetExposurePara(uint8_t exposure_level, uint16_t *exposure, uint8_t *gain);
	bool SetGroundDistance(CmdInterfaceLinux* port, uint32_t distance);
	bool SetWorkMode(CmdInterfaceLinux* port, uint8_t address,uint8_t mode);
protected:
	TRData tr_unpack_data_;
private:
	std::string sdk_pack_version_number_;
	LDType product_type_number_;
	bool frame_ready_;
	bool parameters_ready_;
	uint16_t coe_u_;
	uint16_t coe_v_;
	std::vector<bool> coe_map_bit_;
	std::vector<std::vector<uint8_t>>* video_buffer_;
  	double fov_angle_;
	double total_point_number_;
	const TRData* tr_data_;
	uint32_t coe_[35];
	std::vector<uint8_t> data_tmp_;
	Points2D  laser_scan_data_;
	std::mutex mutex_lock1_;
	std::mutex mutex_lock2_;
	std::mutex mutex_lock3_;
	std::mutex mutex_lock4_;
	std::mutex mutex_lock5_;
	std::mutex mutex_lock6_;
	std::mutex mutex_lock7_;

	uint8_t sn_[SN_TOTAL_LEN];
	bool sn_ready_;
	bool version_ready_;
	uint32_t cmd_;
	uint32_t ack_;
	bool cmd_ack_ready_;
	bool com_err_;

	const uint32_t LEADING_CODE = 0xAAAAAAAA;
	const uint32_t HEADER_LEN = 4; //device_address , pack_id , chunk_offset len
	const uint32_t EXTRA_LEN = 11;

  	LidarInfo lidarInfo_01;
	LidarInfo lidarInfo_02;
	uint32_t parse_data_len_;
	uint8_t	distance_module;
	bool is_filter_;

	uint8_t CalCheckSum(const uint8_t *data, uint16_t len);
	bool Transform(const TRData *tr_data);			   /*transform raw data to stantard data */
	void SetFrameReady(void);
	void SetParametersReady(void);
	void SetLaserScanData(Points2D& src);
	void SetSNReady(void);
	void SetVERSIONReady(void);
	void SetCmdAckReady(void);
	void SetCmdAckData(uint32_t cmd, uint32_t ack);
	const TRData *Unpack(const uint8_t *data, uint32_t len);
	bool AnalysisTRNetByte(uint8_t byte);
	void SetLidarInfo(ldlidar_ssl::LidarInfo* info, uint8_t address);
};

}

#endif // _TR_NET_H
/********************* (C) COPYRIGHT SHENZHEN LDROBOT CO., LTD *******END OF
 * FILE ********/