#include "pch.h"
#include "work_2.h"

int C_chars(istream &fl, File &fn, Words &wn)
{
	char chr;
	int count_c = 0, flag = 0;		//flag�ж���Ч��
	while (!fl.eof())				//�Ƿ�����ļ�β
	{
		fl.get(chr);
		if ((chr <= 126 && chr >= 32) || chr == 9 || chr == 10)
		{
			if (fl.eof())
				break;
			if (chr <= 126 && chr >= 33)
				flag = 1;
			wn.all_string += chr;	//�����ַ�������
			count_c++;
			if (chr == 10 && flag == 1)
			{
				fn.count_lines++;
				flag = 0;
			}
			//cout << chr <<" "<<count_c<< endl;
		}
	}
	if (flag == 1)
		fn.count_lines++;		//��ĩ��Ч�в������������
	return count_c;
}