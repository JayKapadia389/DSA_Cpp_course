//maxheap

#include <iostream>
#include <vector>

using namespace std;

class heap{

    vector<int> v ;

    public:

    heap(){
        v.push_back(0);
    }

    void push(int data){

        v.push_back(data);
        int i = v.size() - 1;
        int temp ; 

        while(i != 1 && v[i] > v[i/2]){

            temp = v[i];
            v[i] = v[i/2] ;
            v[i/2] = temp;

            // v[i] = v[i] + v[i/2] ;
            // v[i/2] = v[i] - v[i/2] ;
            // v[i] = v[i] - v[i/2] ;

            i = i/2 ;

        }
    }

    void display(){

        for(int i = 1 ; i < v.size() ; i++){
            cout << v[i] << " " ;
        }
    }
};

int main(){

    heap h1 ;

    h1.push(5);
    h1.push(2);
    h1.push(3);
    h1.push(6);
    h1.push(9);
    h1.push(1);

    h1.display();



}