#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n ;
    cin >> n ;

    vector<int> v(n);

    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }

    int val ;
    cout << "val :" ;
    cin >> val ;

    int i=0;

    while(val != 0 && i != v.size()){

        if(val - v[i] < 0){
            i++;
        }
        else{
            val -= v[i];
            cout << v[i] << " ";
        }
    }

    if(val != 0){
        cout << "not enough denominations";
    }

}