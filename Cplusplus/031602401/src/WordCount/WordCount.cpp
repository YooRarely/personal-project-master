#include <iostream>
#include <fstream>
#include <string>
#include<cstring>
using namespace std;
struct wd {
	int num;
	char* s;
	int flag = 1;
};
wd word[500] = { 0 };
wd word2[200] = { 0 };
int ans[200];
int Judge(char Word[]) {//判断是不是四个英文字母开头 后面跟着字母数字符号

	if (Word == NULL) return 0;
	if (strlen(Word) < 4) return 0;
	if (Word[0] >= 'a'&&Word[0] < 'z'&&Word[1] >= 'a'&&Word[1] <= 'z'&&Word[2] >= 'a'&&Word[2] <= 'z'&&Word[3] >= 'a'&&Word[3] <= 'z')
		return 1;
	else
		return 0;
}

void lower(string& str) {//大写转化成小写
	for (int j = 0; j < str.size(); j++)
	{
		if (str[j] <= 'Z'&&str[j] >= 'A') {
			str[j] = str[j] + 32;
		}
	}
}
void change(string& str, char a[200]) {
	for (int j = 0; j < str.size(); j++)
	{
		a[j] = str[j];
	}
	a[str.size()] = '\0';
}
void bubble_sort(wd arr[], int len)
{
	int i, j;  wd temp;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - 1 - i; j++)
			if (arr[j].num < arr[j + 1].num)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}
int main(int argc,char **argv)
{
	int m = 0;
	int linenumber = 0;
	int Num = 0;
	int linenum = 0;
	string temp;
	if (argv[1] == NULL) {
		cout << "No input";
	}
	fstream file(argv[1]);
	if (!file) {
		printf("Unable to open");
	}
	char p[500];
	while (getline(file, temp)) {//每一行
		int n = 10;
		linenum = temp.size() + 1;
		linenumber++;
		Num = Num + linenum;
		lower(temp);
		change(temp, p);
		//cout << p;
		int l = 0;
		for (int y = 0; y < temp.size(); ) {
			if (p[y] == ' ' || p[y] == '.' || p[y] == '?' || p[y] == '!' || p[y] == ',' || p[y] == '"')
			{
				y++;
				continue;
			}
			else {//发现一个单词
				char *danci = (char*)malloc(sizeof(char) * 10);
				memset(danci, 0, sizeof(char) * 10);
				int k = 0;
				while ((p[y] >= 'a'&&p[y] <= 'z') || (p[y] >= '0'&&p[y] <= '9')) {
					danci[k] = p[y];
					k++; y++;
				}
				danci[k] = '\0';
				//cout << danci << "*"<<endl;
				if (Judge(danci)) {
					word2[m].s = danci;
					word2[m].num = 0;
					/*if (word2[m].s) {
						cout << word2[m].s << endl;
					}*/
					m++;
				}
			}
		}
	}
	file.close();
	//for (int i = 0; i < m; i++)
	//	cout << word2[i].s << word2[i].num << "*";  //测试
	cout << endl;
	for (int i = 0; i < m; i++) {
		for (int e = 0; e < m; e++) {
			if (!strcmp(word2[i].s, word2[e].s)) {
				word2[i].num++;
				if (e < i)
					word2[i].flag = 0;
			}
		}
	}
	int x = 0;
	for (int i = 0; i < m; i++) {
		if (word2[i].flag != 0) {
			word[x] = word2[i];
			x++;
		}
	}
	bubble_sort(word, x);//冒泡排序
	cout << "characters:" << Num << endl;
	cout << "words:" << m << endl;
	cout << "lines:" << linenumber << endl;
	for (int i = 0; i < x; i++) {
		cout << "word" << i + 1 << ":" << word[i].s << " " << "times:" << word[i].num << endl;  //测试
		if (i == 10)
			break;
	}

	return 0;
}