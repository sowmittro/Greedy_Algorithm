#include<bits/stdc++.h>
using namespace std;

struct activity
{
    char name[10];
    int st;
    int ft;
};

int main()
{
    int n;
    cin >> n;

    struct activity act[n];

    for(int i = 0; i < n; i++)
    {
        cin >> act[i].name >> act[i].st >> act[i].ft;
    }

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(act[j].ft > act[j + 1].ft)
            {
                swap(act[j], act[j + 1]);
            }
        }
    }

    vector<string> selec_act;
    selec_act.push_back(act[0].name);
    int count = 1;
    int last_ft = act[0].ft;

    for(int i = 1; i < n; i++)
    {
        if(act[i].st >= last_ft)
        {
            selec_act.push_back(act[i].name);
            count++;
            last_ft = act[i].ft;
        }
    }

    cout << count << endl;
    cout << "Selected activitis: " << endl;
    for(int i = 0; i < selec_act.size(); i++)
    {
        cout << selec_act[i] << " ";
    }
    cout << endl;
    return 0;
}
