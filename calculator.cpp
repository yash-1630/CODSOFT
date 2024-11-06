/* Task-2: Simple calculator: Develop a calculator program that performs basic arithmetic
 operations such as addition, subtraction, multiplication, and
 division. Allow the user to input two numbers and choose an
 operation to perform.*/

#include<iostream>
#include<cmath>

using namespace std;

int main() {
    char operation;
    double num1,num2;

    cout << "Enter Number 1:";
    cin >> num1;

    cout << "Enter operator(Ex: +,-,*,/):";
    cin >> operation;

    cout << "Enter Number 2:";
    cin >> num2;

    switch (operation)
    {
    case '+': 
        cout << num1+num2;  
        break;
    
    case '-': 
        cout<< num1-num2;
        break;

    case '*' :
        cout<< num1*num2;
        break;
    
    case '/':
        cout<<num1/num2;
        break;

    default:
        cout<<"The given input is invalid.";
        break;
    }
    
    return 0;
}