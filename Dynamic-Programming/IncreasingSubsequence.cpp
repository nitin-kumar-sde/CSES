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
    vector<int> input(n);

    for(int i=0;i<n;i++)
    cin >> input[i];

    vector<int> lis;
    lis.push_back(input[0]);

    for(int i=1;i<n;i++) {
        if(input[i] > lis.back())
        lis.push_back(input[i]);
        else {
            int index = lower_bound(lis.begin(), lis.end(),
        input[i]) - lis.begin();
        lis[index] = input[i];
        }
    }
    cout << lis.size() << endl;
    return 0;
}