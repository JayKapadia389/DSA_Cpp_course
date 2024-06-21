#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    string s1 = "jegfab" , s2 = "gfjedab";

    int n = s1.size() , m = s2.size() ;

    vector<vector<int>> lcs( n + 1 , vector<int>(m+1 , 0)) ;

    for(int i = n-1 ; i >= 0 ; i--){

        for(int j = m-1 ; j >= 0 ; j--){
            
            if(s1[i] == s2[j]){
                lcs[i][j] = 1 + lcs[i+1][j+1] ;
            }
            else{

                lcs[i][j] = max(lcs[i+1][j] , lcs[i][j+1]);
            }
        }
    }

    cout << lcs[0][0] ; 
    
}