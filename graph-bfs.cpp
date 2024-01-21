#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    int m  ,n ;

    cin >> n >> m ;

    vector<vector<int>> adjm(n+1 , vector<int>(n+1 , 0));

    int x , y;

    for(int i = 0 ; i < m ;i++){
        cin >> x >> y ;

        adjm[x][y] = 1;
        adjm[y][x] = 1;
    }

    queue<int> q ;
    int vis[n] = {0} , i ;

    int a = 3 ;

    q.push(a) ;
    cout << a << " ";
    vis[a] = 1 ;

    while(!q.empty()){

        i = q.front() ;
        q.pop() ;

        for(int j = 1 ; j <= n ; j++){
            if(adjm[i][j] && !vis[j]){
                q.push(j);
                cout << j << " " ;
                vis[j] = 1 ;
            }
        }


    }

}