#include "char_cnt.h"
#include "file.h"

int Char_counter::char_count(istream &f, Files &fn)
{
	char a;
	int cnt = 0;
	string temp = "";
	while (f.get(a))//�ַ���ȡ���ɹ�����ֹ
	{
		if ((a >= 32 && a <= 126) || a == '\n' || a == '\t')
			cnt++;
		temp += a;//��ÿ���ַ�����all_string
	}
	fn.set_alstring(temp);
	return cnt;
}
