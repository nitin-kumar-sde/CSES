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
#define N 200005
#define MOD 1000000007
#define pip pair<ll, pair<ll, ll>>

vector<pip> jobs(N);
vector<ll> dp(N,0);

int upper_bound(int start, int end, ll target) {
   
    int low = start, high = end-1;

    while(low <= high) {
     int mid = (high - low)/2 + low;
     
     if(jobs[mid].first > target) high = mid - 1;
     else low = mid + 1;    
      
    }

    return low;
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

    for(int i=0;i<n;i++) {
        cin >> jobs[i].first >> jobs[i].second.first >> jobs[i].second.second;
    }
    sort(jobs.begin(), jobs.begin()+n);    // sort based on start times

    dp[n-1] = jobs[n-1].second.second;

    for(int i=n-2;i>=0;i--) {
        dp[i] = dp[i+1];
        int index = upper_bound(i+1, n, jobs[i].second.first);
        dp[i] = max(dp[i], jobs[i].second.second + dp[index]);
    }
    cout << dp[0] << endl;
    return 0;
}