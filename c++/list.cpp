#include <list>
#include <iostream>
using namespace std;

int main(){
  list<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

  cout << cars.front();
  cout << cars.back();
  
  // Print the elements
  //  for (string car : cars )
  //    {cout << car << endl;}

  cars.front()="Opel";
  cout << cars.front();
  cout << cars.back();
  cars.push_front("Tesla");
  cout << cars.front();
}
