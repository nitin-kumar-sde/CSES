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
    map<int,int> frequency;

    for(int i=0;i<n;i++) {
        int input;
        cin >> input;
        frequency[input]++;
    }
   
    ll count = 1;

    map<int,int>::iterator it = frequency.begin();

    while(it != frequency.end()) {
        count = (count * (it->second + 1))%MOD;
        it++;
    }

    count = (count - 1 + MOD)%MOD;
    cout << count << endl;
    return 0;
}