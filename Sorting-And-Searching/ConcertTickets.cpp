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
    int m; cin >> m;

    multiset<int> prices;

    for(int i=0;i<n;i++) {
        int temp; cin >> temp;
        prices.insert(temp);
    }

    int ticket;

    for(int i=0;i<m;i++) {
        cin >> ticket;

        auto it = prices.upper_bound(ticket);

        if(it == prices.begin())  ticket = -1;

        else {
            it--;
            ticket = *it;
            prices.erase(it);
        }

        cout << ticket << endl;
    }

    return 0;
}