#include <iostream>
using namespace std;

class MyClass{
  public:
  void myMethod();
  int speed(int maxSpeed);
};

int MyClass::speed(int maxSpeed){
  return maxSpeed;
};

void MyClass::myMethod(){
    cout << "Hello World!";
  };

int main (){
  MyClass myObj;
  cout << myObj.speed(20000)<< endl;
  myObj.myMethod();
  return 0;  
}
