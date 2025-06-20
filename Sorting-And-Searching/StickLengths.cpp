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
    vector<int> nums(n);

    for(int i=0;i<n;i++)
    cin >> nums[i];

    sort(nums.begin(), nums.end());

    int median = nums[n/2];
    
    ll minCost = 0;
    
    for(int i=0;i<n;i++) {
        minCost += (abs(nums[i] - median));
    }

    cout << minCost << endl;
    return 0;
}