#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isCycle(){

}

int main(){

    int n , m ;

    cin >> n >> m ;
    // n = 7 ,  m = 7 ;

    vector<vector<int>> adj(n+1) ;
    int x , y ;

    for(int i = 0 ; i < m ; i++){

        cin >> x >> y ;

       adj[x].push_back(y);

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
    vector<bool> stack(n+1);
    bool cycle = false ;

    for(int i = 1 ; i <= n ; i++){

        if(!vis[i] && isCycle()){
            cycle = true ;
        }
    }

    if(cycle){
        cout << "cycle is present";
    }
    else{
        cout << "cycle is not present";
    }

}
