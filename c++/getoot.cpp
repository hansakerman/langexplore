#include <iostream>
using namespace std;

int main(){
  int i=0;

  while (i<4)
    {
      cout << "foobar: "<<i<<endl;
      i++;
    }

  for (i=0;i<50;i++){
    if (i==2){cout << "I skipped the two!"<< endl;continue;}
    else if (i==42){cout << i<<" the meaning!!";break;}
    cout << i << "|";
  }

}
