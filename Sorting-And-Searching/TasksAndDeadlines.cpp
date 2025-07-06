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

    int n ; cin >> n;
    vector<ll> start_times(n);
    ll deadline_sum = 0;
    
    for(int i=0;i<n;i++) {
        cin >> start_times[i];
        ll deadline; cin >> deadline;
        deadline_sum += deadline;
    }

    sort(start_times.begin(), start_times.end());

    ll prefix_sum = 0;
    for(int i=0;i<n;i++) {
        prefix_sum += start_times[i];
        deadline_sum -= prefix_sum;
    }

    cout << deadline_sum << endl;
    return 0;
}