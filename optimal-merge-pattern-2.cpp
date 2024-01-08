#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int optimal(vector<int> v){

    sort(v.begin() , v.end());

    int ans = 0 ;
    int e1 , e2 ;
    priority_queue<int , vector<int> , greater<int>> minHeap ;

    for(int i = 0  ; i < v.size() ; i++){
        minHeap.push(v[i]);
    }

    while(minHeap.size() > 1){
        e1 = minHeap.top();
        minHeap.pop();
        e2 = minHeap.top();
        minHeap.pop();

        ans+= e1 + e2 ;

        minHeap.push(e1 + e2);
    }   

    return ans ;
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