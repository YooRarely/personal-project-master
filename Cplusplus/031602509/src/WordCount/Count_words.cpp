#include "pch.h"
#include "work_2.h"

int C_words(istream &fl, Words &wn, Wordnode **l)
{
	int count = 0;
	int flag = 0;
	regex pattern(".[a-zA-Z]{3}[a-zA-Z0-9]*");		//�趨������ʽģ��
	smatch result;									//smatch����string���
	//cout << regex_search(wn.all_string, result, pattern)<<endl;
	string::const_iterator start = wn.all_string.begin();	//�ַ�����ʼ������
	string::const_iterator end = wn.all_string.end();		//�ַ���ĩβ������
	string temp_str;
	while (regex_search(start, end, result, pattern))		//ѭ������ƥ��ģ��ĵ���
	{
		flag = 0;
		//cout<<"successfully match";
		temp_str = result[0]; 

		if (!((temp_str[0] <= 90 && temp_str[0] >= 65) || (temp_str[0] <= 122 && temp_str[0] >= 97)))//���ַ��ж�
		{
			if (temp_str[0] >= 48 && temp_str[0] <= 57)												//�������ַ��ж�
				flag = 1;
			temp_str.erase(0, 1);
			if (!(temp_str.size()>=4&&((temp_str[3] <= 90 && temp_str[3] >= 65) || (temp_str[3] <= 122 && temp_str[3] >= 97))))
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			transform(temp_str.begin(), temp_str.end(), temp_str.begin(), ::tolower);//ת��ΪСд����
			hash_insert(l, temp_str);							//��ϣ�ڵ����
			count++;
		}
		start = result[0].second;							//�����һ����
	}
	//cout << endl;
	return count;
}