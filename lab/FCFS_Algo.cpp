#include <iostream>
using namespace std;

//  lets short all the three arrays

void shortAllArrivalBurstArray(int totalproc, int ArrivalTime[], int BurstTime[], int ProcessId[])
{

    for (int i = 0; i < totalproc - 1; i++)
    {

        for (int j = i + 1; j < totalproc; j++)
        {
            if (ArrivalTime[j] < ArrivalTime[i])
            {
                swap(ArrivalTime[j], ArrivalTime[i]);
                swap(ProcessId[j], ProcessId[i]);
                swap(BurstTime[j], BurstTime[i]);
            }
        }
    }
}

//   lets Find out the Completion Time

void findCompletionTime(int totalproc, int ArrivalTime[], int BurstTime[], int completionTime[])
{
    int initial = ArrivalTime[0];
    for (int i = 0; i < totalproc; i++)
    {
        if(initial <ArrivalTime[i]){
            int diff= 0;
            diff=ArrivalTime[i]-initial;
            initial=initial+diff;
        }
        
        completionTime[i] = initial + BurstTime[i];
        initial = completionTime[i];

        
    }
}

//  lets Find out the Turn Around Time

void findTurnAroundTime(int totalproc, int ArrivalTime[], int completionTime[], int TurnAroundTime[])
{

    for (int j = 0; j < totalproc; j++)
    {
        TurnAroundTime[j] = completionTime[j] - ArrivalTime[j];
    }
}

//  lets Find Out Waiting Time

void findWaitingTime(int totalproc, int TurnAroundTime[], int BurstTime[], int waitingTime[])
{

    for (int j = 0; j < totalproc; j++)
    {
        waitingTime[j] = TurnAroundTime[j] - BurstTime[j];
    }
}

// Lets Find Out Avg.Waiting Time

float findAvgWatingTime(int totalproc, int waitingTime[], float AvgWaitingTime)
{
    float totalWaitingTime = 0;

    for (int j = 0; j < totalproc; j++)
    {
        totalWaitingTime = totalWaitingTime + waitingTime[j];
    }
    return AvgWaitingTime = (float)totalWaitingTime / (float)totalproc;

}

// Lets Print Whole Answer in the form of Table

void printWholeTable(int totalproc, int ProcessId[], int ArrivalTime[], int BurstTime[], int completionTime[], int TurnAroundTime[], int waitingTime[], float x)
{

    cout << "Process Id"
         << "\t"
         << "Arrival Time"
         << "\t"
         << "Burst Time"
         << "\t"
         << "Completion Time"
         << "\t   "
         << "Turn Around Time"
         << "\t"
         << "Waiting Time" << endl;

    for (int i = 0; i < totalproc; i++)
    {
        cout << ProcessId[i] << "\t\t\t" << ArrivalTime[i] << "\t     " << BurstTime[i] << "\t\t\t" << completionTime[i] << "\t\t" << TurnAroundTime[i] << "\t\t\t" << waitingTime[i] << endl;
    }
    cout << "\t\t\t\t\t\t\t\t\t\t" << "Avg.Waiting Time is : "<< x <<  endl;
}

int main()
{

    // ask To user how much process it have
    int totalproc;
    cout << " Please tell how many process you want to execute : ";
    cin >> totalproc;
    cout << endl;

    int ProcessId[10] = {0};
    int ArrivalTime[10] = {0};
    int BurstTime[10] = {0};

    cout << "ProcessId No. "
         << "    "
         << "Arrival Time" << endl;
    for (int i = 1; i <= totalproc; i++)
    {
        ProcessId[i - 1] = i;
        cout << ProcessId[i - 1] << "\t\t\t";
        cin >> ArrivalTime[i - 1];
    }

    cout<<endl<<endl;

    cout << "ProcessId No. "
         << "    "
         << "Arrival Time"
         << "    "
         << "Enter the Burst Time " << endl;
    for (int i = 0; i < totalproc; i++)
    {
        cout << ProcessId[i] << " \t\t\t";
        cout << ArrivalTime[i] << " \t\t\t";
        cin >> BurstTime[i];
    }

    cout<<endl<<endl;
    
    shortAllArrivalBurstArray(totalproc, ArrivalTime, BurstTime, ProcessId);
    int waitingTime[10] = {0};
    int completionTime[10] = {0};
    int TurnAroundTime[10] = {0};
    

    findCompletionTime(totalproc, ArrivalTime, BurstTime, completionTime);
    findTurnAroundTime(totalproc, ArrivalTime, completionTime, TurnAroundTime);
    findWaitingTime(totalproc, TurnAroundTime, BurstTime, waitingTime);
    float AvgWaitingTime = 0;
    float x = findAvgWatingTime(totalproc, waitingTime, AvgWaitingTime);

    printWholeTable(totalproc, ProcessId, ArrivalTime, BurstTime, completionTime, TurnAroundTime, waitingTime, x);
}