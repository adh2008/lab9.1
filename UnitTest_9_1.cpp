// UnitTest_9_1.cpp – unit-тест до проекту Lab_9_1 (arctg x, варіант 9)
#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include "C:/Users/Legion/Desktop/lab9/dod.cpp"
#include "C:/Users/Legion/Desktop/lab9/sum.cpp"
#include "C:/Users/Legion/Desktop/lab9/var.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_9_1
{
    TEST_CLASS(UnitTest_9_1)
    {
    public:

        // dod(): a_1 = x^3/3 зі знаком "-", тобто -x^3/3
        TEST_METHOD(TestDod_FirstTerm)
        {
            nsVar::x = 0.5; nsVar::n = 1; nsVar::a = 0.5;
            nsDod::dod();
            Assert::AreEqual(-0.5 * 0.5 * 0.5 / 3.0, nsVar::a, 1e-12);
        }

        // dod(): a_2 = x^5/5
        TEST_METHOD(TestDod_SecondTerm)
        {
            nsVar::x = 0.5; nsVar::n = 2; nsVar::a = -0.5 * 0.5 * 0.5 / 3.0;
            nsDod::dod();
            Assert::AreEqual(std::pow(0.5, 5) / 5.0, nsVar::a, 1e-12);
        }

        // sum(): сума ряду збігається з atan(x)
        TEST_METHOD(TestSum_Positive)
        {
            nsVar::x = 0.5; nsVar::e = 1e-6;
            nsSum::sum();
            Assert::AreEqual(std::atan(0.5), nsVar::s, 1e-5);
        }

        // sum(): функція непарна, arctg(-x) = -arctg(x)
        TEST_METHOD(TestSum_Negative)
        {
            nsVar::x = -0.5; nsVar::e = 1e-6;
            nsSum::sum();
            Assert::AreEqual(std::atan(-0.5), nsVar::s, 1e-5);
        }

        // sum(): x = 0 -> сума 0, виконується одна ітерація
        TEST_METHOD(TestSum_Zero)
        {
            nsVar::x = 0; nsVar::e = 1e-6;
            nsSum::sum();
            Assert::AreEqual(0.0, nsVar::s, 1e-12);
            Assert::AreEqual(1, nsVar::n);
        }
    };
}
