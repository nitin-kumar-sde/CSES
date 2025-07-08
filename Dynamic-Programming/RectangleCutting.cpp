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
#define N 505
#define MOD 1000000007


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/CSES/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/CSES/output.txt", "w", stdout);
    #endif

    int a,b; cin >> a >> b;
    vector<vector<int> > dp(a + 1, vector<int>(b + 1, 1e9));
    for(int i=0;i<=a;i++) {
        for(int j=0;j<=b;j++) {
            if(i==j)
            dp[i][j] = 0;
            else {
                for(int k=i-1;k>=0;k--) {
                    dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
                }
                for(int k=j-1;k>=0;k--) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
                }
            }
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}