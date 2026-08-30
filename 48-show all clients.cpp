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

void PrintClientRecord(stClient Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber;
    cout << "| " << left << setw(10) << Client.PinCode;
    cout << "| " << left << setw(40) << Client.Name;
    cout << "| " << left << setw(12) << Client.Phone;
    cout << "| " << left << setw(12) << fixed << setprecision(0)<< Client.AccountBalance;
}

void PrintAllClientsData(vector<stClient> vClients)
{
    cout << "\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).\n";
    cout << "------------------------------------------------------------------------------------------------------------" << endl;

   
   cout << "| " << left << setw(15) << "Account Number"
        << "| " << left << setw(10) << "Pin Code"
        << "| " << left << setw(40) << "Client Name"
        << "| " << left << setw(12) << "Phone"
        << "| " << left << setw(12) << "Balance";
    cout << "\n------------------------------------------------------------------------------------------------------------\n" << endl;

    for (stClient Client : vClients)
    {
        PrintClientRecord(Client);
        cout << endl;
    }

    cout << "\n------------------------------------------------------------------------------------------------------------\n" << endl;
}

int main()
{   
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    PrintAllClientsData(vClients);
    system("pause>0");
    return 0;
}
