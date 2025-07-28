#include<iostream>
#include<queue>
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

// Returns Root Node of the tree
Node* createTree(){
    int data;
    cin >> data;
    if(data == -1){
        return NULL;
    }
    // Step 1 : Create Node
    Node* root = new Node(data);
    // Step 2 : Create Left Subtree
    root -> left = createTree();
    // Step 3 : Create Right Subtree
    root -> right = createTree();
    return root;
}

void preOrderTraversal(Node* root){ // N L R
    if(root == NULL) return;
    cout << root -> data << " ";
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
}

void inOrderTraversal(Node* root){ // L N R
    if(root == NULL) return;
    inOrderTraversal(root -> left);
    cout << root -> data << " ";
    inOrderTraversal(root -> right);
}

void postOrderTraversal(Node* root){ // L R N
    if(root == NULL) return;
    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    cout << root -> data << " ";
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        cout << front -> data << " ";
        if(front -> left) q.push(front -> left);
        if(front -> right) q.push(front -> right);
    }
}

void levelOrder(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL); // LEVEL KA PTA LAGANE KE LIYE NULL INSERT KRDO
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp -> data << " ";
            if(temp -> left != NULL){
                q.push(temp -> left);
            }
            if(temp -> right != NULL){
                q.push(temp -> right);
            }
        }
    }
}

int main(){

    Node* root = createTree();
    cout << "Pre Order Traversal : ";
    preOrderTraversal(root);
    cout << endl;

    cout << "In Order Traversal : ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Post Order Traversal : ";
    postOrderTraversal(root);
    cout << endl;

    cout << "Level Order Traversal : ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}