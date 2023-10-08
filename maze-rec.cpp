#include <iostream>

using namespace std;

int count = 0 ;

void maze(int m ,int  n){

    if(m==1 || n==1){
        count++;
        return;
    }
    else{
        maze(m-1 , n);
        maze(m , n-1);
    }
}

int main(){

    maze(3, 3);
    cout << count ;
}