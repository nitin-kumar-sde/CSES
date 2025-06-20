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
    ll x; cin >> x;
    
    vector<ll> weight(n);

    for_each(weight.begin(), weight.end(), [](ll & e){
        cin >> e;
    });

    sort(weight.begin(), weight.end());
    
    int i = 0, j = n-1;
    int count = 0;

    while(i<j) {
        // collect pair which sum <= taget sum 
        if(weight[i] + weight[j] <= x) {
            i++; 
            j--;
            count++;
        }
        else j--;
    }

    cout << n - count << endl;

    return 0;
}