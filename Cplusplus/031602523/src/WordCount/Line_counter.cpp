#include "line_cnt.h"
#include "file.h"

int Line_counter::lines_counter(istream &f, Files &fn)
{
	int flag = 0;
	int cnt = 0;
	string temp = fn.get_alstring();
	int len = temp.length();
	for (int i = 0; i < len; i++)
	{
		if (temp[i] >= 33 && temp[i] <= 126)//��ʾ��������Ч��
		{
			flag = 1;
			continue;
		}
		if (temp[i] == 10 && flag == 1)//����������Ч�У����ұ�����1�����з�ʱ��������1
		{
			cnt++;
			flag = 0;
		}
	}
	if (flag == 1)//���һ�����û�л��з���ҲҪ��1
		cnt++;

	return cnt;
}