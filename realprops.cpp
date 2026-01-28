#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

const int n = 100;

string getField(string record, int field);
void loadUsers(string userName[], string userPass[], int& userCount);
void saveUsers(string userName[], string userPass[], int userCount);
void loadAgents(string agentName[], string agentPass[], int agentAssignedCount[], int agentDoneCount[], 
                int agentPendingCount[], float agentEarnings[], int& agentCount);
void saveAgents(string agentName[], string agentPass[], int agentAssignedCount[], int agentDoneCount[], 
                int agentPendingCount[], float agentEarnings[], int agentCount);
void loadProperties(int ptID[], string ptName[], string ptLocation[], float ptPrice[], 
                    string ptDate[], string ptOwner[], int& propCount);
void saveProperties(int ptID[], string ptName[], string ptLocation[], float ptPrice[], 
                    string ptDate[], string ptOwner[], int propCount);
void loadQueries(int queryptID[], string queryptName[], string queryptLocation[], float queryptPrice[], 
                 string queryptDate[], string queryType[], string queryAssignedAgent[], 
                 string queryUser[], string listStatus[], int& querypropCount);
void saveQueries(int queryptID[], string queryptName[], string queryptLocation[], float queryptPrice[], 
                 string queryptDate[], string queryType[], string queryAssignedAgent[], 
                 string queryUser[], string listStatus[], int querypropCount);
void loadListedProperties(int listptID[], string listptName[], string listptLocation[], 
                          float listptPrice[], string listptDate[], int& listpropCount);
void saveListedProperties(int listptID[], string listptName[], string listptLocation[], 
                          float listptPrice[], string listptDate[], int listpropCount);
void loadBookedProperties(int bookedptID[], string bookedptName[], string bookedptLocation[], 
                          float bookedptPrice[], string bookedptDate[], int& bookedpropCount);
void saveBookedProperties(int bookedptID[], string bookedptName[], string bookedptLocation[], 
                          float bookedptPrice[], string bookedptDate[], int bookedpropCount);
void loadRentedProperties(int rentptID[], string rentptName[], string rentptLocation[], 
                          float rentptPrice[], string rentptDate[], int& rentpropCount);
void saveRentedProperties(int rentptID[], string rentptName[], string rentptLocation[], 
                          float rentptPrice[], string rentptDate[], int rentpropCount);

void menuHeading(string heading);
void setupConsoleUI();
int mainMenuModules(string userName[], string userPass[], int& userCount,
                    int ptID[], string ptName[], string ptLocation[], float ptPrice[], string ptDate[], string ptOwner[], int& propCount,
                    int bookedptID[], string bookedptName[], string bookedptLocation[], float bookedptPrice[], string bookedptDate[], int& bookedpropCount,
                    int rentptID[], string rentptName[], string rentptLocation[], float rentptPrice[], string rentptDate[], int& rentpropCount,
                    int listptID[], string listptName[], string listptLocation[], float listptPrice[], string listptDate[], int& listpropCount,
                    int queryptID[], string queryptName[], string queryptLocation[], float queryptPrice[], string queryptDate[], 
                    string queryType[], string queryAssignedAgent[], string queryUser[], string listStatus[], int& querypropCount,
                    string agentName[], string agentPass[], int agentAssignedCount[], int agentDoneCount[], int agentPendingCount[], 
                    float agentEarnings[], int& agentCount, float& companyEarnings, string& currentUser);

int adminModules(string userName[], string userPass[], int& userCount,
                 int ptID[], string ptName[], string ptLocation[], float ptPrice[], string ptDate[], string ptOwner[], int& propCount,
                 int queryptID[], string queryptName[], string queryptLocation[], float queryptPrice[], string queryptDate[],
                 string queryType[], string queryAssignedAgent[], string queryUser[], string listStatus[], int& querypropCount,
                 string agentName[], string agentPass[], int agentAssignedCount[], int agentDoneCount[], int agentPendingCount[],
                 float agentEarnings[], int& agentCount, float& companyEarnings);

int userModules(int ptID[], string ptName[], string ptLocation[], float ptPrice[], string ptDate[], string ptOwner[], int& propCount,
                int bookedptID[], string bookedptName[], string bookedptLocation[], float bookedptPrice[], string bookedptDate[], int& bookedpropCount,
                int rentptID[], string rentptName[], string rentptLocation[], float rentptPrice[], string rentptDate[], int& rentpropCount,
                int listptID[], string listptName[], string listptLocation[], float listptPrice[], string listptDate[], int& listpropCount,
                int queryptID[], string queryptName[], string queryptLocation[], float queryptPrice[], string queryptDate[],
                string queryType[], string queryAssignedAgent[], string queryUser[], string listStatus[], int& querypropCount,
                string& currentUser);

int agentModules(int queryptID[], string queryptName[], string queryptLocation[], float queryptPrice[], string queryptDate[],
                 string queryType[], string queryAssignedAgent[], string queryUser[], string listStatus[], int& querypropCount,
                 string agentName[], string agentPass[], int agentAssignedCount[], int agentDoneCount[], int agentPendingCount[],
                 float agentEarnings[], int& agentCount, float& companyEarnings, string& currentUser);

int agentMenu();
int mainMenu();
void setColor(int color);
void printHeader();
void printProps(int rowIndex, int id, string name, string location, float price, string date);
int adminMenu();
int userMenu();
void tableMenu(int rowIndex);
void gotoxy(int x, int y);
string getCurrentDate();
void drawHeader(int x, int y);
void slideHeaderUp(int startX, int startY, int endY);
void loader();



int main()
{
    system("cls");
    setupConsoleUI();
    loader();
    Sleep(500);

    string userName[n];
    string userPass[n];
    int userCount = 0;
    
    int ptID[n];
    string ptName[n];
    string ptLocation[n];
    float ptPrice[n];
    string ptDate[n];
    string ptOwner[n];
    int propCount = 0;
    
    int bookedptID[n];
    string bookedptName[n];
    string bookedptLocation[n];
    float bookedptPrice[n];
    string bookedptDate[n];
    int bookedpropCount = 0;
    
    int listptID[n];
    string listptName[n];
    string listptLocation[n];
    float listptPrice[n];
    string listptDate[n];
    int listpropCount = 0;
    
    int rentptID[n];
    string rentptName[n];
    string rentptLocation[n];
    float rentptPrice[n];
    string rentptDate[n];
    int rentpropCount = 0;
    
    int queryptID[n];
    string queryptName[n];
    string queryptLocation[n];
    float queryptPrice[n];
    string queryptDate[n];
    string queryType[n];
    string queryAssignedAgent[n];
    string queryUser[n];
    string listStatus[n];
    int querypropCount = 0;
    
    string currentUser = "";
    
    int agentCount = 0;
    string agentName[n];
    string agentPass[n];
    int agentAssignedCount[n];
    int agentDoneCount[n];
    int agentPendingCount[n];
    float agentEarnings[n];
    
    for(int i = 0; i < n; i++) {
        ptID[i] = 0;
        ptPrice[i] = 0;
        bookedptID[i] = 0;
        bookedptPrice[i] = 0;
        listptID[i] = 0;
        listptPrice[i] = 0;
        rentptID[i] = 0;
        rentptPrice[i] = 0;
        queryptID[i] = 0;
        queryptPrice[i] = 0;
        agentAssignedCount[i] = 0;
        agentDoneCount[i] = 0;
        agentPendingCount[i] = 0;
        agentEarnings[i] = 0.0;
    }
    
    float companyEarnings = 0.0;
    
    loadUsers(userName, userPass, userCount);
    loadAgents(agentName, agentPass, agentAssignedCount, agentDoneCount, agentPendingCount, agentEarnings, agentCount);
    loadProperties(ptID, ptName, ptLocation, ptPrice, ptDate, ptOwner, propCount);
    loadQueries(queryptID, queryptName, queryptLocation, queryptPrice, queryptDate, queryType, queryAssignedAgent, queryUser, listStatus, querypropCount);
    loadListedProperties(listptID, listptName, listptLocation, listptPrice, listptDate, listpropCount);
    loadBookedProperties(bookedptID, bookedptName, bookedptLocation, bookedptPrice, bookedptDate, bookedpropCount);
    loadRentedProperties(rentptID, rentptName, rentptLocation, rentptPrice, rentptDate, rentpropCount);
    
    
    mainMenuModules(userName, userPass, userCount,
                    ptID, ptName, ptLocation, ptPrice, ptDate, ptOwner, propCount,
                    bookedptID, bookedptName, bookedptLocation, bookedptPrice, bookedptDate, bookedpropCount,
                    rentptID, rentptName, rentptLocation, rentptPrice, rentptDate, rentpropCount,
                    listptID, listptName, listptLocation, listptPrice, listptDate, listpropCount,
                    queryptID, queryptName, queryptLocation, queryptPrice, queryptDate,
                    queryType, queryAssignedAgent, queryUser, listStatus, querypropCount,
                    agentName, agentPass, agentAssignedCount, agentDoneCount, agentPendingCount,
                    agentEarnings, agentCount, companyEarnings, currentUser);
    
    return 0;
}

string getCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int day = ltm->tm_mday;
    int month = 1 + ltm->tm_mon;
    int year = 1900 + ltm->tm_year;
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

string getField(string record, int field)
{
    int commaCount = 1;
    string item;
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}

void loadUsers(string userName[], string userPass[], int& userCount)
{
    string record;
    fstream data;
    data.open("users.txt", ios::in);
    userCount = 0;
    
    if(data.is_open())
    {
        while (getline(data, record))
        {
            if(record.length() > 0)
            {
                userName[userCount] = getField(record, 1);
                userPass[userCount] = getField(record, 2);
                userCount++;
            }
        }
        data.close();
    }
}

void saveUsers(string userName[], string userPass[], int userCount)
{
    fstream data;
    data.open("users.txt", ios::out);
    
    for(int i = 0; i < userCount; i++)
    {
        data << userName[i] << "," << userPass[i] << endl;
    }
    
    data.close();
}

void loadAgents(string agentName[], string agentPass[], int agentAssignedCount[], int agentDoneCount[], 
                int agentPendingCount[], float agentEarnings[], int& agentCount)
{
    string record;
    fstream data;
    data.open("agents.txt", ios::in);
    agentCount = 0;
    
    if(data.is_open())
    {
        while (getline(data, record) && agentCount < n)
        {
            if(record.length() > 0)
            {
                agentName[agentCount] = getField(record, 1);
                agentPass[agentCount] = getField(record, 2);
                string assigned = getField(record, 3);
                if (assigned == "") {
                    agentAssignedCount[agentCount] = 0;
                } else {
                    agentAssignedCount[agentCount] = stoi(assigned);
                }
                string done = getField(record, 4);
                if (done == "") {
                    agentDoneCount[agentCount] = 0;
                } else {
                    agentDoneCount[agentCount] = stoi(done);
                }
                string pending = getField(record, 5);
                if (pending == "") {
                    agentPendingCount[agentCount] = 0;
                } else {
                    agentPendingCount[agentCount] = stoi(pending);
                }
                string earnings = getField(record, 6);
                if (earnings == "") {
                    agentEarnings[agentCount] = 0.0;
                } else {
                    agentEarnings[agentCount] = stof(earnings);
                }
                agentCount++;
            }
        }
        data.close();
    }
}

void saveAgents(string agentName[], string agentPass[], int agentAssignedCount[], int agentDoneCount[], 
                int agentPendingCount[], float agentEarnings[], int agentCount)
{
    fstream data;
    data.open("agents.txt", ios::out);
    
    for(int i = 0; i < agentCount; i++)
    {
        data << agentName[i] << "," << agentPass[i] << "," 
             << agentAssignedCount[i] << "," << agentDoneCount[i] << "," 
             << agentPendingCount[i] << "," << agentEarnings[i] << endl;
    }
    
    data.close();
}

void loadProperties(int ptID[], string ptName[], string ptLocation[], float ptPrice[], 
                    string ptDate[], string ptOwner[], int& propCount)
{
    string record;
    fstream data;
    data.open("properties.txt", ios::in);
    propCount = 0;
    
    if(data.is_open())
    {
        while (getline(data, record))
        {
            if(record.length() > 0)
            {
                ptID[propCount] = stoi(getField(record, 1));
                ptName[propCount] = getField(record, 2);
                ptLocation[propCount] = getField(record, 3);
                ptPrice[propCount] = stof(getField(record, 4));
                ptDate[propCount] = getField(record, 5);
                ptOwner[propCount] = getField(record, 6);
                propCount++;
            }
        }
        data.close();
    }
}

void saveProperties(int ptID[], string ptName[], string ptLocation[], float ptPrice[], 
                    string ptDate[], string ptOwner[], int propCount)
{
    fstream data;
    data.open("properties.txt", ios::out);
    
    for(int i = 0; i < propCount; i++)
    {
        if(ptID[i] != 0)
        {
            data << ptID[i] << "," << ptName[i] << "," << ptLocation[i] << "," 
                 << ptPrice[i] << "," << ptDate[i] << "," << ptOwner[i] << endl;
        }
    }
    
    data.close();
}

void loadQueries(int queryptID[], string queryptName[], string queryptLocation[], float queryptPrice[], 
                 string queryptDate[], string queryType[], string queryAssignedAgent[], 
                 string queryUser[], string listStatus[], int& querypropCount)
{
    string record;
    fstream data;
    data.open("queries.txt", ios::in);
    querypropCount = 0;
    
    if(data.is_open())
    {
        while (getline(data, record))
        {
            if(record.length() > 0)
            {
                queryptID[querypropCount] = stoi(getField(record, 1));
                queryptName[querypropCount] = getField(record, 2);
                queryptLocation[querypropCount] = getField(record, 3);
                queryptPrice[querypropCount] = stof(getField(record, 4));
                queryptDate[querypropCount] = getField(record, 5);
                queryType[querypropCount] = getField(record, 6);
                queryAssignedAgent[querypropCount] = getField(record, 7);
                queryUser[querypropCount] = getField(record, 8);
                listStatus[querypropCount] = getField(record, 9);
                querypropCount++;
            }
        }
        data.close();
    }
}

void saveQueries(int queryptID[], string queryptName[], string queryptLocation[], float queryptPrice[], 
                 string queryptDate[], string queryType[], string queryAssignedAgent[], 
                 string queryUser[], string listStatus[], int querypropCount)
{
    fstream data;
    data.open("queries.txt", ios::out);
    
    for(int i = 0; i < querypropCount; i++)
    {
        if(queryptID[i] != 0)
        {
            data << queryptID[i] << "," << queryptName[i] << "," << queryptLocation[i] << "," 
                 << queryptPrice[i] << "," << queryptDate[i] << "," << queryType[i] << "," 
                 << queryAssignedAgent[i] << "," << queryUser[i] << "," << listStatus[i] << endl;
        }
    }
    
    data.close();
}

void loadListedProperties(int listptID[], string listptName[], string listptLocation[], 
                          float listptPrice[], string listptDate[], int& listpropCount)
{
    string record;
    fstream data;
    data.open("listedProperties.txt", ios::in);
    listpropCount = 0;
    
    if(data.is_open())
    {
        while (getline(data, record))
        {
            if(record.length() > 0)
            {
                listptID[listpropCount] = stoi(getField(record, 1));
                listptName[listpropCount] = getField(record, 2);
                listptLocation[listpropCount] = getField(record, 3);
                listptPrice[listpropCount] = stof(getField(record, 4));
                listptDate[listpropCount] = getField(record, 5);
                listpropCount++;
            }
        }
        data.close();
    }
}

void saveListedProperties(int listptID[], string listptName[], string listptLocation[], 
                          float listptPrice[], string listptDate[], int listpropCount)
{
    fstream data;
    data.open("listedProperties.txt", ios::out);
    
    for(int i = 0; i < listpropCount; i++)
    {
        if(listptID[i] != 0)
        {
            data << listptID[i] << "," << listptName[i] << "," << listptLocation[i] << "," 
                 << listptPrice[i] << "," << listptDate[i] << endl;
        }
    }
    
    data.close();
}

void loadBookedProperties(int bookedptID[], string bookedptName[], string bookedptLocation[], 
                          float bookedptPrice[], string bookedptDate[], int& bookedpropCount)
{
    string record;
    fstream data;
    data.open("bookedProperties.txt", ios::in);
    bookedpropCount = 0;
    
    if(data.is_open())
    {
        while (getline(data, record))
        {
            if(record.length() > 0)
            {
                bookedptID[bookedpropCount] = stoi(getField(record, 1));
                bookedptName[bookedpropCount] = getField(record, 2);
                bookedptLocation[bookedpropCount] = getField(record, 3);
                bookedptPrice[bookedpropCount] = stof(getField(record, 4));
                bookedptDate[bookedpropCount] = getField(record, 5);
                bookedpropCount++;
            }
        }
        data.close();
    }
}

void saveBookedProperties(int bookedptID[], string bookedptName[], string bookedptLocation[], 
                          float bookedptPrice[], string bookedptDate[], int bookedpropCount)
{
    fstream data;
    data.open("bookedProperties.txt", ios::out);
    
    for(int i = 0; i < bookedpropCount; i++)
    {
        if(bookedptID[i] != 0)
        {
            data << bookedptID[i] << "," << bookedptName[i] << "," << bookedptLocation[i] << "," 
                 << bookedptPrice[i] << "," << bookedptDate[i] << endl;
        }
    }
    
    data.close();
}

void loadRentedProperties(int rentptID[], string rentptName[], string rentptLocation[], 
                          float rentptPrice[], string rentptDate[], int& rentpropCount)
{
    string record;
    fstream data;
    data.open("rentedProperties.txt", ios::in);
    rentpropCount = 0;
    
    if(data.is_open())
    {
        while (getline(data, record))
        {
            if(record.length() > 0)
            {
                rentptID[rentpropCount] = stoi(getField(record, 1));
                rentptName[rentpropCount] = getField(record, 2);
                rentptLocation[rentpropCount] = getField(record, 3);
                rentptPrice[rentpropCount] = stof(getField(record, 4));
                rentptDate[rentpropCount] = getField(record, 5);
                rentpropCount++;
            }
        }
        data.close();
    }
}

void saveRentedProperties(int rentptID[], string rentptName[], string rentptLocation[], 
                          float rentptPrice[], string rentptDate[], int rentpropCount)
{
    fstream data;
    data.open("rentedProperties.txt", ios::out);
    
    for(int i = 0; i < rentpropCount; i++)
    {
        if(rentptID[i] != 0)
        {
            data << rentptID[i] << "," << rentptName[i] << "," << rentptLocation[i] << "," 
                 << rentptPrice[i] << "," << rentptDate[i] << endl;
        }
    }
    
    data.close();
}

int mainMenuModules(string userName[], string userPass[], int& userCount,
                    int ptID[], string ptName[], string ptLocation[], float ptPrice[], string ptDate[], string ptOwner[], int& propCount,
                    int bookedptID[], string bookedptName[], string bookedptLocation[], float bookedptPrice[], string bookedptDate[], int& bookedpropCount,
                    int rentptID[], string rentptName[], string rentptLocation[], float rentptPrice[], string rentptDate[], int& rentpropCount,
                    int listptID[], string listptName[], string listptLocation[], float listptPrice[], string listptDate[], int& listpropCount,
                    int queryptID[], string queryptName[], string queryptLocation[], float queryptPrice[], string queryptDate[],
                    string queryType[], string queryAssignedAgent[], string queryUser[], string listStatus[], int& querypropCount,
                    string agentName[], string agentPass[], int agentAssignedCount[], int agentDoneCount[], int agentPendingCount[],
                    float agentEarnings[], int& agentCount, float& companyEarnings, string& currentUser)
{
    while (true)
    {
        system("cls");
        printHeader();
        int option = mainMenu();

        if (option == 1)
        {
            system("cls");
            printHeader();
            int signY = 22;
            gotoxy(71, signY);
            cout << ">>           Sign Up          <<";
            
            gotoxy(71, signY + 2);
            cout << "Enter User Name";
            gotoxy(71, signY + 3);
            setColor(11);
            cout << "--------------------------------";
            gotoxy(71, signY + 5);
            cout << "--------------------------------";
            setColor(7);
            gotoxy(71, signY + 4);  
            
            string name;
            getline(cin, name);

            bool duplicate = true;
            while (duplicate)
            {
                duplicate = false;
                for (int i = 0; i < userCount || i<agentCount; i++)
                {
                    if (userName[i] == name || name == "" || name == "admin" || name == agentName[i])
                    {
                        duplicate = true;
                        setColor(4);
                        gotoxy(71, signY + 6);
                        cout << "Username already exists!" << endl;
                        setColor(7);
                        gotoxy(71, signY + 2);
                        cout << "Enter User Name";
                        gotoxy(71, signY + 3);
                        setColor(11);
                        cout << "--------------------------------";
                        gotoxy(71, signY + 5);
                        cout << "--------------------------------";
                        setColor(7);
                        gotoxy(71, signY + 4);
                        getline(cin, name);
                        break;
                    }
                }
            }

            userName[userCount] = name;
            gotoxy(71, signY + 6);
            cout << "                        " << endl;
            gotoxy(71, signY + 6);
            cout << "Enter Password: ";
            gotoxy(71, signY + 7);
            setColor(11);
            cout << "--------------------------------";
            gotoxy(71, signY + 9);
            cout << "--------------------------------";
            setColor(7);
            gotoxy(71, signY + 8);
            getline(cin, userPass[userCount]);
            userCount++;

            saveUsers(userName, userPass, userCount);

            setColor(2);
            gotoxy(71, signY + 10);
            cout << "Sign up successful!" << endl;
            setColor(7);
        }
        else if (option == 2)
        {
            string loginName, loginPass;
            system("cls");
            printHeader();

            int logY = 22;
            gotoxy(71, logY);
            cout << ">>            Login           <<";
            bool found = false;
            
            gotoxy(71, logY + 2);
            cout << "Enter User Name: ";
            gotoxy(71, logY + 3);
            setColor(11);
            cout << "--------------------------------";
            gotoxy(71, logY + 5);
            cout << "--------------------------------";
            setColor(7);
            gotoxy(71, logY + 4);
            getline(cin, loginName);
            gotoxy(71, logY + 6);
            cout << "Enter Password: ";
            gotoxy(71, logY + 7);
            setColor(11);
            cout << "--------------------------------";
            gotoxy(71, logY + 9);
            cout << "--------------------------------";
            setColor(7);
            gotoxy(71, logY + 8);
            getline(cin, loginPass);

            if (loginName == "admin" && loginPass == "123")
            {
                found = true;
                system("cls");
                printHeader();
                gotoxy(33, 15);
                cout << "ADMIN ENTERED";
                Sleep(1000);
                system("cls");
                adminModules(userName, userPass, userCount,
                           ptID, ptName, ptLocation, ptPrice, ptDate, ptOwner, propCount,
                           queryptID, queryptName, queryptLocation, queryptPrice, queryptDate,
                           queryType, queryAssignedAgent, queryUser, listStatus, querypropCount,
                           agentName, agentPass, agentAssignedCount, agentDoneCount, agentPendingCount,
                           agentEarnings, agentCount, companyEarnings);
            }

            if (!found)
            {
                for (int i = 0; i < agentCount; i++)
                {
                    if (loginName == agentName[i] && loginPass == agentPass[i])
                    {
                        found = true;
                        currentUser = loginName;
                        system("cls");
                        printHeader();
                        gotoxy(33, 15);
                        cout << "AGENT ENTERED";
                        Sleep(1000);
                        system("cls");
                        agentModules(queryptID, queryptName, queryptLocation, queryptPrice, queryptDate,
                                   queryType, queryAssignedAgent, queryUser, listStatus, querypropCount,
                                   agentName, agentPass, agentAssignedCount, agentDoneCount, agentPendingCount,
                                   agentEarnings, agentCount, companyEarnings, currentUser);
                        break;
                    }
                }
            }

            if (!found)
            {
                for (int i = 0; i < userCount; i++)
                {
                    if (loginName == userName[i] && loginPass == userPass[i])
                    {
                        found = true;
                        system("cls");
                        printHeader();
                        gotoxy(33, 15);
                        cout << "USER ENTERED";
                        Sleep(1000);
                        system("cls");
                        currentUser = loginName;
                        userModules(ptID, ptName, ptLocation, ptPrice, ptDate, ptOwner, propCount,
                                  bookedptID, bookedptName, bookedptLocation, bookedptPrice, bookedptDate, bookedpropCount,
                                  rentptID, rentptName, rentptLocation, rentptPrice, rentptDate, rentpropCount,
                                  listptID, listptName, listptLocation, listptPrice, listptDate, listpropCount,
                                  queryptID, queryptName, queryptLocation, queryptPrice, queryptDate,
                                  queryType, queryAssignedAgent, queryUser, listStatus, querypropCount, currentUser);
                        break;
                    }
                }
            }

            if (!found)
            {
                setColor(4);
                gotoxy(71, logY + 10);
                cout << "Invalid Information";
                setColor(7);
            }
        }
        else if (option == 3)
        {
            gotoxy(71, 36);
            cout << "Thank you for using RealProps!" << endl;
            // return 0;
            exit(0);
        }

        gotoxy(71, 36);
        setColor(96);
        cout << "Press any key to continue.......";
        setColor(7);
        getch();
    }
    return 0;
}

int adminModules(string userName[], string userPass[], int& userCount,
                 int ptID[], string ptName[], string ptLocation[], float ptPrice[], string ptDate[], string ptOwner[], int& propCount,
                 int queryptID[], string queryptName[], string queryptLocation[], float queryptPrice[], string queryptDate[],
                 string queryType[], string queryAssignedAgent[], string queryUser[], string listStatus[], int& querypropCount,
                 string agentName[], string agentPass[], int agentAssignedCount[], int agentDoneCount[], int agentPendingCount[],
                 float agentEarnings[], int& agentCount, float& companyEarnings)
{
    int option;
    while (true)
    {
        system("cls");
        printHeader();
        option = adminMenu();

        if (option == 1)
        {
            system("cls");
            printHeader();
            menuHeading(">>      Add New Property      <<");

            if (propCount >= n)
            {
                gotoxy(71, 17);
                setColor(4);
                cout << "Maximum Memory Reached!" << endl;
                setColor(7);
            }
            else
            {
                int newID;
                bool duplicate = false;
                gotoxy(71, 17);
                cout << "Enter ID of Property: ";
                gotoxy(71, 18);
                setColor(11);
                cout << "--------------------------------";
                gotoxy(71, 20);
                cout << "--------------------------------";
                setColor(7);
                gotoxy(71, 19);
                cin >> newID;
                cin.ignore();


                for (int i = 0; i < propCount; i++)
                {
                    if (ptID[i] == newID)
                    {
                        duplicate = true;
                        break;
                    }
                }

                if (duplicate)
                {
                    setColor(4);
                    gotoxy(71, 21);
                    cout << "Property ID Already Exists!" << endl;
                    setColor(7);
                }
                else
                {
                    ptID[propCount] = newID;

                    
                    gotoxy(71, 21);
                    cout << "Enter Name of Property: ";
                    gotoxy(71, 22);
                    setColor(11);
                    cout << "--------------------------------";
                    gotoxy(71, 24);
                    cout << "--------------------------------";
                    setColor(7);
                    gotoxy(71, 23);
                    getline(cin, ptName[propCount]);
                    gotoxy(71, 25);
                    cout << "Enter Location of Property: ";
                    gotoxy(71, 26);
                    setColor(11);
                    cout << "--------------------------------";
                    gotoxy(71, 28);
                    cout << "--------------------------------";
                    setColor(7);
                    gotoxy(71, 27);
                    getline(cin, ptLocation[propCount]);
                    gotoxy(71, 29);
                    cout << "Enter Price of Property: ";
                    gotoxy(71, 30);
                    setColor(11);
                    cout << "--------------------------------";
                    gotoxy(71, 32);
                    cout << "--------------------------------";
                    setColor(7);
                    gotoxy(71, 31);
                    cin >> ptPrice[propCount];
                cin.ignore();


                    ptDate[propCount] = getCurrentDate();
                    ptOwner[propCount] = "admin";

                    propCount++;

                    saveProperties(ptID, ptName, ptLocation, ptPrice, ptDate, ptOwner, propCount);

                    setColor(2);
                    gotoxy(71, 34);
                    cout << "Property Added Successfully!" << endl;
                    setColor(7);
                }
            }
            gotoxy(0, 36);
        }
        else if (option == 2)
        {
            system("cls");
            printHeader();
            menuHeading(">>       All Properties      <<");

            if (propCount == 0)
            {
                setColor(4);
                gotoxy(71,17);
                cout << "No properties available!" << endl;
                setColor(7);
            }
            else
            {
                int row=0;
                tableMenu(17);
                for (int i = 0; i < propCount; i++)
                {
                    printProps(row, ptID[i], ptName[i], ptLocation[i], ptPrice[i], ptDate[i]);
                    row++;
                }
            }
        }
        else if (option == 3)
        {
            string searchName = "";
            while (true)
            {
                system("cls");
                printHeader();
                menuHeading(">>       Search Property      <<");

                gotoxy(71, 17);
                cout << "Enter Property Name to Search: ";
                gotoxy(71, 18);
                cout << "--------------------------------";
                gotoxy(71, 20);
                cout << "--------------------------------";
                gotoxy(71, 19);
                cout << searchName;


                tableMenu(23);
                int row = 0;
                bool found = false;
                for (int i = 0; i < propCount; i++)
                {
                    {
                        bool match = true;
                        if (searchName != "")
                        {
                            match = false;
                            int len = searchName.length();
                            int plen = ptName[i].length();
                            if (plen >= len)
                            {
                                for (int j = 0; j <= plen - len; ++j)
                                {
                                    bool found_match = true;
                                    for (int k = 0; k < len; ++k)
                                    {
                                        if (tolower(ptName[i][j + k]) != tolower(searchName[k]))
                                        {
                                            found_match = false;
                                            break;
                                        }
                                    }
                                    if (found_match)
                                    {
                                        match = true;
                                        break;
                                    }
                                }
                            }
                        }
                        if (match)
                        {
                            printProps(row + 2, ptID[i], ptName[i], ptLocation[i], ptPrice[i], ptDate[i]);
                            row++;
                            found = true;
                        }
                    }
                }
                if (!found && searchName != "")
                {
                    gotoxy(71, 19);
                    setColor(4);
                    cout << searchName;
                    setColor(7);
                }

                char ch = _getch();
                if (ch == 13) 
                {
                    break;
                }
                else if (ch == 8) 
                {
                    if (searchName != "")
                    {
                        string temp = "";
                        for (int i = 0; i < searchName.length() - 1; i++)
                        {
                            temp += searchName[i];
                        }
                        searchName = temp;
                    }
                }
                else if (ch >= 32 && ch <= 126) 
                {
                    searchName += ch;
                }
            }
        }
        else if (option == 4)
        {
            system("cls");
            printHeader();
            menuHeading(">>       Delete Property      <<");
            int del;
            gotoxy(71, 17);
            cout << "Enter ID of Property to Delete: ";
            gotoxy(71, 18);
            cout << "--------------------------------";
            gotoxy(71, 20);
            cout << "--------------------------------";
            gotoxy(71, 19);
            cin >> del;
                cin.ignore();

            bool found = false;
            for (int i = 0; i < propCount; i++)
            {
                if (ptID[i] == del)
                {
                    for (int j = i; j < propCount - 1; j++)
                    {
                        ptID[j] = ptID[j + 1];
                        ptName[j] = ptName[j + 1];
                        ptLocation[j] = ptLocation[j + 1];
                        ptPrice[j] = ptPrice[j + 1];
                        ptDate[j] = ptDate[j + 1];
                        ptOwner[j] = ptOwner[j + 1];
                    }
                    propCount--;  
                    found = true;
                    saveProperties(ptID, ptName, ptLocation, ptPrice, ptDate, ptOwner, propCount);
                    setColor(2);
                    gotoxy(71, 21);
                    cout << "Property Deleted Successfully!" << endl;
                    setColor(7);
                    break;
                }
            }
            if (!found)
            {
                setColor(4);
                gotoxy(71, 21);
                cout << "Property Not Found" << endl;
                setColor(7);
            }
        }
        else if (option == 5)
        {
            system("cls");
            printHeader();
            menuHeading(">>       Update Property      <<");
            int update;
            gotoxy(71, 17);
            cout << "Enter ID of Property to Update: ";
            gotoxy(71, 18);
            cout << "--------------------------------";
            gotoxy(71, 20);
            cout << "--------------------------------";
            gotoxy(71, 19);
            cin >> update;
                cin.ignore();

            bool found = false;
            for (int i = 0; i < propCount; i++)
            {
                if (ptID[i] == update)
                {
                    found = true;
                    
                    gotoxy(71, 21);
                    cout << "Enter New Name of Property: ";
                    gotoxy(71, 22);
                    cout << "--------------------------------";
                    gotoxy(71, 24);
                    cout << "--------------------------------";
                    gotoxy(71, 23);
                    getline(cin, ptName[i]);

                    gotoxy(71, 25);
                    cout << "Enter New Location of Property: ";
                    gotoxy(71, 26);
                    cout << "--------------------------------";
                    gotoxy(71, 28);
                    cout << "--------------------------------";
                    gotoxy(71, 27);
                    getline(cin, ptLocation[i]);

                    gotoxy(71, 29);
                    cout << "Enter New Price of Property: $";
                    gotoxy(71, 30);
                    cout << "--------------------------------";
                    gotoxy(71, 32);
                    cout << "--------------------------------";
                    gotoxy(71, 31);
                    cin >> ptPrice[i];
                cin.ignore();


                    ptDate[i] = getCurrentDate();

                    saveProperties(ptID, ptName, ptLocation, ptPrice, ptDate, ptOwner, propCount);

                    setColor(2);
                    gotoxy(71, 34);
                    cout << "Property Updated Successfully!" << endl;
                    setColor(7);
                    break;
                }
            }
            if (!found)
            {
                setColor(4);
                gotoxy(71, 21);
                cout << "Property Not Found" << endl;
                setColor(7);
            }
        }
        else if (option == 6)
        {
            system("cls");
            printHeader();
            menuHeading(">>         All Queries        <<");

            if (querypropCount == 0)
            {
                setColor(4);
                gotoxy(71, 17);
                cout << "No queries available!" << endl;
                setColor(7);
            }
            else
            {
                gotoxy(26+(61-33), 17);
                cout << left << setw(8) << "ID"
                     << setw(18) << "Username"
                     << setw(10) << "Type"
                     << setw(15) << "Agent"
                     << setw(15) << "Status" << endl;
                gotoxy(26+(61-33), 18);
                cout << "-----------------------------------------------------------------" << endl;

                for (int i = 0; i < querypropCount; i++)
                {
                    if (queryptID[i] != 0)
                    {
                        gotoxy(26+(61-33), 19 + i);
                        setColor(96);
                        cout << left << setw(8) << queryptID[i];
                        cout << left << setw(18) << queryUser[i];
                        cout << setw(10) << queryType[i];

                        if (queryAssignedAgent[i] == "")
                        {
                            cout << setw(15) << "None";
                            cout << setw(15) << "Pending";
                        }
                        else
                        {
                            cout << setw(15) << queryAssignedAgent[i];
                            cout << setw(15) << listStatus[i];
                        }
                        cout << endl;
                        setColor(7);
                    }
                }
            }
        }
        else if (option == 7)
        {
            system("cls");
            printHeader();
            menuHeading(">>       Sold Properties      <<");

            bool foundSold = false;
            gotoxy(26+(61-40), 17);
            cout << left << setw(8) << "ID"
                 << setw(20) << "Property"
                 << setw(18) << "Client"
                 << setw(18) << "Agent"
                 << setw(12) << "Price"
                 << setw(12) << "Date" << endl;
            gotoxy(26+(61-40), 18);
            cout << "--------------------------------------------------------------------------------" << endl;

            int row = 0;
            for (int i = 0; i < querypropCount; i++)
            {
                if (queryptID[i] != 0 && queryType[i] == "Booked" && listStatus[i] == "Done")
                {
                    gotoxy(26+(61-40), 19 + row);
                    setColor(96);
                    cout << left << setw(8) << queryptID[i]
                         << setw(20) << queryptName[i]
                         << setw(18) << queryUser[i]
                         << setw(18) << queryAssignedAgent[i]
                         << setw(12) << fixed << setprecision(2) << queryptPrice[i]
                         << setw(12) << queryptDate[i] << endl;
                    setColor(7);
                    foundSold = true;
                    row++;
                }
            }

            if (!foundSold)
            {
                setColor(4);
                gotoxy(26+(61-40), 19);
                cout << "No sold properties found!" << endl;
                setColor(7);
            }
        }
        else if (option == 8)
        {
            system("cls");
            printHeader();
            menuHeading(">>        Add New Agent       <<");

            if (agentCount >= n)
            {
                gotoxy(71, 17);
                setColor(4);
                cout << "Maximum Agents Reached!" << endl;
                setColor(7);
            }
            else
            {
                string newAgentName, newAgentPass;
                bool duplicate = false;

                gotoxy(71, 17);
                cout << "Enter Agent Username: ";
                gotoxy(71, 18);
                setColor(11);
                cout << "--------------------------------";
                gotoxy(71, 20);
                cout << "--------------------------------";
                setColor(7);
                gotoxy(71, 19);
                getline(cin, newAgentName);

                for (int i = 0; i < agentCount; i++)
                {
                    if (agentName[i] == newAgentName)
                    {
                        duplicate = true;
                        break;
                    }
                }
                for (int i = 0; i < userCount; i++)
                {
                    if (userName[i] == newAgentName)
                    {
                        duplicate = true;
                        break;
                    }
                }
                if (newAgentName == "admin" || newAgentName == "")
                {
                    duplicate = true;
                }

                if (duplicate)
                {
                    setColor(4);
                    gotoxy(71, 21);
                    cout << "Username already exists or invalid!" << endl;
                    setColor(7);
                }
                else
                {
                    agentName[agentCount] = newAgentName;

                    gotoxy(71, 21);
                    cout << "Enter Agent Password: ";
                    gotoxy(71, 22);
                    setColor(11);
                    cout << "--------------------------------";
                    gotoxy(71, 24);
                    cout << "--------------------------------";
                    setColor(7);
                    gotoxy(71, 23);
                    getline(cin, newAgentPass);

                    agentPass[agentCount] = newAgentPass;
                    agentAssignedCount[agentCount] = 0;
                    agentDoneCount[agentCount] = 0;
                    agentPendingCount[agentCount] = 0;
                    agentEarnings[agentCount] = 0.0;

                    agentCount++;

                    saveAgents(agentName, agentPass, agentAssignedCount, agentDoneCount, agentPendingCount, agentEarnings, agentCount);

                    setColor(2);
                    gotoxy(71, 26);
                    cout << "Agent Added Successfully!" << endl;
                    setColor(7);
                }
            }
        }
        else if (option == 9)
        {
            system("cls");
            printHeader();
            menuHeading(">>          All Agents        <<");
            for (int i = 0; i < agentCount; i++)
            {
                gotoxy(71, 17+i);
                cout << (i + 1) << ". Agent Name: " << agentName[i] << endl;
            }
        }
        else if (option == 10)
        {
            system("cls");
            printHeader();
            menuHeading(">>      Agent Performance     <<");

            gotoxy(26+(61-28), 17);
            setColor(6);
            cout << left
                 << setw(15) << "Agent"
                 << setw(12) << "Assigned"
                 << setw(8) << "Done"
                 << setw(10) << "Pending"
                 << setw(12) << "Efficiency "
                 << endl;
            gotoxy(26+(61-28), 18);
            cout << "---------------------------------------------------------" << endl;
            setColor(7);

            for (int i = 0; i < agentCount; i++)
            {
                float efficiency = 0;

                if (agentAssignedCount[i] > 0)
                {
                    efficiency = (agentDoneCount[i] * 100.0) / agentAssignedCount[i];
                }
                gotoxy(26+(61-28), 19 + i);
                setColor(96);
                cout << " " << left
                     << setw(14) << agentName[i]
                     << setw(12) << agentAssignedCount[i]
                     << setw(8) << agentDoneCount[i]
                     << setw(10) << agentPendingCount[i]
                     << setw(10) << efficiency << "% " << endl;
                setColor(7);
            }
        }
        else if (option == 11)
        {
            system("cls");
            printHeader();
            menuHeading(">>        Assign Agents       <<");

            int qID;
            string agtName;

            gotoxy(71, 17);
            cout << "Enter Query ID: ";
            gotoxy(71, 18);
            cout << "--------------------------------";
            gotoxy(71, 20);
            cout << "--------------------------------";
            gotoxy(71, 19);
            cin >> qID;
            cin.ignore();

            int queryIndex = -1;

            for (int i = 0; i < querypropCount; i++)
            {
                if (queryptID[i] == qID)
                {
                    queryIndex = i;
                    break;
                }
            }

            if (queryIndex == -1)
            {
                setColor(4);
                gotoxy(71, 21);
                cout << "Query Not Found!" << endl;
                setColor(7);
            }
            else if (queryAssignedAgent[queryIndex] != "")
            {
                setColor(4);
                cout << "Agent already assigned to this query!" << endl;
                setColor(7);
            }
            else
            {
                gotoxy(71, 21);
                cout << "Enter Agent Name: ";
                gotoxy(71, 22);
                cout << "--------------------------------";
                gotoxy(71, 24);
                cout << "--------------------------------";
                gotoxy(71, 23);
                
                getline(cin, agtName);

                bool agentFound = false;
                for (int i = 0; i < agentCount; i++)
                {
                    if (agentName[i] == agtName)
                    {
                        agentFound = true;
                        queryAssignedAgent[queryIndex] = agtName;
                        agentAssignedCount[i]++;
                        agentPendingCount[i]++;
                        listStatus[queryIndex] = "Assigned";

                        saveQueries(queryptID, queryptName, queryptLocation, queryptPrice, queryptDate, 
                                   queryType, queryAssignedAgent, queryUser, listStatus, querypropCount);
                        saveAgents(agentName, agentPass, agentAssignedCount, agentDoneCount, 
                                  agentPendingCount, agentEarnings, agentCount);

                        setColor(2);
                        gotoxy(71, 25);
                        cout << "Agent assigned successfully!" << endl;
                        setColor(7);
                        break;
                    }
                }

                if (!agentFound)
                {
                    setColor(4);
                    gotoxy(71, 25);
                    cout << "Agent Not Found!" << endl;
                    setColor(7);
                }
            }
        }
        else if (option == 12)
        {
            system("cls");
            printHeader();
            menuHeading(">>      Platform Earnings     <<");

            cout << fixed << setprecision(2);
            gotoxy(71, 17);
            cout << "Company Earnings: ";
            setColor(160);
            cout << "$" << companyEarnings;
            setColor(7);

            gotoxy(71, 19);
            cout << "Agent Earnings:";
            gotoxy(71, 20);
            cout << "----------------------";
            for (int i = 0; i < agentCount; i++)
            {
                gotoxy(71, 21 + i);
                cout << agentName[i] << " : ";
                setColor(160);
                cout << "$" << agentEarnings[i];
                setColor(7);
            }
        }
        else if (option == 13)
        {
            return 1;
        }
        else if (option == 14)
        {
            gotoxy(71, 35);
            cout << "Exiting system..." << endl;
            // return 0;
            exit(0);
        }
        gotoxy(71, 36);
        setColor(96);
        cout << "Press any key to continue.......";
        setColor(7);
        getch();
        system("cls");
    }
    return 0;
}

int userModules(int ptID[], string ptName[], string ptLocation[], float ptPrice[], string ptDate[], string ptOwner[], int& propCount,
                int bookedptID[], string bookedptName[], string bookedptLocation[], float bookedptPrice[], string bookedptDate[], int& bookedpropCount,
                int rentptID[], string rentptName[], string rentptLocation[], float rentptPrice[], string rentptDate[], int& rentpropCount,
                int listptID[], string listptName[], string listptLocation[], float listptPrice[], string listptDate[], int& listpropCount,
                int queryptID[], string queryptName[], string queryptLocation[], float queryptPrice[], string queryptDate[],
                string queryType[], string queryAssignedAgent[], string queryUser[], string listStatus[], int& querypropCount,
                string& currentUser)
{
    int option;
    while (true)
    {
        system("cls");
        printHeader();
        option = userMenu();

        if (option == 1)
        {
            system("cls");
            printHeader();
            menuHeading(">>       All Properties       <<");
            if (propCount == 0)
            {
                setColor(4);
                gotoxy(71, 17);
                cout << "No properties available!" << endl;
                setColor(7);
            }
            else
            {
                int row=0;
                tableMenu(17);
                for (int i = 0; i < propCount; i++)
                {
                    if (ptID[i] != 0)
                    {
                        printProps(row, ptID[i], ptName[i], ptLocation[i], ptPrice[i], ptDate[i]);
                        row++;
                    }
                }
            }
        }
        else if (option == 2)
        {
            string searchName = "";
            while (true)
            {
                system("cls");
                printHeader();
                menuHeading(">>       Search Property      <<");

                gotoxy(71, 17);
                cout << "Enter Property Name to Search: ";
                gotoxy(71, 18);
                cout << "--------------------------------";
                gotoxy(71, 20);
                cout << "--------------------------------";
                gotoxy(71, 19);
                cout << searchName;

                tableMenu(23);
                int row = 0;
                bool found = false;
                for (int i = 0; i < propCount; i++)
                {
                    {
                        bool match = true;
                        if (searchName != "")
                        {
                            match = false;
                            int len = searchName.length();
                            int plen = ptName[i].length();
                            if (plen >= len)
                            {
                                for (int j = 0; j <= plen - len; ++j)
                                {
                                    bool found_match = true;
                                    for (int k = 0; k < len; ++k)
                                    {
                                        if (tolower(ptName[i][j + k]) != tolower(searchName[k]))
                                        {
                                            found_match = false;
                                            break;
                                        }
                                    }
                                    if (found_match)
                                    {
                                        match = true;
                                        break;
                                    }
                                }
                            }
                        }
                        if (match)
                        {
                            printProps(row + 2, ptID[i], ptName[i], ptLocation[i], ptPrice[i], ptDate[i]);
                            row++;
                            found = true;
                        }
                    }
                }
                if (!found && searchName != "")
                {
                    gotoxy(71, 19);
                    setColor(4);
                    cout << searchName;
                    setColor(7);
                }

                char ch = _getch();
                if (ch == 13) 
                {
                    break;
                }
                else if (ch == 8) 
                {
                    if (searchName != "")
                    {
                        string temp = "";
                        for (int i = 0; i < searchName.length() - 1; i++)
                        {
                            temp += searchName[i];
                        }
                        searchName = temp;
                    }
                }
                else if (ch >= 32 && ch <= 126) 
                {
                    searchName += ch;
                }
            }
        }
        else if (option == 3)
        {
            system("cls");
            printHeader();
            menuHeading(">>        Book Property       <<");
            int bookProp;
            gotoxy(71, 17);
            cout << "Enter Property ID to Book: ";
            gotoxy(71, 18);
            cout << "--------------------------------";
            gotoxy(71, 20);
            cout << "--------------------------------";
            gotoxy(71, 19);
            cin >> bookProp;
            cin.ignore();


            bool found = false;
            bool alreadyBooked = false;

            for (int i = 0; i < bookedpropCount; i++)
            {
                if (bookedptID[i] == bookProp)
                {
                    alreadyBooked = true;
                    break;
                }
            }

            if (alreadyBooked)
            {
                setColor(4);
                gotoxy(71, 21);
                cout << "Property Already Booked!";
                setColor(7);
            }
            else
            {
                bool booked = false;
                int row=0;
                for (int i = 0; i < propCount; i++)
                {
                    if (ptID[i] == bookProp)
                    {
                        found = true;
                        if (ptOwner[i] == currentUser)
                        {
                            setColor(4);
                            gotoxy(71, 21);
                            cout << "Cannot be book!";
                            setColor(7);
                            break;
                        }

                        tableMenu(17);
                        printProps(row, ptID[i], ptName[i], ptLocation[i], ptPrice[i], ptDate[i]);

                        bookedptID[bookedpropCount] = ptID[i];
                        bookedptName[bookedpropCount] = ptName[i];
                        bookedptLocation[bookedpropCount] = ptLocation[i];
                        bookedptPrice[bookedpropCount] = ptPrice[i];
                        bookedptDate[bookedpropCount] = ptDate[i];

                        queryptID[querypropCount] = bookedptID[bookedpropCount];
                        queryptName[querypropCount] = bookedptName[bookedpropCount];
                        queryptLocation[querypropCount] = bookedptLocation[bookedpropCount];
                        queryptPrice[querypropCount] = bookedptPrice[bookedpropCount];
                        queryptDate[querypropCount] = bookedptDate[bookedpropCount];
                        queryUser[querypropCount] = currentUser;

                        for (int j = i; j < propCount - 1; j++)
                        {
                            ptID[j] = ptID[j + 1];
                            ptName[j] = ptName[j + 1];
                            ptLocation[j] = ptLocation[j + 1];
                            ptPrice[j] = ptPrice[j + 1];
                            ptDate[j] = ptDate[j + 1];
                            ptOwner[j] = ptOwner[j + 1];
                        }
                        propCount--;

                        queryType[querypropCount] = "Booked";
                        queryAssignedAgent[querypropCount] = "";
                        listStatus[querypropCount] = "Pending";

                        querypropCount++;
                        bookedpropCount++;
                        
                        saveProperties(ptID, ptName, ptLocation, ptPrice, ptDate, ptOwner, propCount);
                        saveBookedProperties(bookedptID, bookedptName, bookedptLocation, bookedptPrice, bookedptDate, bookedpropCount);
                        saveQueries(queryptID, queryptName, queryptLocation, queryptPrice, queryptDate, 
                                   queryType, queryAssignedAgent, queryUser, listStatus, querypropCount);
                        
                        row++;
                        booked = true;
                        break;
                    }
                }

                if (!found)
                {
                    setColor(4);
                    gotoxy(71, 21);
                    cout << "Property Not Found!";
                    setColor(7);
                }
                else if (booked)
                {
                    setColor(2);
                    gotoxy(71, 35);
                    cout << "Property Booked Successfully!";
                    setColor(7);
                }
            }
        }
        else if (option == 4)
        {
            system("cls");
            printHeader();
            menuHeading(">>        Rent Property       <<");
            int rentProp;
            gotoxy(71, 17);
            cout << "Enter Property ID to Rent: ";
            gotoxy(71, 18);
            cout << "--------------------------------";
            gotoxy(71, 20);
            cout << "--------------------------------";
            gotoxy(71, 19);
            cin >> rentProp;
            cin.ignore();


            bool found = false;
            bool alreadyRented = false;

            for (int i = 0; i < rentpropCount; i++)
            {
                if (rentptID[i] == rentProp)
                {
                    alreadyRented = true;
                    break;
                }
            }

            if (alreadyRented)
            {
                setColor(4);
                gotoxy(71, 21);
                cout << "Property Already Rented!";
                setColor(7);
            }
            else
            {
                bool rented = false;
                int row=0;
                for (int i = 0; i < propCount; i++)
                {
                    if (ptID[i] == rentProp)
                    {
                        found = true;
                        if (ptOwner[i] == currentUser)
                        {
                            setColor(4);
                            gotoxy(71, 21);
                            cout << "Cannot be rent!";
                            setColor(7);
                            break;
                        }

                        tableMenu(17);
                        printProps(row, ptID[i], ptName[i], ptLocation[i], ptPrice[i], ptDate[i]);
                        row++;

                        rentptID[rentpropCount] = ptID[i];
                        rentptName[rentpropCount] = ptName[i];
                        rentptLocation[rentpropCount] = ptLocation[i];
                        rentptPrice[rentpropCount] = ptPrice[i];
                        rentptDate[rentpropCount] = ptDate[i];

                        queryptID[querypropCount] = rentptID[rentpropCount];
                        queryptName[querypropCount] = rentptName[rentpropCount];
                        queryptLocation[querypropCount] = rentptLocation[rentpropCount];
                        queryptPrice[querypropCount] = rentptPrice[rentpropCount];
                        queryptDate[querypropCount] = rentptDate[rentpropCount];
                        queryUser[querypropCount] = currentUser;

                        for (int j = i; j < propCount - 1; j++)
                        {
                            ptID[j] = ptID[j + 1];
                            ptName[j] = ptName[j + 1];
                            ptLocation[j] = ptLocation[j + 1];
                            ptPrice[j] = ptPrice[j + 1];
                            ptDate[j] = ptDate[j + 1];
                            ptOwner[j] = ptOwner[j + 1];
                        }
                        propCount--;

                        queryType[querypropCount] = "Rented";
                        queryAssignedAgent[querypropCount] = "";
                        listStatus[querypropCount] = "Pending";

                        querypropCount++;
                        rentpropCount++;
                        
                        saveProperties(ptID, ptName, ptLocation, ptPrice, ptDate, ptOwner, propCount);
                        saveRentedProperties(rentptID, rentptName, rentptLocation, rentptPrice, rentptDate, rentpropCount);
                        saveQueries(queryptID, queryptName, queryptLocation, queryptPrice, queryptDate, 
                                   queryType, queryAssignedAgent, queryUser, listStatus, querypropCount);
                        
                        rented = true;
                        break;
                    }
                }

                if (!found)
                {
                    setColor(4);
                    gotoxy(71, 21);
                    cout << "Property Not Found!";
                    setColor(7);
                }
                else if (rented)
                {
                    setColor(2);
                    gotoxy(71, 21);
                    cout << "Property Rented Successfully!";
                    setColor(7);
                }
            }
        }
        else if (option == 5)
        {
            system("cls");
            printHeader();
            menuHeading(">>       List Property       <<");

            if (propCount >= n)
            {
                setColor(4);
                gotoxy(71, 17);
                cout << "Maximum Memory Reached!" << endl;
                setColor(7);
            }
            else
            {
                int newID;
                bool duplicate = false;
                gotoxy(71, 17);
                cout << "Enter ID of Property: ";
                gotoxy(71, 18);
                cout << "--------------------------------";
                gotoxy(71, 20);
                cout << "--------------------------------";
                gotoxy(71, 19);
                cin >> newID;
            cin.ignore();


                for (int i = 0; i < propCount; i++)
                {
                    if (ptID[i] == newID)
                    {
                        duplicate = true;
                        break;
                    }
                }

                if (duplicate)
                {
                    setColor(4);
                    gotoxy(71, 21);
                    cout << "Property ID Already Exists!" << endl;
                    setColor(7);
                }
                else
                {
                    string listName;
                    string listLocation;
                    float listPrice;

                    ptID[propCount] = newID;
                    listptID[listpropCount] = newID;
                    queryptID[querypropCount] = newID;

                    
                    gotoxy(71, 21);
                    cout << "Enter Name of Property: ";
                    gotoxy(71, 22);
                    cout << "--------------------------------";
                    gotoxy(71, 24);
                    cout << "--------------------------------";
                    gotoxy(71, 23);
                    getline(cin, listName);

                    ptName[propCount] = listName;
                    listptName[listpropCount] = listName;
                    queryptName[querypropCount] = listName;

                    gotoxy(71, 25);
                    cout << "Enter Location of Property: ";
                    gotoxy(71, 26);
                    cout << "--------------------------------";
                    gotoxy(71, 28);
                    cout << "--------------------------------";
                    gotoxy(71, 27);
                    getline(cin, listLocation);

                    ptLocation[propCount] = listLocation;
                    listptLocation[listpropCount] = listLocation;
                    queryptLocation[querypropCount] = listLocation;

                    gotoxy(71, 29);
                    cout << "Enter Price of Property: $";
                    gotoxy(71, 30);
                    cout << "--------------------------------";
                    gotoxy(71, 32);
                    cout << "--------------------------------";
                    gotoxy(71, 31);
                    cin >> listPrice;
            cin.ignore();


                    ptPrice[propCount] = listPrice;
                    listptPrice[listpropCount] = listPrice;
                    queryptPrice[querypropCount] = listPrice;

                    string currentDate = getCurrentDate();

                    ptDate[propCount] = currentDate;
                    listptDate[listpropCount] = currentDate;
                    queryptDate[querypropCount] = currentDate;

                    ptOwner[propCount] = currentUser;

                    queryType[querypropCount] = "Listed";
                    queryAssignedAgent[querypropCount] = "";
                    listStatus[querypropCount] = "Pending";
                    queryUser[querypropCount] = currentUser;

                    propCount++;
                    listpropCount++;
                    querypropCount++;

                    saveProperties(ptID, ptName, ptLocation, ptPrice, ptDate, ptOwner, propCount);
                    saveListedProperties(listptID, listptName, listptLocation, listptPrice, listptDate, listpropCount);
                    saveQueries(queryptID, queryptName, queryptLocation, queryptPrice, queryptDate, 
                               queryType, queryAssignedAgent, queryUser, listStatus, querypropCount);

                    setColor(2);
                    gotoxy(71, 34);
                    cout << "Property Listed Successfully!" << endl;
                    setColor(7);
                }
            }
        }
        else if (option == 6)
        {
            system("cls");
            printHeader();
            menuHeading(">>        Property Status      <<");

            gotoxy(71 - 23, 17);
            cout << left << setw(25) << "Property Name"
                 << setw(15) << "Type"
                 << setw(20) << "Agent"
                 << setw(15) << "Status" << endl;
            gotoxy(71 - 23, 18);
            cout << "---------------------------------------------------------------------------" << endl;

            bool isMineProp = false;
            int row = 0;

            for (int i = 0; i < querypropCount; i++)
            {
                if (queryUser[i] == currentUser)
                {
                    isMineProp = true;
                    gotoxy(71 - 23, 19 + row);
                    setColor(96);
                    cout << left << setw(25) << queryptName[i];
                    cout << setw(15) << queryType[i];
                    if (queryAssignedAgent[i] == "")
                    {
                        cout << setw(20) << "None";
                        cout << setw(15) << "Not Assigned";
                    }
                    else
                    {
                        cout << setw(20) << queryAssignedAgent[i];
                        cout << setw(15) << listStatus[i];
                    }
                    cout << endl;
                    setColor(7);
                    row++;
                }
            }

            if (!isMineProp)
            {
                setColor(4);
                gotoxy(71 - 23, 19);
                cout << "No properties!" << endl;
                setColor(7);
            }
        }
        else if (option == 7)
        {
            return 1;
        }
        else if (option == 8)
        {
            gotoxy(71, 35);
            cout << "Exiting system..." << endl;
            // return 0;
            exit(0);
        }

        gotoxy(71, 36);
        setColor(96);
        cout << "Press any key to continue.......";
        setColor(7);
        getch();
        system("cls");
    }
    return 0;
}

int agentModules(int queryptID[], string queryptName[], string queryptLocation[], float queryptPrice[], string queryptDate[],
                 string queryType[], string queryAssignedAgent[], string queryUser[], string listStatus[], int& querypropCount,
                 string agentName[], string agentPass[], int agentAssignedCount[], int agentDoneCount[], int agentPendingCount[],
                 float agentEarnings[], int& agentCount, float& companyEarnings, string& currentUser)
{
    int option;
    while (true)
    {
        system("cls");
        printHeader();
        option = agentMenu();

        if (option == 1)
        {
            system("cls");
            printHeader();
            menuHeading(">>      Assigned Properties     <<");

            bool found = false;

            gotoxy(26+(61-55), 17);
            cout << left << setw(8) << "ID"
            << setw(18) << "Client Name"
            << setw(18) << "Property Name"
            << setw(10) << "Type"
            << setw(30) << "Location"
            << setw(12) << "Price"
            << setw(15) << "Status" << endl;
            gotoxy(26 + (61 - 55), 18);
            cout << "---------------------------------------------------------------------------------------------------------------" << endl;

            for (int i = 0; i < querypropCount; i++)
            {
                if (queryAssignedAgent[i] == currentUser)
                {
                    gotoxy(26 + (61 - 55), 19+i);
                    setColor(96);
                    cout << left << setw(8) << queryptID[i]
                         << setw(18) << queryUser[i]
                         << setw(18) << queryptName[i]
                         << setw(10) << queryType[i]
                         << setw(30) << queryptLocation[i]
                         << setw(12) << fixed << setprecision(2) << queryptPrice[i]
                         << setw(15) << listStatus[i] << endl;
                    setColor(7);
                    found = true;
                }
            }

            if (!found)
            {
                setColor(4);
                gotoxy(26 + (61 - 55), 19);
                cout << "No properties assigned to you" << endl;
                setColor(7);
            }
        }
        else if (option == 2)
        {
            system("cls");
            printHeader();
            menuHeading(">>     Update Property Status    <<");
            int agentQID, qStatus;
            bool queryFound = false;
            gotoxy(71, 17);
            cout << "Enter Query ID: ";
            gotoxy(71, 18);
            cout << "--------------------------------";
            gotoxy(71, 20);
            cout << "--------------------------------";
            gotoxy(71, 19);
            cin >> agentQID;
            cin.ignore();


            for (int i = 0; i < querypropCount; i++)
            {
                if (agentQID == queryptID[i] && queryAssignedAgent[i] == currentUser)
                {
                    queryFound = true;
                    gotoxy(71, 21);
                    cout << "Update Property Status: ";
                    gotoxy(71, 22);
                    cout << "1. Done";
                    gotoxy(71, 23);
                    cout << "2. Pending";
                    gotoxy(71, 24);
                    cout << "Select option: ";
                    gotoxy(71, 25);
                    cout << "--------------------------------";
                    gotoxy(71, 27);
                    cout << "--------------------------------";
                    gotoxy(71, 26);
                    cin >> qStatus;
            cin.ignore();


                    if (qStatus == 1)
                    {
                        listStatus[i] = "Done";

                        float propertyPrice = queryptPrice[i];
                        float companyShare = propertyPrice * 0.02;
                        float agentShare = propertyPrice * 0.04;
                        companyEarnings += companyShare;

                        for (int a = 0; a < agentCount; a++)
                        {
                            if (agentName[a] == currentUser)
                            {
                                agentEarnings[a] += agentShare;
                                agentDoneCount[a]++;
                                if (agentPendingCount[a] > 0)
                                {
                                    agentPendingCount[a]--;
                                }
                                break;
                            }
                        }

                        saveQueries(queryptID, queryptName, queryptLocation, queryptPrice, queryptDate, 
                                   queryType, queryAssignedAgent, queryUser, listStatus, querypropCount);
                        saveAgents(agentName, agentPass, agentAssignedCount, agentDoneCount, 
                                  agentPendingCount, agentEarnings, agentCount);

                        setColor(2);
                        gotoxy(71, 28);
                        cout << "Status updated to Done!";
                        setColor(7);
                    }
                    else if (qStatus == 2)
                    {
                        listStatus[i] = "Pending";
                        saveQueries(queryptID, queryptName, queryptLocation, queryptPrice, queryptDate, 
                                   queryType, queryAssignedAgent, queryUser, listStatus, querypropCount);
                        setColor(3);
                        gotoxy(71, 28);
                        cout << "Status set to Pending!";
                        setColor(7);
                    }
                    else
                    {
                        setColor(4);
                        gotoxy(71, 28);
                        cout << "Invalid Option!";
                        setColor(7);
                    }
                    break;
                }
            }

            if (!queryFound)
            {
                setColor(4);
                gotoxy(71, 21);
                cout << "Query Not Found!" << endl;
                setColor(7);
            }
        }
        else if (option == 3)
        {
            system("cls");
            printHeader();
            menuHeading(">>      Your Performance      <<");

            gotoxy(26+(61-31), 17);
            setColor(6);
            cout << left << setw(18) << "Agent Name"
                 << setw(12) << "Assigned"
                 << setw(10) << "Done"
                 << setw(10) << "Pending"
                 << setw(12) << "Efficiency" << endl;
            gotoxy(26+(61-31), 18);
            cout << "---------------------------------------------------------------" << endl;
            setColor(7);

            for (int i = 0; i < agentCount; i++)
            {
                if (agentName[i] == currentUser)
                {
                    float efficiency = 0;
                    if (agentAssignedCount[i] > 0)
                    {
                        efficiency = (agentDoneCount[i] * 100.0) / agentAssignedCount[i];
                    }

                    gotoxy(26 + (61 - 31), 19);
                    setColor(96);
                    cout << left << setw(18) << agentName[i]
                         << setw(12) << agentAssignedCount[i]
                         << setw(10) << agentDoneCount[i]
                         << setw(10) << agentPendingCount[i]
                         << setw(12) << fixed << setprecision(1) << efficiency << left << "%" << endl;
                    setColor(7);

                    gotoxy(26 + (61 - 31), 21);
                    cout << "Total Earnings: " << fixed << setprecision(2);
                    setColor(160);
                    cout << "$" << agentEarnings[i];
                    setColor(7);
                    break;
                }
            }
        }
        else if (option == 4)
        {
            return 1;
        }
        else if (option == 5)
        {
            gotoxy(71, 35);
            cout << "Exiting system..." << endl;
            // return 0;
            exit(0);
        }

        gotoxy(71, 36);
        setColor(96);
        cout << "Press any key to continue.......";
        setColor(7);
        getch();
        system("cls");
    }
    return 0;
}

void printHeader()
{
    setColor(11);
    SetConsoleOutputCP(CP_UTF8);
    cout << endl;
    int x = 26, y = 1;
    gotoxy(x, y);
    cout << "   ███████████   ██████████   █████████   █████       ███████████  ███████████      ███████    ███████████   █████████   ";
    gotoxy(x, y + 1);
    cout << "  ░░███░░░░░███ ░░███░░░░░█  ███░░░░░███ ░░███       ░░███░░░░░███░░███░░░░░███   ███░░░░░███ ░░███░░░░░███ ███░░░░░███  ";
    gotoxy(x, y + 2);
    cout << "   ░███    ░███  ░███  █ ░  ░███    ░███  ░███        ░███    ░███ ░███    ░███  ███     ░░███ ░███    ░███░███    ░░░   ";
    gotoxy(x, y + 3);
    cout << "   ░██████████   ░██████    ░███████████  ░███        ░██████████  ░██████████  ░███      ░███ ░██████████ ░░█████████   ";
    gotoxy(x, y + 4);
    cout << "   ░███░░░░░███  ░███░░█    ░███░░░░░███  ░███        ░███░░░░░░   ░███░░░░░███ ░███      ░███ ░███░░░░░░   ░░░░░░░░███  ";
    gotoxy(x, y + 5);
    cout << "   ░███    ░███  ░███ ░   █ ░███    ░███  ░███      █ ░███         ░███    ░███ ░░███     ███  ░███         ███    ░███  ";
    gotoxy(x, y + 6);
    cout << "   █████   █████ ██████████ █████   █████ ███████████ █████        █████   █████ ░░░███████░   █████       ░░█████████   ";
    gotoxy(x, y + 7);
    cout << "  ░░░░░   ░░░░░ ░░░░░░░░░░ ░░░░░   ░░░░░ ░░░░░░░░░░░ ░░░░░        ░░░░░   ░░░░░    ░░░░░░░    ░░░░░         ░░░░░░░░░    ";
    gotoxy(x, y + 9);
    setColor(6);
    cout << "+------------------------------------------- Real Estate Management Dashboard ------------------------------------------+";
    for (int i = 10; i <= 42; i++)
    {
        gotoxy(x, y + i);
        cout << "|                                                                                                                       |";
    }
    gotoxy(x, y + 43);
    cout << "+-----------------------------------------------------------------------------------------------------------------------+";
    setColor(7);
}

int adminMenu()
{
    int menuItems = 14;
    string menuStrings[menuItems] = {
        "Add New Property",
        "View All Properties",
        "Search Property",
        "Delete Property",
        "Update Property",
        "View Queries",
        "View Sold Properties",
        "Add New Agent",
        "View All Agents",
        "Agents Performance",
        "Assign Agents",
        "Platform Earnings",
        "Return to Main Menu",
        "Exit"};

    int selected = 0;
    bool running = true;
    gotoxy(71, (35 / 2) - 2);
    cout << ">>          Admin Menu        <<";

    while (running)
    {
        for (int i = 0; i < menuItems; i++)
        {
            gotoxy(71, ((35 / 2)) + i);
            if (i == selected)
            {
                setColor(96);
                cout << " > " << left << setw(29) << menuStrings[i];
            }
            else
            {
                setColor(6);
                cout << "   " << left << setw(29) << menuStrings[i];
            }
        }
        setColor(7);

        char key = _getch();

        if (key == 72)
        {
            if (selected > 0)
            {
                selected = selected - 1;
            }
            else
            {
                selected = menuItems - 1;
            }
        }
        else if (key == 80)
        {
            if (selected < menuItems - 1)
            {
                selected = selected + 1;
            }
            else
            {
                selected = 0;
            }
        }
        else if (key == 13)
        {
            return selected + 1;
        }
    }
}

int userMenu()
{
    int menuItems = 8;
    string menuStrings[menuItems] = {
        "View All Properties",
        "Search Property",
        "Book Property",
        "Rent Property",
        "List Property",
        "View Property Status",
        "Return to Main Menu",
        "Exit"};

    int selected = 0;
    bool running = true;
    gotoxy(71, (35 / 2) - 2);
    cout << ">>          User Menu         <<";

    while (running)
    {
        for (int i = 0; i < menuItems; i++)
        {
            gotoxy(71, ((35 / 2)) + i);
            if (i == selected)
            {
                setColor(96);
                cout << " > " << left << setw(29) << menuStrings[i];
            }
            else
            {
                setColor(6);
                cout << "   " << left << setw(29) << menuStrings[i];
            }
        }
        setColor(7);

        char key = _getch();

        if (key == 72)
        {
            if (selected > 0)
            {
                selected = selected - 1;
            }
            else
            {
                selected = menuItems - 1;
            }
        }
        else if (key == 80)
        {
            if (selected < menuItems - 1)
            {
                selected = selected + 1;
            }
            else
            {
                selected = 0;
            }
        }
        else if (key == 13)
        {
            return selected + 1;
        }
    }
}

int agentMenu()
{
    int menuItems = 5;
    string menuStrings[menuItems] = {
        "View Assigned Properties",
        "Update Property Status",
        "View Your Performance",
        "Return to Main Menu",
        "Exit"};

    int selected = 0;
    bool running = true;
    gotoxy(71, (35 / 2) - 2);
    cout << ">>          Agent Menu        <<";

    while (running)
    {
        for (int i = 0; i < menuItems; i++)
        {
            gotoxy(71, ((35 / 2)) + i);
            if (i == selected)
            {
                setColor(96);
                cout << " > " << left << setw(29) << menuStrings[i];
            }
            else
            {
                setColor(6);
                cout << "   " << left << setw(29) << menuStrings[i];
            }
        }
        setColor(7);

        char key = _getch();

        if (key == 72)
        {
            if (selected > 0)
            {
                selected = selected - 1;
            }
            else
            {
                selected = menuItems - 1;
            }
        }
        else if (key == 80)
        {
            if (selected < menuItems - 1)
            {
                selected = selected + 1;
            }
            else
            {
                selected = 0;
            }
        }
        else if (key == 13)
        {
            return selected + 1;
        }
    }
}

int mainMenu()
{
    int mainMenuItems = 3;
    string mainMenuStrings[mainMenuItems] = {
        "Sign Up",
        "Login",
        "Exit"};

    int selected = 0;
    bool running = true;
    gotoxy(71, (10 + 35 / 2) - mainMenuItems - 2);
    cout << ">>          Main Menu         <<";

    while (running)
    {
        for (int i = 0; i < mainMenuItems; i++)
        {
            gotoxy(71, ((10 + 35 / 2) - mainMenuItems) + i);
            if (i == selected)
            {
                setColor(96);
                cout << " > " << left << setw(29) << mainMenuStrings[i];
            }
            else
            {
                setColor(6);
                cout << "   " << left << setw(29) << mainMenuStrings[i];
            }
        }
        setColor(7);

        char key = _getch();

        if (key == 72)
        {
            if (selected > 0)
            {
                selected = selected - 1;
            }
            else
            {
                selected = mainMenuItems - 1;
            }
        }
        else if (key == 80)
        {
            if (selected < mainMenuItems - 1)
            {
                selected = selected + 1;
            }
            else
            {
                selected = 0;
            }
        } 
        else if (key == 13)
        {
            return selected + 1;
        }
    }
}

void tableMenu(int rowIndex)
{
    setColor(6);
    gotoxy((27+(120/2)-48), rowIndex);
    cout << " __" << setw(10) << left << "__________";
    cout << " __" << setw(18) << left << "__________________";
    cout << " __" << setw(30) << left << "______________________________";
    cout << " __" << setw(10) << left << "__________";
    cout << " __" << setw(12) << left << "____________";
    cout << endl;
    gotoxy((27+(120/2)-48), rowIndex+1);
    cout << "|  " << setw(10) << left << "";
    cout << "|  " << setw(18) << left << "";
    cout << "|  " << setw(30) << left << "";
    cout << "|  " << setw(10) << left << "";
    cout << "|  " << setw(12) << left << "            |";
    cout << endl;
    gotoxy((27+(120/2)-48), rowIndex+2);
    cout << "|  " << setw(10) << left << "ID";
    cout << "|  " << setw(18) << left << "Name";
    cout << "|  " << setw(30) << left << "Location";
    cout << "|  " << setw(10) << left << "Price";
    cout << "|  " << setw(12) << left << "Date Added" << "|";
    cout << endl;
    gotoxy((27+(120/2)-48), rowIndex+3);
    cout << "|__" << setw(10) << left << "__________|";
    cout << "__" << setw(18) << left << "__________________|";
    cout << "__" << setw(30) << left << "______________________________|";
    cout << "__" << setw(10) << left << "__________|";
    cout << "__" << setw(12) << left << "____________|";
    cout << endl;
    setColor(7);
}

void printProps(int rowIndex, int id, string name, string location, float price, string date)
{
    int y = 20 + rowIndex * 3;
    gotoxy((27 + (120 / 2) - 48), y+1);
    cout << "|  " << setw(10) << left << "";
    cout << "|  " << setw(18) << left << "";
    cout << "|  " << setw(30) << left << "";
    cout << "|  " << setw(10) << left << "";
    cout << "|  " << setw(12) << left << "";
    cout << "|";
    cout << endl;
    gotoxy((27 + (120 / 2) - 48), y + 2);
    cout << "|  " << setw(10) << left << id;
    cout << "|  " << setw(18) << left << name;
    cout << "|  " << setw(30) << left << location;
    cout << "|  " << setw(10) << left << fixed << setprecision(2) << price;
    cout << "|  " << setw(12) << left << date << "|";
    cout << endl;
    gotoxy((27 + (120 / 2) - 48), y + 3);
    cout << "|__" << setw(10) << left << "__________|";
    cout << "__" << setw(18) << left << "__________________|";
    cout << "__" << setw(30) << left << "______________________________|";
    cout << "__" << setw(10) << left << "__________|";
    cout << "__" << setw(12) << left << "____________|";
    cout << endl;
}

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setupConsoleUI()
{
    HWND console = GetConsoleWindow();

    ShowWindow(console, SW_MAXIMIZE);

    SendMessage(console, WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hOut, &csbi);

    COORD newSize;
    newSize.X = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    newSize.Y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    SetConsoleScreenBufferSize(hOut, newSize);

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void menuHeading(string heading)
{
    gotoxy(71, 15);
    cout << heading;
}

void drawHeader(int x, int y)
{
    setColor(11);
    gotoxy(x, y);
    cout << "   ███████████   ██████████   █████████   █████       ███████████  ███████████      ███████    ███████████   █████████   ";
    gotoxy(x, y + 1);
    cout << "  ░░███░░░░░███ ░░███░░░░░█  ███░░░░░███ ░░███       ░░███░░░░░███░░███░░░░░███   ███░░░░░███ ░░███░░░░░███ ███░░░░░███  ";
    gotoxy(x, y + 2);
    cout << "   ░███    ░███  ░███  █ ░  ░███    ░███  ░███        ░███    ░███ ░███    ░███  ███     ░░███ ░███    ░███░███    ░░░   ";
    gotoxy(x, y + 3);
    cout << "   ░██████████   ░██████    ░███████████  ░███        ░██████████  ░██████████  ░███      ░███ ░██████████ ░░█████████   ";
    gotoxy(x, y + 4);
    cout << "   ░███░░░░░███  ░███░░█    ░███░░░░░███  ░███        ░███░░░░░░   ░███░░░░░███ ░███      ░███ ░███░░░░░░   ░░░░░░░░███  ";
    gotoxy(x, y + 5);
    cout << "   ░███    ░███  ░███ ░   █ ░███    ░███  ░███      █ ░███         ░███    ░███ ░░███     ███  ░███         ███    ░███  ";
    gotoxy(x, y + 6);
    cout << "   █████   █████ ██████████ █████   █████ ███████████ █████        █████   █████ ░░░███████░   █████       ░░█████████   ";
    gotoxy(x, y + 7);
    cout << "  ░░░░░   ░░░░░ ░░░░░░░░░░ ░░░░░   ░░░░░ ░░░░░░░░░░░ ░░░░░        ░░░░░   ░░░░░    ░░░░░░░    ░░░░░         ░░░░░░░░░    ";
    setColor(7);
}

void slideHeaderUp(int startX, int startY, int endY)
{
    for (int y = startY; y >= endY; y--)
    {
        system("cls");
        drawHeader(startX, y);
        Sleep(5);
    }
}

void loader()
{
    setColor(11);
    SetConsoleOutputCP(CP_UTF8);

    int x = 26, y = 15;

    drawHeader(x, y);

    setColor(6);
    gotoxy(x - 1, y + 8);
    cout << "+";
    gotoxy(x - 1, y + 10);
    cout << "+";
    gotoxy(x + 120, y + 8);
    cout << "+";
    gotoxy(x + 120, y + 10);
    cout << "+";

    gotoxy(x, y + 9);
    setColor(6);

    for (int i = 0; i < 22; i++)
    {
        cout << "█";
        Sleep(20);
    }
    for (int i = 0; i < 70; i++)
    {
        cout << "█";
        Sleep(1);
    }
    for (int i = 0; i < 28; i++)
    {
        cout << "█";
        Sleep(20);
    }
    Sleep(500);

    setColor(7);

    slideHeaderUp(x, y, y - 14);

    setColor(7);
}