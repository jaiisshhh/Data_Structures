#include <iostream>
#include <queue>

using namespace std;

int main(){
    // Min Heap Creation 
    priority_queue<int, vector<int>, greater<int> > pq;

    // Insertion 
    pq.push(100);
    pq.push(90);
    pq.push(70);

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