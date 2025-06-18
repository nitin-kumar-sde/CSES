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
        freopen("/Users/nitinkumar/Desktop/codeforces/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/codeforces/output.txt", "w", stdout);
    #endif

    int n, m, k; cin >> n >> m >> k;

    vector<int> applicantPreferences(n);

    for(int i=0;i<n;i++) cin >> applicantPreferences[i];

    vector<int> apartments(m);

    for(int i=0;i<m;i++) cin >> apartments[i];

    sort(applicantPreferences.begin(), applicantPreferences.end());
    sort(apartments.begin(), apartments.end());
    
    int i=0, j = 0, assignment = 0;
    
    while(i < n && j < m) {
        if(applicantPreferences[i] - k > apartments[j])
        j++;
        else if(applicantPreferences[i] + k < apartments[j])
        i++;
        else {i++; j++;assignment++;}
    }

    cout << assignment << endl;
    return 0;
}