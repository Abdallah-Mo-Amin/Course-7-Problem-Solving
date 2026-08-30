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

string TrimLeft(string S1)
{

    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ')
        {
            return S1.substr(i, S1.length() - i);
        }

    }
    return "";
}

string TrimRight(string S1)
{
    for (short i = S1.length() - 1; i >= 0; i--)
    {
        if (S1[i] != ' ')
        {
            return S1.substr(0, i + 1);
        }
    }
    return "";
}

string Trim(string S1)
{
    return TrimLeft(TrimRight(S1));
}

int main() 
{    
    string S1 = "    FooBArBaz  kk   ";

    cout << "\nString     =" << S1;

    cout << "\n\nTrim Left  =" << TrimLeft(S1) << endl;;
    cout << "Trim Right =" << TrimRight(S1) << endl;;
    cout << "Trim       =" << Trim(S1) << endl;;


    system("pause>0");
    return 0;
}
