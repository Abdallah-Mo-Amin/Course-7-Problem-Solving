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

enum enWhatToCount {SmallLetters=0, CapitalLetters=1, All=2};

short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
{
    if (WhatToCount == enWhatToCount::All)
    {
        return S1.length();
    }

    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (WhatToCount == enWhatToCount::CapitalLetters &&  isupper(S1[i]))
        {
            Counter++;
        }
        if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
        {
            Counter++;
        }
    }
    return Counter;
}

short CountCapitalLetters(string S1)
{
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
        {
            Counter++;
        }
    }
    return Counter;
}

short CountSmallLetters(string S1)
{
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (islower(S1[i]))
        {
            Counter++;
        }
    }
    return Counter;
}


int main() 
{
    string S1 = ReadString();


    cout << "\nString Length = " << S1.length() << endl;
    cout << "Capital Letters count = " << CountCapitalLetters(S1) << endl;
    cout << "Small Letters Count  = " << CountSmallLetters(S1) << endl;
    
    cout << "\n\nMethod 2 \n\n";
    
    cout << "\nString Length = " << CountLetters(S1) << endl;
    cout << "Capital Letters count = " << CountLetters(S1, enWhatToCount::CapitalLetters) << endl;
    cout << "Small Letters Count  = " << CountLetters(S1, enWhatToCount::SmallLetters) << endl;

    system("pause>0");

    return 0;
}
