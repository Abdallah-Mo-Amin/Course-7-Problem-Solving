#include <iostream>
#include <cstdlib>  
#include <iomanip> // this library stored the std::setw
#include <cmath>
#include <string> // this library stired the string object
#include <vector>
#include <cctype>
#include <ctime>
#include <fstream> 
#include "MyinputLib.h"

using namespace std;
using namespace MyInputLib;

string ReadString()
{
    string S1 = "";
    cout << "Please enter your string?\n";
    getline(cin, S1);

    return S1;
}

vector<string> SplitString(string S1, string delim)
{
    vector <string> vString;
    short pos = 0;
    string sWord;

    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + delim.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}


int main() 
{    
    vector<string> vString;


    string S2 = "Mohammed#,,#Ali#,,#ahmed#,,#fadi#,,#Rasha";


    vString = SplitString(S2, "#,,#");

    cout << "\nTokens = " << vString.size() << endl;
    for (string& s : vString)
    {
        cout << s << endl;
    }


    system("pause>0");


    return 0;
}
