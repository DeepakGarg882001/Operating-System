#include <iostream>
using namespace std;

class Process
{
public:
    int processName;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int completionTime;
    int turnAroundTime;
    int remainingTime;

    void initialize()
    {
        waitingTime = 0;
        turnAroundTime = 0;
        remainingTime = burstTime;
    }
};
int main()
{
    int numOfProcesses;
    int timeQuantum;
    int currentTime = 0;

    cout << "\nEnter No. of Processes : ";
    cin >> numOfProcesses;

    cout << "\nEnter Time Quantum : ";
    cin >> timeQuantum;

    Process processes[numOfProcesses];

    cout << "\nEnter Burst Time & Arrival Time for each Process : \n";


    for (int i = 0; i < numOfProcesses; i++)
    {
        cout << "Process : #" << i + 1 << endl;
        processes[i].processName = i + 1;
        cout << "Burst Time : ";
        cin >> processes[i].burstTime;
        cout << "Arrival Time : ";
        cin >> processes[i].arrivalTime;
        cout << endl
             << endl;
        processes[i].initialize();
    }

    cout << "\n";

    for (int i = 0; i < numOfProcesses - 1; i++)
    {
        for (int j = i + 1; j < numOfProcesses; j++)
        {
            if (processes[j].arrivalTime < processes[i].arrivalTime)
            {
                Process temp = processes[j];
                processes[j] = processes[i];
                processes[i] = temp;
            }
        }
    }

    currentTime = processes[0].arrivalTime;
    int remainingProcesses = numOfProcesses;

    for (int i = 0; i < numOfProcesses; i = (i + 1) % numOfProcesses)
    {
        if (processes[i].remainingTime == 0 && processes[(i + 1) %
                                                         numOfProcesses]
                                                       .arrivalTime > currentTime)
        {
            currentTime = processes[(i + 1) % numOfProcesses].arrivalTime;
        }
        if (processes[i].remainingTime > 0 && processes[i].arrivalTime <= currentTime)
        {
            if (processes[i].remainingTime <= timeQuantum)
            {
                currentTime += processes[i].remainingTime;
                processes[i].completionTime = currentTime;
                processes[i].remainingTime = 0;
                remainingProcesses--;
            }
            else
            {
                currentTime += timeQuantum;
                processes[i].remainingTime -= timeQuantum;
            }
        }
        if (remainingProcesses == 0)
        {
            break;
        }
    }
    for (int i = 0; i < numOfProcesses - 1; i++)
    {
        for (int j = i + 1; j < numOfProcesses; j++)
        {
            if (processes[j].completionTime < processes[i].completionTime)
            {
                Process temp = processes[j];
                processes[j] = processes[i];
                processes[i] = temp;
            }
        }
    }
    int sumWaitingTime = 0;
    int sumTurnAroundTime = 0;

    cout << "\n Process \t Burst Time \t Arrival Time \t Waiting Time \t Turnaround Time " << endl;
    cout << "--------------------------------------------------------------------------------------------------";

    for (int n = 0; n < numOfProcesses; n++)
    {
        processes[n].turnAroundTime = processes[n].completionTime - processes[n].arrivalTime;
        processes[n].waitingTime = processes[n].turnAroundTime - processes[n].burstTime;

        cout << "\n  # "
             << processes[n].processName
             << "\t\t      "
             << processes[n].burstTime
             << "\t\t      "
             << processes[n].arrivalTime
             << "\t\t      "
             << processes[n].waitingTime
             << "\t\t       "
             << processes[n].turnAroundTime;

        sumWaitingTime += processes[n].waitingTime;
        sumTurnAroundTime += processes[n].turnAroundTime;
    }
    cout << "\n\nAverage Waiting Time : "
         << (float)sumWaitingTime / numOfProcesses;

    cout << "\nAverage Turn Around Time : "
         << (float)sumTurnAroundTime / numOfProcesses;

    cout << endl
         << endl;

    return 0;
}