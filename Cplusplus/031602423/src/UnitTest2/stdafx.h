// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

// ���� CppUnitTest ��ͷ�ļ�
#include "CppUnitTest.h"
#include<iostream>
#include<string>
#include<map>
#include <fstream>
#include <algorithm>
#include<vector>
#include <assert.h>
using namespace std;
int character(char* path);
int word(char* path);
int isstring(string c);
string mytolower(string s);
vector<pair<string, int>> WordsFrequency(char* path);
int cmp(const pair<string, int>& x, const pair<string, int>& y);
vector<string> splitt(const string &s);
int main(int args, char* argv[]);
// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
