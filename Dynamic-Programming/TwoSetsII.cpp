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
#define N 500005
#define MOD 1000000007
ll dp[N][2] = {0};

ll modInverse(ll a, ll mod) {
    ll res = 1, power = mod - 2;
    while (power) {
        if (power & 1) res = res * a % mod;
        a = a * a % mod;
        power >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/CSES/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/CSES/output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    ll sum = ((n)*(n+1))/2;

    if(sum%2){
        cout << 0 << endl;
        return 0;
    }

    ll target = sum/2;
    dp[0][0] = 1;
    int col = 1;

    for(int i=1;i<=n;i++) {
        for(int j=0;j<N;j++) {
            dp[j][col] = dp[j][col^1];   
            if(j >= i)
            dp[j][col] = (dp[j][col] + dp[j-i][col^1])%MOD;
        }
        col = col ^ 1;
    }

    ll ans = dp[target][col ^ 1];
    ans = ans * modInverse(2, MOD) % MOD;

    cout << ans << endl;

    return 0;
}