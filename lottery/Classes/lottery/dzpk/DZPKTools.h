#ifndef _DZPKTOOLS_H_
#define  _DZPKTOOLS_H_


//����ת��


#include "cocos2d.h"
#include "ans/AnsSingleton.h"
#include "serializers/TinyXmlReader.h"

#pragma comment(lib, "libiconv.lib")


/*
int GBKToUTF8(std::string & gbkStr, const char* toCode, const char* fromCode);
*/

//�����ı���Դ
const char* DZPK_loadText(const char* key);

#endif