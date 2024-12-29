#include<iostream>
using namespace std;


class Employee{
private:
  int salary;
public:
  int getSalary(){
    return salary;
  }
  void setSalary(int x){
    salary=x;
      }
  
};

int main(){
  Employee emp;
  emp.setSalary(40);
  cout<< emp.getSalary();
  return 0;
}
