#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n ;
    cin >> n ;
    vector<int> ele(n) ;

    for(int i = 0 ; i<n ;i++){
        cin >> ele[i];
    }

    vector<int> lis(n , 1);

    for(int i = n-1 ; i >= 0 ; i--){

        for(int j = i+1 ; j < n ; j++){

            if(ele[i] < ele[j] && 1+lis[j] > lis[i]){
                lis[i] = 1+lis[j] ;
            }
        }

    }

    int ans = 0;

    for(int i = 0 ; i < n ; i++){
        ans = max(ans , lis[i]);
    }

    cout << ans ;

}