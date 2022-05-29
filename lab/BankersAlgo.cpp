#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cout << "\nEnter the number of processes : ";
    cin >> n;
    cout << "\nEnter the total resources : ";
    cin >> m;
    int permutate[n];
    for (int i = 0; i < n; i++)
    {
        permutate[i] = i + 1;
    }
    vector<int> safeseq;
    vector<vector<int>> possibleper;
    vector<int> one;
    do
    {
        for (int i = 0; i < n; i++)
        {
            one.push_back(permutate[i]);
        }
        possibleper.push_back(one);
        one.clear();
    } while (next_permutation(permutate, permutate + n));
    int allocated[n][m], max[n][m], available[m], need[n][m];
    cout << "\nEnter the available resources : ";
    for (int i = 0; i < m; i++)
    {
        cin >> available[i];
    }
    cout << "\nEnter the allocated resources : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P[" << i << "]: ";
        for (int j = 0; j < m; j++)
        {
            cin >> allocated[i][j];
        }
    }
    cout << "\nEnter the maximum resources : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P[" << i << "]: ";
        for (int j = 0; j < m; j++)
        {
            cin >> max[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocated[i][j];
    }
    int tempavail[m];
    for (int i = 0; i < possibleper.size(); i++)
    {
        int safe = 1;
        for (int a = 0; a < m; a++)
        {
            tempavail[a] = available[a];
        }
        for (int j = 0; j < possibleper[i].size(); j++)
        {
            int flag = 0;
            for (int k = 0; k < m; k++)
            {
                if (need[(possibleper[i][j] - 1)][k] > tempavail[k])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                safe = 0;
                break;
            }
            if (flag == 0)
            {
                for (int y = 0; y < m; y++)
                    tempavail[y] += allocated[(possibleper[i][j] - 1)][y];
            }
        }
        if (safe == 1)
        {
            safeseq.push_back(i);
        }
    }
    if (safeseq.size() == 0)
    {
        cout << "\n\n No Safe Sequence :)";
    }
    else
    {
        cout << "\n\nSafe Sequences Are : " << endl;
        for (int i = 0; i < safeseq.size(); i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "P-" << possibleper[safeseq[i]][j] - 1;
                if (j != n - 1)
                {
                    cout << " -> ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}