#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossibleSol(vector<int> cooksRank, int nP, int mid){
    int currP = 0;
    for(int i=0; i<cooksRank.size();i++){
        int R = cooksRank[i] , j = 1;
        int timeTaken = 0;
        while(true){
            if(timeTaken + j * R <= mid){
                ++currP;
                timeTaken += j * R;
                ++j;
            }
            else{
                break;
            }
        }
        if(currP >= nP){
            return true;
        }
    }
    return false;
}

int minTimeTakenToCompleteOrder(vector<int> cooksRank, int nP){
    int start = 0;
    int highestRank = *max_element(cooksRank.begin(),cooksRank.end());
    int end = highestRank * ( nP *( nP + 1 )/2);
    int ans = -1;
    
    while(start <= end){
        int mid = start + (end - start)/2;
        if(isPossibleSol(cooksRank,nP,mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    
    int T ; cin >> T; // T = number of test cases
    while(T--){
        int nP, nC;  // nP = number of Prata ; nC = number of cooks
        cin >> nP >> nC;
        vector<int> cooksRank;
        while(nC--){
            int R; cin >> R; // Rank of cook
            cooksRank.push_back(R);
        }
        cout << minTimeTakenToCompleteOrder(cooksRank,nP) << endl;
    }

    return 0;
}