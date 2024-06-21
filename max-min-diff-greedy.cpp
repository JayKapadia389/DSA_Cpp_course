#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximum(vector<int> v){

    int diff = 0 ;

    sort(v.begin() , v.end());

    for(int i =0 ; i < (v.size()/2) ;i++){
        diff += abs(v[i] - v[v.size()-i-1]);
    }

    return diff ;
}

int minimum(vector<int> v){

    int diff = 0 ;

    sort(v.begin() , v.end());

    for(int i = 0 ; i < v.size() ; i+=2){
        diff += abs(v[i] - v[i+1]);
    }

    return diff ;
}

int main(){

    int n;
    cin >> n;

    vector<int> v(n);

    for(int i= 0 ; i< n ; i++){
        cin >> v[i];
    }

    cout << maximum(v) << " " << minimum(v);

}