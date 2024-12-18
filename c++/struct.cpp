#include <iostream>
#include <string>
using namespace std;

int main() {

  struct {
    int myNum;
    string myString;
  } myStruct,otherStruct;

  myStruct.myNum=3;
  cout << myStruct.myNum;

  struct myStroktur {
    int myNum;
    string myString;
  };

    myStroktur newStruct;

    newStruct.myString="foo";
    // a reference. 
    string &H = newStruct.myString;
    cout << H;

    int a=42;
    int b=17;
    int* aptr=&a;
    int* bptr=&b;
   
    cout <<endl<<&a;
    cout <<endl<<&b;
    cout <<endl<<aptr;
    cout <<endl<<bptr;
    cout <<endl << (bptr-aptr)<<endl;

    cout <<endl << *aptr<<"what"<<endl; // dereference
    
    return 0;
}
