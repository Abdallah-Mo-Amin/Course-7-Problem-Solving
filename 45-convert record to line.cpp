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

stClint ReadNewClint()
{
    stClint Clint;

    cout << "Enter Account Number? ";
    getline(cin, Clint.AccountNumber);

    cout << "Enter PinCode? ";
    getline(cin, Clint.PinCode);

    cout << "Enter Name? ";
    getline(cin, Clint.Name);

    cout << "Enter Phone? ";
    getline(cin, Clint.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Clint.AccountBalance;

    return Clint;
}

string ConvertRecordToLine(stClint Clint, string Seperator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += Clint.AccountNumber + Seperator;
    stClientRecord += (Clint.PinCode) + Seperator;
    stClientRecord += Clint.Name + Seperator;
    stClientRecord += Clint.Phone + Seperator;
    stClientRecord += to_string(Clint.AccountBalance);

    return stClientRecord;
}

int main()
{
    
    stClint Clint;

    cout << "\nPlease Enter Client Data:\n\n";
    Clint = ReadNewClint();

    cout << "\n\nClint Record for saving is:\n";
    cout << ConvertRecordToLine(Clint) << endl;


    system("pause>0");


    return 0;
}
