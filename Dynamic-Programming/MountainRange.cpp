#include <iostream>
#include <vector>
#include <string>
#include <stack>
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
    vector<int> heights(n+2);

    for(int i=1;i<=n;i++)
    cin >> heights[i];

    stack<int> monotonic_stack;
    heights[0] = heights[n+1] = 1e9;
    monotonic_stack.push(0);

    int ans = 1;
    for(int i=1;i<=n;i++) {
        while(heights[monotonic_stack.top()] < heights[i])
        monotonic_stack.pop();
     
        ans = max(ans, i-monotonic_stack.top());
        monotonic_stack.push(i);
    }
    while(!monotonic_stack.empty()) {
        monotonic_stack.pop();
    }
    monotonic_stack.push(n+1);
    for(int i=n;i>=1;i--) {
        while(heights[monotonic_stack.top()] < heights[i])
        monotonic_stack.pop();
     
        ans = max(ans, monotonic_stack.top() - i);
        monotonic_stack.push(i);
    }
    cout << ans << endl;
    return 0;
}