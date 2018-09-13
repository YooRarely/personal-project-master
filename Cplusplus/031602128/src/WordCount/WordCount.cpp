
#include "pch.h"
#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<utility>
#include<set>
#include<map>
#pragma warning(disable:4996)
using namespace std;
#define de(x) cout<<#x<<" = "<<x<<endl
#define rep(i,a,b) for(int i=(a);i<(b);++i)
int ifargcisok(int argc) {
	if (argc <=1) {
		printf("Error:Please input filename.\n");
		return 0;
	}
	else if (argc > 2) {
		printf("Error:Please do not enter too many parameters.\n");
		return 0;
	}
	else return 1;
}
int main(int argc,char *argv[])
{
	if (!ifargcisok(argc))return 0;
	QWE_wordCount *A = new  QWE_wordCount();
	A->init();
	A->MYscanf(argv[1]);
	if (A->error) {return 0;}
	A->eft_char = A->CountChar();
	A->eft_word = A->CountWord();
	A->CountMxWord();
	A->MYprint();
	return 0;
}