#include <iostream>
using namespace std;

class fooBar{
  public:
    int x=42;
  private:
    int y=17;
};

    
int main(){

    fooBar fooObj;
    
    cout << fooObj.x;
    //    cout << fooObj.y;  DECLARED PRIVATE

}
