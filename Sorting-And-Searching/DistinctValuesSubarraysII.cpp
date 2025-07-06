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

    int n,k; cin >> n >> k;

    vector<ll> input(n);
    for(int i=0;i<n;i++)
    cin >> input[i];

    unordered_map<ll, ll> frequency;
    int i = 0, j = 0;
    ll count  = 0;
    while(j < n) {
        frequency[input[j]]++;
        // move to interval which contain atmost k elements
        while(frequency.size() > k) {
            frequency[input[i]]--;
            if(frequency[input[i]] == 0)
            frequency.erase(input[i]);
            i++;
        }
        count+= (j-i+1);
        j++;
    }

    cout << count << endl;
    return 0;
}