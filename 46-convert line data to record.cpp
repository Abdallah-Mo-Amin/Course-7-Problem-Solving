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

struct stClint
{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double AccountBalance = 0.0;
};

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

stClint ConvertLineToRecord(string Line, string Seperator="#//#")
{
    stClint Client;

    vector<string> vClientData;

    vClientData = SplitString(Line, Seperator);
    
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); // cast string to double

    return Client;
}

void PrintClientRecord(stClint Client)
{
    cout << "\n\nThe following is the extracted client record:\n";

    cout << "\nAccount Number   : " << Client.AccountNumber;
    cout << "\nPin Code         : " << Client.PinCode;
    cout << "\nName             : " << Client.Name;
    cout << "\nphone            : " << Client.Phone;
    cout << "\nAccount Balance  : " << Client.AccountBalance << endl;
}

int main()
{
    string stLine = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#45215632#//#50000.000000";
    cout << "Line Record is:\n" << stLine << endl;
    
    stClint Clint = ConvertLineToRecord(stLine);
    PrintClientRecord(Clint);

    system("pause>0");


    return 0;
}
