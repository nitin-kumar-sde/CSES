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
    
    int n; cin >> n;

    vector<int> coins(n);

    for(int i=0;i<n;i++) 
    cin >> coins[i];

    sort(coins.begin(), coins.end());

    ll missCount = 1;

    for(int i=0;i<n;i++) {

        if(coins[i] <= missCount)
        missCount += coins[i];
    }

    cout << missCount << endl;
    return 0;
}