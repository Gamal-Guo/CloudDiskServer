#pragma once

#include <string>

/*--------------------------------------------------------
| �û���¼���������ɵ�Token, ��Key: Value��ʽ�洢��Redis
| ��kTokenPrefixǰ׺��ʶkey
| ͨ�� SETEX key seconds value ���ù���ʱ��, 12Сʱ����
`--------------------------------------------------------*/
const std::string kTokenPrefix = "TOKEN:";
const int kTokenExpiration = 60 * 60 * 12;

/*--------------------------------------------------------
| �����û��ļ����򼯺� (ZSET)
| Key:     kFilePublicZset
| value:   md5�ļ���
| redis ���
|   ZADD key score member ��ӳ�Ա
|   ZREM key member ɾ����Ա
|   ZREVRANGE key start stop [WITHSCORES] ����鿴
|   ZINCRBY key increment member Ȩ���ۼ�increment
|   ZCARD key ����key������Ԫ�ظ���
|   ZSCORE key member ��ȡĳ����Ա�ķ���
|   ZREMRANGEBYRANK key start stop ɾ��ָ����Χ�ĳ�Ա
|   zlexcount zset [member [member �ж�ĳ����Ա�Ƿ���ڣ����ڷ���1�������ڷ���0
`---------------------------------------------------------*/
const std::string kFilePublicZset = "FILE_PUBLIC_ZSET";

/*-------------------------------------------------------
| �ļ���ʾ���ļ�����Ӧ�� (HASH)
| Key:    kFileNameHash
| field:  file_id(md5�ļ���)
| value:  file_name
| redis ���
|    hset key field value
|    hget key field
`--------------------------------------------------------*/
const std::string kFileNameHash = "FILE_NAME_HASH";