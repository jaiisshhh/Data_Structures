#include<iostream>
using namespace std;

int main(){
    //SORT A GIVEN ARRAY SUCH THAT ALL THE NEGATIVE NUMBERS ARE ON THE LEFT AND POSITIVE NUMBERS ON THE RIGHT
    int size = 7;
    int arr[] = {23,-7,12,-10,-11,40,60};
    int j = 0;
    for(int i=0; i<size; i++){
        if(arr[i]<0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}