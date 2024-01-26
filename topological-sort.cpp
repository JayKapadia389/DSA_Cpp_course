#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    int n , m ;

    cin >> n >> m ;

    vector<int> indeg(n+1);
    vector<vector<int>> adjl(n+1) ;

    int x , y;

    for(int i = 0 ; i < m ; i++){
        cin >> x >> y ;

        adjl[x].push_back(y);
        indeg[y]++ ;
    }

    queue<int> q ;
    // map<int , int > :: iterator mit ;
    vector<int> :: iterator vit ;

    for(int i = 1 ; i <= n; i++){
        // cout << "1" ;
        if(indeg[i] == 0){
            // cout << "2" ;
            q.push(i);
            cout << "push" << i << endl; 
        }
    }

    int curr ;

    if(q.empty()){
        cout << "graph is cyclic" ;
    }

    while(!q.empty()){

        curr = q.front();
        cout << curr << " " ;
        q.pop();

        for(vit = adjl[curr].begin() ; vit != adjl[curr].end() ; vit++){
            
            indeg[*vit]--;

            if(indeg[*vit] == 0){
                q.push(*vit);
            }
        }

    }
}