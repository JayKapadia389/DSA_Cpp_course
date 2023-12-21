#include <iostream>
#include <queue>
#include <vector>

using namespace std ;

int ss(vector<int> v , int k){

    int sum = 0 ;
    int c = 0 ;

    priority_queue<int , vector<int>> maxHeap ;

    for(int i =0 ;  i< v.size() ; i++){
        maxHeap.push(v[i]) ;
    }

    while(sum < k && !maxHeap.empty()){

        sum += maxHeap.top();
        maxHeap.pop();
        c++ ;
    }

    if(sum < k){
        return 0 ;
    }
    else{
        return c ;
    }

}

int main(){

    int n , k ;

    cin >> n >> k ;

    vector<int> v(n) ;

    for(int i =0 ;  i< n ; i++){
        cin >> v[i] ;
    }

    cout << ss(v , k);
    
}