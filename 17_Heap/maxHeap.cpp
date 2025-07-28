#include <iostream>
using namespace std;

class Heap{
public : 
    int *arr; // Dynamic Array
    int capacity;
    int size;

    Heap(int cap){
        this -> arr = new int[cap];
        this -> capacity = cap;
        this -> size = 0; // Current number of elements in heap
    }

    void insert(int val){
        if(size == capacity){
            cout << "Heap Overflow !" << endl;
            return;
        }
        // If element is added size will increase
        size++;
        int index = size;
        arr[index] = val;
        // Heapification
        while(index > 1){
            int parentIndex = index / 2;
            if(arr[index] > arr[parentIndex]){
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else{
                break;
            }
        }
    }

    int deleteFromHeap(){
        // Replacement
        int answer = arr[1];
        arr[1] = arr[size];
        // Delete last element while changeing the size
        size--;
        // Heapify
        int index = 1;
        while(index < size){
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;
            // Find out larger element
            int largestIndex = index;
            if(leftIndex <= size && arr[largestIndex] < arr[leftIndex]){
                largestIndex = leftIndex; 
            }
            if(rightIndex <= size && arr[largestIndex] < arr[rightIndex]){
                largestIndex = rightIndex; 
            }
            // No change
            if(index == largestIndex){
                break;
            }
            else{
                swap(arr[index], arr[largestIndex]);
                index = largestIndex;
            }
        }
        return answer;
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
    int largestIndex = index;
    // Find max of all three
    if(leftIndex <= n && arr[leftIndex] > arr[largestIndex]){
        largestIndex = leftIndex;
    }
    if(rightIndex <= n && arr[rightIndex] > arr[largestIndex]){
        largestIndex = rightIndex;
    }
    if(index != largestIndex){
        swap(arr[index], arr[largestIndex]);
        index = largestIndex;
        heapify(arr, n, index);
    }
}

void buildHeap(int arr[], int n){
    for(int index = n/2; index > 0; index--){
        heapify(arr, n, index);
    }
}

void heapSort(int arr[], int n)
{
    while(n != 1){
        swap(arr[1], arr[n]);
        n--; 
        heapify(arr, n, 1);
    }
}
int main(){
    Heap h(20); // Heap h of size 20
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(6);
    h.insert(11);

    h.printHeap();

    int ans = h.deleteFromHeap();
    cout << "Deleted from heap : " << ans << endl;

    cout << "Printing Heap After Deletion : " << endl;
    h.printHeap(); 

    int arr[] = {-1,5,10,15,20,25,12};
    buildHeap(arr, 6);
    int n = 6;
    cout << "Printing Heap : ";
    for(int i=1; i<=n; i++) cout << arr[i] << " ";
    cout << endl;

    heapSort(arr, n);
    cout << "PRINTING HEAP AFTER SORT !" << endl;
    cout << "Printing Heap : ";
    for(int i=1; i<=n; i++) cout << arr[i] << " ";
    cout << endl;
}
