// rapidJsonLearning.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<list>
#include"rapidjson/document.h"
#include"rapidjson/istreamwrapper.h"
#include"rapidjson/pointer.h"

using std::cout;
using std::string;
using namespace rapidjson;

/* Related Data Structure */
//typedef std::string dn_;
//typedef std::string LdapAttributeValue_;
//
//typedef std::vector<LdapAttributeValue_> values_;
//typedef std::string name_;
//
//
//class LdapAttribute_ {
//public:
//	name_ name;
//	values_ values;
//};
//
//typedef std::vector<LdapAttribute_> ldapAttributes_;
//class LdapEntry_ {
//public:
//	dn_ dn;
//	ldapAttributes_ ldapAttributes;
//};
//
//
//typedef std::vector<LdapEntry_> LdapEntries_;
//
//
//
//struct content_ {
//	LdapEntries_ LdapEntries;
//};

  
/* Generated classes*/
typedef std::string LdapAttributeValue_;
typedef std::vector<LdapAttributeValue_> values_;
typedef std::string name_;
class LdapAttribute_ {
public:
	name_ name;
	values_ values;
};
typedef std::vector<LdapAttribute_> ldapAttributes_;
typedef std::string dn_;
class LdapEntry_ {
public:
		dn_ dn;
		ldapAttributes_ ldapAttributes;
};
typedef std::vector<LdapEntry_> LdapEntries_;
class content_ { public: LdapEntries_ ldapEntries;  } content;


/* general class for parser */

class jsonParser {  
public:
	jsonParser();
	jsonParser(const string&);
	void readFile(const string&);
	void DOMparse();
private:
	string jsonFile;
	Document document;
	content_ content;
};







 



// TODO: 在此处引用程序需要的其他标头。
