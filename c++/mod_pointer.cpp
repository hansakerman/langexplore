#include <iostream>
using namespace std;

int main (){
  string food="pizza";
  string* ptr=&food;

  cout << food <<"\n";
  // the memory adress 
  cout << &food << "\n";

  // value of the pointer (what it points to)
  cout << *ptr << "\n";
  
  *ptr = "hamborg";

  cout << *ptr << "\n";
  cout << food << "\n";
  
  
}
