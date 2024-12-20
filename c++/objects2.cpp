#include <iostream>
using namespace std;

class Car {
public:
  string brand;
  string model;
  int year;
};

int main(){
  Car carObj1;
  carObj1.brand="volvo";
  carObj1.model="amazon";
  carObj1.year=1968;

  Car carObj2;
  carObj2.brand="porsche";
  carObj2.model="911";
  carObj2.year=1972;

  cout <<   carObj1.brand<<carObj1.model<<carObj1.year<<"\n";
  cout <<   carObj2.brand<<carObj2.model<<carObj2.year<<"\n";
  return 0;  
}
