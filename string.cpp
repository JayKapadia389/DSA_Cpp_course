#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){

    //substr
    //append
    //sort
    //length
    //begin , end
    //getline( cin , [identifer] )

    string s1 = "jay is the best";
    string s2 = " ,or is he?";
    string s3 = s1.append(s2);
    string s4 = "aedbc";
    string s5 ;

    int i=0 ;

    // cout << s1[15];

    // while(s1[i] != ''){

    //     cout << "1";
    //     i++;
    // }

    cout << s1.substr(4 , 2);
    // cout << s1.append(s2) ;
    // cout << "s1 " << s1 << endl <<  "s3 " << s3;
    // cout << s4.length();

    // getline( cin , s5);
    // cout << s4;

    // sort( s4 , s4+3 );

    // cout << s5 ; 
}