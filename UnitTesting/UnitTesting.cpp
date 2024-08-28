#include "pch.h"
#include "CppUnitTest.h"
#include "../message.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesting
{
	TEST_CLASS(UnitTesting)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		}

		// This should fail
		TEST_METHOD(TestMethod2)
        {
            int expected = 2;
            int actual = 1;
            Assert::AreEqual(expected, actual);
        }

	};
}
