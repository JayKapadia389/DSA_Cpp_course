#include <iostream>
#include <vector>

using namespace std;

bool isBipartite(int src , vector<vector<int>> adjl , bool c){

    static vector<bool> vis(adjl.size());
    static vector<bool> color(adjl.size());

    bool ans = 0 ;

    vis[src] = 1 ;
    color[src] = c ;

    for(auto i : adjl[src]){
        if(!vis[i]){
            if(isBipartite(i , adjl , !c)){

                return true ;
            }
        }
        else{

        }
    }

    return false ;


}

int main(){

    int n , m ;

    vector<vector<int>> adjl(n+1) ;
    int x , y ;

    for(int i = 0 ; i< m ;i++){

        cin >> x >> y ;

        adjl[x].push_back(y);
        adjl[y].push_back(x);

    }

    if(isBipartite(1 , adjl , 0 )){
        cout << "graph is bipartite";
    }
    else{
        cout << "graph is not bipartite";
    }

}