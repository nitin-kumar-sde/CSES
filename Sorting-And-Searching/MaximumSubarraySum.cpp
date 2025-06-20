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
    
    vector<ll> nums(n); 

    for(int i=0;i<n;i++) {
        cin >> nums[i];
    }

    ll prev_max = -1e9, max_sum = -1e9;

    for(int i=n-1;i>=0;i--) {
        prev_max = nums[i] + max((ll)0, prev_max);
        max_sum = max(max_sum, prev_max);
    }

    cout << max_sum << endl;
    return 0;
}