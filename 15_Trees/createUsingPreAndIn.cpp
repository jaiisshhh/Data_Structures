#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left = this->right = NULL;
    }
};

void levelOrderTraversal(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root) ;
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        cout << front -> data << " ";
        if(front -> left != NULL){
            q.push(front -> left);
        }
        if(front -> right != NULL){
            q.push(front -> right);
        }
    }
}

int searchInorder(int inOrder[], int size, int target){
    for(int i=0; i<size; i++){
        if(inOrder[i] == target) return i;
    }
    return -1;
}

Node* constructTreeFromPreAndInOrderTraversal(int preOrder[], int inOrder[], int &preIndex, int inOrderStart, int inOrderEnd, int size){
    // Base case : Out Of Bound Conditions 
    if(preIndex >= size || inOrderStart > inOrderEnd) return NULL;
    int ele = preOrder[preIndex];
    preIndex++;
    Node* root = new Node(ele);
    // Element in InOrder
    int pos = searchInorder(inOrder, size, ele);
    root -> left = constructTreeFromPreAndInOrderTraversal(preOrder, inOrder, preIndex, inOrderStart, pos - 1, size);
    root -> right = constructTreeFromPreAndInOrderTraversal(preOrder, inOrder, preIndex, pos + 1, inOrderEnd, size);
    return root;
}

int main(){
    int inOrder[] = {10,8,6,2,4,12};
    int preOrder[] = {2,8,10,6,4,12};
    int size = 6;
    int preIndex = 0;
    int inOrderStart = 0;
    int inOrderEnd = 5; // size - 1
    
    Node* root = constructTreeFromPreAndInOrderTraversal(preOrder, inOrder, preIndex, inOrderStart, inOrderEnd, size);
    cout << "Printing tree : " << " ";
    levelOrderTraversal(root);

    return 0;
}