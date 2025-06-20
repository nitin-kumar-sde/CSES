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

    map<int, int> indexMap;

    int n; cin >> n;

    for(int i=1;i<=n;i++) {
        int temp; cin >> temp;
        indexMap[temp] = i;
    }

    int count = 1;

    for(int i=2;i<=n;i++) {
        if(indexMap[i] < indexMap[i-1])
        count++;
    }

    cout << count << endl;
    return 0;
}