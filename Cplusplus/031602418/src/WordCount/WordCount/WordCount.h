#include<sstream>
#include<fstream>
#include<iterator>
#include<cctype>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;
unordered_map<string, int>My;
class file {
public:
	char Filename[100];
	string fname;
	int numChar = 0;  //�ַ���
	int numWords = 0; //������
	int numLine = 0;  //����
	file(string name)
	{
		strcpy_s(Filename, name.c_str());
		fname = name;
	}

	void countChar_Line(char *Filename) //ͳ���ַ���������
	{
		char ch;
		bool fg = false;   //��־��Ч������
		FILE *fp;
		if ((fopen_s(&fp, Filename, "r")) != NULL)
		{
			throw "�ļ���ʧ��";
		}
		ch = fgetc(fp);
		if (ch != '\n')
			fg = true; numLine++;
		while (ch != EOF)
		{
			numChar++;
			if (ch == '\n'&&fg == true)   //���ݻ��з��ͱ�־�жϸ����Ƿ���Ч
			{
				numLine++;
				fg = false;
			}
			ch = fgetc(fp);
			if (ch != '\n')
				fg = true;
		}
		fclose(fp);
	}
	void countWord2(stringstream &ss)
	{
		string stemp;
		while (ss >> stemp)
		{
			for (int i = 0; i < stemp.length(); i++)
			{
				if ('A' < stemp[i] && stemp[i] < 'Z')
					stemp[i] += 32;
			}

			if (stemp.length() < 4)
			{
				continue;
			}
			if ((stemp[0]>'z' || stemp[0]<'a' || stemp[1]>'z' || stemp[1]<'a' || stemp[2]>'z' || stemp[2]<'a' || stemp[3]>'z' || stemp[3]<'a'))
			{
				continue;
			}
			numWords++;
			unordered_map<string, int>::iterator it = My.find(stemp);
			if (it == My.end())
			{
				My.insert(unordered_map<string, int>::value_type(stemp, 1));
			}
			else
				My[stemp]++;
		}
	}

	void countWord1()
	{
		string File, temp;
		fstream file(fname);
		while (getline(file, File))
		{
			File.append(temp);
			temp.clear();
			for (int i = 0; i < File.length(); i++)
			{
				if (File[i] == '\n')
					File[i] = ' ';
				if (ispunct(File[i]))
					File[i] = ' ';
			}
			stringstream ss(File);
			countWord2(ss);
		}
	}
};