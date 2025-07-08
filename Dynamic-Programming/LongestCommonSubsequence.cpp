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
#define N 1005
#define MOD 1000000007

int dp[N][N] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/CSES/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/CSES/output.txt", "w", stdout);
    #endif

    int n, m; cin >> n >> m;
    vector<int> nums1(n);
    vector<int> nums2(m);

    for(int i=0;i<n;i++)
    cin >> nums1[i];

    for(int i=0;i<m;i++)
    cin >> nums2[i];
    
    for(int i=1;i<=n;i++) {
        dp[i][0] = 0;
        for(int j=1;j<=m;j++) {
            if(nums1[i-1] == nums2[j-1])
            dp[i][j] = 1 + dp[i-1][j-1];
            else 
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[n][m] << endl;
    int i = n, j = m;
    vector<int> lcs;
    while(i > 0 && j > 0) {
        if(nums1[i-1] == nums2[j-1]) {
            lcs.push_back(nums1[i-1]);
            i--; j--;
        }
        else if(dp[i][j] == dp[i-1][j])
        i--;
        else 
        j--;
    }
    reverse(lcs.begin(), lcs.end());
    for(int element : lcs) {
        cout << element << " ";
    }
    return 0;
}