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

string LowerAllString(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }

    return S1;
}

string JoinString(vector<string>& vString, string delim)
{
    string S1 = "";

    for (string& s : vString)
    {
        S1 = S1 + s + delim;
    }
    return S1.substr(0, S1.length() - delim.length());
}

string ReplaceWordsInStringUsingSplit(string S1, string StringToReplace, string sReplaceTo, bool MatchCase=true)
{
    vector<string> vString = SplitString(S1, " ");

    for (string &s : vString)
    {
        if (MatchCase)
        {
            if (s == StringToReplace)
            {
                s = sReplaceTo;
            }
        }
        else
        {
            if (LowerAllString(s) == LowerAllString(StringToReplace))
            {
                s = sReplaceTo;
            }
        }
    }
    return JoinString(vString, " ");
}

int main()
{
    string S1 = "Welcome to Egypt , Egypt is a nice country";
    string StringToReplace = "EgypT";
    string ReplaceTo = "usa";

    cout << "\nOriginal String:\n" << S1;
    cout << "\n\nString After Replace:\n";
    cout << ReplaceWordsInStringUsingSplit(S1, StringToReplace, ReplaceTo);
    
    cout << "\n\nString After With don't match Replace:\n";
    cout << ReplaceWordsInStringUsingSplit(S1, StringToReplace, ReplaceTo, false);


    system("pause>0");


    return 0;
}
