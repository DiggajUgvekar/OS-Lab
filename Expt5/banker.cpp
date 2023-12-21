#include<iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

int m, n, flag;

int allocation[10][10], maximum[10][10], need[10][10];
int available[10];

void safety()
{
    int safe[10], work[10];
    bool finish[10];

    for(int i = 0; i < n; i++)
    {
        safe[i] = -1;
        finish[i] = false;
    }

    for(int i = 0; i < m; i++)
        work[i] = available[i];

    int k = 0, loop_flag;

    do
    {
        loop_flag = 0;

        for(int i = 0; i < n; i++)
        {
            flag = 0;

            for(int j = 0; j < m; j++)
            {
                if (finish[i] == false && need[i][j] <= work[j])
                    continue;
                else
                    flag = 1;
            }

            if (flag == 0)
            {
                finish[i] = true;

                for(int j = 0; j < m; j++)
                    work[j] = work[j] + allocation[i][j];

                safe[k] = i;
                k++;
                loop_flag = 1;
            }
        }

        flag = 0;

        for(int i = 0; i < n; i++)
        {
            if (finish[i] == false)
                flag = 1;
        }

        if (flag == 0)
            break;

        if (loop_flag == 0)
            break;
    } while(true);

    if (flag == 0)
    {
        cout << endl << "Safe Sequence:  ";
        for (int j = 0; j < n; j++)
        {
            if (j == n - 1)
            {
                cout << "P" << safe[j];
            }
            else
            {
                cout << "P" << safe[j] << " -> ";
            }
        }
        cout << endl;
    }
    else
        cout << endl << "Safe sequence doesn't exist" << endl;
}

void display()
{
    cout << endl << "------------------------ Current System State ------------------------" << endl;
    cout << "Processes   Allocation   Maximum   Need   Available" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "P" << i << "           ";
        for (int j = 0; j < m; j++)
            cout << allocation[i][j] << " ";
        cout << "         ";
        for (int j = 0; j < m; j++)
            cout << maximum[i][j] << " ";
        cout << "      ";
        for (int j = 0; j < m; j++)
            cout << need[i][j] << " ";

        if (i == 0)
        {
            cout << "       ";
            for (int j = 0; j < m; j++)
            {
                cout << available[j] << " ";
            }
        }

        cout << endl;
    }
}

int main()
{
    cout << "Enter the number of Processes: ";
    cin >> n;

    cout << "Enter the number of Resource types: ";
    cin >> m;

    cout << "\nAllocation Matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> allocation[i][j];
    }

    cout << endl << "Max Matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> maximum[i][j];
    }

    cout << endl << "Available Matrix" << endl;
    for (int i = 0; i < m; i++)
        cin >> available[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            need[i][j] = maximum[i][j] - allocation[i][j];
    }

    display();
    safety();

    char ans = 'y';

    do
    {
        int request[10], p;
        cout << endl << "Enter Process Number: ";
        cin >> p;

        cout << "Enter Request: ";
        for (int i = 0; i < m; i++)
            cin >> request[i];

        for (int i = 0; i < m; i++)
        {
            if (need[p][i] < request[i])
            {
                cout << endl << "Process exceeded maximum claim for resources.\nRequest Cannot be granted." << endl;
                goto end;
            }
            if (available[i] < request[i])
            {
                cout << endl << "Process must wait. Resources not available." << endl;
                goto end;
            }
        }

        for (int i = 0; i < m; i++)
        {
            available[i] -= request[i];
            allocation[p][i] += request[i];
            need[p][i] -= request[i];
        }

        cout << endl << endl;
        display();
        safety();

        if (flag == 1)
        {
            cout << "Request cannot be granted." << endl;
            for (int i = 0; i < m; i++)
            {
                available[i] += request[i];
                allocation[p][i] -= request[i];
                need[p][i] += request[i];
            }
            cout << endl << "States Reverted:" << endl;
            display();
        }
        else
        {
            cout << endl << "Safe Sequence Exists, and the request can be granted immediately to the process." << endl;
            cout << "Snapshot after request:" << endl;
            display();
        }

        end:
        cout << endl << "Try another Process? (Y/N)  ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    return 0;
}
