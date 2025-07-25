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
    
    int n, target_sum; 
    cin >> n >> target_sum;

    ll sum = 0;
    ll count = 0;
    map<ll, int> sum_count;
    sum_count[0] = 1;

    for(int i=0;i<n;i++) {
       int temp; cin >> temp;
       sum += temp;
       count += (sum_count[sum -target_sum]);
       sum_count[sum]++;
    }
    
    cout << count << endl;
    return 0;
}