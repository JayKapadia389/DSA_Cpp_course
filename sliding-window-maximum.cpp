#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){

    int n,k;
    cout << "enter number of elements : " ;

    cin >> n ;
    cout << endl;

    vector<int> a(n) , ans ;

    cout << "enter elements :" << endl ; 

    for(int i = 0 ; i < n ; i++){
        cout << i+1 << " : " ;
        cin >> a[i] ;
    }

    cout << "enter width of window : " ;
    cin >> k ; 

    multiset<int , greater<int>> m ; 

    for(int i = 0 ; i< k ; i++){
        m.insert(a[i]);
    }

    for(int i = 0 ; i <= n-k ; i++){
        ans.push_back(*m.begin());

         m.erase(m.lower_bound(a[i]));
         m.insert(a[i+k]);

    }

    for( int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << " " ; 
    }
}