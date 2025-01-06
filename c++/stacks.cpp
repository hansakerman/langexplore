#include <iostream>
#include <stack>
using namespace std;

int main (){

  stack<string> consoles;
  consoles.push("N64");
  consoles.push("PS1");
  consoles.push("PS2");
  cout << consoles.top();
  cout << consoles.top();
  consoles.top()="Megadrive";
  cout << consoles.top();
  consoles.pop();
  cout << consoles.top();
  cout << " Size: " <<consoles.size();    
  cout << " Empty?: " <<consoles.empty();    
}

