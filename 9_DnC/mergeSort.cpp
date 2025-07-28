#include<iostream>
using namespace std;

void merge(int arr[], int start, int end){
    int mid = (start + end) / 2;
    int lenLeft = mid - start + 1;
    int lenRight = end - mid;
    int *left = new int[lenLeft];
    int *right = new int[lenRight];
    int k = start; // To copy array of the left part
    for(int i=0; i<lenLeft; i++){
        left[i] = arr[k];
        k++;
    }
    k = mid + 1; // To copy array of the right part
    for(int i=0; i<lenRight; i++){
        right[i] = arr[k];
        k++;
    }
    // MERGING 
    // Note that the values are allready sorted in both arrays
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = start; // Yahi galti karoge ! 
    while(leftIndex < lenLeft && rightIndex < lenRight){
        if(left[leftIndex] < right[rightIndex]){
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        else{
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }
    // Corner case 
    // 1. if left array is Exausted
    while(rightIndex < lenRight){
        arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
    }
    // 2. if right array is exausted
    while(leftIndex < lenLeft){
        arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
    }
    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int start, int end){
    //Base case
    // if(start>=end)
    if(start>end){
        //Inavlad array
        return;
    }
    if(start==end){
        //Signle element array
        return;
    }
    // 1. Break
    int mid = (start+end)/2;
    // 2. Recusrsion
    // Left recursive call
    mergeSort(arr,start,mid);
    // Right recursive call
    mergeSort(arr,mid+1,end);
    // 3. Merge sorted
    merge(arr,start,end);
}

int main(){

    int arr[] = {2,1,9,7,4,6};
    int n = 6;
    int start = 0;
    int end = n-1;
    cout << "Before Merge Sort : " << endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    mergeSort(arr,start,end);
    cout << "After Merge Sort : " << endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}