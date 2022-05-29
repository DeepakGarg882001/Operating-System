#include <iostream>
#include <limits>
using namespace std;

class Process
{
public:
    int processName;
    int arrivalTime;
    int burstTime;
    int priority;

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
    cout << "\nEnter Burst Time, Arrival Time & Priority for each Process : \n\n";

    for (int i = 0; i < numOfProcesses; i++)
    {
        cout << "Process : #" << i + 1 << endl;
        processes[i].processName = i + 1;
        cout<<"Burst Time : ";
        cin >> processes[i].burstTime ;
        cout<<"Arrival Time : ";
        cin >> processes[i].arrivalTime;
        cout<<"Priority : ";
        cin >> processes[i].priority;
        cout<<endl;
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

    int currentTime = 0;

    while (true)
    {

        int currentHighestPriorityIndex = -1;
        int currentHighestPriority = numeric_limits<int>::max();

        bool isAllCompleted = true;

        for (int i = 0; i < numOfProcesses; i++)
        {
            if (processes[i].remainingTime > 0)
            {
                isAllCompleted = false;

                if (processes[i].arrivalTime <= currentTime)
                {
                    if (processes[i].priority < currentHighestPriority)
                    {
                        currentHighestPriority = processes[i].priority;
                        currentHighestPriorityIndex = i;
                    }
                }
            }
        }

        if (isAllCompleted)
        {
            break;
        }

        processes[currentHighestPriorityIndex].remainingTime--;
        currentTime++;

        if (processes[currentHighestPriorityIndex].remainingTime == 0)
        {
            processes[currentHighestPriorityIndex].completionTime = currentTime;
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

    cout << "\nProcess \t Burst Time \t Arrival Time \t Priority \t Waiting Time \t Turnaround Time " << endl;
    cout << "--------------------------------------------------------------------------------------------------";

    for (int n = 0; n < numOfProcesses; n++)
    {
        processes[n].turnAroundTime = processes[n].completionTime - processes[n].arrivalTime;
        processes[n].waitingTime = processes[n].turnAroundTime - processes[n].burstTime;

        cout << "\n #" 
             << processes[n].processName
             << "\t\t      " 
             << processes[n].burstTime 
             << "\t\t      " 
             << processes[n].arrivalTime 
             << "\t             " 
             << processes[n].priority 
             << "\t\t      " 
             << processes[n].waitingTime 
             << "\t\t        " 
             << processes[n].turnAroundTime;

        sumWaitingTime += processes[n].waitingTime;
        sumTurnAroundTime += processes[n].turnAroundTime;
    }

    cout << "\n\n Average Waiting Time : " 
         << (float)sumWaitingTime / numOfProcesses;

    cout << "\n Average Turn Around Time : " 
         << (float)sumTurnAroundTime / numOfProcesses;

    cout<<endl<<endl<<endl;     

    return 0;
}