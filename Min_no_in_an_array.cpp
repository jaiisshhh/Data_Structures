#include<iostream>
#include<limits.h>
using namespace std;

int minNum(int arr[], int size){
    int minNum = INT_MAX;
    for(int i=0; i<size; i++){
        if(arr[i]<minNum){
            minNum = arr[i];
        }
    }
    return minNum;
}

int maxNum(int arr[], int size){
    int maxNum = INT_MIN;
    for(int i=0; i<size;i++){
        if(arr[i]>maxNum){
            maxNum = arr[i];
        }
    }
    return maxNum;
}

int main(){
    int arr[] = {12,3,44,56,7};
    int size = 5;

    int minimum = minNum(arr, size);
    cout<<"Minimum number is "<<minimum<<endl;

    int maximum = maxNum(arr, size);
    cout<<"Maximum number is "<<maximum<<endl;

    return 0;
}