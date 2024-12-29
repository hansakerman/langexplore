#include <iostream>
#include <fstream>
//using namespace std;

int main(){

  std::ofstream MyFile("file.txt");
  MyFile << "Now I write the the file object. Hurray!"<<std::endl<<"foo";
  MyFile.close();

  std::string myText;
  std::ifstream MyReadFile("file.txt");

  while (std::getline (MyReadFile, myText)) {
    std::cout << myText;
  }

  MyReadFile.close();
}
