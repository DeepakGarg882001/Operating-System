#include <bits/stdc++.h>
#include <iostream>
using namespace std;

 int main()
    {                     // memory req for each processs
        int ms, bs, nob, ef, nop, mp[10], tif = 0;
        int i, p = 0;
        cout << "Enter the total memory available in bytes : ";
        cin >> ms;
        cout << "Enter the block size in bytes : ";
        cin >> bs;
        nob = ms / bs;
        ef = ms - nob * bs;
        cout << "Enter the number of processes : ";
        cin >> nop;
        for (i = 0; i < nop; i++)
        {
            cout << "Enter memory required for the processes " << i + 1 << " in bytes : ";
            cin >> mp[i];
        }
        cout << "Number of blocks available in the memory : " << nob << endl;
        cout << "\n\nPROCESSES\t MEMORY REQUIRED\t ALLOCATED\t INTERNAL FRAGMENTATION " << endl;
        for (i = 0; i < nop && p < nob; i++){
            cout << "\n"
                 << i + 1 << "\t\t\t" << mp[i];
            if ((mp[i]) > bs){
                cout << "\t\t\t NO \t\t\t --- ";
            }
            else
            {
                cout << "\t\t\t YES \t\t\t" << bs - mp[i];
                tif = tif + bs - mp[i];
                p++;
            }

        }
        cout << "\n"
             << "Memory is full , remaining processes cannot be accommodated";
        cout << "\n"
             << "Total internal fragmentation is : " << tif << endl;
        cout << "\n"
             << "Total external fragmentation is : " << ef << endl;
    }