#include<iostream>
using namespace std;

void sumOfEvenUptoN(int n){
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(i%2==0){
            ans = ans + i;
        }
    }
    cout<<ans<<endl;
}
int main(){
    sumOfEvenUptoN(10);
    return 0;
}