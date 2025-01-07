#include <iostream>
#include <deque>
using namespace std;

int main (){

  // deque: You can access items by index and access front and back.
  deque<string> cars ={"Volvo","BMW","Ford","Mazda"};

  for (string car:cars){
    cout <<car<<endl;
    if ( car=="Ford"){cout << "FOobaRD"<<endl;}}

  cout << "First: "<< cars[0]<<endl;;
  cout << "Second: " << cars.at(1)<<endl;;
  cout << "Last: "<< cars.back()<<endl;;
  cars.at(0)="Trabant";
  cout << "First: "<< cars[0]<<endl;;
  cars.push_front("Lada");
  cout << "First: "<< cars[0]<<endl;;
  cars.push_back("Saab");
  cout << "Last: "<< cars.back()<<endl;;
  cars.pop_front();
  cars.pop_back();

  for(int i;i<cars.size();i++){
    cout << cars[i] << endl;
  }
}
