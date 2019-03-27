#include <iostream>
#include "Multime.h"

using namespace std;

int main() {
    Multime a, b(9);
    a.Inserare(1);
    a.Inserare(-1);
    Multime c = a;
    cin >> b;
    for (int i = 0; i < c.Numar(); i++)
        cout << c[i] << " ";
    cout << endl;
    Multime d;
    d = b + a;
    for (int i = 0; i < d.Numar(); i++)
        cout << d[i] << " ";
    cout << endl;
    c.Sterge(0);
    Multime e;
    e = d - c;
    a = e;
    for (int i = 0; i < a.Numar(); i++)
        cout << a[i] << " ";
    cout << endl;
    b = b - d;
    for (int i = 0; i < b.Numar(); i++)
        cout << b[i] << " ";
    cout << endl;
    if (a > b)
        cout << "Multimea a este mai mare ca b" << endl;
    else if (a < b)
        cout << "Multimea b este mai mare ca a" << endl;
    int x = e.Cautare(-1);
    cout << "In multimea e elementul -1 se afla pe pozitia " << x;
    return 0;
}