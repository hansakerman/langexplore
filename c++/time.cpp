#include <iostream>
#include <ctime>
using namespace std;

int main(){
  time_t timestamp;
  time(&timestamp);
  cout << ctime(&timestamp);

  //mktime()
  // date structs

  struct tm datetime;
  datetime.tm_year = 2023-1900;
  datetime.tm_mon = 12 -1;
  datetime.tm_mday=17;
  datetime.tm_hour=0;
  datetime.tm_min=0;
  datetime.tm_sec=0;
  datetime.tm_isdst=-1;
  mktime(&datetime);

  string weekdays[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};


  cout << "The date is on a "<< weekdays[datetime.tm_wday]<<endl;

  time_t timestamp2=time(&timestamp);
  struct tm datetime2 = *localtime(&timestamp);
  cout << "Hour: " << datetime2.tm_hour<<endl;

  cout <<"CLOCKS_PER_SEC: "<<CLOCKS_PER_SEC<< endl;
  clock_t stamp_clock = clock();
  cout << "Press enter after a second."<<endl;
  cin.ignore();
  cout << clock()-stamp_clock;
}
