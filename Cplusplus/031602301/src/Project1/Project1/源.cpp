#include "zuoye.h"

int main()
{
	cout << "����Ҫд����ļ�·�����ļ�����" << endl;
	string filename;
	cin >> filename;
	File file;
	file.ShuRufile(filename);
	file.Wordscount(filename);
	file.Show();
	cout << "����Ҫ��ȡ���ļ�·�����ļ�����" << endl;
	cin >> filename;
	file.ShuChufile(filename);
	system("pause");
	return 0;
}
