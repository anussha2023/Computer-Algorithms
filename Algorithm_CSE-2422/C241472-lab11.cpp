#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> activities(n);
    for(int i = 0; i < n; i++){
        cin >> activities[i].first >> activities[i].second;
    }

    sort(activities.begin(), activities.end(),
         [](auto &a, auto &b){
             return a.second < b.second;
         });

    int count = 1;
    int last_finish = activities[0].second;

    for(int i = 1; i < n; i++){
        if(activities[i].first >= last_finish){
            count++;
            last_finish = activities[i].second;
        }
    }

    cout << count << endl;
    return 0;
}
