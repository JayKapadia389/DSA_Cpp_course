#include <iostream>
#include <vector>

using namespace std;

int val = 0 , wt = 0 ;

void knapsack(int currVal , int currWt , vector<bool > taken , int idx , vector<pair<int,int>> v , int W){

    if(idx != -1){

        taken[idx] = 1;

        if(currVal > val){
            val = currVal;
            wt = currWt  ;
        }
    }

    for(int i = 0 ; i < taken.size() ; i++){

        if(!taken[i]){

            if((currWt + v[i].second) <= W){
                knapsack(currVal + v[i].first , currWt + v[i].second , taken , i , v , W);
            }
        }
    }

    return ;

}

int main(){

    int n ;
    cin >> n ;

    vector<pair<int,int>> v(n) ; // value , weight
    vector<bool> taken(n , 0);

    for(int i = 0 ; i < n ; i++){
        cin >> v[i].first  ;
    }

    for(int i = 0 ; i < n ; i++){
        cin >> v[i].second  ;
    }
    

    int W ;
    cin >> W ;

    knapsack(0 , 0 , taken , -1 , v , W) ;

    cout << val << " " << wt ;

}