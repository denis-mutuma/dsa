#include <bits/stdc++.h>
using namespace std;

template <class T>
class Calculator
{
public:
    int num1;
    int num2;
    char operation;
    Calculator(T x, T y) : num1(x), num2(y) {}

    T result()
    {
        T result;
        switch (operation)
        {
        case '+':
            result = add();
            break;
        case '-':
            result = subtact();
            break;
        case '*':
            result = multiply();
            break;
        case '/':
            result = divide();
            break;
        default:
            cout << "Invalid operation" << endl;
            break;
        }
        return result;
    }

    T add() { return num1 + num2; }
    T subtact() { return num1 - num2; }
    T multiply() { return num1 * num2; }
    T divide()
    {
        if (num2 == 0)
        {
            cout << "Cannot divide by zero" << endl;
            return -1;
        }
        return num1 / num2;
    }
};

int main()
{
    Calculator<int> calc(1, 1);
    cout << "Enter first number: " << endl;
    cin >> calc.num1;
    cout << "Enter second number: " << endl;
    cin >> calc.num2;
    cout << "Enter one of the following operations to perform: +, -, *, /";
    cin >> calc.operation;
    cout << "The result is: " << calc.result() << endl;
}