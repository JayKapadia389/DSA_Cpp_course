#include <iostream>
#include <cmath>

using namespace std;

void subsets(char a[] , int n){

    char ans[pow(2,n)][n+1] = {'\0'};

    for(int i=0 ; i < (pow(2,n)) ; i++){

        for(int j=0 ; j<n ; j++){

            if( i & (1<<j)){

                ans[i][(n-1)-j] = a[(n-1)-j];
            }
        }
    }

    for(int i=0 ; i < (pow(2,n)) ; i++){

        for(int j=0 ; j< n ; j++){
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }


}

int main(){

    char a[6]={'a','b','c','d','e'};

    subsets( a , 5);

}
