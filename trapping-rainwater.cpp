#include <iostream>
#include <vector>
#include <stack>

using namespace std; 

int trappedWater(vector<int> v){

    int n = v.size();
    stack<int> st ;
    int ans = 0 ; 
    int diff = 0;

    for(int i = 0 ; i < n ; i++){

        while(!st.empty() && v[st.top()] <= v[i] ){
            
            int curr = st.top();

            st.pop();

            if(st.empty()){
                break;
            }

            diff = i - st.top() - 1 ;

            ans += (min(v[i] , v[st.top()]) - v[curr]) * diff ; 
        }

        st.push(i);
    }

    return ans ;

}

int main(){

    int n ;
    cout << "enter n :";
    cin >> n;

    vector<int> v(n);

    cout << "enter heights : " << endl ;

    for(int i =0 ; i< n ; i++){
        cin >> v[i];
    }

    cout << trappedWater(v);

}