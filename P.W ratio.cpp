#include <bits/stdc++.h>
using namespace std;

struct activity {
    char name[10];
    double p;
    double w;
    double r;
};

int main() {
    int n;
    cin >> n;

    double cap;
    cin >> cap;

    vector<activity> act(n);

    for (int i = 0; i < n; i++) {
        cin >> act[i].name >> act[i].p >> act[i].w;
        act[i].r = act[i].p / act[i].w;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (act[j].r < act[j + 1].r) {
                swap(act[j], act[j + 1]);
            }
        }
    }

    double tp = 0.0;

    for (int i = 0; i < n; i++) {
        if (cap == 0) {
            break;
        }
        else if (act[i].w <= cap) {
            cap -= act[i].w;
            tp += act[i].p;
        }
        else {
            tp += act[i].r * cap;
            cap = 0;
        }
    }

    cout << tp << endl;
    return 0;
}
