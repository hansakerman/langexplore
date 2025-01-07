#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main (){

  vector<string> cars = {"Volvo","BMW","Ford","Mazda"};
  //  vector<string>::iterator it;
  auto it = cars.begin();
  for (it;it !=cars.end();++it){
    cout << *it <<endl;
  }
  // I am here: For-Each Loop vs. Iterators  
}
