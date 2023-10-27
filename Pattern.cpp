#include<iostream>
using namespace std;

int main(){

    //Square
    // int n; 
    // cin>>n; //No of rows
    // for(int i=0;i<n;i++){ //Outer Loop -> rows
    //     for(int j=0;j<n;j++){ //Inner Loop -> No. of stars to be printed 
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // //Rectangle
    // for(int i=0; i<3; i++){
    //     for(int j=0; j<5; j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // //HOLLOW SQUARE OF SIDE 5
    // for(int row=0; row<5; row++){
    //     for(int col=0; col<5; col++){
    //         if(row==0 || row==4){
    //             cout<<"* ";
    //         }
    //         else{
    //             if(col==0 || col==4){
    //                 cout<<"* ";
    //             }
    //             else{
    //                 cout<<"  ";
    //             }
    //         }
    //     }
    //     cout<<endl;
    // }

    // //HOLLOW RECTANGLE OF ANY GIVEN SIDES
    // int ROW;
    // cin>>ROW;
    // int COL;
    // cin>>COL;
    // for(int row=0; row<ROW; row++){
    //     for(int col=0; col<COL; col++){
    //     }
    // }

    // //HALF PYRAMID
    // int n;
    // cin>>n;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<i+1; j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // //INVERTED HALF PYRAMID
    // int n = 5;
    // for(int row=0; row<n; row++){
    //     for(int col=0; col<n-row; col++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // //NUMERIC HALF PYRAMID
    // int n = 5;
    // for(int row=0; row<5; row++){
    //     for(int col=0; col<row+1; col++){
    //         cout<<col+1<<" ";
    //     }
    //     cout<<endl;
    // }

    // //INVERTED NUMERIC HALF PYRAMID 
    // int n = 5;
    // for(int row=0; row<n; row++){
    //     for(int col=0; col<n-row; col++){
    //         cout<<col+1<<" ";
    //     }
    //     cout<<endl;
    // }

    //HALF PYRAMID 
    // int n9;
    // cin>>n9;
    // for(int row=0; row<n9; row++){ //Rows
    //     for(int col=0; col<n9-row-1; col++){ //Space
    //         cout<<" ";
    //     }
    //     for(int col=0; col<row+1; col++){ //Stars
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // //INVERTED HALF PYRAMID
    // int n10;
    // cin>>n10;
    // for(int row=0; row<n10; row++){ //Rows
    //     for(int col=0; col<row; col++){ //Space
    //         cout<<" ";
    //     }
    //     for(int col=0; col<n10-row; col++){ //Star
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    //DAIMOND 
    // int n11=5;
    // for(int row=0; row<n11; row++){ //Rows
    //     for(int col=0; col<n11-row-1; col++){ //Space
    //         cout<<" ";
    //     }
    //     for(int col=0; col<row+1; col++){ //Stars
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }
    // for(int row=0; row<n11; row++){ //Rows
    //     for(int col=0; col<row; col++){ //Space
    //         cout<<" ";
    //     }
    //     for(int col=0; col<n11-row; col++){ //Star
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    //HOLLOW PYRAMID
    // int n12 = 4;
    // for(int row=0; row<n12; row++){ //Rows
    //     for(int col=0; col<n12-row-1; col++){ //Space
    //         cout<<" ";
    //     }
    //     for(int col=0; col<row+1; col++){ //Stars
            // if(col==0 || col==row){
            //     cout<<"* ";
            // }
            // else{
            //     cout<<"  ";
            // }
    //     }
    //     cout<<endl;
    // }

    //INVERTED HOLLOW PYRAMID
    // int n12=6;
    // for(int row=0; row<n12; row++){ //Rows
    //     for(int col=0; col<row; col++){ //Space
    //         cout<<" ";
    //     }
    //     for(int col=0; col<n12-row; col++){ //Star
            // if(col == 0 || col == n12-row-1){
            //     cout<<"* ";
            // }
            // else{
            //     cout<<"  ";
            // }
    //     }
    //     cout<<endl;
    // }

    //HOLLOW DIMOND 
    // int n13=5;
    // for(int row=0; row<n13; row++){ //Rows
    //     for(int col=0; col<n13-row-1; col++){ //Space
    //         cout<<" ";
    //     }
    //     for(int col=0; col<row+1; col++){ //Stars
    //         if(col==0 || col==row){
    //             cout<<"* ";
    //         }
    //         else{
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }
    // for(int row=0; row<n13; row++){ //Rows
    //     for(int col=0; col<row; col++){ //Space
    //         cout<<" ";
    //     }
    //     for(int col=0; col<n13-row; col++){ //Star
    //         if(col == 0 || col == n13-row-1){
    //             cout<<"* ";
    //         }
    //         else{
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }

    //HOLLOW STAR DIMOND 
    int n14;
    for(int row=0; row<n14; row++){ //Rows
        for(int col=0; col<n14-row-1; col++){ //Space
            cout<<"*";
        }
        for(int col=0; col<row+1; col++){ //Stars
            cout<<" ";
        }
        cout<<endl;
    }

}