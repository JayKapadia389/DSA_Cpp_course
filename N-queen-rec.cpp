#include <iostream>

using namespace std;

int nqueen(int n ,int i, int board , int ans ){

    

}

int main(){

    int n  ;

    cout << "enter n: ";
    cin >> n;

    int board[n][n];

    for(int i=0 ; i<n ;i++){
        for(int j =0 ;j<n ; j++){
            board[i][j] = 0 ;
        }
    }

    nqueen(n , 1 , board , 0);
}