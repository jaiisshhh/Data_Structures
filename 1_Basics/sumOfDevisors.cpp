#include <iostream>
using namespace std;

int sumOfDiv(int n){
    int sum = 0;
    for(int i=1; i <= n; i++){
        if( n % i == 0) sum += i;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    int totalSum = 0;
    for(int i=1; i <= n; i++){
        totalSum += sumOfDiv(i);
    }
    cout << totalSum << endl;
}

