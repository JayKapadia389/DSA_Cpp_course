#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    int n , m ;

    cin >> n >> m ;
    // n = 7 ,  m = 7 ;

    vector<vector<int>> adjm(n+1 , vector<int>(n+1 , 0)) ;
    int x , y ;

    for(int i = 0 ; i < m ; i++){

        cin >> x >> y ;

        adjm[x][y] = 1 ;
        adjm[y][x] = 1 ;

    }

    // adjm = {{0,0,0,0,0,0,0,0},
    //         {0,0,1,1,0,0,0,0},
    //         {0,1,0,0,1,1,1,0},
    //         {0,1,0,0,0,0,0,1},
    //         {0,0,1,0,0,0,0,0},
    //         {0,0,1,0,0,0,0,0},
    //         {0,0,1,0,0,0,0,0},
    //         {0,0,0,1,0,0,0,0}} ;
    
    vector<int> vis(n+1);
    vector<int> par(n+1);

    queue<int> q ;

    bool cycle = false;

    q.push(3);
    vis[3] = 1;

    int curr ;

    while(!q.empty() && !cycle){

        curr = q.front();
        q.pop() ;

        for(int i = 1 ; i<= n ;i++){

            if(adjm[curr][i] == 1){
                
                if(vis[i] == 1){
                    if(i != par[curr]){
                        cycle = true ;
                        break ;
                    }
                }
                else{
                    vis[i] = 1 ;
                    par[i] = curr ;
                    q.push(i);
                }

            }
        }
    }

    if(cycle){
        cout << "cycle is present";
    }
    else{
        cout << "cycle is not present";

    }

}