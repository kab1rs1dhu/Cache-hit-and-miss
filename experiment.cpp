#include "OSULL.h"
#include "OSLL.h"
#include <iostream>
#include <chrono>
using namespace std;

int main()
{
    const int size = 20000000;
    int* A = new int [size];
    for(int i=0; i< size ; i++)
    {
        A[i] = i;
    }

    auto s = chrono::steady_clock::now();

    for (int i = 0 ; i < size  ; i++)
    {
        if (A[i] == size)
            cout << "of" << endl;
    }

    cout << "\n";
    cout << "ARRAY  TIME : ";
    auto e = chrono::steady_clock::now();
    auto d = e - s;
    cout << chrono::duration<double, milli>(d).count() << " ms" << endl;

    OSULL <int , 2000> osull;
    for(int i=size; i>0 ; i--)
    {
        osull.insert(i);
    }

    auto start = chrono::steady_clock::now();

    osull.find(size);

    cout << "\n";
    cout << "OSULL TIME : ";
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    



    OSLL <int> osll;
    for(int i=size; i>0 ; i--)
    {
        osll.insert(i);
    }

    auto FIRST = chrono::steady_clock::now();

    osll.find(size);


    cout << "\n";
    cout << "OSLL TIME : ";
    auto LAST = chrono::steady_clock::now();
    auto dif = LAST - FIRST;
    cout << chrono::duration<double, milli>(dif).count() << " ms" << endl;

    delete [] A;
}
