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

ll dp[N][N] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/CSES/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/CSES/output.txt", "w", stdout);
    #endif
    
    int n; cin >> n;
    vector<ll> input(n);
    ll sum = 0; 
    for(int i=0;i<n;i++) {
    cin >> input[i];
    sum+=input[i];
    }

    for(int i=n-1;i>=0;i--) {
        for(int j=i;j<n;j++) {
            if(i==j)
            dp[i][j] = input[i];
            else 
            dp[i][j] = max(input[i] - dp[i+1][j], 
                input[j] -dp[i][j-1]);
        }
    }
    ll ans = (dp[0][n-1] + sum)/2;
    cout << ans << endl;
    return 0;
}