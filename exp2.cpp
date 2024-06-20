#include <iostream>
#include <map>

using namespace std;

int main(){

    map<int ,bool> e ;

    e[0] = 1;
    e[1] =1 ;
    e[3] = 1;
    int prev = -1 ; 

    for(auto i: e){

        cout << prev << " " << i.first << endl;

        prev = i.first ;

    }
}