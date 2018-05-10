#include "Common.h"
#include "XXIconv.h"

using namespace cocos2d_xx;

Common::Common(){

}

Common::~Common() {

}

std::string& Common::replace_all(std::string& str, const std::string& old_value, const std::string& new_value)
{
	while (true)   {
		std::string::size_type   pos(0);
		if ((pos = str.find(old_value)) != std::string::npos)
			str.replace(pos, old_value.length(), new_value);
		else   break;
	}
	return   str;
}
std::string& Common::replace_all_distinct(std::string&   str, const   std::string&   old_value, const   std::string&   new_value)
{
	for (std::string::size_type pos(0); pos != std::string::npos; pos += new_value.length())   {
		if ((pos = str.find(old_value, pos)) != std::string::npos)
			str.replace(pos, old_value.length(), new_value);
		else   break;
	}
	return   str;
}

std::vector<std::string> Common::getStrings(std::string str, std::string findstr){
	std::vector<std::string> vecs;
	int index = str.find(findstr);
	int len = findstr.length();
	while (index != -1){
		std::string temp;
		temp = str.substr(0,index);
		if (!temp.empty()){
			vecs.push_back(temp);
		}
		str = str.substr(index + len, str.length());
		index = str.find(findstr);
	}
	vecs.push_back(str);
	return vecs;
}

bool Common::isHave(std::vector<std::string> vecs, std::string value){
	for (int i = 0; i < vecs.size(); i++){
		if (value == vecs.at(i)){
			return true;
		}
	}
	return false;
}

int Common::is_zh_ch(char p)
{
	/*���ֵ������ֽڵ����Ϊ��Ϊ1,��������ж����λ�ķ���
	��p�ֽڽ�����λ���㣬����8λ�������������λ����0��
	��˵��ԭ�����ֽ����λΪ0������1��ôҲ�Ͳ��Ǻ��ֵ�һ���ֽ�
	*/
	if (~(p >> 8) == 0)
	{
		return 1;//�����Ǻ���
	}
	return -1;
}

string Common::sub(string str, int count, string replace)
{

	if (typeid(str) == typeid(string) && str.length() > 0)
	{
		int len = str.length();
		string one = XXIconv::GBK2UTF("��");
		int ll = one.length();
		string tmp = "";

		//�Ȱ�str��ĺ��ֺ�Ӣ�ķֿ�
		vector <string> dump;
		int i = 0;
		int ct = 0;
		while (i < len)
		{
			if (is_zh_ch(str.at(i)) == 1)
			{
				dump.push_back(str.substr(i, ll));
				i = i + ll;
				ct++;
			}
			else
			{
				dump.push_back(str.substr(i, 1));
				i = i + 1;
				ct++;
			}
		}
		//ֱ�Ӵ�dump��ȡ����
		int co = count<ct?count:ct;
		for (int j = 0; j < co; j++)
		{
			tmp += dump[j];
		}
		if (ct-count>=3){
			tmp +=replace;
		}
		return tmp;
	}
	else
	{
		printf("str is not string\n");
		return "";

	}
}