#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main(){

    int snakes , ladders , u , v;

    cin >> ladders ;
    map<int, int> lad ;
    for(int i = 0 ; i < ladders ; i++){
        cin >> u >> v ;
        lad[u] = v ;
    }

    cin >> snakes ;
    map<int, int> sna ;
    for(int i = 0 ; i < snakes ; i++){
        cin >> u >> v ;
        sna[u] = v ;
    }

    queue<int> q ;
    q.push(1);
    bool found = 0;  
    int steps = 0 ;

    while(!found){

        int size = q.size() ;
        
        for(int i = 0 ; (i< size && !found) ; i++){
            int x = q.front();
            q.pop();

            for(int j = 1 ; j <= 6 ; j++){

                if(x+j == 100){
                    found = 1 ;
                    break ;
                }
                else{

                    if(sna[x+j] == 0){
                        if(lad[x+j] != 0){

                            int l = x+j ;

                            while(lad[l] != 0){
                                l = lad[l] ;
                            }

                            if(l == 100){
                                found = 1 ;
                                break ;
                            }
                            else{
                                q.push(l);
                            }
                        }
                        else{
                            q.push(x+j);
                        }
                    }

                }

                
            }

        }
            steps++ ;
    }

    cout << steps ;

}