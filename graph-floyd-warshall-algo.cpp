#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<vector<int>> graph = {
                                    {},
                                    {},
                                    {},
                                    {}

                                }

    for(int k = 0 ; k < n ; k++){
        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(graph[i][k] + graph[k][j] < graph[i][j]){
                    graph[i][j] = graph[i][k] + graph[k][j] ;
                }
            }
        }
    }

    for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << graph[i][j] << " " ;
        }
        cout << endl ;
    }
}