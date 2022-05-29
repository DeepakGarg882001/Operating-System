#include <iostream>
#include <limits>
using namespace std;

class Process
{
public:
    int processName;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int waitingTime;
    int turnAroundTime;

    void initialize()
    {
        remainingTime = burstTime;
    }
};

int main()
{
    int numOfProcesses;
    cout << "Enter No. of processes : ";
    cin >> numOfProcesses;

    Process processes[numOfProcesses];
    cout << "\nEnter Burst Time & Arrival Time for each Process : \n\n";

    for (int i = 0; i < numOfProcesses; i++)
    {
        cout << "Process : # " << i + 1 << endl;
        processes[i].processName = i + 1;
        cout << "Burst Time : ";
        cin >> processes[i].burstTime;
        cout << "Arrival Time : ";
        cin >> processes[i].arrivalTime;
        cout << endl
             << endl;
        processes[i].initialize();
    }

    cout << endl;

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

    int currentTime = 0;

    while (true)
    {
        int currentLowestBurstIndex = -1;
        int cureentLowestBurst = numeric_limits<int>::max();

        bool isAllCompleted = true;

        for (int i = 0; i < numOfProcesses; i++)
        {
            if (processes[i].remainingTime > 0)
            {
                isAllCompleted = false;
                if (processes[i].arrivalTime <= currentTime)
                {
                    if (processes[i].burstTime < cureentLowestBurst)
                    {
                        cureentLowestBurst = processes[i].burstTime;
                        currentLowestBurstIndex = i;
                    }
                }
            }
        }

        if (isAllCompleted)
        {
            break;
        }
        processes[currentLowestBurstIndex].remainingTime--;
        currentTime++;

        if (processes[currentLowestBurstIndex].remainingTime == 0)
        {
            processes[currentLowestBurstIndex].completionTime = currentTime;
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

    cout << "\nProcess No. \t Burst Time \t Arrival Time \t Waiting Time \t Turnaround Time " << endl;
    cout << "--------------------------------------------------------------------------------------------------";

    for (int n = 0; n < numOfProcesses; n++)
    {
        processes[n].turnAroundTime = processes[n].completionTime - processes[n].arrivalTime;
        processes[n].waitingTime = processes[n].turnAroundTime - processes[n].burstTime;

        cout << "\n # "
             << processes[n].processName
             << " \t\t      "
             << processes[n].burstTime
             << "   \t\t "
             << processes[n].arrivalTime
             << " \t\t "
             << processes[n].waitingTime
             << "\t\t"
             << processes[n].turnAroundTime;

        sumWaitingTime += processes[n].waitingTime;
        sumTurnAroundTime += processes[n].turnAroundTime;
    }

    cout << "\n\nAverage Waiting Time : "
         << (float)sumWaitingTime / numOfProcesses;

    cout << "\nAverage Turn Around Time : "
         << (float)sumTurnAroundTime / numOfProcesses;

    cout << endl
         << endl
         << endl;

    return 0;
}