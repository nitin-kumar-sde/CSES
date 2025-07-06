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

    int n, a, b; cin >> n >> a >> b;
    vector<ll> prefix_sum(n+1, 0);

    for(int i=1;i<=n;i++) {
        int temp; cin >> temp;
        prefix_sum[i] = prefix_sum[i-1] + temp;
    }

    ll ans = -1e16;
    multiset<ll> prefix_sum_in_window;

    for(int i=a;i<=n;i++) {
        prefix_sum_in_window.insert(prefix_sum[i-a]);
        auto it = *prefix_sum_in_window.begin();
        ans = max(ans, prefix_sum[i] - it);

        if(i >= b)
        prefix_sum_in_window.erase(prefix_sum_in_window
            .find(prefix_sum[i-b])); // remove elements outside of window
    }

    cout << ans << endl;
    return 0;
}