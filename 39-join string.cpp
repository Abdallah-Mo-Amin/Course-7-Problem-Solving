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

string JoinString(vector<string> &vString, string delim)
{
    string S1 = "";

    for (string& s : vString)
    {
        S1 = S1 + s + delim;
    }
    return S1.substr(0, S1.length() - delim.length());
}


int main()
{
    vector<string> vString{"Ahmed", "Mohammed", "Ali", "Maher", "Ali", "Dina"};

    string S1 = JoinString(vString, "## ");

    cout << "Vector after join:\n";
    cout << S1 << endl;

    system("pause>0");


    return 0;
}
