#include<iostream>
#include<queue>
#include<map>
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

void leftView(Node* root, int level, vector<int>& ans){
    if(root == NULL) return;
    if(level == ans.size()){ // Left view vali node mil gayi hai 
        ans.push_back(root -> data);
    }
    leftView(root -> left, level + 1, ans);
    leftView(root -> right, level + 1, ans);
}

void rightView(Node* root, int level, vector<int>& ans){
    if(root == NULL) return;
    if(level == ans.size()){ // Left view vali node mil gayi hai 
        ans.push_back(root -> data);
    }
    rightView(root -> right, level + 1, ans);
    rightView(root -> left, level + 1, ans);
}

void topView(Node* root){
    map<int, int> hdToNodeMap; // hd : horizontal Distance
    queue<pair<Node*, int> > q;
    q.push(make_pair(root, 0));
    while(!q.empty()){ // level order traversal
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;
        // Agar is Horizontal Disance ke liye koi bhi data nahi aaya hai means ye phli baar aaya hai isko store krlo
        if(hdToNodeMap.find(hd) == hdToNodeMap.end()){
            hdToNodeMap[hd] = frontNode -> data;
        }
        if(frontNode -> left != NULL) q.push(make_pair(frontNode -> left, hd - 1));
        if(frontNode -> right != NULL) q.push(make_pair(frontNode -> right, hd + 1));
    }
    for(auto i : hdToNodeMap){
        cout << i.second << " ";
    }
}

void bottomView(Node* root){
    map<int, int> hdToNodeMap; // hd : horizontal Distance
    queue<pair<Node*, int> > q;
    q.push(make_pair(root, 0));
    while(!q.empty()){ // level order traversal
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;
        
        // Here we are just updating the data not checking if its exists allready 
        hdToNodeMap[hd] = frontNode -> data;
        
        if(frontNode -> left != NULL) q.push(make_pair(frontNode -> left, hd - 1));
        if(frontNode -> right != NULL) q.push(make_pair(frontNode -> right, hd + 1));
    }
    for(auto i : hdToNodeMap){
        cout << i.second << " ";
    }
}

int main(){
    Node* root = createTree();

    vector<int> left_ans;
    cout << "Printing Left View : ";
    leftView(root, 0, left_ans);
    for(int i=0; i<left_ans.size(); i++){
        cout << left_ans[i] << " ";
    }

    cout << endl;

    vector<int> right_ans;
    cout << "Printing Right View : ";
    rightView(root, 0, right_ans);
    for(int i=0; i<right_ans.size(); i++){
        cout << right_ans[i] << " ";
    }

    cout << endl;

    cout << "Printing Top View : ";
    topView(root);

    cout << endl;

    cout << "Printing Bottom View : ";
    bottomView(root);
}