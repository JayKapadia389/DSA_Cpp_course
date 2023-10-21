#include <iostream>
#include <string>
#include <typeinfo>

using namespace std ;

int main(){

   cout << static_cast<int>('-') << static_cast<int>('+') << static_cast<int>('*') << " " << static_cast<int>('/');

   // for(int i = 0 ; i < 256 ; i++){

   //    cout << static_cast<char>(i) << endl;
   // }
}