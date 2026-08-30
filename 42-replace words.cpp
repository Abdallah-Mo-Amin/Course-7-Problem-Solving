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

string ReplaceWordsInStringUsingBuildInFunction(string S1, string StringToReplace, string ReplaceTo)
{
    short pos = S1.find(StringToReplace);
    while (pos != string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(), ReplaceTo);
        pos = S1.find(StringToReplace); // find next
    }
    return S1;
}

int main()
{
    string S1 = "Welcome to egypt , egypt is a nice country";
    string StringToReplace = "egypt";
    string ReplaceTo = "usa";

    cout << "\nOriginal String:\n" << S1;
    cout << "\n\nString After Replace:\n";
    cout << ReplaceWordsInStringUsingBuildInFunction(S1, StringToReplace, ReplaceTo);



    system("pause>0");


    return 0;
}
