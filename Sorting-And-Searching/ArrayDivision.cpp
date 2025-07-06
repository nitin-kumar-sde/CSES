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

bool isPossible(vector<int> array, int n ,int k, ll mid) {
    int num_partitions = 1;
    ll sum = 0;
    int i = 0;

    while(i < n) {
        sum += array[i];
        if(sum > mid) {
            sum = array[i];
            num_partitions++;
            if(sum > mid)
            return false;
        }
        i++;
    }
    return (num_partitions <= k);
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
    int k; cin >> k;
    vector<int> array(n);

    for(int i=0;i<n;i++) {
        cin >> array[i];
    }

    ll low = *max_element(array.begin(), array.end());
    ll high = accumulate(array.begin(), array.end(), (ll) 0);

    while(low <= high) {
        ll mid = (high - low)/2 + low ;
        if(isPossible(array, n, k, mid))
        high = mid - 1;
        else 
        low = mid + 1;
    }

    cout << low << endl;
    return 0;
}