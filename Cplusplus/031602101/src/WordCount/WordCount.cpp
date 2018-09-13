#include"stdafx.h"
#define _CRT_SECURE_NO_DEPRECATE��
#define _CRT_SECURE_NO_WARNINGS��
#pragma warning(disable:4996)��
using namespace std;
#define M 20000
typedef struct
{
	char danci[19];//���浥��
	int count;//��¼���ʸ���,������ּ���
}sq;

void wordsta(FILE *fp, sq t_word, sq *word)  //ͳ�Ƶ���Ƶ��
{
	int characters = 0, lines = 0, numberC = 0;
	int i, j, K, n = 0;
	while (!feof(fp))//feof()����Ƿ�ﵽ�ļ�β��
	{
		char ch;
		ch = getc(fp);//��ȡ��ǰ�ַ�
		characters++;
		if (ch == ' ' || ch == 10)
		{//ASCLL����10Ϊ���з���������Ϊ�����ո��س�������
			if (ch == 10)
			{
				lines++;
			}//�ж�����
			continue;
		}
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))              //����һ������
		{
			K = 0;
			t_word.count = 1;
			while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch == '\''))
			{
				if (ch >= 'A'&&ch <= 'Z')
					ch += 32;//ת����Сд
				t_word.danci[K++] = ch;//�ѵ�ǰ��ĸ��������
				ch = getc(fp);
				characters++;
			}
			t_word.danci[K++] = '\0';//������־\0
			if (K <= 4)
			{
				continue;
			}
			numberC++;
			//һ�����ʽ���
			j = n;
			for (i = 0; i < j; i++) //��ǰ��ĵ��ʱȽ�
			{
				if (strcmp(t_word.danci, word[i].danci) == 0)//����е�����ͬ
				{
					word[i].count++;//����൥�ʼ�1
					break;
				}
			}
			if (n == 0 || i == j)//ǰ�����û����ͬ�ĵ���
			{
				word[n] = t_word;//��Ϊ���൥�ʿ����µ�Ԫ
				n++;
			}
		}
	}
	cout << "characters" << characters << endl;
	cout << "words" << numberC << endl;
	cout << "lines" << lines << endl;
}
sq* namemath(sq *word) //����ð�ݷ�����ǰʮ����
{
	int i, j, n = 0;
	sq *frequency_max = new sq[11];
	sq temp;
	for (i = 0; i<10; i++)
	{
		frequency_max[i] = word[i];//��ʼ��Ƶ����ߵ�ʮ������Ϊǰʮ������
	}
	//ð������
	for (j = 0; j<10; j++)
		for (i = 0; i<10 - j; i++)
			if (frequency_max[i].count<frequency_max[i + 1].count)
			{
				temp = frequency_max[i];
				frequency_max[i] = frequency_max[i + 1];
				frequency_max[i + 1] = temp;
			}
	for (i = 10; i<n; i++)
	{
		if (frequency_max[9].count<word[i].count)
		{
			int a = 8;
			while (frequency_max[a].count<word[i].count&&a >= 0)
			{
				a--;
			}


			for (j = 9; j>a + 1; j--)
			{
				frequency_max[j] = frequency_max[j - 1];
			}
			if (a<0)
				frequency_max[0] = word[i];
			else
				frequency_max[j] = word[i];
		}
	}
	return frequency_max;
}
void main(int arg, char* argv[])
{
	int i;
	sq *word = new sq[M];
	sq t_word = { 0,0 };
	FILE *fp;
	fp = fopen(argv[1], "r");
	cout << argv[1] << endl;
	if (!fp) cout << "error" << endl;
	cout << "ͳ���ļ���Ƶ����ߵ�ʮ������" << endl;
	wordsta(fp, t_word, word);
	sq* frequency_max = namemath(word);
	for (i = 0; i<10; i++)
	{
		cout << setiosflags(ios::left) << setw(10) << frequency_max[i].danci << frequency_max[i].count << endl;//setw()����������Ĭ���Ҷ���
	}
	std::cin.ignore(std::cin.rdbuf()->in_avail() + 1);
}