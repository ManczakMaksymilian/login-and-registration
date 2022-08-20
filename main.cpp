#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <windows.h>

using namespace std;

ofstream file("database.txt");

bool CheckWord(string filename, string search)
{
    int offset;
    string line;
    ifstream Myfile;
    Myfile.open(filename);

    if (Myfile.is_open())
    {
        while (!Myfile.eof())
        {
            getline(Myfile, line);
            if ((offset = line.find(search, 0)) != string::npos)
            {
                // cout << "found '" << search << "' in '" << line << "'" << endl;
                Myfile.close();
                return true;
            }
            else
            {
                // cout << "Not found" << endl;
            }
        }
        Myfile.close();
    }
    else
        cout << "Unable to open this file." << endl;

    return false;
}

void Registration()
{
    string username;
    string password;
    cout << "Provide a new username: ";
    cin >> username;
    cout << "Provide a new password: ";
    cin >> password;

    if (CheckWord("database.txt", username))
    {
        cout << "Username already in use, change it please" << endl;
    }

    file << username << " " << password << endl;
}

void Login()
{
    string username, checkUsername;
    string password, checkPassword;
    cout << "Type a username: ";
    cin >> username;
    cout << "Type a password: ";
    cin >> password;

    if (CheckWord("database.txt", username) && CheckWord("database.txt", password))
        cout << "Logged in" << endl;

    else
        cout << "Failed to log in" << endl;
}

int main()
{
    while (true)
    {
        // choice
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "Choose a number: ";

        int choice;
        cin >> choice;

        // system("cls");

        switch (choice)
        {
        case 1:
            Registration();
            break;
        case 2:
            Login();
            break;
        default:
            cout << "Invalid number";
            break;
        }
    }

    file.close();

    return 0;
    getchar();
}