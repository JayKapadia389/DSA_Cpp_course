#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int maxOnes(vector<int> v , int k){

    queue<int> q ; 
    int len = 0 ;
    int ans = 0 ;

    for(int i = 0 ; i < v.size() ; i++){

        if(!v[i]){

            if(q.size() == k){
                len = i -  q.front() -1;

                q.pop();

            }

            q.push(i);
        }

        len++;

        ans = max(ans , len);
    }

    return ans ; 
}

int main(){

    vector<int> v = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1} ;
    int k = 3 ;

    cout << maxOnes(v , k);

}