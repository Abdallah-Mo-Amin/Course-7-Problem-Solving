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

bool FindClientByAccountNumber(string AccountNumber, stClient &Client)
{
    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

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

int main()
{   
    stClient Client;
    string AccountNumber = ReadClientAccountNumber();



    if (FindClientByAccountNumber(AccountNumber, Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is not found\n";
    }
    


    system("pause>0");
    return 0;
}
