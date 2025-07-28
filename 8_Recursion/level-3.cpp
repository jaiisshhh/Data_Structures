#include<iostream>
using namespace std;

bool checkSorted(int arr[], int size, int index){
    if(index >= size){
        return true;
    }
    if(arr[index] > arr[index-1]){
        return checkSorted(arr,size,index+1);
    }
    else{
        return false;
    }
}

int binarySearch(int arr[], int start, int end, int target){
    if(start>end){
        return -1;
    }
    int mid = start + (end - start)/2;
    if(arr[mid] == target){
        return mid;
    }
    if(arr[mid] < target){
        return binarySearch(arr,mid + 1, end, target);
    }
    if(arr[mid] > target){
        return binarySearch(arr,start, mid-1, target);
    }
}

void findSubsequences(string str, string output, int index){
    if(index >= str.length()){
        cout << output << endl;
        return;
    }
    char ch = str[index];
    //exclude
    findSubsequences(str, output, index+1);
    //include
    output.push_back(ch);
    findSubsequences(str, output, index+1);
}

int main(){

    // IS THE ARRAY SORTED
    // int arr[] = {10,20,30,60,50};
    // int size = 5;
    // int index = 1;
    // bool isSorted = checkSorted(arr,size,index);
    // if(isSorted==true){
    //     cout<< "Array is sorted" << endl;
    // }
    // else{
    //     cout << "Array is not sorted" << endl;
    // }

    // BINARY SEARCH
    // int arr[] = {1,3,2,4,23,0,5,6,4534,231};
    // int start = 0;
    // int end = 9;
    // int target = 4534;
    // int fountAt = binarySearch(arr,start,end,target);
    // if(fountAt != -1){
    //     cout << "Target found at : " << fountAt << endl;
    // }
    // else{
    //     cout << "Target not fount" << endl;
    // }

    // FIND SUBSEQUECE V.IMP
    string str = "abc";
    string output = "";
    int index = 0;
    findSubsequences(str,output,index);
    
    return 0;
}