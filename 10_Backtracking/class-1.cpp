#include<iostream>
#include<vector>
using namespace std;

// Will take extra space when we are using str by value, but we 
// can fix it by taking by reference but then we have to handle the 
// backtracking case. 
void printPermutation(string &str, int i){
    // Base Case
    if(i >= str.length()){
        cout << str << " ";
        return;
    }
    for(int j = i; j<str.length(); j++){
        swap(str[i], str[j]);
        // Recrsive call
        printPermutation(str, i+1);
        // Backtracking : Nullify the work done on recusion
        swap(str[i], str[j]);
    }
}

bool isSafe(int srcx, int srcy, int newx, int newy,int maze[][4], int row, int col, vector<vector<bool> > &visited){
    if(
        (newx >=0 && newx<row) && // In bound row
        (newy >=0 && newy<col) && // In bound col
        maze[newx][newy] == 1 && // Path should be open 
        visited[newx][newy] == false // Path should not be visited 
        ){
            return true;
        }
    else{
        return false;
    }
}

void printAllPaths(int maze[][4],int row,int col,int srcx,int srcy,string &output, vector<vector<bool> > &visited){
    // Destination coordinates maze[n-1][m-1]
    if(srcx == row-1 && srcy == col-1){
        // Reached Destination
        cout << output << endl;
        return;
    }
    // UP
    int newx = srcx - 1;
    int newy = srcy;
    if(isSafe(srcx, srcy, newx, newy, maze, row, col, visited)){
        visited[newx][newy] = true; // Mark path visited
        output.push_back('U');
        printAllPaths(maze,row,col,newx,newy,output,visited); // recursive call
        output.pop_back(); // Backtrack
        visited[newx][newy] = false; // Backtrack
    }
    // RIGHT
    newx = srcx;
    newy = srcy + 1;
    if(isSafe(srcx, srcy, newx, newy, maze, row, col, visited)){
        visited[newx][newy] = true; // Mark path visited
        output.push_back('R');
        printAllPaths(maze,row,col,newx,newy,output ,visited); // recursive call
        output.pop_back(); // Backtrack
        visited[newx][newy] = false; // Backtrack
    }
    // LEFT
    newx = srcx;
    newy = srcy - 1;
    if(isSafe(srcx, srcy, newx, newy, maze, row, col, visited)){
        visited[newx][newy] = true; // Mark path visited
        output.push_back('L');
        printAllPaths(maze,row,col,newx,newy,output ,visited); // recursive call
        output.pop_back(); // Backtrack
        visited[newx][newy] = false; // Backtrack
    }
    // DOWN
    newx = srcx + 1;
    newy = srcy;
    if(isSafe(srcx, srcy, newx, newy, maze, row, col, visited)){
        visited[newx][newy] = true; // Mark path visited
        output.push_back('D');
        printAllPaths(maze,row,col,newx,newy,output ,visited); // recursive call
        output.pop_back(); // Backtrack
        visited[newx][newy] = false; // Backtrack
    }
}


int main(){

    // PERMUTATIONS OF STRING
    // string str = "abc";
    // int i=0;
    // printPermutation(str, i);

    // RAT IN A MAZE
    int maze[4][4] = {
        {1,0,0,0},
        {1,1,0,0},
        {1,1,1,0},
        {1,1,1,1}
    };
    int row = 4;
    int col = 4;
    int srcx = 0;
    int srcy = 0;
    string output = "";
    vector<vector<bool> > visited(row, vector<bool>(col, false));
    if(maze[0][0] == 0){
        // Path is blocked, the rate cannot move
        cout << "No Paths exists" << endl;
    }
    else{
        visited[srcx][srcy] = true;
        printAllPaths(maze,row,col,srcx,srcy,output,visited);
    }
    

    return 0;
} 