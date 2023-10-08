#include <iostream>
#include <string>

using namespace std;

bool powerOfTwo(int n){

    return (0 && (n & (n-1)));
    
}

int main(){

    int a=0;

    if(!powerOfTwo(a))
    cout << "2s power";

    else
    cout << "not 2s power";

}