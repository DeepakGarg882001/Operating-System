#include <bits/stdc++.h>
using namespace std;

   int main()
    {
        int MemCapacity = 0, MemReq = 0, MemRem = 0, NoP, count = 0, i;
        cout<<"Enter the Memory capacity for MVT: ";
        cin>>MemCapacity;
        cout<<"Enter How many processes: ";
        cin>>NoP;
        cout<<endl;
        for (i = 0; i < NoP; i++){
            cout<<"Enter Memory required for Process ["<< i+1 <<"]: ";
            cin>>MemReq;
            count = count + MemReq;
            if (MemReq <= MemCapacity)
            {
                if (count == MemCapacity){
                    cout<<"There is no further Memory remaining. (required < capacity)";
                }
                else{
                    cout<<"The Memory allocated for Process ["<< i+1 <<"] is "<<MemCapacity <<"\n";
                    MemRem = MemCapacity - MemReq;
                    cout<<"Remaining Memory is "<<MemRem;
                    MemCapacity = MemRem;
                }
            }
            else{
                cout<<"Memory is not allocated for Process ["<< i+1 <<"] \n";
            }
            cout<<endl<<"External fragmentation for this process is "<<MemRem<<endl<<endl;
        }
    }