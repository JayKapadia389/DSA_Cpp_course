#include <iostream>

using namespace std;

bool getBit(int n , int i){
    return(n & (1 << i));
}

int setBit(int n , int i ){
    return(n | (1 << i));
}

int clearBit(int n , int i){
    return( n & ~(1 << i));
}

int updateBit(int n , int i ){
    return( n ^ (1 << i ));
}

int main(){

    // cout << getBit(5 , 2);
    // cout << setBit(5 , 1);
    // cout << clearBit(5 , 2);
    cout << updateBit(9 ,2);

}