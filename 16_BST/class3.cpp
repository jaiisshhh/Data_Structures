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

Node* insertIntoBST(Node* root, int data){
    if(!root){
        Node* root = new Node(data);
        return root;
    }
    if(data > root -> data) root -> right = insertIntoBST(root -> right, data);
    else root -> left = insertIntoBST(root -> left, data);
    return root;
}

void createBST(Node* &root){
    int data;
    cin >> data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node* root ) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			cout << temp->data << " ";
			if(temp->left != NULL) {
				q.push(temp->left);
			}
			if(temp->right != NULL) {
				q.push(temp->right);
			}
		}
	}
}

Node* bstFromInorder(int inorder[], int s, int e){
    if(s > e) return NULL;
    int mid = (s+e)/2;
    int ele = inorder[mid];
    Node* root = new Node(ele);
    root -> left = bstFromInorder(inorder, s, mid - 1);
    root -> right = bstFromInorder(inorder, mid + 1, e);
    return root;
}

void convertBSTintoDLL(Node* root, Node* &head){
    if(!root) return;
    // Right
    convertBSTintoDLL(root -> right, head);
    // Node
    root -> right = head;
    if(head) head -> left = root;
    head = root;
    // Left
    convertBSTintoDLL(root -> left, head);
}

Node* convertDLLintoBST(Node* &head, int n){
    if(!head || n <=0) return NULL;
    // L
    Node* leftSubtree = convertDLLintoBST(head, n/2);
    // N
    Node* root = head;
    root -> left = leftSubtree;
    head = head -> right;
    // R
    Node* rightSubtree = convertDLLintoBST(head, n-n/2-1); 
    root -> right = rightSubtree;
    return root;
}

void printList(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp -> data << " <-> ";
        temp = temp -> right;
    }
    cout << endl; 
}

int main(){

    int inorder[] = {10,20,30,40,50,60,70};
    int size = 7;
    int start = 0;
    int end = size - 1;
    Node* root = bstFromInorder(inorder, start, end);
    levelOrderTraversal(root);

    // CONVERT BST INTO SORTED DOUBLY LINKED LIST
    Node* head = NULL;
    convertBSTintoDLL(root, head);
    printList(head);
}