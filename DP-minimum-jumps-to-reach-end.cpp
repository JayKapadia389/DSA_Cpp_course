#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){

    int n ;
    cin >> n ;

    vector<int> ms(n);

    for(int i = 0 ; i < n ; i++){
        cin >> ms[i] ;
    }

    bool found = 0 ;
    int ans = 0 ;
    queue<int> q ;
    q.push(0);
    vector<bool> exist(n);

    while(!found){

        int size = q.size();

        for(int i = 0 ; i < (size && !found) ; i++){

            int x = q.front();
            q.pop();

            int val = ms[x];

            for(int j = 1 ; j <= val ; j++){

                if(!exist[x+j]){

                    exist[x+j] = 1;

                    if(x+j == n-1){
                        found = 1;
                        break ;
                    }
                    else{
                        q.push(x+j);
                    }

                }
                
            }   
        }

        ans++ ;

    }

    cout << ans ;
}