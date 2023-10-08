#include <iostream>
#include <string>

using namespace std;

int count = 1;

void perm( string str , string curr){

    bool flag = 0;

    if(curr.length() == str.length()){

        cout << curr << " " << count++ << endl ;
        return ; 
    }

    for(int i=0 ; i < str.length() ; i++ ){

        flag = 0;

        for( int j=0 ; j < curr.length() ; j++){

            if(str[i] == curr[j]){
                flag = 1;
            }

        }

        if(!flag){
         perm(str , curr+str.substr(i,1) );  
        }
    }

}

int main(){

    perm("abcd" , "");
}