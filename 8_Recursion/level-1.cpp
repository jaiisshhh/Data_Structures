#include<iostream>
#include<climits>
#include<vectors>
using namespace std;

int factorial(int n){
    // Base Case
    if(n==1){
        return 1;
    }
    if(n==0){
        return 0;
    }
    // Recusrive Relation 
    int ans = n * factorial(n-1);
    return ans;
}

void revCount(int n){
    if(n==1){
        cout << 1 << endl;
        return;
    }
    cout << n << " ";
    revCount(n-1);

}

int powOfn(int n){
    if(n==0){
        return 1;
    }
    int power = 2 * powOfn(n-1);
    return power;
}

int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int fibonacci = fib(n-1) + fib(n-2);
    return fibonacci;
}

int sum(int n){
    if(n==1){
        return 1;
    }
    int ans = n + sum(n-1);
    return ans;
}

int main(){

    // FACTORIAL 
    // int n = 5;
    // cout << factorial(n) << endl;

    // REVERSE COUNTING
    // int n = 5;
    // revCount(n);

    // 2 TO THE POWER OF N
    // int n = 10;
    // cout << powOfn(n) << endl;

    // FIBONACCI ELEMENT
    // cout << fib(7) << endl; 

    // SUM FROM N -> 1
    // cout << sum(5) << endl;

    return 0;
}