#include <iostream>
#include <vector>

using namespace st;

int main(){

    int n , m ;

    cin >> n >> m ;

    // vector<int> par(n+1);
    // vector<int> sz(n+1);

    vector<vector<int>> edges;

    int x, y ;

    // bool cycle = false ;

    for(int  i = 0 ; i < m ; i++){

        cin >> x >> y ;

        edges.push_back({x,y});
        
    }

    vector<vector<int>> mst_edges;

    // for(int i = 1 ; i <= n ; i++){

    //     par[i] = i ;
    //     sz[i] = 1 ;
    // }

}