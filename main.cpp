//
//  main.cpp
//  
//
//  Created by William Smith on 10/2/19.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;


void ShortenSpace(string& words){
  string newString; 
  int index;
  
  while(true) {
    
   index = words.find("  ");
   if (index == -1) {
     break;
   }
   
   newString = words.substr(0, index);
   words.replace(0, index + 1, newString);
  }
  
  return;
}


void ReplaceExclamation(string& words){
  string newString;
  int index;
  
  while(true){
    
    index = words.find("!");
    if (index == -1){
      break;
    }
    
    words.at(index) = '.';
  }
  return;
}


int FindText(string usrStr, string words){
  
  string newString; 
  int index;
  int timesFound = 0;
  
  while(true) {
    
   index = words.find(usrStr);
   if (index == -1) {
     break;
   }
   
   timesFound++;
   
   newString = words.substr(0, index);
   words.replace(0, index + 1, newString);
   
  }
  return timesFound;
}


string OutputWithoutWhitespace(string usrStr) {
  
  string newString; 
  int index;
  
  while(true) {
    
   index = usrStr.find(" ");
   if (index == -1) {
     break;
   }
   
   newString = usrStr.substr(0, index);
   usrStr.replace(0, index + 1, newString);
  }
  
  return usrStr;
}


int GetNumOfNonWSCharacters(string words){
  
  int numOfNonWSChars;
  
  numOfNonWSChars = OutputWithoutWhitespace(words).size();
  
  return numOfNonWSChars;
  
}


int GetNumOfWords(const string usrStr){
  string String = usrStr;
  string newString; 
  int index;
  int numWords = 1;
  
  if (String.size() == 0){
    return 0;
    
  }
  while(true) {
    
   index = String.find(" ");
   if (index == -1) {
     break;
   }
   
   newString = String.substr(0, index);
   String.replace(0, index + 1, newString);
   
   if (String.at(index) != ' '){
     numWords++;
   }
  }
  
  return numWords;
}


char PrintMenu(string words){
  
  char paragraph;
  
  while (true){
    cout << "MENU" << endl;
    cout << "c - Number of non-whitespace characters"<<endl;
    cout << "w - Number of words"<<endl;
    cout << "f - Find text"<<endl;
    cout << "r - Replace all !'s"<<endl;
    cout << "s - Shorten spaces"<<endl;
    cout << "q - Quit"<<endl;
    cout << endl<<"Choose an option:";
    cin >>paragraph; 
    cout <<endl;
    
    switch(paragraph){
      
      case 'c':
        cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(words) << endl << endl;
        return paragraph;
        break;
        
      case 'w':
        cout << "Number of words: " << GetNumOfWords(words) << endl << endl;
        return paragraph;
        break;
      
      case 'f': 
        {
        string Text;
        cin.ignore(5, '\n');
        cout << "Enter a word or phrase to be found:";
        getline(cin, Text);
        cout << endl << "\"" << Text << "\"" << " instances: " << FindText(Text, words) << endl << endl;
        return paragraph;
        break;
        }
        
      case 'r':
        ReplaceExclamation(words);
        cout << "Edited text: " << words << endl << endl;
        return paragraph;
        break;
        
      case 's':
        ShortenSpace(words);
        cout << "Edited text: "<<words<<endl<<endl;
        
        
      case 'q':
        return paragraph;
        break;
      default:
        cout<<endl<<"INVALID CHOICE"<<endl<<endl;
    }
  }
  
}

int main(){
  
  string text;
  char paragraph;
  
  cout<<"Enter a sample text:"<<endl;
  getline(cin, text);
  cout<<endl;
  cout<<"You entered: "<<text<<endl<<endl;
  
  while(true){
    paragraph = PrintMenu(text);
    if (paragraph == 'q'){
      break;
    }
  }
  
  return 0;
}
