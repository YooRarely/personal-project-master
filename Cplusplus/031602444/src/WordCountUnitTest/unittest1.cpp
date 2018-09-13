#include "stdafx.h"
#include "CppUnitTest.h"
#include"../WordCount/CountAndSort.h"
#include"../WordCount/CountCharacters.h"
#include"../WordCount/CountLines.h"
#include"../WordCount/CountWords.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CharCountTest//ͳ���ַ�
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char f[] = "CharCountTest.txt";
			int chars = CountCharacters(f);
			Assert::IsTrue(chars == 29);
		}

	};
}
namespace LineCountTest1//ͳ������
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char f[] = "LineCountTest1.txt";
			int lines = CountLines(f);
			Assert::IsTrue(lines == 0);
		}

	};
}

namespace WordCountTest1//ͳ�Ƶ���
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char f[] = "WordCountTest1.txt";
			int words = CountWords(f);
			Assert::IsTrue(words == 10);
		}

	};
}

namespace WordCountTest2//��Сд����
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char f[] = "WordCountTest2.txt";
			int words = CountWords(f);
			vector<pair<string, int>> v;
			CountAndSort(f, v);
			vector<pair<string, int>>::iterator vec = v.begin();

			Assert::IsTrue((vec)->first == "aaaa111a" &&words == 3);
		}

	};
}



namespace SortCountTest1//���ֵ������
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char f[] = "SortCountTest1.txt";
			vector<pair<string, int>> v;
			CountAndSort(f, v);
			vector<pair<string, int>>::iterator vec = v.begin();

			Assert::IsTrue((vec)->first == "aaaa" && (vec + 1)->first == "bbbb" &&
							(vec + 2)->first == "cccc" && (vec + 3)->first == "dddd");

		}

	};
}

namespace SortCountTest2//������ʮ��
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char f[] = "SortCountTest2.txt";
			vector<pair<string, int>> v;
			CountAndSort(f, v);
			
			int num = Display(v);

			Assert::IsTrue(num == 10);

		}

	};
}

namespace SortCountTest3//����Ƶ���
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char f[] = "SortCountTest3.txt";
			vector<pair<string, int>> v;
			CountAndSort(f, v);
			vector<pair<string, int>>::iterator vec = v.begin();

			Assert::IsTrue((vec)->second == 5 && (vec + 1)->second == 4 &&
				(vec + 2)->second == 3);

		}

	};
}

namespace SortCountTest4//�ۺ�����
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char f[] = "SortCountTest4.txt";
			vector<pair<string, int>> v;
			CountAndSort(f, v);
			vector<pair<string, int>>::iterator vec = v.begin();

			Assert::IsTrue((vec)->first =="aaaa1a" && (vec + 1)->first == "bbbb" &&
				(vec + 2)->first == "ssss");

		}

	};
}


namespace EmptyFile//���ļ�
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char f[] = "EmptyFile.txt";
			int chars = CountCharacters(f);
			int lines = CountLines(f);
			int words = CountWords(f);
			Assert::IsTrue(chars == 0 && lines == 0 && words == 0);

		}

	};
}

namespace LineCountTest2
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char f[] = "LineCountTest2.txt";
			int lines = CountLines(f);
			Assert::IsTrue(lines == 4 );

		}

	};
}