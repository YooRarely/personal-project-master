#include "stdafx.h"
#include "wordcount.h"

int wordcount(char *tx)
{
	int wordcnt = 0, j, n = 0;
	wd temp, word[2000];
	int k, i;
	ofstream outf("H:\\result.txt", ios::app);

	FILE *fp;
	fopen_s(&fp, tx, "r");

	if (fp == NULL)
	{
		cout << "���ļ������ڣ�" << endl;
		return 0;
	}

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
				wordcnt++;
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
	outf << "words:" << wordcnt << endl;
	outf.close();
	return wordcnt;
}