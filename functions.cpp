#include<iostream>
using namespace std;

// void printName(string name) {
//     for(int i=0; i<5; i++){
//         cout<< name <<endl;
//     }
// }

// void addNumVoid(int a, int b, int c){ //Printing the sum of 3 numbers
//     cout << a + b + c << endl;
// }

// int addNumRet(int a, int b, int c){  //Returning the sum of 3 numbers
//     return a + b + c;
// }

//QUESTOIN 1 : FIND THE MAX OF 3 NUMBERS
// void maxNum(int num1, int num2, int num3){
//     if(num1 > num2 && num1 > num3){
//         cout << "Max number is " << num1 <<endl ;    
//     }
//     else if(num2 > num3){
//         cout << "Max number is " << num2 <<endl;
//     }
//     else{
//         cout << "Max number is " << num3 <<endl;
//     }
// }

//QUESTION 2 : PRINT NUMBERS FROM 1 TO N
// void printNum(int n){
//     for(int i=0; i<=n; i++){
//         cout<<i<<endl;
//     }
// }

void checkEvenOdd(int n){
    if(n % 2 == 0){
        cout<<"even"<<endl;
    }
    else{
        cout<<"odd"<<endl;
    }
}
int main(){
    // printName("jaish");
    // printName("Anurag");
    // printName("Utkarsh");
    // printName("Arjun");

    // addNumVoid(5,10,5);
    // cout << addNumRet(5,10,5) << endl;

    // maxNum(1,2,3);
    // maxNum(5,3,1);

    // printNum(5);

    // checkEvenOdd(3);

    return 0;
}