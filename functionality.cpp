#include "functionality.h"

using namespace std;


void adminFunction()
{
    system("cls");
    cout << "\n\n\t\t\t\t\t | Logged In as Admin |\n";
    cout << "\n\n\t\t\t\t\t 1. Add Students Detail";
    cout << "\n\n\t\t\t\t\t 2. Delete Students";
    cout << "\n\n\t\t\t\t\t 3. View Table ";
    cout << "\n\n\t\t\t\t\t 4. Main Menu ";
    cout << "\n\n\t\t\t\t\t 5. Exit";

    int option;
    cout << "\n\n\t\t\t\t\tEnter choice : ";
    do
    {
        cin >> option;

        {
            switch (option)
            {

            case 1:
                addData();
                break;

            case 2:
                deleteData();
                break;

            case 3:
                viewData();
                break;

            case 4:
                mainMenu();
                break;

            case 5:
                system("cls");
                cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQuitting The Program";

                for (int i = 0; i < 4; i++)
                {

                    Sleep(1000);
                    cout << ".";
                }
                exit(0);
                break;

            default:
                system("cls");
                cout << "\n\n\t\t\t\t\t Logged In as Admin";
                cout << "\n\n\t\t\t\t\t 1. Add Students Record";
                cout << "\n\n\t\t\t\t\t 2. Delete Record";
                cout << "\n\n\t\t\t\t\t 3. View Table ";
                cout << "\n\n\t\t\t\t\t 4. Main Menu ";
                cout << "\n\n\t\t\t\t\t 5. Exit";

                cout << "\n\n\t\t\t\t\t invalid input!";

                cout << "\n\n\t\t\t\t\t Enter choice : ";
            }
        }

    } while (option != '5');
}


void adminVerification()
{
    system("cls");

    string password;

    cout << "\n\n\n\n\n\t\t\t\t\t";
    cout << "\n\n\n\t\t\t\t\tEnter Password : ";

    do
    {
        cin >> password;

        if (password != "admin")
        {
            system("cls");
            cout << "\n\n\n\n\n\t\t"
                 << "wrong password!, try again or type 'menu' to Navigate to Main Menu";
            cout << "\n\n\n\t\t\t\t\tEnter Password : ";
            cin >> password;
        }

        if (password == "Menu" || password == "menu" || password == "MENU")
        {
            mainMenu();
        }

    }

    while (password != "admin");
    adminFunction(); 
}


void mainMenu()
{
    system("cls");

    cout << "\n\n\n\n\t\t\t\t\t Login As : ";
    cout << "\n\n\n\t\t\t\t\t 1. Admin ";
    cout << "\n\n\t\t\t\t\t 2. Student";
    cout << "\n\n\t\t\t\t\t 3. Exit";
    cout << "\n\n\n\t\t\t\t\t Enter your choice : ";

    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        adminVerification();
        break;

    case 2:
        system("cls");

        cout << "Welcome as Student";
        studentFunction();
        break;

    case 3:
        system("cls");
        cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\tQuitting The Program";

        for (int i = 0; i < 4; i++)
        {

            Sleep(1000);
            cout << ".";
        }

        exit(0);
        break;

    default:
        cout << "invalid input";
    }

    system("pause");
}

void deleteData()
{
    system("cls");

    fstream file;
    file.open("data.csv", ios::in); // Open the file for reading

    if (!file.is_open())
    {
        cout << "Error opening file!" << endl;
        return;
    }

    vector<string> rows; 
    string line;
    int rollnum, roll1;
    bool found = false;

    cout << "Enter the roll number of the record to be deleted: ";
    cin >> rollnum;

    while (getline(file, line))
    {
        stringstream ss(line);
        string word;

        getline(ss, word, ','); 
        roll1 = stoi(word);  // Convert word to int

        if (roll1 == rollnum)
        {
            found = true; // Mark that we found the record to delete
        }
        else
        {
            rows.push_back(line); // Store the line if it's not the one to delete
        }
    }

    file.close();

    if (found)
    {
        // Re-open the file for writing (this clears the file content -trunc flag-)
        file.open("data.csv", ios::out | ios::trunc);

        for (const string &row : rows)
        {
            file << row << "\n";
        }

        cout << "Record deleted\n";
    }
    else
    {
        cout << "Record not found\n";
    }

    file.close();

    Sleep(2000);
    adminFunction(); 
}


void addData()
{
    system("cls");
    fstream file("data.csv", ios::out | ios::app);

    if (!file.is_open())
    {
        cout << "Error opening file!" << endl;
        return;
    }

    cout << "\t|Enter Data|\n" << endl;

    string rollNumber, name, college, branch, attendance, physics, chemistry, maths;

    cout << "Enter Student's Roll Number: ";
    cin >> rollNumber;
    cout << "Enter Student's Name: ";
    cin >> name;
    cout << "Enter College: ";
    cin >> college;
    cout << "Enter Branch: ";
    cin >> branch;
    cout << "Enter Attendance: ";
    cin >> attendance;
    cout << "Enter Physics Record: ";
    cin >> physics;
    cout << "Enter Chemistry Record: ";
    cin >> chemistry;
    cout << "Enter Maths Record: ";
    cin >> maths;

    file << rollNumber << ", " << name << ", " << college << ", " << branch << ", "
         << attendance << ", " << physics << ", " << chemistry << ", " << maths << "\n";
    file.close();

    char moreData;
    cout << "\nAdd more Record? (Y/N): ";
    cin >> moreData;

    if (tolower(moreData) == 'y')
    {
        addData();
    }
    else
    {
        adminFunction();
    }
}



void viewData()
{
    system("cls");


    fstream file("data.csv"); // A file pointer to data.csv
    if (!file.is_open())
    {
        cout << "Error opening file!" << endl;
        return;
    }

    cout << "\n\t\t\t\t\t\t| Students Record | \n\n";
    cout << "\n-----------------------------------------------------------------------------------------------------------------------\n" << endl;
    cout << left << setw(8) << "Roll"
         << setw(24) << "Name"
         << setw(16) << "College"
         << setw(16) << "Branch"
         << setw(12) << "Attendance"
         << setw(10) << "Physics"
         << setw(12) << "Chemistry"
         << setw(10) << "Maths" << endl;
    cout << endl;

    string line;
    
    while (getline(file, line)) // Read each line from the file // More effective that the !file.eof condition
    {
        stringstream ss(line);
        string rollNumber, name, college, branch, attendance, physics, chemistry, maths;

        getline(ss, rollNumber, ',');
        getline(ss, name, ',');
        getline(ss, college, ',');
        getline(ss, branch, ',');
        getline(ss, attendance, ',');
        getline(ss, physics, ',');
        getline(ss, chemistry, ',');
        getline(ss, maths, '\n');

        // Output the row with proper formatting
        cout << left << setw(8) << rollNumber
             << setw(24) << name
             << setw(16) << college
             << setw(16) << branch
             << setw(12) << attendance
             << setw(10) << physics
             << setw(12) << chemistry
             << setw(10) << maths << endl;
    }

    cout << "\n-----------------------------------------------------------------------------------------------------------------------" << endl;
    file.close();
    system("Pause");

    adminFunction();
}


void studentFunction()   // correct function
{
    system("cls");

    fstream file("data.csv");

    if(!file.is_open())
    {
        cout << "Error opening file!" << endl;
        return;
    }

    int roll;
    cout << "Enter your roll number :" << endl;
    cin >> roll;

    string line, word;
    int roll1;
    while(getline(file, line))
    {
        stringstream ss(line);
        getline(ss, word, ',');
        roll1 = stoi(word);
        if(roll1 == roll)
        {
            
            cout << "\n\t\t\t\t\t\t| Your Records | \n\n";
            cout << "\n-----------------------------------------------------------------------------------------------------------------------\n" << endl;
    
            string rollNumber, name, college, branch, attendance, physics, chemistry, maths;

            rollNumber = word;
            getline(ss, name, ',');
            getline(ss, college, ',');
            getline(ss, branch, ',');
            getline(ss, attendance, ',');
            getline(ss, physics, ',');
            getline(ss, chemistry, ',');
            getline(ss, maths, '\n');

            // Output the row with proper formatting
            cout << left << setw(8) << rollNumber
                << setw(24) << name
                << setw(16) << college
                << setw(16) << branch
                << setw(12) << attendance
                << setw(10) << physics
                << setw(12) << chemistry
                << setw(10) << maths << endl;

            cout << "\n-----------------------------------------------------------------------------------------------------------------------" << endl;

            break;
        } 
    }
    file.close();
    system("Pause");
    mainMenu();
}

