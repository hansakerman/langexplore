#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

int main(){
  string userInput;
  map<string,string> words;
  
  ofstream MyFile("file.txt");
  string myText;
  ifstream MyReadFile("words.txt");

  while (getline (MyReadFile, myText)) {
    int pos=myText.find(" "); // We have to cut out the first glossary word.
    words.insert({myText.substr(0,pos),myText.substr(pos+1)});
  }

  string answer;

  for (auto const& [word, definition] : words)
    {
      
      cout << word<<endl;
      cout << "Svar: ";
      cin >> answer;
      cout << definition << endl;
      if (definition.find(answer)!=string::npos){cout << "korrekt"<<endl;}
      else {cout << "NOPE"<<endl;}
    }
  
  cout <<  words.size()<< endl;
  cout << "Svara: ";
	  cin >> userInput;
  cout << userInput;
  MyReadFile.close();
}
