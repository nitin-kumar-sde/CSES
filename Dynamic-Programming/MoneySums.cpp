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
#define N 100005
#define MOD 1000000007

int dp[N][2] = {0};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/CSES/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/CSES/output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    vector<int> coins(n+1);

    for(int i=0;i<n;i++)
    cin >> coins[i];
    
    dp[0][0] = 1;

    int col = 1;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<N;j++) {
            dp[j][col] = dp[j][col^1];
            if(j >= coins[i-1])
            dp[j][col] |= dp[j-coins[i-1]][col^1];
        }
        col = col^1;
    }
    vector<int> possible_sums;

    for(int i=1;i<N;i++) {
        if(dp[i][col^1])
        possible_sums.push_back(i);
    }
    cout << possible_sums.size() << endl;

    for(int element : possible_sums)
    cout << element << " ";

    return 0;
}