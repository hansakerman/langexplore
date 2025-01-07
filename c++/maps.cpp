#include <iostream>
#include <map>

using namespace std;

void printmap(auto people){
  for (auto person:people){
    cout << person.first << " is: "<< person.second<<endl;}
  }

int main (){
  map<string, int> people = {{"John",32},{"Adele",45},{"Bo",29}};

  cout << people["John"]<<endl;
  cout << people.at("Bo")<<endl;
  people["John"]=50;
  cout << people["John"]<<endl;
  // add new
  people["Foobar"]=42;
  people["Foobar"]=24;
  people["Baz"]=17;
  cout << people["Foobar"]<< endl;
  
  printmap(people);
  people.erase("John");
  cout << "John erasad"<<endl;
  printmap(people);
}
