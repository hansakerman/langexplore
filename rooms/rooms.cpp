#include <iostream>
using namespace std;

class room{
  public:
  string name="void";
  string description="void";
};

int main()
{
  room firstRoom;

  firstRoom.description="Hey, this is the initial room";

  while (1)
    {
      cout << "You are in a void : ) "<<endl;
      cout<< firstRoom.description;
    }
}





