#include<bits/stdc++.h>
using namespace std;
 
int pageFaults(int pages[], int n, int frames)
{
    unordered_set<int> s;
 
    unordered_map<int, int> indexes;
 
    int page_faults = 0;
    for (int i=0; i<n; i++)
    {
        if (s.size() < frames)
        {
            if (s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);
 
                page_faults++;
            }
 
            indexes[pages[i]] = i;
        }
 
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int lru = INT_MAX, val;
                for (auto it=s.begin(); it!=s.end(); it++)
                {
                    if (indexes[*it] < lru)
                    {
                        lru = indexes[*it];
                        val = *it;
                    }
                }
                s.erase(val);
 
                s.insert(pages[i]);
 
                page_faults++;
            }
 
            indexes[pages[i]] = i;
        }
    }
 
    return page_faults;
}

// Driver code   7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2
int main()
{
    int size,frames;
    cout<<"Enter the number of pages:";
    cin>>size;
    int pages[size];
    for(int i=0;i<size;i++){
        cout<<"Page["<<i+1<<"]:";
        cin>>pages[i];
    }
    cout<<"Enter the number of frames:";
    cin>>frames;
    int n = sizeof(pages)/sizeof(pages[0]);

    cout << "Page Faults: " << pageFaults(pages, n, frames);

    return 0;
}

