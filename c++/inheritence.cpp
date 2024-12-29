#include <iostream>
using namespace std;

class animal{
public:
  bool isAlive=true;
  string foo="hej";
};


class deer: public animal{
public:
  bool fourLegs=true;
};
    
  
int main(){

  deer Rudolph;

  cout <<Rudolph.isAlive;
  cout <<Rudolph.fourLegs;
  cout <<Rudolph.foo;
  return 0;
}
