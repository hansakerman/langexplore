#include <string>
#include <iostream>
using namespace std;

// some language rehearsal.

int main () {

  string foo="bar";
  cout << foo << endl;

  int meaningLife=42;
  // Well, some basic stuff. Very good.: ) 
  cout << 10%3 << endl;
  cout << --meaningLife << endl;
  cout << ++meaningLife << endl;
  cout << ++meaningLife << endl;
  meaningLife+=20;
  cout << meaningLife << endl;
  cout << (5>7); // returns zero
  cout << (42==42); // returns on
  // The logicals! AND OR NEGATION and stuff
  cout << (1==1)&&(2==2);
  cout << !((1==1)||(2==3))<<endl;

  enum randomTags {FOO=42, BAR, BAZ};
  //  enum randomTags tag17;
  enum randomTags tag17=BAR;
  cout << tag17;
}
