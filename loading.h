#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void loadingBar()
{
    system("cls");
    system("color 1F");

    // Fetch console width dynamically
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    int barLength = columns / 2; // Loading bar takes half of the screen width
    int loadingPosition = (columns - barLength) / 2; // Center loading bar

    char a = 177, b = 219;

    cout << "\n\n\n\n";
    cout << string((columns - 38) / 2, ' ') << "Student's Records Management System";
    cout << "\n";
    cout << string((columns - 22) / 2, ' ') << "Project By Bilal EL-OTMANI";
    cout << "\n\n\n";
    cout << string((columns - 10) / 2, ' ') << "Loading...\n";
    cout << "\n";
    cout << string(loadingPosition, ' ');

    // Print initial loading bar
    for (int i = 0; i < barLength; i++) cout << a;

    cout << "\r";
    cout << string(loadingPosition, ' ');

    // Progressively fill the loading bar
    for (int i = 0; i < barLength; i++)
    {
        cout << b;
        Sleep(100);
    }

    cout << "\n\n";
}

