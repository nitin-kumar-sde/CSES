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
#define N 5005
#define MOD 1000000007

int dp[2][N] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/CSES/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/CSES/output.txt", "w", stdout);
    #endif
    
    string s1,s2; cin >> s1 >> s2;

    int n = s1.length(), m = s2.length();

    for(int i=1;i<=m;i++)
    dp[0][i] = i;
    
    int row = 1;
    for(int i=1;i<=n;i++) {
        dp[row][0] = i;

        for(int j=1;j<=m;j++) {
            if(s1[i-1] == s2[j-1])
            dp[row][j] = dp[1^row][j-1];
            else 
            dp[row][j] = 1 + min(dp[1^row][j], 
                min(dp[row][j-1], dp[1^row][j-1]));
        }
        row = 1^row;
    }

    cout << dp[row^1][m] << endl;
    return 0;
}