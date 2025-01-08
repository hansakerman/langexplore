#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main (){

  vector<string> cars = {"Volvo","BMW","Ford","Mazda"};
  //  vector<string>::iterator it;
  //auto it = cars.begin();
  //for (it;it !=cars.end();++it){
  //  cout << *it <<endl;
  //}
  // I am here: For-Each Loop vs. Iterators
  // If we want to mess with items then you might have to use an iterator

  for(auto it = cars.begin();it != cars.end();){
    if (*it == "BMW"){
      it=cars.erase(it);}else{++it;}
  } 

  for (const string& car : cars) {
    cout << car << endl;}
  auto foo=cars.begin();
    auto foo2=cars.rend();
    cout << &foo<<endl;
    cout << &foo2<<endl;

}

