#include "stdafx.h"
#include "wordmaxsort.h"

void  sor(wd1 *f, int n)
{
	int w;
	for (int i = 0; i<n - 1; i++)
		for (int j = 0; j<n - i - 1; j++)
		{
			w = 0;
			while (f[j].s[w] == f[j + 1].s[w])
				w++;
			if (f[j].s[w] > f[j + 1].s[w])
				swap(f[j], f[j + 1]);
		}
}

void wordmax(char *tx)
{
	FILE *fp;
	fopen_s(&fp, tx, "r");

	if (fp == NULL)
	{
		cout << "���ļ������ڣ�" << endl;
		return;
	}
	ofstream outf("H:\\result.txt", ios::app);

	wd1 temp, word[2000];
	int k, i, n = 0, j;

	while (!feof(fp))
	{
		char c = getc(fp);
		if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))//�����ǵ��� 
		{
			k = 0;
			temp.frq = 1;
			while ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z') || (c >= '0'&&c <= '9'&&k >= 4))//������λ����֤ 
			{
				if (c >= 'A'&&c <= 'Z')
				{
					c = c + 32;
				}
				temp.s[k] = c;
				k++;

				c = getc(fp);
			}
			temp.s[k] = '\0';//���ʽ�����ʶ 
			k++;

			j = n;

			if (strlen(temp.s) >= 4)//ȷ������4λӢ����ĸ 
			{
				for (i = 0; i < j; i++)
				{
					if (strcmp(temp.s, word[i].s) == 0)//����֮ǰ�� 
					{
						word[i].frq++;
						break;
					}
				}

				if (n == 0 || i == j)
				{
					word[n] = temp;
					n++;
				}
			}
		}
	}

	sor(word, n);
	wd1 max[10];

	for (i = 0; i < 10; i++)//��ʼ��ǰʮ��
	{
		max[i] = word[i];
	}

	for (j = 0; j < 10; j++)//ǰʮ������ 
	{
		for (i = 0; i < 10 - j - 1; i++)
		{
			if (max[i].frq < max[i + 1].frq)
			{
				swap(max[i], max[i + 1]);
			}
		}
	}

	for (i = 10; i < n; i++)//�Һ������ 
	{
		if (max[9].frq < word[i].frq)//����С�Ļ��� 
		{
			int a = 8;
			while (max[a].frq < word[i].frq&&a >= 0)
			{
				a--;//��λ����һ�����Լ����word
			}

			for (j = 9; j > a + 1; j--)
			{
				max[j] = max[j - 1];//ǰ���������һλ 
			}
			if (a < 0)//˵��word[i]��max[0]��
				max[0] = word[i];
			else
				max[j] = word[i];
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (strlen(max[i].s) == 0)
			continue;
		outf << "<" << max[i].s << ">" << ":" << max[i].frq << endl;
	}
	outf.close();
}