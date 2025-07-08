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

    int n, money; cin >> n >> money;
    vector<int> currency(n);
    for(int i=0;i<n;i++)
    cin >> currency[i];

    vector<ll> dp(money+1, 1e18);
    dp[0] = 0;

    for(int i=1;i<=n;i++) {
        dp[0] = 0;
        for(int j=1;j<=money;j++) {
            if(j >= currency[i-1])
            dp[j] = min(dp[j], 1 + dp[j-currency[i-1]]);
        }
    }
    if(dp[money] >= 1e18) dp[money] = -1;

    cout << dp[money] << endl;
    return 0;
}