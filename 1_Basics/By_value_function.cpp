#include<iostream>
using namespace std;

// int incrimentBy1(int n)   //This is call by value as the value of n is going to the fucntion 
// {
//     n = n + 1;
//     return n;
// }

void incrimentBy1(int&n){  //This is calling by refrence where you are calling the refrence value of n 
    n++;
    return;
}
int main() {
    int n;
    cin >> n;

    incrimentBy1(n);
    cout<<n<<endl;

    return 0;

}