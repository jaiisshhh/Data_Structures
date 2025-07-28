#include <iostream>
#include <queue>
#include <map>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

void levelOrderTraversal(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        cout << front->data << " ";
        if(front->left != NULL){
            q.push(front->left);
        }
        if(front->right != NULL){
            q.push(front->right);
        }
    }
    cout << endl;
}

void createMapping(int inOrder[], int size, map<int, int> &valueToIndexMap) {
    for(int i = 0; i < size; i++) {
        valueToIndexMap[inOrder[i]] = i; // Map each value to its index in the inOrder array
    }
}

Node* constructTreeFromPostAndInOrderTraversal(map<int,int> &valueToIndexMap, int postOrder[], int inOrder[], int &postIndex, int inOrderStart, int inOrderEnd, int size){
    if(postIndex < 0 || inOrderStart > inOrderEnd) return NULL;
    int ele = postOrder[postIndex];
    postIndex--;
    Node* root = new Node(ele);
    int pos = valueToIndexMap[ele];
    root->right = constructTreeFromPostAndInOrderTraversal(valueToIndexMap, postOrder, inOrder, postIndex, pos + 1, inOrderEnd, size);
    root->left = constructTreeFromPostAndInOrderTraversal(valueToIndexMap, postOrder, inOrder, postIndex, inOrderStart, pos - 1, size);
    return root;
}

int main(){
    int inOrder[] = {8, 14, 6, 2, 10, 4};
    int postOrder[] = {8, 6, 14, 4, 10, 2};
    int size = 6;
    int postIndex = size - 1;
    int inOrderStart = 0;
    int inOrderEnd = size - 1;
    map<int, int> valueToIndexMap;

    // Create the mapping for inOrder values to their indices
    createMapping(inOrder, size, valueToIndexMap);
    
    // Construct the tree
    Node* root = constructTreeFromPostAndInOrderTraversal(valueToIndexMap, postOrder, inOrder, postIndex, inOrderStart, inOrderEnd, size);
    
    // Print the tree using level-order traversal
    cout << "Printing tree: ";
    levelOrderTraversal(root);

    return 0;
}