#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cctype>
#include<regex>
#include<io.h>
#include<unordered_map>
#include<iterator>
#include "Tool.h"
using namespace std;

/*ȫ�ֱ�������*/
unordered_map<string, int> strMap;


/*ͳ������*/

/*ͳ�Ƶ��ʸ�����Ƶ��*/
int WordCount(char *argv)
{
	//�����ĵ�
	fstream file2;
	string strfile, stmp;
	file2.open(argv);
	int numWordCount = 0;
	while (getline(file2, strfile))
	{
		strfile.append(stmp);
		stmp.clear();

		

		//ȥ�������������ͳ��
		for (int i = 0; i < strfile.length(); i++)
		{   
			//Сд����
			strfile[i] = tolower(strfile[i]);

			if (ispunct(strfile[i]))
			{
				strfile[i] = ' ';
				numWordCount++;
			}
		}



		//ͳ���ַ�Ƶ��
		stringstream ss(strfile);
		string strTmp;
		while (ss >> strTmp)
		{
			unordered_map<string, int>::iterator it = strMap.find(strTmp);
			if (it == strMap.end())//strMap����������ڵ�ǰ���������һ���¼�ֵ�ԣ�����Ƶ��Ϊ1
			{
				strMap.insert(unordered_map<string, int>::value_type(strTmp, 1));

			}
			else //������������Ƶ�ʼ�1
				strMap[strTmp]++;
		}
		//CountWordFrequency(ss);
	}
	//���������ڷָ���+1
	if (numWordCount > 0)
		numWordCount++;
	file2.close();
	return numWordCount;
}

/*������*/

int main(int argc, char* argv[])
{
	//�����ļ��쳣����
	if(argv == NULL)
	{
		cout << "error: you do not put a file " << endl;
	}
	if (argc > 2)
	{
		cout << "error: you put too many files" << endl;
	}

	//unordered_map<string, int> strMap;
	int numCharCount = 0, numLineCount = 0, numWordCount = 0;

	

	numCharCount = Tool::CharCount(argv[1]);

	numLineCount = Tool::LineCount(argv[1]);

	numWordCount = WordCount(argv[1]);



	//Output(strMap);
	ofstream OutputFile("result.txt");
	if (OutputFile.is_open())
	{
		unordered_map<string, int>::const_iterator it;

		OutputFile << "characters: " << numCharCount << endl;
		OutputFile << "words: " << numWordCount << endl;
		OutputFile << "lines: " << numLineCount << endl;

		//����
		vector<pair<string, int>>vtMap;
		for (auto it = strMap.begin(); it != strMap.end(); it++)
			vtMap.push_back(make_pair(it->first, it->second));

		sort(vtMap.begin(), vtMap.end(),
			[](const pair<string, int> &x, const pair<string, int> &y) -> int {
			return y.second < x.second; });
		int count = 1;
		for (auto it = vtMap.begin(); it != vtMap.end(); it++)
		{
			if (count > 10)
				break;
			OutputFile << it->first << ':' << it->second << endl;
			count++;
		}
		//cout << count << endl;

	}



	return 0;
}
