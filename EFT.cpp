#include <bits/stdc++.h>
using namespace std;

void activitySelection(vector<string> &act, vector<int> &st, vector<int> &end, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(end[j] > end[j + 1])
            {
                swap(end[j], end[j + 1]);
                swap(st[j], st[j + 1]);
                swap(act[j], act[j + 1]);
            }
        }
    }

    vector<string> selected;
    selected.push_back(act[0]);

    int count = 1;
    int lastFinish = end[0];

    for(int i = 1; i < n; i++)
    {
        if(st[i] >= lastFinish)
        {
            selected.push_back(act[i]);
            count++;
            lastFinish = end[i];
        }
    }

    cout << count << endl;
    cout << "Selected activities:" << endl;

    for(int i = 0; i < selected.size(); i++)
    {
        cout << selected[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<string> act(n);
    vector<int> st(n), end(n);

    for(int i = 0; i < n; i++)
    {
        cin >> act[i] >> st[i] >> end[i];
    }
    activitySelection(act, st, end, n);
    return 0;
}
