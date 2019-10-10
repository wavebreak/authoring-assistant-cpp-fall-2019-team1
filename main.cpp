#include <iostream>
#include <string>
#include <vector>
using namespace std;


 void PrintMenu(){
   cout << "\nMENU" << endl;
   cout << "c - Number of non-whitespace characters" << endl;
   cout << "w - Number of words" << endl;
   cout << "f - Find text" << endl;
   cout << "r - Replace all !'s" << endl;
   cout << "s - Shorten spaces" << endl;
   cout << "q - Quit" << endl;
   cout << endl;
   cout<<"Choose an option:"<<endl;
   //cin >> PrintMenu;
   

   return;
}


int main() {

   string sentence;

    cout << "Enter a sample text:" << endl;
    getline(cin, sentence);
    cout << endl;
    //cout << sentence;
    cout << "You entered: " << sentence << endl;
    /*cout <<*/ 
    PrintMenu();
 
   return 0;
}
