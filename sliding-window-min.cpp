#include <iostream>
#include <vector>
#include <math.h>

using namespace std ;

int mn(vector<int> v , int k ){

    int kSum = 0 ;

    for(int i = 0 ; i < k ; i++){
        kSum+=v[i] ;
    }

    int mn = kSum ;

    for(int i = 1 ; i <= v.size() - k ; i++ ){
        
        kSum -= v[i-1];
        kSum += v[i+k-1];

        mn = min(mn , kSum);

    }

    return mn ;

}

int main(){

    vector<int > v = {-2 , 10 , 1 ,3 ,2 ,-1 ,4 ,5};
    int k = 3;

    cout << mn(v , k) ;


}