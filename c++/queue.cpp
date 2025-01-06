#include <iostream>
#include <queue>
using namespace std;

int main(){
  queue<string> people;
  people.push("Robert");
  people.push("Anna");
  people.push("Heinrich");
  people.push("Emma");

  cout << "Front: "<<people.front()<<endl;
  cout << "Back: "<<people.back()<<endl;

  people.front()="Foobar";
  cout << "Front: "<<people.front()<<endl;
  cout << "Back: "<<people.back()<<endl;

  people.pop();
  cout << "Front after pop: "<<people.front()<<endl;

  
}
