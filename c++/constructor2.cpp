#include <iostream>
using namespace std;

class MyClass{
 public:
  MyClass(string foo, int foo2 );
};

MyClass::MyClass(string foo, int foo2 ) {
    cout << "I am called when the object is created";
    cout << foo<<foo2<<endl;
  }

int main(){
  MyClass myObj("foo",42);
  MyClass myObj2("bar",17);
  return 0;
}
