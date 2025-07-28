#include <iostream>
#include <queue>

using namespace std;

int main(){
    // Creating Max Heap
    priority_queue<int> pq;

    // Insertion
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);

    // Accessing heap only possible from root element 
    cout << "Top element of Heap : " << pq.top() << endl;

    // Deleting is done for the root elemet only so, 
    pq.pop();
    cout << "Top element of Heap After Deletion : " << pq.top() << endl;

    // Checking Size
    cout << "Size of Max Heap : " << pq.size() << endl;

    // Checking Empty
    cout << "Is Heap Empty : " << pq.empty() << endl;
}