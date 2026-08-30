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
const string ClientsFileName = "Clients.txt";

struct stClient
{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double AccountBalance = 0.0;
};

stClient ReadNewClint()
{
    stClient Client;

    cout << "Enter Account Number? ";

    // usage of std::ws will extract all the whitespace character
    getline(cin >> ws, Client.AccountNumber);

    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}

string ConvertRecordToLine(stClient Clint, string Seperator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += Clint.AccountNumber + Seperator;
    stClientRecord += (Clint.PinCode) + Seperator;
    stClientRecord += Clint.Name + Seperator;
    stClientRecord += Clint.Phone + Seperator;
    stClientRecord += to_string(Clint.AccountBalance);

    return stClientRecord;
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

stClient ConvertLineToRecord(string Line, string Seperator="#//#")
{
    stClient Client;

    vector<string> vClientData;

    vClientData = SplitString(Line, Seperator);
    
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); // cast string to double

    return Client;
}

void PrintClientRecord(stClient Client)
{
    cout << "\n\nThe following is the extracted client record:\n";

    cout << "\nAccount Number   : " << Client.AccountNumber;
    cout << "\nPin Code         : " << Client.PinCode;
    cout << "\nName             : " << Client.Name;
    cout << "\nphone            : " << Client.Phone;
    cout << "\nAccount Balance  : " << Client.AccountBalance << endl;
}

void AddDataLineToFile(string FileName, string stDataLine)
{
    fstream MyFile;

    MyFile.open(FileName, ios::out | ios::app);
    if (MyFile.is_open())
    {
        MyFile << stDataLine << endl;
        MyFile.close();
    }
}

void AddNewClient()
{
    stClient Client;
    Client = ReadNewClint();
    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddClients()
{
    char AddMore = 'Y';

    do
    {
        system("cls");
        cout << "Adding New Client:\n\n";

        AddNewClient();
        cout << "\nClient Added Successfully, do you want to add more clients? ";
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');
}

int main()
{   
    AddClients();

    system("pause>0");
    return 0;
}
