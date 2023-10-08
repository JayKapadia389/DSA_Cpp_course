#include <iostream>

using namespace std ;

void getSPF(int n){

    int spf[100] = {0};

    for(int i=2 ; i <= n; i++){

        for(int j = i ; j <= n ; j+=i){

            if(spf[j]==0){
                spf[j] = i ; 
            }
        }
    }

    while(n!=1){

        cout << spf[n] << ' ';

        n = n/spf[n];

    }

}

int main(){

    int n ;

    cin >> n ;

    getSPF(n);
}