#include <iostream>
using namespace std;

class Heap{
public : 
    int * arr;
    int capacity;
    int size;

    Heap(int cap){
        this -> arr = new int[cap];
        this -> capacity = cap;
        this -> size = 0;
    }

    void insert(int val){
        if(size == capacity){
            cout << "Heap Overflow" << endl;
            return;
        }
        size++;
        int index = size;
        arr[size] = val;
        while(index > 1){
            int parentIndex = index / 2;
            if(arr[index] < arr[parentIndex]){
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else{
                break;
            }
        }
    }

    void printHeap(){
        cout << "Priting Heap : ";
        for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int *arr, int n, int index){
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;
    int smallestIndex = index;
    if(leftIndex <= n && arr[leftIndex] < arr[smallestIndex]){
        smallestIndex = leftIndex;
    }
    if(rightIndex <= n && arr[rightIndex] < arr[smallestIndex]){
        smallestIndex = rightIndex;
    }
    if(index != smallestIndex){
        swap(arr[index], arr[smallestIndex]);
        index = smallestIndex;
        heapify(arr, n, index);
    }
}

void heapSort(int arr[], int n){
    while(n != 1){
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }
}

void buildHeap(int arr[], int n){
    for(int index = n/2; index > 0; index--){
        heapify(arr, n, index);
    }
}

int main(){
    Heap h(20);
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(6);
    h.insert(11);

    h.printHeap();

    
    int arr[] = {-1,5,10,15,20,25,12};
    int n = 6;
    buildHeap(arr, n);
    cout << "Printing Heap : ";
    for(int i=1; i<=n; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "After Sorting : ";
    heapSort(arr, n);
    for(int i=1; i<=n; i++) cout << arr[i] << " ";
    cout << endl;
}