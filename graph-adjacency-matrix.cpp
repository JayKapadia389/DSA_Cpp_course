#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n , m ;

    cin >> n >> m ;

    // vector<vector<int>> adjm(n+1 , vector<int>(n+1 , 0)) ; // ( size , initialization)

    // for(int i = 0 ; i < m ; i++  ){

    //     int x , y ;

    //     cin >> x >> y ;

    //     adjm[x][y] = 1 ;
    //     adjm[y][x] = 1 ; 

    // }

    // for(int i = 1 ; i < n ; i++){
    //     for(int j = 1 ; j < n ; j++){
    //         cout << adjm[i][j] << " " ;
    // }
    //         cout << endl ;
    // }

    vector<vector <int>> adjl(n+1) ;

    int x , y ;

    for(int i = 0 ; i < m ;i++){

        cin >> x >> y ;

        adjl[x].push_back(y);
        adjl[y].push_back(x);

    }

    for(int i= 1 ; i<=n ; i++){

        cout << i << "-> " ;
        for(int j = 0 ; j < adjl[i].size() ; j++){
            cout << adjl[i][j] << " " ;
        }
        cout << endl ;
    }
}