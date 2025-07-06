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
/*
This function checks if its possible create t product in given time.
*/
bool isPossible(vector<ll> time_taken, int n, ll t, ll mid) {
    ll count = 0;

    for(int i = 0; i < n; i++) {
        ll completed_cycles = mid / time_taken[i];
        count += (completed_cycles);
        // break when time exceeds the target
        if(completed_cycles == 0)
        break;
        // break if count exceeds t
        if(count >= t)
        return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/CSES/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/CSES/output.txt", "w", stdout);
    #endif
    
    int n; cin >> n;
    ll t; cin >> t;
    vector<ll> time_taken(n);

    for(int i=0; i<n; i++) {
        cin >> time_taken[i];
    }

    sort(time_taken.begin(), time_taken.end());
    
    ll low = (t * (time_taken.front()))/n;
    ll high = (t * (time_taken.back()));
    
    while(low <=high) {
        ll mid = low + (high - low)/2;

        if(isPossible(time_taken, n, t, mid))
        high = mid - 1;
        else
        low = mid + 1;      
    }

    cout << low << endl;
    return 0;
}