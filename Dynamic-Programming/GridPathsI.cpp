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
    vector<string> grid(n);

    for(int i=0;i<n;i++)
    cin >> grid[i];
 
    vector<vector<ll>> dp(n, vector<ll> (2, 0));

    int col = 0;
    dp[n-1][1] = 1;
    for(int i=n-1;i>=0;i--) {
        dp[n-1][col] = (grid[n-1][i]) == '*' ? 0 : dp[n-1][1^col]; 
        for(int j=n-2;j>=0;j--) {
            ll option1 = dp[j+1][col];
            ll option2 = dp[j][1^col];
            if(grid[j][i] == '*') 
            dp[j][col] = 0;
            else
            dp[j][col] = (option1 + option2)%MOD;
        }
        col = 1^col;
    }
    cout << dp[0][1^col] << endl;
    return 0;
}