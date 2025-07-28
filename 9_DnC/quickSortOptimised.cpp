#include<iostream>
using namespace std;

void quickSort(int arr[], int start, int end){
    if(start >= end){
        return;
    }
    int pivot = end;
    int i = start - 1;
    int j = start;
    while(j < pivot){
        if(arr[j] < arr[pivot]){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    i++; // i is the right position for the pivot elemenet
    swap(arr[i], arr[pivot]);
    quickSort(arr, start, i - 1); // Left Part 
    quickSort(arr, i + 1, end); // Right part
}

int main(){
    int arr[] = {7,2,1,8,6,3,5,4};
    int n = 8;
    int start = 0;
    int end = n-1;
    cout << "Before Quick Sort : " << endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    quickSort(arr,start,end);
    cout << "After Quick Sort : " << endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

}