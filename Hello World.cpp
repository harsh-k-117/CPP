#include<iostream>
using namespace std;

int main()
{
    int a, b, sum, sub, mul, div, mod;
    cout << "Enter any two numbers: " << endl;
    cin >> a >> b;

    sum = a + b;
    sub = a - b;
    mul = a * b;
    div = a / b;
    mod = a % b;

    cout << "Addition is " << sum << "\nSubtraction is " << sub
         << "\nMultiplication is " << mul << "\nDivision is " << div
         << "\nRemainder is " << mod << endl;

    return 0;
}
