#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <stack>
#include <fstream>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define N 1000005
#define MOD 1000000007
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/CSES/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/CSES/output.txt", "w", stdout);
    #endif

    int n; cin >> n; 
    stack<pii> prev_smaller_element;

    for(int i=1;i<=n;i++) {
        int temp; cin >> temp;

        while(!prev_smaller_element.empty() && prev_smaller_element.top().first >= temp)
        prev_smaller_element.pop();

        if(prev_smaller_element.empty()) 
        cout << 0 << " ";
        else 
        cout << prev_smaller_element.top().second << " "; 

        prev_smaller_element.push({temp, i});
    }

    return 0;
}