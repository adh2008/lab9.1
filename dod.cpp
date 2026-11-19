// dod.cpp
// файл реалізації функції
#include "dod.h"
#include "var.h"
using namespace nsVar;

// Доданок a_n = (-1)^n * x^(2n+1) / (2n+1)
// Рекурентне співвідношення: a_n = a_(n-1) * (-x^2) * (2n-1) / (2n+1)
void nsDod::dod() {
    a *= -x * x * (2.0 * n - 1) / (2.0 * n + 1);
}
