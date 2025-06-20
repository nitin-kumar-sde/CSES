#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define N 1000005
#define MOD 1000000007

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/CSES/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/CSES/output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    vector<pair<int,int>> movieTimes(n);

    for(int i=0;i<n;i++) {
        cin >> movieTimes[i].first;
        cin >> movieTimes[i].second;
    }

    // sort pair based on movie end times
    sort(movieTimes.begin(), movieTimes.end(), [](const auto &a, const auto &b) {
        return (a.second < b.second) || (a.second == b.second && a.first < b.first);
    });

    int prev = -1;
    int count = 0;
    for(int i=0;i<n;i++) {

        if(movieTimes[i].first >= prev) {
            count++;
            prev = movieTimes[i].second;
        }
    }

    cout << count << endl;
    return 0;
}