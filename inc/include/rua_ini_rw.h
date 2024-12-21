/**
 * 文件：apirwini.h
 * 版本：1.0
 *
 * 说明：ini配置文件读写
 * 1、支持;和#注释符号，支持行尾注释。
 * 2、支持带引号'或"成对匹配的字符串，提取时自动去引号。引号中可带其它引号或;#注释符。
 * 3、支持无section或空section(名称为空)。
 * 4、支持10、16、8进制数，0x开头为16进制数，0开头为8进制。
 * 5、支持section、key或=号前后带空格。
 * 6、支持\n、\r、\r\n或\n\r换行格式。
 * 7、不区分section、key大小写，但写入时以新串为准，并保持其大小写。
 * 8、新增数据时，若section存在则在该节最后一个有效数据后添加，否则在文件尾部添加。
 * 9、支持指定key所在整行删除，即删除该键值，包括注释。
 * 10、可自动跳过格式错误行，修改时仍然保留。
 * 11、修改时保留原注释：包括整行注释、行尾注释(包括前面空格)。
 * 12、修改时保留原空行。以上三点主要是尽量保留原格式。
 */


#ifndef _RUA_INI_RW_H_
#define _RUA_INI_RW_H_

#define SIZE_LINE       1024    //每行最大长度
typedef struct {
    char *IniName;
    char *Buffer;
    int Buflen;
} RuaIni_st;

#ifdef __cplusplus
extern "C" {
#endif

//加载ini文件至内存
RuaIni_st *RuaIniFileLoad(const char *filename);
//释放ini文件所占资源
void RuaIniFileFree(RuaIni_st *stIni_p);

//获取字符串，不带引号
int RuaIniGetString(RuaIni_st *stIni_p, const char *section,
                    const char *key,
                    char *value, int size);
//获取整数值
int RuaIniGetInt(RuaIni_st *stIni_p, const char *section, const char *key,
                 int *value);
//获取浮点数
int RuaIniGetDouble(RuaIni_st *stIni_p, const char *section,
                    const char *key,
                    double *value);

int RuaIniSetDouble(RuaIni_st *stIni_p, const char *section,
                    const char *key,
                    double value);

//设置字符串：若value为NULL，则删除该key所在行，包括注释
int RuaIniSetString(RuaIni_st *stIni_p, const char *section,
                    const char *key,
                    const char *value, const int addquote);

//获取section 中项目的个数
int RuaIniGetValueCountInSection(RuaIni_st *stIni_p, const char *section);

//获取section中索引为index的key 和value值
int RuaIniGetValueInSection(RuaIni_st *stIni_p, const char *section, int index,
                            char *key, int key_len, char *value, int value_len);

//设置整数值：base取值10、16、8，分别表示10、16、8进制，缺省为10进制
int RuaIniSetInt(RuaIni_st *stIni_p, const char *section, const char *key,
                 int value, int base);

#ifdef __cplusplus
}
#endif

#endif

