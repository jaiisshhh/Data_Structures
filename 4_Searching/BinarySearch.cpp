#include <iostream> 
using namespace std;

int binary_search(int arr[], int size, int target){
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;
    while(start <= end){
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            start = mid + 1;
        }
        else if(arr[mid] > target){
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    return -1;
}

int findFirstOccuerence(int arr[], int size, int target){
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;
    int ans = -1;

    while(start <= end){
        if(arr[mid] == target){
            //Store the answer
            ans = mid; 
            end = mid - 1;
        }
        else if(arr[mid] > target){
            end = mid - 1;
        }
        else if(arr[mid] < target){
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return ans;
}

int findLastOccuerence(int arr[], int size, int target){
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;
    int ans = -1;

    while(start <= end){
        if(arr[mid] == target){
            //Store the answer
            ans = mid; 
            start = mid + 1;
        }
        else if(arr[mid] > target){
            end = mid - 1;
        }
        else if(arr[mid] < target){
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return ans;
}

int totalOccuerence(int arr[], int size, int target){
    int firstOccuerence = findFirstOccuerence(arr, size, target);
    int lastOccuerence = findLastOccuerence(arr, size, target);
    int totalOccerence = lastOccuerence - firstOccuerence + 1;
    return totalOccerence;
}

int findMissingElement(int arr[], int size){
    int s = 0;
    int e = size - 1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e){
        int diff = arr[mid] - mid;
        if(diff == 1){
            s = mid + 1;
        }
        else{
            ans = mid;
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    if(ans + 1 == 0){
        ans = size+1;
    }
    return ans + 1;
}

int findPivot(int arr[], int size, int target){
    int s = 0;
    int e = size - 1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s <= e){
        if(s == e){
            ans = s;
        }
        // Have to put condition so that the index don't go out of bound
        else if(mid-1 >= 0 && arr[mid] < arr[mid - 1]){
            ans = mid - 1;
        } 
        // Have to put condition so that the index don't go out of bound
        else if(mid+1 < size && arr[mid] > arr[mid + 1]){
            ans = mid;
        } 
        else if(arr[s] > arr[mid]){
            e = mid - 1;
        } 
        else{
            s = mid + 1;
        } 
        mid = s + (e-s)/2;
    }
    if(ans == target){
        return ans;
    }
    return -1;
}

int division(int a, int b){
    int s = 0;
    int e = a;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s <= e){
        if(b*mid == a){
            return mid;
        }
        else if(b*mid < a){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int nearlySorted(int arr[], int size, int target){
    int s = 0;
    int e = size - 1;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(mid - 1 >= 0 && arr[mid - 1] == target){
            return mid - 1;
        }
        else if(arr[mid] == target){
            return mid;
        }
        else if(mid + 1 < size && arr[mid + 1] == target){
            return mid + 1;
        }
        else if(arr[mid] < target){
            s = mid + 2;
        }
        else{
            e = mid - 2;
        }
        mid = s + (e-s)/2;
    }
    return -1;
}

int oddOccuringElem(int arr[], int size){
    int s = 0;
    int e = size - 1;
    int mid = s = (e-s)/2;
    while(s<=e){
        if(s==e){
            return s;
        }
        else if(mid % 2 == 0){
            if(mid + 1 < size && arr[mid] == arr[mid + 1]){
                s = mid + 2;
            }
            else{
                //Either on the right part or on the ans
                e = mid;
            }
        }
        else{
            if(mid - 1 >= 0 && arr[mid] == arr[mid - 1]){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        mid = s + (e-s)/2;
    }
    return -1; 
}

int main() {
    
    // int arr[] = {1,2,3,4,5,6,7,8,9};
    // int size = 9;
    // int target = 8;
    // int ans = binary_search(arr,size,target);
    // if(ans == -1){
    //     cout << "Element not found" << endl;
    // }
    // else{
    //     cout << "Element found on index : " << ans << endl;
    // }

    // FIND FIRST OUCCERENCE OF A NUMBER IN A SORTED ARRAY
    // int arr[] = {10,3 0,30,30,30,30,40,50};
    // int size = 8;
    // int target = 30;
    // int ans = findFirstOccuerence(arr,size,target);
    // if(ans == -1){
    //     cout << "Element not found" << endl;
    // }
    // else{
    //     cout << "Element found on index : " << ans << endl;
    // }

    // FIND LAST OCCUERENCE IN A SORTED ARRAY
    // int arr[] = {10,20,30,30,30,30,30,40,50};
    // int size = 9;
    // int target = 30;
    // int ans = findLastOccuerence(arr,size,target);
    // if(ans == -1){
    //     cout << "Element not found" << endl;
    // }
    // else{
    //     cout << "Element found on index : " << ans << endl;
    // }

    // FIND TOTAL OCCUERENCE 
    // int arr[] = {10,20,30,30,30,30,30,40,50};
    // int size = 9;
    // int target = 30;
    // int ans = totalOccuerence(arr,size,target);
    // cout << "Total Occerence is : " << ans << endl;

    // FIND MISSING ELEMENT IN A SORTED ARRAY
    // int arr[] = {1,2,3,4,6,7,8,9};
    // int size = 8;
    // int ans = findMissingElement(arr, size);
    // cout << "Missing element is : " << ans << endl;

    //PEAK ELEMENT IN A MOUNTAIN ARRAY (V.IMP .. (s<e concept]))
    
    // FIND PIVOT ELEMENT IN A ROTATED SORTED ARRAY
    // int arr[] = {4,5,6,7,0,1,2};
    // int size = sizeof(arr)/sizeof(int);
    // int target = 0;
    // int ans = findPivot(arr,size,target);
    // cout << "Pivot element's index is : " << ans << endl;

    // DEVIDE THE NUMBER USING BINARY SEARCH
    // int a = 10;
    // int b = 3;
    // int ans = division(abs(a),abs(b));
    // if((a>0 && b<0) || (a<0 && b>0)){
    //     ans = 0 - ans;
    // }
    // cout << ans << endl;

    // BINARY SEARCH IN A NEARLY SORTED ARRAY
    // int arr[] = {20,10,30,50,40,70,60};
    // int size = sizeof(arr)/sizeof(int);
    // int target = 70;
    // int ans = nearlySorted(arr,size,target);
    // cout << ans << endl;

    // FIND ODD OCCUERING ELEMENT 
    int arr[] = {1,1,5,5,2,2,3,3,2,4,4};
    int size = sizeof(arr)/sizeof(int);
    int ans = oddOccuringElem(arr,size);
    cout << arr[ans] << endl;

    return 0;
}