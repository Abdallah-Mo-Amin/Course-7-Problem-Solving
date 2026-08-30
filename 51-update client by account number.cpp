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
    bool MarkForDelete = false;
};

string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "Please enter Account Number? ";
    getline(cin, AccountNumber);

    return AccountNumber;
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

vector<stClient> LoadClientsDataFromFile(string FileName)
{
    vector<stClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);//read mode


    if (MyFile.is_open())
    {
        string Line;
        stClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return vClients;
}

void PrintClientCard(stClient Client)
{
    cout << "\n\nThe following are the client details:\n";

    cout << "\nAccount Number   : " << Client.AccountNumber;
    cout << "\nPin Code         : " << Client.PinCode;
    cout << "\nName             : " << Client.Name;
    cout << "\nphone            : " << Client.Phone;
    cout << "\nAccount Balance  : " << Client.AccountBalance << endl;
}

bool FindClientByAccountNumber(string AccountNumber, vector <stClient> vClients,stClient &Client)
{

    for (stClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }

    return false;
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

vector <stClient> SaveClientDataToFile(string FileName, vector<stClient> &vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out); // overwrite

    string DataLine;

    if (MyFile.is_open())
    {
        for (stClient& C : vClients)
        {
            if (C.MarkForDelete == false)
            {
                // we only write records that are not marked for delete
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }

        MyFile.close();
    }

    return vClients;
}

stClient ChangeClientRecord(string AccountNumber)
{
    stClient Client;

    Client.AccountNumber = AccountNumber;
     
    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector<stClient> &vClients)
{
    stClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);

        cout << "\n\nAre you sure you want to update this client? y/n ?  ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {            

            for (stClient& C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }

            SaveClientDataToFile(ClientsFileName, vClients);

            cout << "\n\nClient Updated Successfully.\n";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is not found\n";
        return false;
    }
}

int main()
{   
    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);

    system("pause>0");
    return 0;
}
