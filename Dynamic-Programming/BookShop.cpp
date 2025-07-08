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
    
    int n,x; cin >> n >> x;
    vector<ll> prices(n);
    vector<ll> pages(n);

    for(int i=0;i<n;i++)
    cin >> prices[i];

    for(int i=0;i<n;i++)
    cin >> pages[i];

    vector<ll> dp(x+1, 0);

    for(int i=1;i<=n;i++) {

        for(int j=x;j>=0;j--) {
            if(j>=prices[i-1])
            dp[j] = max(dp[j], pages[i-1] + dp[j-prices[i-1]]);
        }
    }

    cout << dp[x] << endl;
    return 0;
}