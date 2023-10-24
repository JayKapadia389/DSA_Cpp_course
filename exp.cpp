#include <iostream>
#include <string>
#include <typeinfo>

using namespace std ;

int main(){

   // cout << static_cast<int>('-') << static_cast<int>('+') << static_cast<int>('*') << " " << static_cast<int>('/');

   // string s = "jay";

   // int i = -1 ; 

   int * arr ;

   arr = new int[20];

   // *arr = 10;
   arr[0] = 10;

   cout << arr[0] ;


   // for(int i = 0 ; i < 256 ; i++){

   //    cout << static_cast<char>(i) << endl;
   // }
}