#include <iostream>

using namespace std;

int main(){

    int n;
    cout << "enter length of string" << endl ;
    cin >> n ;
    cin.ignore();

    char s[100];
    cout << "enter the string" << endl ;
    cin.getline(s , n+1);

    int l=0 , max=0;
    char ls[100];

    for(int i=0 ; i<= n ;i++){
        if((s[i] != ' ') && (s[i] != '\0')){
            // cout << i; 
            l++;
        }
        else{
            if(l > max){
                max = l;
                l = 0;

                for(int j=0 ; j<max ;j++){
                    ls[j] = s[i-max+j];
                }
            }
        }
    }

    cout << endl;

    cout << max << endl ;

    for(int j=0 ; j<max ; j++){
        cout << ls[j];
    }
}