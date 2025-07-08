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

    vector<ll> dp(n+1, 1e18);
    dp[0] = 0;

    for(int i=1;i<=n;i++) {
       int num = i;
       while(num) {
        int current_digit = num%10;
        if(current_digit)
        dp[i] = min(dp[i], 1+ dp[i-current_digit]);
        num = num/10;
       }
    }

    cout << dp[n] << endl;

    return 0;
}