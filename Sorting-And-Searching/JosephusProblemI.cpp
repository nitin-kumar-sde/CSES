#include <iostream>
#include <vector>
#include <string>
#include <queue>
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

    deque<int> dq;
    int n; cin >> n;

    for(int i=1;i<=n;i++)
    dq.push_back(i);

    while(!dq.empty()) {
        
        int front = dq.front();
        dq.pop_front();
        dq.push_back(front);

        front = dq.front(); 
        cout << front << " ";
        dq.pop_front();
    }
    return 0;
}