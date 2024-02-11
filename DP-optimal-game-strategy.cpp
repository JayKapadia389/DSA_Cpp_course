#include <bits/stdc++.h>

using namespace std;

int dp[100][100];

int solve(vector<int> a , int i , int j){

    if(i == j){
        return a[i] ;
    }

    if(i > j){
        return 0 ;
    }

    if(dp[i][j] != -1)
        return dp[i][j] ;

    int l = a[i] + min(solve(a , i+2 , j) , solve(a , i+1 , j-1));

    int r = a[j] + min(solve(a , i+1 , j-1) , solve(a , i , j-2));

    return dp[i][j] = max(l , r);

}

int main(){

    memset(dp , -1 , sizeof(dp)); 

    int n ;
    cin >> n ;

    vector<int> a(n) ;

    for(auto &i : a){
        cin >> i ;
    }

    cout << solve(a , 0 , n-1) ; 
}