#include <iostream>
#include <stack>

using namespace std;

bool recc(stack<int> &st , int target , int &sum , int curr , int &flag){

    if(st.empty()){
        return 0 ;
    }
    else{

        int top = st.top();
    sum+=top; 
    st.pop() ;

    if(sum < target){

        if(recc(st , target , sum , curr , flag)){
            return 1;
        }
        else{

            if( curr > top && flag == 0){
                st.push(curr); 
                flag = 1;
            }

            st.push(top);

            return 0 ;

        }


    }

    else if(sum == target){
        return 1;
    }
    
    else{
        return 0;
    }

    }

}

bool threeSum(int arr[] , int target , int n){

    stack<int> st ;
    int sum = 0 , flag = 0;


    for(int i = 0 ; i < n ; i++){
        if(recc(st , target , sum , arr[i] , flag)){
            return 1;
        }
        sum = 0;
        flag = 0 ;
    }

    return 0;
    
}

int main(){

    int arr[] = {12,3,7,1,6,9};
    int target = 24 ;
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << threeSum(arr , target , n );

}