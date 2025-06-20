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
#define pii pair<int,int> 
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

    set<pii> ranges;
    multiset<int> lengths;

    ranges.insert({0,n});
    lengths.insert(n);

    int m; cin >> m;

    for(int i=0;i<m;i++) {

        int position; cin >> position;
        auto it = prev(ranges.upper_bound({position, position}));
        pii range = *it;
        
        ranges.insert({range.first, position});
        ranges.insert({position, range.second});
        ranges.erase(it);

        int length = range.second - range.first ;
        auto it2 = lengths.lower_bound(length);   
        lengths.erase(it2);
        lengths.insert(position - range.first );
        lengths.insert(range.second - position );
        it2 = prev(lengths.end());
        length = *it2;

        cout << length << endl;
    }

    return 0;
}