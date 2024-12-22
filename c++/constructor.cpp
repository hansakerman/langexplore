#include <iostream>
using namespace std;

class MyClass{
 public:
  MyClass() {
    cout << "I am called when the object is created";
  }
};

int main(){
  MyClass myObj;
  return 0;
}
