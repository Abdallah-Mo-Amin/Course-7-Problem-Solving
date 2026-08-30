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
    string text = "";
    cout << "Please Enter your string?\n";
    getline(cin, text);
    return text;
}

string UpperAllString(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = toupper(S1[i]);
    }
    return S1;
}

string LowerAllString(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {        
        S1[i] = tolower(S1[i]);
    }
    return S1;
}



int main() 
{
    string S1 = ReadString();

    cout << "\nString after upper:\n";
    S1 = UpperAllString(S1);
    cout << S1 << endl;
    
    cout << "\nString after lower:\n";
    S1 = LowerAllString(S1);
    cout << S1 << endl;

    system("pause>0");

    return 0;
}
