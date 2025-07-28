#include <iostream>
#include <vector>
using namespace std;

void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl; 
}

void printVector(vector<int>v){
    cout<<"Printing Vector"<<endl;
    int size = v.size();
    for(int i=0; i<size; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){

    // Static memory allocation
    // int arr[5] = {1,2,3,4,5};
    // printArr(arr, 5);

    // Dynamic
    // int n;
    // cin >> n;
    // int *arr = new int[n];
    // for(int i=0; i<n; ++i){
    //     int data;
    //     cin >> data;
    //     arr[i] = data;
    // }
    // printArr(arr,n);

    vector<int>v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // printVector(v);
    int n= 5;
    for(int i=1; i<=5; i++){
        v.push_back(i);
    }
    // printVector(v);
    // int a = v.at(3);
    // cout << "the value at i'th index is " << a << endl;

    for(auto i: v){
        cout << i << " ";
    }
    cout << endl;


    return 0;
}