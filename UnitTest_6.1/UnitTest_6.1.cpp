#include "pch.h"
#include "CppUnitTest.h"
#include "../6.1/6.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_6_1
{
    TEST_CLASS(UnitTest_6_1)
    {
    public:

        TEST_METHOD(TestGenArray)
        {
            const int size = 25;
            int arr[size];
            gen(arr, size, 15, 94);

            for (int i = 0; i < size; i++) {
                Assert::IsTrue(arr[i] >= 15 && arr[i] <= 94);
            }
        }

        TEST_METHOD(TestCountElements)
        {
            const int size = 25;
            int arr[size] = { 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52 };

            int count = countElements(arr, size);
            Assert::AreEqual(2, count);
        }

        TEST_METHOD(TestSumElements)
        {
            const int size = 25;
            int arr[size] = { 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 78, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52 };

            int sum = sumElements(arr, size);
            Assert::AreEqual(78, sum);  // 78 (26 + 52)
        }

        TEST_METHOD(TestZeroArray)
        {
            const int size = 25;
            int arr[size] = { 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

            Zero(arr, size);

            Assert::AreEqual(0, arr[0]); 
            Assert::AreEqual(0, arr[13]);
            Assert::AreEqual(0, arr[24]);
        }
    };
}
