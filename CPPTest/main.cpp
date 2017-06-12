#include <iostream>
#include "MyCode.hpp"


using namespace std;
int main() {
//    My_code::main();
    int a = 3;
    cout << "before change" << endl;
    cout << "a is " << a << endl;
    int &b = a;
    cout << "b is " << b << endl;
    b = 2;
    cout << "after change" << endl;
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;

    //
    string first_name;
    string last_name;
    cout << "Enter first name:";
    cin >> first_name;
    cin >> last_name;
    cout << endl;
    cout << "The name entered: " << first_name << " " << last_name << endl;



    return 0;
}