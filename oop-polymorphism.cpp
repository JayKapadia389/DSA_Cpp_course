#include <iostream>

using namespace std;

class complexNum {

    int real , imag;

    public:

    void fun(){
        cout << "function with no parameters" << endl;
    }

    void fun(int a){
        cout << "function with integer parameters" << endl;
    }

    void fun(char c){
        cout << "function with character parameters" << endl;
    }

    // complexNum(){

    // }

    // complexNum(int r , int i){
    //     real = r;
    //     imag = i;

    // }

    // complexNum operator + (complexNum num){

    //     complexNum res;

    //     res.real = real + num.real;
    //     res.imag = imag + num.imag;

    //     return res;

    // }

    void display(){
        cout << real << " + i" <<  imag <<endl;
    }
};

int main(){

    complexNum 
    // num1(3 ,7),
     num2(3,7);

    // complexNum num3 = num1 + num2;

    // num3.display();

    

}


//constructor
// &obj ?


//function overloading 
//operator overloading