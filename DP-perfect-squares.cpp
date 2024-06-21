#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main(){

    int n ;
    cin >> n ;

    map<int , bool > exist ;
    queue<int> q ;
    q.push(0) ;
    bool found = 0 ;
    int ans = 0 ;

    while(!found){

        int size = q.size() ;

        for(int i = 0 ; ((i < size) && (!found)) ; i++ ){

            int x = q.front();
            q.pop();

            int c = 1 ;

            while((x + c*c )<= n){

                if((x + c*c) == n){
                    found = 1;
                    break ;
                }
                else{
                    if(!exist[x + c*c]){
                        exist[x + c*c] = 1 ;
                        q.push(x+c*c);
                    }
                }

                c++ ;
            }
        }

        ans++ ;

    }

    cout << ans ;

}