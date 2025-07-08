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

ll dp[N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/CSES/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/CSES/output.txt", "w", stdout);
    #endif
    // pre compute
    dp[1][0]=1;
	dp[1][1]=1;
	for(int i=2;i<=N;i++) {
		dp[i][1]=((2*dp[i-1][1]))%MOD + (dp[i-1][0])%MOD;
		dp[i][0]=(dp[i-1][1]%MOD)+(4*(dp[i-1][0])%MOD)%MOD;
	}
    int t;
    cin >> t;
	while(t--) {
		int n;
        cin>>n;
		cout<<(dp[n][0]+dp[n][1])%MOD << endl;
	}

    return 0;
}