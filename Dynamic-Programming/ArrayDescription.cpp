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
#define N 105
#define MOD 1000000007
vector<vector<ll>> dp(N, vector<ll> (2, 0));

void calculateFromPrevious(int row, int col) {
    dp[row][col] = (dp[row][1^col] + dp[row-1][1^col] + dp[row+1][1^col])%MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/CSES/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/CSES/output.txt", "w", stdout);
    #endif

    int n,m; cin >> n >> m;
    vector<ll> input(n+1);
    for(int i=0;i<n;i++)
    cin >> input[i];


    for(int j=1;j<=m;j++) {
        if(input[0] == 0)
        dp[j][0] = 1;
    }
    if(input[0] != 0)
    dp[input[0]][0] = 1;

    int col = 1;
    for(int i=2;i<=n;i++) {
       if(input[i-1] != 0) {
          for(int j=1;j<=m;j++)
          dp[j][col] = 0;

          int current_element = input[i-1];
          calculateFromPrevious(current_element, col);
       }

       else {
        for(int j=1;j<=m;j++)
        calculateFromPrevious(j, col);
       }
       col = 1^col;
    }

    ll sum = 0;
    for(int i=1;i<=m;i++) 
    sum = (sum + dp[i][1^col])%MOD;

    cout << sum << endl;
    return 0;
}