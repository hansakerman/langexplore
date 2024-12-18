#include <iostream>
using namespace std;

int main() {
  /*  int foo=17;
  if (foo==42) {cout << "hejhej";}
  else if (foo==69) {cout << "elseiffu";}
  else if (foo==17) {cout << "elseiffu 2";}
  else {cout << "nope";}*/


  int foo = 420;
  //ternary operator
  //string result = (foo==42) ? "Meaning" : "Not meaning";
  //cout << result;

  switch(foo){
  case 42:
    cout << "Meaning!!!";
      break;
  case 43:
    cout << "More than meaning";
    break;
  default:
    cout << "Glorp";
  }

  int i=0;
  while (i<10){
    cout << i << endl;
    i++;
  }

  int j=0;
  do{
    cout << "bonk";
    j++;
  }
  while(j<10);


  for(int k=0;k<10;k+=2){
    cout << k << "\n";
  }

  int lotsOfNumbers[3]={10,22,59};
  for (int l : lotsOfNumbers) {

    cout << l << "\n";}
}
