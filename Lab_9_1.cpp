// Lab_9_1.cpp
// головний файл проекту – функція main
#include <iostream>
#include <cmath>
#include <iomanip>
#include "dod.h"
#include "sum.h"
#include "var.h"
using namespace std;
using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main()
{
    cout << "x_p = "; cin >> x_p;
    cout << "x_k = "; cin >> x_k;
    cout << "dx  = "; cin >> dx;
    cout << "e   = "; cin >> e;
    cout << endl;

    cout << "Table of arctg(x) via Taylor series" << endl;
    cout << string(55, '-') << endl;
    cout << "|" << setw(10) << "x"
         << "|" << setw(14) << "arctg(x)"
         << "|" << setw(14) << "Sum"
         << "|" << setw(12) << "Terms" << "|" << endl;
    cout << string(55, '-') << endl;

    x = x_p;
    while (x <= x_k + 1e-12) {  
        sum();
        cout << "|" << setw(10) << fixed << setprecision(4) << x
             << "|" << setw(14) << setprecision(8) << atan(x)
             << "|" << setw(14) << s
             << "|" << setw(12) << n + 1 << "|" << endl;  
        x += dx;
    }
    cout << string(55, '-') << endl;

    cin.get(); cin.get();
    return 0;
}
