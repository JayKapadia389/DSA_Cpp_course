#include <iostream>
#include <vector>

using namespace std;

void star(int i , int j , vector<vector<char>> &grid , int n){

    grid[i][j] = '*' ;

    if((i-1 >= 0) && (grid[i-1][j] == 'O')){
        star(i-1 , j , grid , n);
    }
    if((i+1 < n)  && (grid[i+1][j] == 'O')){
        star(i+1 , j , grid , n);
    }
    if((j-1 >= 0) && (grid[i][j-1] == 'O')){
        star(i , j-1 , grid , n);
    }
    if((j+1 < n) && (grid[i][j+1] == 'O')){
        star(i , j+1 , grid , n);
    }

    return ;
}

int main(){

    int n ;
    cin >> n;

    vector<vector<char>> grid(n , vector<char>(n));

    for(int i = 0 ; i < n ; i++){

        for(int j = 0 ; j < n ; j++){
            cin >> grid[i][j] ;
        }    

    }

    for(int i = 0 ; i < n ; i++){

        for(int j = 0 ; j < n ; j++){

            if(i == 0 || i == n-1 || j == 0 || j == n-1 ){

                if(grid[i][j] == 'O'){
                    star(i , j , grid , n);
                }
            }

        }    

    }

    for(int i = 0 ; i < n ; i++){

        for(int j = 0 ; j < n ; j++){

            if(grid[i][j] == 'O'){
                grid[i][j] = 'X';
            }
            if(grid[i][j] == '*'){
                grid[i][j] = 'O';
            }
        }    

    }

    for(int i = 0 ; i < n ; i++){

        for(int j = 0 ; j < n ; j++){

            cout << grid[i][j] << " " ;
        }    
            cout << endl;

    }

}
