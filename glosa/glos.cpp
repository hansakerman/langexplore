#include <iostream>
#include <fstream>
using namespace std;

int main(){

  ofstream MyFile("file.txt");
  //MyFile << "Now I write the the file object. Hurray!"<<std::endl<<"foo";
  //MyFile.close();
  //
  string myText;
  ifstream MyReadFile("words.txt");

  while (std::getline (MyReadFile, myText)) {
    cout << "FOO";
    cout << myText;
  }

  MyReadFile.close();
}
