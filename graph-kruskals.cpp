#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int &x , int &y){

    int temp ;
    temp = x ;
    x = y;
    y = temp ;

    return ;
}

bool comparator(vector<int> a , vector<int> b ){

    if(a[0] <= b[0]){
        return true ;
    }
    else{
        return false ;
    }

}

int find_set(int x , vector<int> par){

    if(par[x] == x){
        return x;
    }
    
    return find_set(par[x] , par);
}

void union_sets(int u , int v , vector<int> &par , vector<int> &sz){

    int x = find_set(u , par);
    int y = find_set(v , par);

    if(sz[x] > sz[y]){
        swap(x , y);
    }

    par[x] = y ;
    sz[y] += sz[x] ;

    return ;
}

bool isCycle(vector<vector<int>> edges , int n){

    vector<int> par(n+1);
    vector<int> sz(n+1);
    int x ,y ;

    for(int i = 1 ; i <= n ; i++){

        par[i] = i ;
        sz[i] = 1 ;
    }

    for(auto i : edges){

        x = find_set(i[1] , par );
        y = find_set(i[2] , par);

        if(x == y){
            return true ;
        }

        union_sets(x , y , par , sz);

    }

    
    return false ;
}

int main(){

    int n , m ;

    // cin >> n >> m ;
    n = 8 , m = 8;

    vector<vector<int>> edges;

    // int w ,x, y ;

    // for(int  i = 0 ; i < m ; i++){

    //     cin >> w >> x >> y ;

    //     edges.push_back({w,x,y});
        
    // }

    edges = {{10,1,2},
            {11,2,4},
            {12,2,3},
            {3,1,6},
            {8,6,5},
            {5,6,7},
            {9,5,8},
            {7,7,8}};

    vector<vector<int>> mst_edges;

    sort(edges.begin() , edges.end() , comparator) ;

    for(int i = 0  ; i < m ; i++){

        mst_edges.push_back(edges[i]);

        if(isCycle(mst_edges , n)){
            mst_edges.pop_back();
        }
    }

    int wt = 0;

    for(auto i : mst_edges){
        wt+= i[0];
        cout << i[0] << " " << i[1] << " " << i[2] << endl ;
    }

    cout << wt ;

}