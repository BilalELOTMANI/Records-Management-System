#include "adminFunction.h"

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

    // File stream objects
    fstream fin, fout;  // fin to read, fout to write

    // Open the existing file
    fin.open("data.csv", ios::in);

    // Create a new file to store the non-deleted data
    fout.open("datanew.csv", ios::out);

    int rollnum, roll1, marks, count = 0, i;
    char sub;
    int index, new_marks;
    string line, word;
    vector<string> row;

    // Get the roll number of the student to be deleted
    cout << "Enter the roll number "
         << "of the record to be deleted: ";
    cin >> rollnum;

    // Check if this record exists
    // If exists, leave it and
    // add all other data to the new file
    while (!fin.eof())
    {

        row.clear();

        getline(fin, line);
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        int row_size = row.size();
        roll1 = stoi(row[0]);

        // writing all records,
        // except the record to be deleted,
        // into the new file 'reportcardnew.csv'
        // using fout pointer
        if (roll1 != rollnum)
        {
            if (!fin.eof())
            {
                for (i = 0; i < row_size - 1; i++)
                {
                    fout << row[i] << ",";
                }
                fout << row[row_size - 1] << "\n";
            }
        }
        else
        {
            count = 1;
        }
        if (fin.eof())
            break;
    }
    if (count == 1)
        cout << "Record deleted\n";
    else
        cout << "Record not found\n";

    // Close the pointers
    fin.close();
    fout.close();

    // removing the existing file
    remove("data.csv");

    // renaming the new file with the existing file name
    rename("datanew.csv", "data.csv");

    Sleep(2000);

    adminFunction();
}


void deleteDataOptimized()
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
    else
        cout << "\t|Enter Data|" << endl
             << endl;

    string rollNumber, name, college, branch, attendance, physics, chemistry, maths;
    string moreData;

    cout << "\nEnter Student's roll Number : ";
    cin >> rollNumber;
    file << "\n"
         << rollNumber << ", ";

    cout << "\nEnter Student's Name : ";
    cin >> name;
    file << name << ", ";

    cout << "\nEnter College : ";
    cin >> college;
    file << college << ", ";

    cout << "\nEnter Branch : ";
    cin >> branch;
    file << branch << ", ";

    cout << "\nEnter Attendance : ";
    cin >> attendance;
    file << attendance << ", ";

    cout << "\nEnter Physic's Record : ";
    cin >> physics;
    file << physics << ", ";

    cout << "\nEnter Chemistry Record : ";
    cin >> chemistry;
    file << chemistry << ", ";

    cout << "\nEnter Maths Record : ";
    cin >> maths;
    file << maths;

    file.close();

    cout << "\nAdd more Record? (Y / N) : ";

    cin >> moreData;
    if (moreData == "y" || moreData == "Y" || moreData == "yes" || moreData == "Yes")
    {
        addData();
    }
    else if (moreData == "n" || moreData == "N" || moreData == "no" || moreData == "No")
        adminFunction();

    else
        cout << "\nEnter a valid option";

    adminFunction();
}


void addDataOptimized()
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

    fstream file("data.csv");

    if (!file.is_open())
    {
        cout << "Error opening file!" << endl;
        return;
    }

    cout << "\n\t\t\t\t\t\t|Students Record| \n\n";

    cout << "\n-----------------------------------------------------------------------------------------------------------------------\n"
         << endl
         << endl;
    cout << "Roll \t Name \t\t\t College \t branch \t Attendance \t Physics \t Chemistry \t Maths" << endl
         << endl;
    string rollNumber, name, college, branch, attendance, physics, chemistry, maths;

    while (!file.eof()) 
    {
        getline(file, rollNumber, ',');
        getline(file, name, ',');
        getline(file, college, ',');
        getline(file, branch, ',');
        getline(file, attendance, ',');
        getline(file, physics, ',');
        getline(file, chemistry, ',');
        getline(file, maths, '\n');

        cout << rollNumber << " \t " << name << "\t\t\t" << college << " \t\t" << branch << " \t\t" << attendance << " \t\t" << physics << " \t\t" << chemistry << " \t\t" << maths << endl;
        cout << endl;
    }

    cout << "\n-----------------------------------------------------------------------------------------------------------------------" << endl;
    file.close();

    adminFunction();
}


void viewDataOptimized()
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

    adminFunction();
}


void studentFunctionOptimized()   // correct function
{
    system("cls");

    fstream file("data.csv");

    if(!file.is_open())
    {
        cout << "Error opening file!" << endl;
        return;
    }

    cout << "Enter your roll number :" << endl;
    cin >> roll;

    string line, word;
    int roll1;
    while(getline(file, line))
    {
        stringstream ss(line);
        getline(ss, word, ',');
        roll1 = stoi(word)
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


void studentFunction()
{

    system("cls");

    fstream file("data.csv");

    if (!file.is_open())
    {
        cout << "Error opening file!" << endl;
        return;
    }
    cout << "\n\t\t\t\t\t\t|Students Record| \n\n";

    cout << "\n-----------------------------------------------------------------------------------------------------------------------\n"
         << endl
         << endl;
    cout << "Roll \t Name \t\t\t College \t branch \t Attendance \t Physics \t Chemistry \t Maths" << endl
         << endl;
    string rollNumber, name, college, branch, attendance, physics, chemistry, maths;

    while (!file.eof()) // file.eof() = detects as how long the file
    {
        getline(file, rollNumber, ',');
        getline(file, name, ',');
        getline(file, college, ',');
        getline(file, branch, ',');
        getline(file, attendance, ',');
        getline(file, physics, ',');
        getline(file, chemistry, ',');
        getline(file, maths, '\n');

        cout << rollNumber << " \t " << name << "\t\t\t" << college << " \t\t" << branch << " \t\t" << attendance << " \t\t" << physics << " \t\t" << chemistry << " \t\t" << maths << endl;
        cout << endl;
    }

    cout << "\n-----------------------------------------------------------------------------------------------------------------------" << endl;
    file.close();
    system("pause");
    mainMenu();
}


