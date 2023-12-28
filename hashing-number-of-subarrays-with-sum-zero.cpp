#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){

    int n ; 

    cin >> n ;

    vector<int> a(n) ;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    map<int , int > cnt ;
    int prefSum = 0 ;

    for(int i = 0 ; i < n ; i++){

        prefSum += a[i] ;

        cnt[prefSum]++ ;
    }

    int ans = 0 ;
    map<int , int > :: iterator it ;

    for(it = cnt.begin() ; it != cnt.end() ; it++){

        if(it->first == 0){
            ans += (it->second + 1)*(it->second)/2 ;
        }

        else{
            ans += (it->second)*(it->second - 1)/2 ;
        }

    }

    cout << ans ;

}