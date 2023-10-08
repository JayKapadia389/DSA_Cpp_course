#include <iostream>

using namespace std;

void getPrime(int n){

    int prime[100] = {0};

    for( int i=2 ; i < n ; i++){

        if(prime[i] == 0){
            for(int j=i*i ; j<=n ; j+=i){
                if(prime[j] == 0 ){
                    prime[j]++;
                }
            }
        }
    }

    for(int i=2 ; i <= n ; i++){

        if(!prime[i])
        cout << i << " ";
    }
}

int main(){

    int n ; 

    cin >> n ; 

    getPrime(n);
}
