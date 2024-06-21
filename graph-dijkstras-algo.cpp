#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){

    int n , m ;

    cin >> n >> m ;

    vector<vector<pair<int , int>>> adj(n+1) ;

    int w , x , y  ;

    for(int i = 0 ; i < m ; i++){

        cin >> x >> y >> w ;

        adj[x].push_back({y , w});
        adj[y].push_back({x , w});

    }

    int inf = 1e9 ; 
    vector<int> dist(n+1 , inf);

    set<pair<int , int>> s ;

    int source ;

    cin >> source ;

    s.insert({0 , source});

    dist[source] = 0 ;

    while(!s.empty()){

        auto x = *(s.begin());
        s.erase(x);

        for(auto it : adj[x.second]){

            if(dist[it.first] > it.second + dist[x.second]){
                s.erase({dist[it.first]  , it.first});

                dist[it.first] = it.second + dist[x.second] ;

                s.insert({dist[it.first]  , it.first});
            }
        }

    }

    for(int i = 1 ; i <= n ; i++){

        if(dist[i] < inf){
            cout << dist[i] << " " ;
        }

        else{
            cout << -1 << " " ;
        }
    }

}