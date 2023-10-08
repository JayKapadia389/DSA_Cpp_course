#include <iostream>

using namespace std ;

int main(){

    // int * p = new int();

    // * p = 10;

    int * p = new int[4];

    *p = 1;
    *(p+1) =2;
    *(p+3) =4;

    cout << *p << " " <<  *(p+1) << " " << *(p+2) << " " << *(p+3)  ;
}