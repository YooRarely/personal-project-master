#include<stdio.h>
#include<cstdlib>
#include"Preprocess.h"
#include"WordCount.h"
#include"CharCount.h"
#include"LineCount.h"

const int FREQUENCY_COUNT = 6;	//�û�ָ��ͳ�ƴʵ�Ƶ��
const int MAX_FILENAME = 266; //ָ������ļ�������

int main()
{
	char filename[MAX_FILENAME] ;
	scanf("%s", filename);
	Preprocess(filename);
	printf("charaters:%d\n", CountChar(filename));
	printf("lines:%d\n", CountLines(filename));
	countWord();
	system("PAUSE");
	return 0;
}
