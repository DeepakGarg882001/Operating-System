#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void arrangeArrival(int num, int arr[][4])
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (arr[j][1] > arr[j + 1][1])
            {
                for (int k = 0; k < 4; k++)
                {
                    swap(arr[j][k], arr[j + 1][k]);
                }
            }
        }
    }
}

void arrangePriority(int num, int arr[][4])
{
    int temp, val, ct;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if ((arr[0][1] == arr[j + 1][1]) && (arr[0][3] > arr[j + 1][3]))
            {
                for (int k = 0; k < 3; k++)
                {
                    swap(arr[0][k], arr[j + 1][k]);
                }
            }
        }
    }
    ct = arr[0][0] + arr[0][1];

    for (int i = 1; i < num; i++)
    {
                val = i;
        int low = arr[i][3];
        if (ct <= arr[val][1])
        {
            ct = arr[val][1];
        }

        for (int j = i; j < num; j++)
        {
            if (ct >= arr[j][1] && low >= arr[j][3])
            {
                low = arr[j][3];
                val = j;
            }
        }

        ct = ct + arr[val][0];
        for (int k = 0; k < 4; k++)
        {
            swap(arr[val][k], arr[i][k]);
        }
    }
}
int main()
{
    int n, wt = 0, tat = 0, ct = 0;
    double avgwt = 0, avgtat = 0;

    cout << "Enter No. of Processes : ";
    cin >> n;

    int table[n][4];

    cout << "\nEnter Burst Time, Arrival Time & Priority for each Process : \n\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Process : #" << i + 1 << endl;
        table[i][2] = i + 1;
        cout <<"Burst Time : ";
        cin >> table[i][0] ;
        cout <<"Arrival Time : ";
        cin >> table[i][1];
        cout <<"Priority : ";
        cin >> table[i][3];
        cout<<endl<<endl;
    }
    arrangeArrival(n, table);
    arrangePriority(n, table);

    cout << "\nProcess\t\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time" << endl;
    cout << "--------------------------------------------------------------------------------------------------";
    for (int i = 0; i < n; i++)
    {
        if (table[i][1] > ct)
        {
            ct = table[i][1];
        }
        ct += table[i][0];
        tat = ct - table[i][1];
        wt = tat - table[i][0];
        avgtat += tat;
        avgwt += wt;

        cout << "\n  #" 
             << table[i][2]
             << "\t\t     " 
             << table[i][0] 
             << "\t\t     " 
             << table[i][1] 
             << "\t\t     " 
             << table[i][3] 
             << "\t\t     " 
             << wt 
             << "\t\t     " 
             << tat;
    }

    avgwt /= n;
    avgtat /= n;

    cout << "\n\nAverage Waiting Time : " 
         << avgwt;

    cout << "\nAverage Turnaround Time : " 
         << avgtat;

    cout <<endl<<endl;

    return 0;
}