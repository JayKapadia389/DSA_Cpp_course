#include <iostream>
#include <vector>

using namespace std;

bool comparator(vector<int> v1 , vector<int> v2){

    return (v1[0]/v1[1]) > (v2[0]/v2[1]) ;
}

int maxValue(vector<vector<int>> v , int W){

    int val = 0 ; 

    sort(v.begin() , v.end() , comparator);

    for(int i = 0 ; i < v.size()  ; i++){

        if(W - v[1] >= 0){
            W-= v[1];
            val+=v[0];
        }
        else{
            val+= v[0] * W / v[1];
            return val ;
        }
    }
}

int main(){

    int W , n ;
    cin >> W >> n ;

    vector<vector<int>> v(n, vector<int>(2)); // [value , weight] 

    for(int i = 0 ; i < n ; i++ ){
        cin >> v[i][0] >> v[i][1] ;
    }

    cout << maxValue(v,W);
}