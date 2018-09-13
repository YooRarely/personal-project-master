#include "FileIO.h"

//����ַ���ȡ�ļ�
string FileIO::readChar(int argc, char *argv[])
{
	string filename = FileIO::getFileName(argc, argv);
	ifstream rf(filename);
	if (!rf) {
		cout << "open file failed. trying open default file:input.txt" << endl;
		rf.open("input.txt", ios::in);
	}
	string charBuf;
	char c;
	while ((c = rf.get()) != EOF)
	{
		if ((c  >= 32 && c <= 126) || c == 9 || c == 10)
		{
			charBuf += c;
		}
	}
	rf.close();
	return charBuf;
}
//���ж�ȡ�ļ�
vector<string> FileIO::readLines(int argc, char *argv[])
{
	string filename = FileIO::getFileName(argc, argv);
	ifstream rf(filename);
	if (!rf) {
		cout << "open file failed. trying open default file:input.txt" << endl;
		rf.open("input.txt", ios::in);
	}
	string tempStr;
	vector<string> lineBuf;
	while (getline(rf, tempStr)) 
	{
		lineBuf.push_back(tempStr);
	}
	return lineBuf;
}
//����ļ�
void FileIO::outputToFile(int characterCount, int wordCount,int lineCount, vector<pair<string, int> > &top10Word)
{
	ofstream wf("result.txt", ios::out);
	wf << "characters:" << characterCount << endl
		<< "words: " << wordCount << endl
		<< "lines:" << lineCount << endl;
	for (int i = 0; i < int(top10Word.size()); i++)
	{
		if (i == 0)
		{
			wf << "<" << top10Word[i].first << ">: " << top10Word[i].second;
		}
		else
		{
			wf << endl << "<" << top10Word[i].first << ">: " << top10Word[i].second;
		}
	}
	wf.close();
	//cout << "Output Completed";
}
//��ȡ�ļ���
string FileIO::getFileName(int argc, char *argv[])
{
	if (argc == 2)
	{
		return string(argv[1]);
	}
	else
	{
		//cout << "Wrong Parameter! trying open default file:input.txt" << endl;
		return "input.txt";
	}
}