#pragma once

#include <string>
#include <vector>
#include "utils_cfg.h"

struct UserFileMessage {
	std::string user;
	std::string token;
};

struct FileInfo {
	std::string md5;               // �ļ�md5��
	std::string filename;          // �ļ�����
	std::string user;              // �û�
	std::string timestamp;         // �ϴ�ʱ��
	std::string url;               // url
	std::string type;              // �ļ�����
	int size;                      // �ļ���С
	int shareStatus;               // �Ƿ���, 1���� 0������
	int downloadCount;             // ������
};

/*
 * GetUserFile working function
 */
void doWork();

/*
 * Parse Client Json data
 */
void parseClientJson(const char* data, const size_t len, UserFileMessage& out);

/*
 * Check Token in Redis
 * if token is valid return true, else return false
 */
bool checkToken(const Utils::RedisInfo& redisInfo,
	const std::string& user, const std::string& token); 

/*
 * Check user files in mysql
 */
Utils::ReplyStatus checkInMysql(const Utils::MysqlInfo& mysqlInfo,
	const UserFileMessage& userMsg, std::vector<FileInfo>& files);

/*
 * Pack reply post json data
 */
std::string setReplyData(const Utils::ReplyStatus stat,
	const std::vector<FileInfo>& files);