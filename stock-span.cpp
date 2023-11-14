#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void rec(stack<int> &st , int vi , int i , int ans[]){

    if(st.empty() || (vi <= st.top())){
        st.push(vi);
        return;
    }
    
    int top = st.top();
    st.pop();
    (*(ans+i))++;

    rec(st , vi , i , ans);

    st.push(top);

    return;
}

int * stockSpan(vector<int> v){

    int n = v.size();
    int * ans = new int[n];
    stack<int> st;

    for(int i = 0 ; i < n ; i++){
        ans[i] = {1};
    }

    for(int i = 0 ; i < n ; i++){

        rec( st, v[i] , i , ans);

    }

    return ans ;

}

int main(){

    vector<int> v = {100,80,60,70,60,75,85};

    int * ans = stockSpan(v);
    
    for(int i = 0 ; i < v.size() ; i++){
        cout << *(ans+i) << " ";
    }
    

}