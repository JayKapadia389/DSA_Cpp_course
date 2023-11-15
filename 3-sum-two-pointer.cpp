#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool threeSum(vector<int> v , int t){

    int n = v.size(),lo , hi , twoSum;
    sort(v.begin() , v.end());

    for(int i = 0 ; i < n ; i++){

        lo = i+1 , hi = n - 1 ;

        while(lo < hi){

            twoSum = v[i] + v[lo] + v[hi] ; 

            if(t == twoSum){
                return 1;
            }
            else if(t > twoSum){
                lo++ ; 
            }
            else{
                hi--;
            }

        }
    }

    return 0;
}

int main(){

    int n , t;
    cin >> n >> t;
    cout << endl ;

    vector<int> v(n);

    for(int i = 0 ;  i< v.size() ; i++){
        cin >> v[i];
    }

    cout << threeSum(v , t) ; 

}