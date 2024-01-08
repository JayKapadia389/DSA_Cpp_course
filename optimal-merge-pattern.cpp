//incorrect

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int optimal(vector<int> v){

    sort(v.begin() , v.end());

    int sum = 0 ;
    int s = 0 ;

    for(int i = 0  ; i < v.size() ; i++){
        if(i!= 0){
            s+= sum + v[i];
        }

        sum += v[i];
    }

    return s ;
}

int main(){

    int n ;
    cin >> n;

    vector<int> v(n);

    for(int i= 0 ; i< n ; i++){
        cin >> v[i];
    }

    cout << optimal(v);
}