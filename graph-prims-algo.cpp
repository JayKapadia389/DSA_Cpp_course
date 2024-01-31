#include <iostream>
#include <vector>
#include <set> // minheap

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

primsMST(set<vector<int>> edges , int n , vector<vector<int>> adj){

    vector<vector<int>> mst_edges ;
    set<vector<int>> heap ;
    int wt = 0 ;

    vector<int> x = *(edges.begin()) ;
    cout << "x " << x[0] << " " << x[1] << " " << x[2] ;
    wt += x[0] ; 

    heap.insert(x);

    edges.erase(x);

    vector<int> list;

    list.push_back(0);
    list.push_back(x[1]);
    list.push_back(x[2]);

    for(auto i : edges){

        if((i[1] == x[1] || i[2] == x[1]) || (i[1] == x[2] || i[2] == x[2]) ){

                x = i ;

                edges.erase(x);

                heap.insert(x);
                
    }}

    int nw , par;

    while(list.size() != n+1){

        x = *(heap.begin());
        heap.erase(x);
        
        mst_edges.push_back(x);

        if(isCycle(mst_edges , n )){
            mst_edges.pop_back();
        }
        else{

            cout << x[0] << " " << x[1] << " " << x[2] << endl ; 
            wt += x[0] ; 
            for(int i = 1 ; i < list.size() ; i++){
                if(list[i] == x[1]){
                    nw = x[2];
                    par = x[1];

                }
                if(list[i] == x[2]){
                    nw = x[1];
                    par = x[2];
                }
            }


        }
    }


    for(auto i : edges){

        if((i[1] == nw && i[2] == par) || (i[1] == nw && i[2] == par) ){

            if(i[1] != par && i[2] != par){

                x = i ;

                edges.erase(x);

                heap.insert(x);
                
            }
        }
    }

}

int main(){

    int n , m ;

    cin >> n >> m ;

    vector<vector<int>> adj(n+1) ;
    set<vector<int>> edges; // {w , u , v}

    int x , y , w;

    for(int i = 0 ; i < m ; i++){

        cin >> w >> x >> y;

        edges.insert({w , x , y});

        adj[x].push_back(y);
        adj[y].push_back(x);

    }

    primsMST(edges , n , adj );

    
    
}