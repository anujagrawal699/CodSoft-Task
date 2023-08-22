#include<iostream>

using namespace std;

int main()
{
    int num1, num2;
    char x;

    cout<<"Enter number one"<<endl;
    cin>>num1;

    cout<<"Enter number two"<<endl;
    cin>>num2;

    cout<<"Press a for addition"<<endl;
    cout<<"Press b for subtraction"<<endl;
    cout<<"Press c for multlipication"<<endl;
    cout<<"Press d for division"<<endl;
    cout<<"Press e for remainder"<<endl;
    cin>>x;

    if (x=='a')
    cout<<"The sum = "<<num1 + num2<<endl;

    else if (x=='b')
    cout<<"The subtraction = "<<num1 - num2<<endl;

    else if (x=='c')
    cout<<"The product = "<<num1 * num2<<endl;

    else if (x=='d')
    cout<<"The division = "<<num1 / num2<<endl;

    else if (x=='e')
    cout<<"The remainder = "<<num1 % num2<<endl;

    else
    cout<<"Invalid Operation"<<endl;   

    return 0;
}