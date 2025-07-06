#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <numeric>
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

    int n ; cin >> n;
    vector<ll> reading_times(n);

    for(int i=0;i<n;i++) 
    cin >> reading_times[i];

    sort(reading_times.begin(), reading_times.end());
    
    ll last_element = reading_times.back();
    ll sum_till_second_last = accumulate(reading_times.begin(), reading_times.end()-1, (ll)0);
    ll ans = last_element + max(last_element, sum_till_second_last);

    cout << ans << endl;

    return 0;
}