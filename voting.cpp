#include <iostream>
using namespace std;
int main()  
    {
        int age;
        cout<<"Enter the age:\t";
        cin >>age;
        if(age>=18){
            cout<<"You're eligible to vote!!!";
        }
        else cout<<"Unable to vote";
        return 0;
    }
