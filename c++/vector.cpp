#include <vector>
#include <iostream>
using namespace std;

int main (){
  vector<string> cars={"Volvo","BMW","Ford","Mazda"};
  //  cout << cars[0]<<endl;
  cout << "first: " << cars.at(0)<< endl;
  //  cout << cars[3]<<endl;

  cout << cars.front()<< " : " << cars.back()<<endl;
  
  for (string car: cars){
    cout << car << "\n";
  }

  cars.at(0)="Saab";
  cout << endl<<"first: " << cars.at(0)<< endl;
  cars.push_back("Tesla");

  for (string car: cars){
    cout << car << "\n";
  }

  cout << cars.back();
  cars.pop_back(); 
  cout << cars.back();
  //  cout << cars.size();

  if ( !cars.empty()){
    cout << "\n Not empty. Size: " << cars.size();
  }

  
}
