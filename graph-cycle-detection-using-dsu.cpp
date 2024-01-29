#include <iostream>
#include <vector>

using namespace std;

void swap(int &x , int &y){

    int temp;

    temp = x ;
    x = y ;
    y = temp ;

    return ;
}

int find_set(int i , vector<int> par){

    if(par[i] == i){
        return i ;
    }

    return find_set(par[i] , par );
}

void union_sets(int u , int v , vector<int> &par , vector<int> &sz ){

    int x = find_set(u , par);
    int y = find_set(v , par);

    if(sz[x] > sz[y]){
        swap(x , y);
    }

    par[x] = y ;
    sz[y] += sz[x];

    return ;
}

int main(){

    int n , m ;

    cin >> n >> m ;

    vector<int> par(n+1);
    vector<int> sz(n+1);

    vector<vector<int>> edges;

    int x, y ;

    bool cycle = false ;

    for(int  i = 0 ; i < m ; i++){

        cin >> x >> y ;

        edges.push_back({x,y});
        
    }

    for(int i = 1 ; i <= n ; i++){

        par[i] = i ;
        sz[i] = 1 ;
    }

    for(auto i : edges){

        x = find_set(i[0] , par);
        y = find_set(i[1] , par);

        if(x == y){
            cycle = true ;
            break ;
        }

        union_sets(x , y ,par , sz);

    }

    if(cycle){
        cout << "cycle is present";
    }
    else{
        cout << "cycle is not present";
    }
}