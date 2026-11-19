// sum.cpp
// файл реалізації функції
#include <cmath>
#include "dod.h"
#include "sum.h"
#include "var.h"
using namespace nsDod;
using namespace nsVar;

void nsSum::sum() {
    n = 0;
    a = x;      // перший доданок (n = 0): x
    s = a;
    do {
        n++;
        dod();  // обчислення наступного доданку
        s += a;
    } while (fabs(a) > e);
}
