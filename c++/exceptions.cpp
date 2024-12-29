#include <iostream>
using namespace std;


// try throw catch

int main(){
  try{  int age=15;
  if (age >= 18){
    cout <<"ID CHECK OK";
  } else {
    throw (age);}
  }
  
  catch(int myNum){
    cout << "ID CHECK DENIED\n";
    cout << "Age: "<<myNum<<"\n";
  }
}


