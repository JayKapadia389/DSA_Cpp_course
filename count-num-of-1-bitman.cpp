#include <iostream>

using namespace std;

int numOfOnes(int n){

    int count = 1;

    if(n == 0){
        count = 0;
        return count;
    }
    else{
        while(true){

            if(!(n & (n-1))){
                break;
            }

            n = (n & (n-1)) ;

            count++;
        }

        return count;

    }


}

int main(){

    int n=15;

    cout << numOfOnes(n) ;
    
}