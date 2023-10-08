#include <iostream>
#include <string>

using namespace std;

string arr[] = { "" , "abc" , "def", "ghi" , "jkl" ,"mno" , "pqrs" ,"tuv" ,"wxyz"} ;

void fun( int m ,int n ,int i ,int j){

    cout << arr[m].substr(i,1) + arr[n].substr(j,1) << endl;

    if(j!= (arr[j].length()-1)){
        fun( m, n , i , j+1);
    }
    else if(i!= (arr[i].length()-1) ){
        fun(m , n , i+1 , 0 );
    }
    else{
        return;        
    }
}

int main(){

    fun( 6 , 8 , 0 , 0);
}