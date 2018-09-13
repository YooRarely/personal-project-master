#include "../WordCount/stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/wordcount.h"
#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: �ڴ�������Դ���
			char *a = "emptywords.txt";
			int cnt = 0;
			cnt = character(a);
			Assert::AreEqual(0, cnt);
		}
		TEST_METHOD(TestMethod2)
		{
			// TODO: �ڴ�������Դ���
			char *a = "singleword.txt";
			int cnt = 1;
			cnt = character(a);
			Assert::AreEqual(1, cnt);
		}
		TEST_METHOD(TestMethod3)
		{
			// TODO: �ڴ�������Դ���
			char *a = "allblank.txt";
			int cnt = 0;
			cnt = word(a);
			Assert::AreEqual(0, cnt);
		}
		TEST_METHOD(TestMethod4)
		{
			// TODO: �ڴ�������Դ���
			char *a = "nowordsornums.txt";
			int cnt = 0;
			cnt = word(a);
			Assert::AreEqual(0, cnt);
		}
		TEST_METHOD(TestMethod5)
		{
			// TODO: �ڴ�������Դ���
			char *a = "allcaps.txt";
			int cnt = 0;
			cnt = word(a);
			Assert::AreEqual(1, cnt);
		}
		TEST_METHOD(TestMethod6)
		{
			// TODO: �ڴ�������Դ���
			char *a = "numfirst.txt";
			int cnt = 0;
			cnt = word(a);
			Assert::AreEqual(0, cnt);
		}
		TEST_METHOD(TestMethod7)
		{
			// TODO: �ڴ�������Դ���
			char *a = "huanhang.txt";
			int cnt = 0;
			cnt = word(a);
			Assert::AreEqual(0, cnt);
		}
		
		TEST_METHOD(TestMethod8)
		{
			// TODO: �ڴ�������Դ���
			char *a = "small4.txt";
			int cnt = 0;
			cnt = character(a);
			Assert::AreEqual(3, cnt);
		}
		TEST_METHOD(TestMethod9)
		{
			// TODO: �ڴ�������Դ���
			char *a = "�½�.txt";
			int cnt = 0;
			cnt = character(a);
			Assert::AreEqual(0, cnt);
		}
		TEST_METHOD(TestMethod10)
		{
			// TODO: �ڴ�������Դ���
			char *a = "inputlarge.txt";
			//Assert::AreEqual()
		}
	};
}