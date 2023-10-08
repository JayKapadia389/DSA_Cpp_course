#include <iostream>
#include <string>

using namespace std;

string rd( string str , int n){

    if(n==1){
        return str.substr(0,1);
    }

    else{

        string prevStr = rd( str , n-1);

        for(int i=0 ; i<prevStr.length() ; i++){
            if(prevStr[i] == str[n-1]){
                return prevStr ;
            }
        }
        return prevStr.append(str.substr(n-1,1));
    }
}

int main(){

    string s = "";

    cout << rd(s , s.length());

}