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

int dice_numbers[] = {1,2,3,4,5,6};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/CSES/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/CSES/output.txt", "w", stdout);
    #endif

    int n; cin >> n;

    vector<ll> dp(n+1, 0);
    dp[0] = 1;
    
    for(int i=1;i<=n;i++) {

        for(int j=0;j<6;j++) {
            if(i>=dice_numbers[j]) {
            dp[i] += dp[i-dice_numbers[j]];
            dp[i] %= MOD;
            }
        }  
    }
    cout << dp[n];
    return 0;
}