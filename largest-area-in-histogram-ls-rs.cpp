#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestAreaInHistogram(vector<int> v){

    int vSize = v.size();
    int maxArea = 0 ; 
    stack<int> st ;
    vector<int> lns(v.size()) , rns(v.size());

    for(int i = 0 ; i < v.size() ; i++){

        while( !st.empty() && (v[st.top()] >= v[i])){
            st.pop();
        }

        if(st.empty()){
            lns[i] = 0 ;
        }
        else{
            lns[i] = st.top()+1;
        }

        st.push(i);
    }

    while(!st.empty()){
        st.pop();
    }

    for(int i = v.size()-1 ; i >= 0 ; i--){

        while( !st.empty() && (v[st.top()] >= v[i])){
            st.pop();
        }

        if(st.empty()){

            maxArea = max( maxArea , ((vSize-1) - lns[i] + 1) * v[i] );
        }
        else{
            maxArea = max( maxArea , ((st.top() -1) - lns[i] + 1) * v[i]);
        }

        st.push(i);

    }

    return maxArea ;
}

int main(){

    int n ;

    cout << "enter number of bars : " ;
    cin >> n;

    vector<int> v(n);

    cout << endl << "enter heights" << endl ;

    for(int i=0 ; i<n ; i++){
        cin >> v[i] ;
    }

    cout << endl << largestAreaInHistogram(v);

}