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
#define pii pair<int,int>
#define MOD 1000000007

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/CSES/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/CSES/output.txt", "w", stdout);
    #endif

    multiset<int> topTowerElements;
    int n; cin >> n;

    for(int i=0;i<n;i++) {

        int cube; cin >> cube;
        auto it = topTowerElements.upper_bound(cube);

        if(it != topTowerElements.end())
        topTowerElements.erase(it);

        topTowerElements.insert(cube);
    }

    cout << topTowerElements.size() << endl;

}