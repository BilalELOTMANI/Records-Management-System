#include <iostream>
#include <string>
#include <Windows.h> 





void loginVerification()
{
    system("cls");

    string password;

    cout << "\n\n\n\n\n\t\t\t\t\t";
    cout << "\n\n\n\t\t\t\t\tEnter Password : ";

    do
    {
        cin >> password;

        if (password != "member")
        {
            system("cls");
            cout << "\n\n\n\n\n\t\t"
                 << "wrong password!, try again or type 'quit' / 'exit' to Quit The program.";
            cout << "\n\n\n\t\t\t\t\tEnter Password : ";
        }

        if (password == "Quit" || password == "quit" || password == "exit" || password == "Exit" || password == "QUIT" || password == "EXIT")
        {
            system("cls");
            cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQuitting The Program";

            for (int i = 0; i < 4; i++)
            {

                Sleep(1000); // 1 second pause;
                cout << ".";
            }

            exit(0);
        }

    }

    while (password != "member");
    mainMenu();
}
