#include"rapidJsonLearning.h"
#include<iostream>
#include<string>
#include<fstream>

#include<vector>

using std::string;
using std::ifstream;
using std::vector;
using std::ios;
int main() {
	jsonParser jsonParser1("message.json");

	jsonParser1.DOMparse();
	return 0;
	

}

jsonParser::jsonParser()
{
	// Do Nothing;
}

jsonParser::jsonParser(const string& fileName)
{
	readFile(fileName);
}

void jsonParser::readFile(const string& fileName) {
	ifstream t(fileName);
	if (!t) {
		cout << "No file found";
		return;
	}
	IStreamWrapper isw(t);
	document.ParseStream(isw);
	return;
}

void jsonParser::DOMparse()
{
	for (Value::ConstValueIterator itr = document.Begin(); itr != document.End(); itr++) {
		LdapEntry_ temp_LdapEntry;
		//以下为填入temp_LdapEntry的过程
		//	以下为填入dn的过程
		dn_ temp_dn;
		if (itr->HasMember("dn")) {
			temp_dn = (*itr)["dn"].GetString();
		}
		temp_LdapEntry.dn = temp_dn;
		//	以上为填入dn的过程
		//	以下为填入ldapAttributes的过程
		ldapAttributes_ temp_ldapAttributes;
		//		以下为填入temp_ldapAttributes的过程
		if (itr->HasMember("ldapAttributes")) {
			for (auto ite1 = (*itr)["ldapAttributes"].Begin(); ite1 != (*itr)["ldapAttributes"].End(); ite1++) {
				LdapAttribute_ temp_ldapAttribute;
		//			以下为填入temp_ldapAttribute的过程

				name_ temp_name;
		//				以下为填入temp_name的过程
				if (ite1->HasMember("name")) {
					temp_name = (*ite1)["name"].GetString();
				}
		//				以上为填入temp_name的过程
				temp_ldapAttribute.name = temp_name;

				values_ temp_values;
		//				以下为填入temp_values的过程
				if (ite1->HasMember("values")) {
					for (auto ite2 = (*ite1)["values"].Begin(); ite2 != (*ite1)["values"].End(); ite2++) {
						LdapAttributeValue_ temp_ldapAttributeValue;
		//					以下为填入temp_ldapAttributeValue的过程
						temp_ldapAttributeValue = ite2->GetString();
		//					以上为填入temp_ldapAttributeValue的过程
						temp_values.push_back(temp_ldapAttributeValue);
					}
				}
		//				以上为填入temp_values的过程
				temp_ldapAttribute.values = temp_values;

		//			以下为填入temp_ldapAttribute的过程		
				if(ite1->HasMember("name"))
		//				以下为填入ldapAttributeName的过程
		//			以上为填入temp_ldapAttribute的过程
				temp_ldapAttributes.push_back(temp_ldapAttribute);
			}
		}
		//		以上为填入temp_ldapAttributes的过程
		temp_LdapEntry.ldapAttributes = temp_ldapAttributes;
		//	以上为填入ldapAttributes的过程

		

		//以上为填入temp_LdapEntry的过程
		content.ldapEntries.push_back(temp_LdapEntry);
	}
}




