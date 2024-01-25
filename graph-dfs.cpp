#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){

    int n , m ;

    // cin >> n >> m ;
    n = 7 ,  m = 7 ;

    vector<vector<int>> adjm(n+1 , vector<int>(n+1 , 0)) ;
    int x , y ;

    // for(int i = 0 ; i < m ; i++){

    //     cin >> x >> y ;

    //     adjm[x][y] = 1 ;
    //     adjm[y][x] = 1 ;

    // }

    adjm = {{0,0,0,0,0,0,0,0},
            {0,0,1,1,0,0,0,0},
            {0,1,0,0,1,1,1,1},
            {0,1,0,0,0,0,0,1},
            {0,0,1,0,0,0,0,0},
            {0,0,1,0,0,0,0,0},
            {0,0,1,0,0,0,0,0},
            {0,0,1,1,0,0,0,0}} ;
    

    stack<int> s ;
    int vis[n+1] = {0};
    bool flag = 0 ;

    int a = 3 ;
    s.push(a);
    vis[a] = 1 ;
    cout << a << " ";

    while(!s.empty()){

        a = s.top() ;
        flag = 0 ;

        for(int i = 1 ; i <= n ;i++){
            if(adjm[a][i] && !vis[i]){

                s.push(i);
                vis[i] = 1;
                cout << i << " ";

                flag = 1;
                break ;
            }
        }

        if(!flag){
         s.pop();
        }
    }

}