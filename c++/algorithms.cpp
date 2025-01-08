#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main (){

  vector<string> alfabeta = {"T","G","R","E","Q","W","Y","V","C","B","A"};


  for (string ab:alfabeta){cout << ab;}
  cout << "\nSORTED\n";
  sort(alfabeta.begin(),alfabeta.end());
  for (string ab:alfabeta){cout << ab;}
  cout << "\nREV SORTED\n";
  sort(alfabeta.rbegin(),alfabeta.rend());
  for (string ab:alfabeta){cout << ab;}

  // Last 3 sort
 cout << "\nSORT LAST 3\n";
 sort(alfabeta.begin()+8,alfabeta.end());
  for (string ab:alfabeta){cout << ab;}

 cout << "\nFIND POSITION OF 'A'\n";
 auto it = find(alfabeta.begin(),alfabeta.end(),"A");
 cout << *it;;
 // upper_bound()
 // min_element()
 // max_element()
 
 return 0;

}
