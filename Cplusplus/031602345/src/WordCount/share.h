#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <String>
#include <fstream>
#include <assert.h>

using namespace std;

// �ַ��Ƿ�����ĸ
bool CharAlphaJudge(char ch);

// �ַ��Ƿ�����ĸ or ����
bool CharAlphaNumberJudge(char ch);

// ���word�ĺϷ���
bool WordCheck(string word);

// ���һ���Ƿ��п���ʾ���ַ�
bool HaveVisibleChar(string line);

// �õ���Ƶ�ֵ� �������������ͳ���ַ�����
void GetWordCountMap(string file_location);

// �Զ���getline����
bool GetLine(ifstream &instream, string &line);