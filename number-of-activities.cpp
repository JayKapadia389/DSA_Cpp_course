#include <iostream>
#include <climits>
#include <vector>
#include <algorithm> 

using namespace std;

bool comparator(vector<int> v1  , vector<int> v2){

    return v1[1] < v2[1];
}

int numOfActivities(vector<vector<int>> v ){

    sort(v.begin() , v.end() , comparator);

    int c = 0 , le = INT_MIN;

    for(int i = 0 ; i< v.size() ; i++){
        if(v[i][0] >= le){
            c++ ; 
            le = v[i][1];
        }
    }

    return c ;
}

int main(){

    int n ;
    cin >> n ;

    vector<vector<int>> v(n, vector<int>(2));

    for(int i = 0 ; i < n ; i++ ){
        cin >> v[i][0] >> v[i][1] ;
    }

    cout << numOfActivities(v);

}