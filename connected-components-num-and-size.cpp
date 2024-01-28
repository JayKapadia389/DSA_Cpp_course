#include <iostream>
#include <vector>

using namespace std;

int getSize(int src ,vector<vector<int>> &adjm , vector<bool> &vis){

    vis[src] = 1 ;

    int sum = 1 ;

    for(int i = 1  ; i < adjm[src].size() ;i++){

        if(adjm[src][i] && !vis[i]){
            sum+= getSize(i , adjm , vis);
        }
    } 

    return sum ;
}

int main(){

    int n , m ;

    cin >> n >> m ;

    vector<vector<int>> adjm(n+1 , vector<int>(n+1 , 0));
    int x , y ;

    for(int i = 0  ;i < m ; i++){
        cin >> x >> y ;
        adjm[x][y] = 1 ;
        adjm[y][x] = 1 ;

    }

    vector<int> comp ; 
    vector<bool> vis(n+1) ;

    for(int i = 1 ; i <= n ; i++){

        if(!vis[i]){
            comp.push_back(getSize(i , adjm , vis));
        }

    }

    cout << "num of comps:" << comp.size() << endl;

    for(int i = 0; i < comp.size() ; i++){

        cout << comp[i] << " " ;

    }
}