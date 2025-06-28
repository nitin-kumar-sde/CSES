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
#define ppii pair<pair<int, int> , int> 

/**
 * This is not the most optimal solution, some cases are giving TLE.
 * Optimal solution uses BIT - will update later.
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/CSES/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/CSES/output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    vector<ppii>ranges(n);

    for(int i=0;i<n;i++) {
        int l,r; cin >> l >> r;
        ranges[i] = {{l,r}, i};
    }
    sort(ranges.begin(), ranges.end(), [](const ppii & a, const ppii & b) {
        return ( a.first.first < b.first.first || 
            (a.first.first == b.first.first && a.first.second > b.first.second));
    });

    vector<int> num_contained(n, 0);
    vector<int> num_contains(n, 0);

    multiset<int> y_so_far = { ranges[0].first.second};

    for(int i=1;i<n;i++) {
        auto it = y_so_far.lower_bound(ranges[i].first.second);
        
        if(it != y_so_far.end())
        num_contained[ranges[i].second] = distance(it, y_so_far.end());;

        y_so_far.insert(ranges[i].first.second);
    }

    multiset<int, greater<int>> y_so_far_rev = { ranges[n-1].first.second };

    for(int i=n-2;i>=0;i--) {
        auto it = y_so_far_rev.lower_bound(ranges[i].first.second);
        
        if(it != y_so_far.end())
        num_contains[ranges[i].second] = distance(it, y_so_far_rev.end());;

        y_so_far_rev.insert(ranges[i].first.second);
    }

    for(int i=0;i<n;i++) {
        cout << num_contains[i] << " ";
    }

    cout << endl;
    
    for(int i=0;i<n;i++) {
        cout << num_contained[i] << " ";
    }
    return 0;
}