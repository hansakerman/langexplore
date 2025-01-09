#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main(){
  string userInput;
  map<string,string> words;
  
  ofstream MyFile("file.txt");
  string myText;
  ifstream MyReadFile("words.txt");

  while (getline (MyReadFile, myText)) {
    words.insert({myText.substr(0,myText.find(" ")),myText});
  }

  for (auto const& [key, val] : words)
    {
      cout << key        // string (key)
	   << ':'  
	   << val        // string's value
	   << std::endl;
    }
  
  cout <<  words.size()<< endl;
  cout << "Svara: ";
	  cin >> userInput;
  cout << userInput;
  MyReadFile.close();
}
