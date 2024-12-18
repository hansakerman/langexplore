#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string cars[4]={"volvo","bmw","saab","porsche"};
  for (string car : cars) {cout << car<< endl;}

  cout << sizeof(cars);
  
}
