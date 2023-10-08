#include <iostream>

using namespace std;

void swap(int * x , int * y){

    int z;
    z = *x;
    *x = *y;
    *y = z;
    
}

int main (){

    int a , b;

    cout << "enter numbers" << endl ; 
    cin >> a >> b;

    swap(&a , &b);

    cout << a << " " << b;
}