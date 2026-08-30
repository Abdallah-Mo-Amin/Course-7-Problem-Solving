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

string RemovePunctionsFromString(string S1)
{
    string S2 = "";

    for (short i = 0; i < S1.length(); i++)
    {
        if (!ispunct(S1[i]))
        {
            S2 += S1[i];
        }
    }
    return S2;
}


int main()
{
    string S1 = "Welcome: to, Jordan, Jordan is a nice country; it's amazing";

    cout << "\nOriginal String:\n" << S1;
    cout << "\n\npuncuations Removed:\n";
    cout << RemovePunctionsFromString(S1) << endl;
    
    system("pause>0");
    return 0;
}
