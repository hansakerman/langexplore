#include <iostream>
using namespace std;

void foo(){
  cout << "HELLO" << endl;
}

void foo2(string foobar = "DEFAULT MAN\n"){
  cout << foobar; 
}

int add5(int a){
  return a+5;
}

int main (){
  foo();
  foo2();
  foo2("foobar foo");
  foo2();
  foo2("goobar goo");
  cout << add5(3);
  return 0;
}
