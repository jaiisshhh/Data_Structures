#include<iostream>
using namespace std;

class Node{
    public : 
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* createTree(){
    int val;
    cin >> val;
    if(val == -1) return NULL;
    Node* root = new Node(val);
    root -> left = createTree();
    root -> right = createTree();
    return root;
}

void printLeftBoundary(Node* root){
    if(root == NULL) return;
    if(root -> left == NULL && root -> right == NULL) return;
    cout << root -> data << " ";
    if(root -> left != NULL) printLeftBoundary(root -> left);
    else printLeftBoundary(root -> right);
}

void printLeafBoundary(Node* root){
    if(root == NULL) return;
    if(root -> left == NULL && root -> right == NULL){
        cout << root -> data << " ";
    }
    printLeafBoundary(root -> left);
    printLeafBoundary(root -> right);
}

void printRightBoundary(Node* root){
    if(root == NULL) return;
    if(root -> left == NULL && root -> right == NULL) return;
    if(root -> right != NULL) printRightBoundary(root -> right);
    else printLeftBoundary(root -> left);
    cout << root -> data << " ";
}

void printBoundary(Node* root){
    if(root == NULL) return;
    cout << root -> data << " ";

    printLeftBoundary(root -> left);

    printLeafBoundary(root -> left); // In case of single node (edge case)
    printLeafBoundary(root -> right);

    printRightBoundary(root -> right);
}

int main(){
    Node* root = createTree();
    cout << "Printing Boundary Traversal : ";
    printBoundary(root);
    cout << endl;
}