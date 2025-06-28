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
#define ppii pair<pair<int, int> , int> 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/CSES/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/CSES/output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    vector<ppii>ranges(n);

    for(int i=0;i<n;i++) {
        int l,r; cin >> l >> r;
        ranges[i] = {{l,r}, i};
    }

    sort(ranges.begin(), ranges.end(), [](const ppii & a, const ppii & b) {
        return ( a.first.first < b.first.first || 
            (a.first.first == b.first.first && a.first.second > b.first.second));
    });

    vector<int> is_contained(n, 0);
    vector<int> contains(n, 0);

    int y_max = ranges[0].first.second;

    for(int i=1;i<n;i++) {
        if(y_max >= ranges[i].first.second)
        is_contained[ranges[i].second] = 1;

        y_max = max(y_max, ranges[i].first.second);
    }

    int y_min = ranges[n-1].first.second;

    for(int i=n-2;i>=0;i--) {
        if(y_min <= ranges[i].first.second)
        contains[ranges[i].second] = 1;

        y_min = min(y_min, ranges[i].first.second);
    }

    for(int i=0;i<n;i++) {
        cout << contains[i] << " ";
    }

    cout << endl;
    
    for(int i=0;i<n;i++) {
        cout << is_contained[i] << " ";
    }
    return 0;
}