/********************************************************************************
* @File name: wc.cpp
* @Author: ChenYuXin
* @Version: 3.1
* @Date: 2018-09-11
* @Description: add error handling
********************************************************************************/


#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<regex>
#include<map>
#include<algorithm>
#include"Count.h"	//��װ���е�ͳ����صĹ���
#include"FileIO.h"	//��װ�����ļ���д��صĹ���
using namespace std;



int main(int argc, char *argv[]) 
{
	for (int i = 0; i < 1000; i++)
	{
		int lineCount = 0;			//����
		int characterCount = 0;		//�ַ���
		int wordCount = 0;			//������

		Count count;
		string charBuf = FileIO::readChar(argc, argv);			//����ַ���ȡ�ļ�������charBuf
		vector<string> linesBuf = FileIO::readLines(argc, argv);//���ж�ȡ�ļ�������linesBuf

		characterCount = count.countCharNum(charBuf);			//�����ַ���
		lineCount = count.countLineNum(linesBuf);				//��������
		wordCount = count.countWordNum(linesBuf);				//���㵥����
		vector<pair<string, int> > top10Word = count.countTop10Word();	//ͳ�Ƴ���Ƶ����ߵ�10�����ʣ��п��ܵ�����û��10����

		FileIO::outputToFile(characterCount, wordCount, lineCount, top10Word);	//�����������ļ�
	}

	//system("pause");
	return 0;
}