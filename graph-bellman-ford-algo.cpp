#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n , m ;

    cin >> n >> m ;

    vector<vector<int>> edges(m);
    int x , y , w ;

    for(int i = 0 ; i < m ; i++){

        cin >> x >> y >> w ;

        edges[i].push_back(x);
        edges[i].push_back(y);
        edges[i].push_back(w);

    }

    int inf = 1e9 , source;

    cin >> source ;
    vector<int> d(n+1 , inf) ;
    
    d[source] = 0 ;

    bool flag = 1 ;

    while(flag){

        flag = 0 ;

        for(auto i : edges){ // x y w

            if(d[i[0]] + i[2] < d[i[1]]){
                flag = 1 ;
                d[i[1]] = d[i[0]] + i[2] ;
            }
        }
    }

    for(int i = 1 ; i < d.size() ; i++){
        cout << i << " " ;
    }

}