// Password Generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

static const char alphnum[] = "0123456789" "!@#$%^&*" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
int strLen = sizeof(alphnum) - 1;

string generate(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    string tmp_s;
    tmp_s.reserve(len);
    
    for (int i = 0; 1 < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

char GenRand()
{
    return alphnum[rand() % strLen];
}

int main()
{
    HANDLE colorConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int n, c = 0, s = 0;
    char saveFile;

    srand(time(0));
    
    SetConsoleTextAttribute(colorConsole, 10);
    cout << "Password Length (Default - 16): ";
    cin >> n;
    if (n == 0) {
        cout << "Invalid number.";
        sleep_for(milliseconds(1000));
    }
    else {
        SetConsoleTextAttribute(colorConsole, 15);
        cout << "Your Password is: ";
    N:
        char C;
        string D;
        for (int z = 0; z < n; z++)
        {
            C = GenRand();
            D += C;
            if (isdigit(C))
            {
                c++;
            }
            if (C == '!' || C == '@' || C == '$' || C == '%' || C == '^' || C == '&' || C == '*' || C == '#')
            {
                s++;
            }
        }
        if (n > 2 && (s == 0 || c == 0))
        {
            goto N;
        }

        cout << D;
        cout << "\n";
        cout << "\n";

        SetConsoleTextAttribute(colorConsole, 10);
        cout << "Do you want to save your password on a text file? (y/n): ";
        cin >> saveFile;
        if (saveFile == 'y') {
            ofstream myPass("Password.txt");
            myPass << D;
            cout << "Your password is saved on Password.txt!";
        }
        else if (saveFile == 'n') {

        }
        else {
            cout << "Invalid command.";
            sleep_for(milliseconds(1000));
        }

        cout << "\n";
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
