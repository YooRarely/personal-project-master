#include "Count.h"

//�����ַ���
int Count::countCharNum(string &charBuf)
{
	return int(charBuf.size());
}
//��������
int Count::countLineNum(vector<string> &linesBuf)
{
	int lineCount = 0;
	for (int i = 0; i != linesBuf.size(); i++) 
	{
		for (string::iterator it = linesBuf[i].begin(); it != linesBuf[i].end(); it++) 
		{
			if (*it > 32) 
			{
				lineCount++;
				break;
			}
		}
	}
	return lineCount;
}
//���㵥����
int Count::countWordNum(vector<string> &linesBuf)
{
	int wordCount = 0;
	string wordBuf;
	for (int i = 0; i != linesBuf.size(); i++) 
	{
		int len = linesBuf[i].length();
		for(int j = 0;j < len;j++)
		{
			if (isLetter(linesBuf[i][j]) || isDigit(linesBuf[i][j])) 
			{
				wordBuf += linesBuf[i][j];
			}
			else {
				if (wordBuf.length() >= 4 && isLetter(wordBuf[0]) && isLetter(wordBuf[1]) && isLetter(wordBuf[2]) && isLetter(wordBuf[3])) 
				{
					transform(wordBuf.begin(), wordBuf.end(), wordBuf.begin(), ::tolower); 
					pair<map<string, int>::iterator, bool> ret = wordMap.insert(make_pair(wordBuf, 1));
					if (!ret.second) 
					{
						++ret.first->second;
					}
					wordCount++;
				}
				wordBuf = "";
			}

		}
		if (wordBuf.length() >= 4 && isLetter(wordBuf[0]) && isLetter(wordBuf[1]) && isLetter(wordBuf[2]) && isLetter(wordBuf[3])) 
		{
			transform(wordBuf.begin(), wordBuf.end(), wordBuf.begin(), ::tolower); 
			pair<map<string, int>::iterator, bool> ret = wordMap.insert(make_pair(wordBuf, 1));
			if (!ret.second) 
			{
				++ret.first->second;
			}
			wordCount++;
		}
		wordBuf = "";

	}
	return wordCount;
}
//ͳ�Ƴ���Ƶ����ߵ�10������
vector<pair<string, int> >  Count::countTop10Word()
{
	vector<pair<string, int> > wordVector;
	for (map<string, int>::iterator it = wordMap.begin(); it != wordMap.end(); it++) 
	{
		wordVector.push_back(make_pair(it->first, it->second));
	}
	for (int i = 0; i < int(wordMap.size()) && i < 10; i++)
	{
		auto maxFreWord = wordMap.begin();
		for (auto it = wordMap.begin(); it != wordMap.end(); it++)
		{
			if (it->second > maxFreWord->second)
			{
				maxFreWord = it;
			}
		}
		top10Word.push_back(make_pair(maxFreWord->first, maxFreWord->second));
		maxFreWord->second = -1;
	}
	return top10Word;
}

//�ж��Ƿ�Ϊ��ĸ
inline bool Count::isLetter(string::iterator it) {
	if ((*it >= 65 && *it <= 90) || (*it >= 97 && *it <= 122)) {
		return true;
	}
	else {
		return false;

	}
}
//�ж��Ƿ�Ϊ��ĸ(����)
inline bool Count::isLetter(const char ch) {
	if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) {
		return true;
	}
	else {
		return false;

	}
}
//�ж��Ƿ�Ϊ����
inline bool Count::isDigit(string::iterator it) {
	if (*it >= 48 && *it <= 57) {
		return true;
	}
	else {
		return false;
	}
}
//�ж��Ƿ�Ϊ����(����)
inline bool Count::isDigit(const char ch) {
	if (ch >= 48 && ch <= 57) {
		return true;
	}
	else {
		return false;
	}
}