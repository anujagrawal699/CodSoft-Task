#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>      
#include <vector>
#include <algorithm>    
using namespace std;

struct WordCount{
    string word;    
    int count;      

    void iCount(){ count++; }

    WordCount(string s){ word = s; count = 1;}
};

string InputText();         
string Normalize(string);   
vector<WordCount> DistinctWords(string);    
bool findWord(string, vector<WordCount>);   
void DisplayResults(vector<WordCount>);    

int main(int argc, char** argv) {
    
    cout << "Lab 9 - Text File Word Counter\n";
    cout << "-------------------------------\n\n";


    string buffer = InputText();

    while (buffer != ""){
        
        cout << "\nThis is the text string read from the file\n";
        cout << "-------------------------------------------\n";
        cout << buffer << endl << endl;

    
        vector<WordCount> words = DistinctWords(buffer);

        
        cout << "There are " << words.size() << " unique words in the above text." << endl;
        cout << "--------------------------------------------" << endl << endl;
        DisplayResults(words);
        buffer = InputText();
    }
    return 0;
}


string InputText(){
    string fileName;
    ifstream inputFile;     
    string str;     
    string text;    

    cout << "File name? "; 
    getline(cin, fileName);

    
    if (fileName.empty()){ exit(0);}

    
    inputFile.open(fileName);

    if (!inputFile){
        cout << "Error opening data file\n";
        cout << "File name? "; cin >> fileName;
    }
    else{
        while (!inputFile.eof()){
            getline(inputFile, str);
            text += str;
        }
    }
    inputFile.close(); return text;
}

string Normalize(string s){

    string nString;
    char c;

   
    for (int i = 0; i < s.length(); i++){
        c = s[i];
        c = tolower(c);
        nString += c;
    }

   
    for (int i = 0; i < nString.length(); i++){
        if (ispunct(nString[i]))
            nString.erase(i, 1);
    }
  
    return nString;
}

vector<WordCount> DistinctWords(string s){
    vector<WordCount> words; 
    string nString = Normalize(s); 

    istringstream iss(nString);

    while(iss >> nString){
        string n;   
        iss >> n;   
        if (findWord(n, words) == true){ continue; }      
        else{
            WordCount tempO(n);    
            words.push_back(tempO);     
        }
    }
    return words;
}


bool findWord(string s, vector<WordCount> words){
  
    for (auto r : words){
        if (r.word == s){   
            r.iCount(); return true;
        }
        else     
            return false;       
    }
}


void DisplayResults(vector<WordCount> words){
   
    cout << "Word"  << setw(20) << "Count\n";
    cout << "-----------------------\n";
    for (auto &r : words){
        cout << setw(6) << left << r.word;
        cout << setw(15) << right << r.count << endl;
    }
}