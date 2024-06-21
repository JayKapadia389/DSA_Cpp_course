#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int main(){

    int n ;
    cin >> n ;

    vector<int> denom(n) ;

    for(int i = 0 ; i < n ; i++){
        cin >> denom[i] ;
    }

    int amount ;
    cin >> amount ;

    bool found = 0;
    queue<int> q ;
    q.push(0);
    map<int , bool > exist ;
    int ans = 0 ; 

    while((!found) && (!q.empty())){

        int size = q.size() ;

        for(int i = 0 ; i < size && !found ; i++){

            int x = q.front();
            q.pop();

            for(int j = 0 ; j < n ; j++){

                if(x + denom[j] <= amount){

                    if(x + denom[j] == amount){
                        found = 1 ;
                        break ;
                    }
                    else{
                        if(!exist[x + denom[j]]){
                            exist[x + denom[j]] = 1 ;

                            q.push(x + denom[j]) ;
                        }
                    }
                }
                
            }
        }

        ans++ ;
    }

    if(found){
        cout << ans ;
    }
    else{
        cout << -1 ;
    }


}