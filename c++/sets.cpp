#include <iostream>
#include <set>
using namespace std;

int main (){
  set<string> kaos;
  kaos.insert("foobar");
  kaos.insert("moo");
  kaos.insert("void");

  for (string kao:kaos){
    cout << kao<<endl;}

  kaos.erase("foobarbb");
  kaos.erase("void");

  for (string kao:kaos){
    cout << kao<<endl;}
  kaos.clear();
  
}
