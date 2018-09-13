#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
#define de(x) cout<<#x<<" = "<<x<<endl
typedef map<string, int> si_map;
class WordCounts{
	public:
	map<string, int>mp;
	bool judge(string str);//ͳ��ÿ�����ʵĳ���Ƶ��
	bool get(string str, int & num);//����ַ���+���㵥�ʸ���
	void work(string file_name,string fout_name);//��ȡ�ļ�+�����������output�ļ�
	void output(string file_name);
};
struct Word {///���ýṹ������
	string word;
	int num;
	bool operator < (const Word & a) const {
		if (num == a.num) return word < a.word;
		else return num > a.num;
	}
};