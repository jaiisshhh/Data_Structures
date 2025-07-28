#include<iostream>
#include<climits>
#include<vector>
using namespace std;

void printArray(int arr[], int size, int index){
    if(index >= size){
        return;
    }
    cout << arr[index] << " ";
    printArray(arr, size, index + 1);
}

void reversePrintArray(int *arr, int size, int index){
    if(index >= size){
        return;
    }
    reversePrintArray(arr,size,index+1);
    cout << arr[index] << " ";
}

bool search(int arr[], int size, int index, int target){
    if(index >= size){
        return false;
    }
    if(arr[index] == target){
        return true;
    }
    bool ans = search(arr,size,index+1,target);
    return ans;
}

void minNumber(int arr[], int size, int index, int &mini){
    if(index >= size){
        return;
    }
    mini = min(arr[index],mini);
    minNumber(arr,size,index+1,mini);
}

void ifEven(int arr[], int size, int index, vector<int> &v){
    if(index >= size){
        return;
    }
    if(arr[index] % 2 == 0){
        v.push_back(arr[index]);
    }
    ifEven(arr,size,index+1,v);
}

void maxNumber(int arr[], int size, int index, int &maxx){
    if(index >= size){
        return;
    }
    maxx = max(arr[index],maxx);
    maxNumber(arr,size,index+1,maxx);
}

void doubleArray(int arr[], int size, int index){
    if(index >= size){
        return;
    }
    arr[index] = arr[index]*2;
    doubleArray(arr,size,index+1);
}

int find(int arr[], int size, int index, int target){
    if(index >= size){
        return -1;
    }
    if(arr[index] == target){
        return index;
    }
    return find(arr,size,index+1,target);
}

void printOccurence(int arr[], int size, int index, int target, vector<int> &ans){
    if(index >= size){
        return;
    }
    if(arr[index] == target){
        ans.push_back(index);
    }
    printOccurence(arr,size,index+1,target,ans);
}

void returnDig(int num, vector<int>& ans){
    if(num==0){
        return;
    }
    int digit = num % 10;
    returnDig(num/10,ans);
    ans.push_back(digit);
}

int main(){
    // PRINTING ARRAY
    // int arr[] = {1,2,3,4,5};
    // int n = 5;
    // int index = 0;
    // printArray(arr,n,index);
    // cout << endl;
    // reversePrintArray(arr,n,index);

    // LINEAR SEARCH
    // int arr[] = {1,2,3,4,5};
    // int size = 5;
    // int target = 4;
    // int index = 0;
    // cout << search(arr,size,index,target) << endl;

    // MIN NUMBER IN ARRAY
    // int arr[] = {4,5,3,7,11};
    // int size = 5;
    // int index = 0;
    // int mini = INT_MAX;
    // minNumber(arr,size,index,mini); //Interesting that we have to pass it by reference to change the acutal min value
    // cout << mini << endl;

    // IF EVEN
    // int arr[] = {11,2,44,38,27};
    // int size = 5;
    // int index = 0;
    // vector<int> v;
    // ifEven(arr,size,index,v);
    // for(int i: v){
    //     cout << i << " ";
    // }
    // cout << endl;

    // MAX NUMBER IN ARRAY
    // int arr[] = {1,2,3,4,5};
    // int size = 5;
    // int index = 0;
    // int max = INT_MIN;
    // maxNumber(arr,size,index,max);
    // cout << max << endl;

    // DOUBLE NUMBER IN ARRAY
    // int arr[] = {1,2,3,4,5};
    // int size = 5;
    // int index = 0;
    // doubleArray(arr,size,index);
    // for(int i=0; i<size; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // RETURN INDEX FOR FIND IN ARRAY
    // int arr[] = {1,3,3,4,5};
    // int size = 5;
    // int index = 0;
    // int target = 3;
    // cout << find(arr,size,index,target) << endl;

    // PRINTING ALL OCCURENCES OF TARGET
    // int arr[] = {1,3,3,4,5};
    // int size = 5;
    // int index = 0;
    // int target = 3;
    // vector<int> ans;
    // printOccurence(arr,size,index,target,ans);
    // for(auto i: ans){
    //     cout << i << " ";
    // }
    // cout << endl;

    // RETURN DIGITS INSIDE VECTOR
    int num = 4205;
    vector<int> dig;
    returnDig(num, dig);
    reverse(dig.begin(),dig.end());
    for(int i: dig){
        cout << i << " ";
    }
    cout << endl;
}