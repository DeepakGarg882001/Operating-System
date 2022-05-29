#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void arrangeArrival(int num, int arr[][3])
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (arr[j][1] > arr[j + 1][1])
            {
                for (int k = 0; k < 3; k++)
                {
                    swap(arr[j][k], arr[j + 1][k]);
                }
            }
        }
    }
}

void arrangeBurst(int num, int arr[][3])
{
    int temp, val, ct;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if ((arr[0][1] == arr[j + 1][1]) && (arr[0][0] > arr[j + 1][0]))
            {
                for (int k = 0; k < 3; k++)
                {
                    swap(arr[0][k], arr[j + 1][k]);
                }
            }
        }
    }

    ct = arr[0][0] + arr[0][1];
   
    for(int i = 1; i < num; i++)
    {
        int low = arr[i][0];
        val = i;
        if(ct < arr[val][1])
        {
            ct = arr[val][1];
        }


        for (int j = i; j < num; j++)
        {
            if (ct >= arr[j][1] && low >= arr[j][0])
            {
                low = arr[j][0];
                val = j;
            }
        }

        ct = ct + arr[val][0];

        for (int k = 0; k < 3; k++)
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

    int table[n][3];

    cout << "\nEnter Burst Time & Arrival Time for each Process : \n\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Process No. : " << i + 1 << endl;
        table[i][2] = i + 1;
        cout<<"Burst Time : ";
        cin >> table[i][0] ;
        cout<<"Arrival Time : ";
        cin >> table[i][1];
        cout<<endl<<endl;
    } 

    arrangeArrival(n, table);
    arrangeBurst(n, table);

    cout <<"\nProcess \t Burst Time \t Arrival Time \t Waiting Time \t Turnaround Time " << endl;
    cout << "----------------------------------------------------------------------------------";

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

        cout << "\n #" 
             << table[i][2]
             << "\t\t     " 
             << table[i][0] 
             << "\t\t     " 
             << table[i][1] 
             << "\t\t       " 
             << wt 
             << "\t\t" 
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