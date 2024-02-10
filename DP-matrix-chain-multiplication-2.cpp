#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n ;
    cin >> n ;

    vector<int> dim(n+1);
    for(int i = 0 ; i <= n  ; i++ ){
        cin >> dim[i] ;
    }

    int inf = 1e9; 

    vector<vector<int>> M( n+1 , vector<int>(n+1 , 0) );
    vector<vector<int>> S( n+1 , vector<int>(n+1 ,  0));

    for(int d = 1  ; d < n ; d++){

        for(int i = 1 ; i+d <= n ; i++){

            for(int j = i ; j < i+d ; j++){

                if(M[i][i+d] == 0){
                    M[i][i+d] = inf ;
                }

                if(M[i][i+d] > (M[i][j] + M[j+1][i+d] + (dim[i-1] * dim[j] * dim[i+d])) ){

                    M[i][i+d] = M[i][j] + M[j+1][i+d] + dim[i-1] * dim[j] * dim[i+d] ;

                    S[i][i+d] = j ;
                }

            }

        }
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){

            cout << M[i][j] <<  " ";
        
        }
        cout << endl ;
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){

            cout << S[i][j] <<  " ";
        
        }
        cout << endl ;
    }


}