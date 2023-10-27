#include<iostream>
using namespace std;

int main(){

    //integer -> 4 bytes
    int num = 50;
    cout<<num<<endl;
    cout<<"size of integer is "<<sizeof(num)<<endl;

    //character -> 4 bytes
    char ch = 'k';
    cout<<ch<<endl;
    cout<<"size of character is "<<sizeof(ch)<<endl;

    //float -> 1 bytes
    float point = 1.69;
    cout<<point<<endl;
    cout<<"size of float is "<<sizeof(point)<<endl;

    //long -> 8 bytes
    long number = 23;
    cout<<"size of long is "<<sizeof(number)<<endl;

    //Bool -> 1 bytes
    bool Boolnum;
    cout<<"size of bool value is "<<sizeof(Boolnum)<<endl;

    //garbage vlaue
    int num1;
    cout<<num1<<endl;
    //if you won't assign anything then it will give a random garbage value
}