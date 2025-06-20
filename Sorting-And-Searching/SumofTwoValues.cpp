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
    int sum; cin >> sum;
    vector<pair<int, int>> numbers(n);

    for(int i=0;i<n;i++) { 
        cin >> numbers[i].first;
        numbers[i].second = i;
    }


    sort(numbers.begin(), numbers.end());

    int i = 0, j = n-1;

    while(i <= j) {
        // no such numbers
        if(i == j) {
            cout << "IMPOSSIBLE" ;
            break;
        }
        // found a pair
        if(numbers[i].first + numbers[j].first == sum) {
            cout << min(numbers[i].second, numbers[j].second) + 1 << " " << max(numbers[i].second, numbers[j].second) + 1;
            break;
        }
        else if(numbers[i].first + numbers[j].first > sum) j--;
        else i++;
    }

    return 0;
}