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

    vector<int> arrival(n), departure(n);

    for(int i=0;i<n;i++) {
        cin >> arrival[i] >> departure[i];
    }

    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int i=0, j=0;
    int count = 0, max_count = 0;
    while(i < n && j < n) {

        if(arrival[i] < departure[j]){
            count++;
            i++;
        }
        else if(arrival[i] > departure[j]) {
            count--;
            j++;
        }
        max_count = max(max_count, count);
    }

    cout << max_count << endl;
    return 0;
}