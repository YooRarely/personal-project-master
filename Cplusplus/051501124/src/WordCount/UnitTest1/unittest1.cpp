#include "stdafx.h"
#include "CppUnitTest.h"
#include "../WordCount/student.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: �ڴ�������Դ���
			student a;
			int b = a.hello();


			Assert::AreSame(b, 123);
		}

	};
}