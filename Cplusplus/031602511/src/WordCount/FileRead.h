#pragma once
#include <fstream>
#include <string> 
#include <unordered_map>
#include <vector>

using namespace std;

#define ORDER_WORD vector<pair<string, int>>

class FileRead
{
public:
	FileRead(string filePath);
	~FileRead();
	int getCrtNum();									//�����ַ���
	int getLineNum();									//��������
	int getWordNum();									//���ص�������
	vector<pair<string, int>> getOrderWord();			//���ش�ź�����ĵ��ʼ�����ִ���������
private:
	int lineNum;
	int wordNum;
	int crtNum;
	bool hasCountCrtAndLine;					//�ж��Ƿ�ͳ�ƹ��ַ���������
	bool hasCountWord;							//�ж��Ƿ�ͳ�ƹ�������
	bool hasReadFile;
	ifstream readFile;
	unordered_map<string, int> wordMap;					//����ļ��з���Ҫ��ĵ���
	unordered_map<string, int>::iterator itor;
	vector<pair<string, int>> orderWord;				//�����ŵ��ʵ�����

	void wordCount();									//ͳ���ļ�������������ļ��е���
	void crtCount();									//ͳ���ļ��ַ���������
	void wordPair();									//���ļ��е��ʰ�Ҫ������
};

class cmp {
public:
	bool operator()(pair<string, int> &a, pair<string, int> &b);
};