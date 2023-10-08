#include <iostream>
#include <string>

using namespace std;

class student
{
    string name;

    public:
    int age;
    bool gender;

    student(){
        cout << "default constructer";
    }

    student(string n , int a , bool g){
        cout << "parametization constructer" << endl;
        name = n;
        age = a;
        gender = g ; 
    }

    student(student & 
    obj){
        name = obj.name;
        age = obj.age;
        gender = obj.gender;
    }

    void setName(string s){
        name = s;
        return;
    }

    void getData(){
        cout << name << endl << age << endl << gender ; 
    }
};

int main()
{

    student a("jay" , 19 , 1);

    student c = a;

    a.setName("goblin");

    a.getData() ;
    cout << endl;
    c.getData() ;
    cout << endl;

    // student s[3];

    // s[0].name = "jay";
    // s[0].age = 19;
    // s[0].gender = 0;

    // s[1].name = "rahul";
    // s[1].age = 32;
    // s[2].gender = 1;

    // s[2].name = "zuck";
    // s[2].age = 13;
    // s[2].gender = 0;

    // for (int i = 0; i < 3; i++)
    // {
    //     cout << s[i].name << " " << s[i].age << " " << s[i].gender << endl;
    // }
}