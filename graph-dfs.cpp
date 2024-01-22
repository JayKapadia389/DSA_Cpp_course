#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){

    int n , m ;

    cin >> n >> m ;

    vector<vector<int>> adjm(n+1 , <vector<int>(n+1 , 0)) ;
    int x , y ;

    for(int i = 0 ; i < m ; i++){

        cin >> x >> y ;

        adjm[x][y] = 1 ;
        adjm[y][x] = 1 ;

    }

    stack<int> s ;
    int vis[n+1] = {0};

    int a = 3 ;
    s.push(3);
    vis[s] = 1 ;
    cout << a << " ";

    while(!s.empty()){

        a = s.top() ;

        for(int i = 1 ; i <= n ;i++){
            if(adjm[a][i] && !vis[i]){

                s.push(i);
                vis[i] = 1;
                cout << i << " ";

            }
        }

        s.pop();
    }
}