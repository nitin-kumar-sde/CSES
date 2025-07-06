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
#define pii pair<int,int>

bool checkForSum(vector<pii> numbers, int start_1, int start_2, int end, ll target) {
    ll current_target = target - numbers[start_1].first - numbers[start_2].first;
    int current_start = start_2 + 1;

    while(current_start < end) {
        if(numbers[current_start].first + numbers[end].first == current_target) {
            cout << numbers[start_1].second + 1 << " " << numbers[start_2].second + 1 << " " <<
            numbers[current_start].second +1  << " " << numbers[end].second + 1 << endl;
            return true;
        }
        else if(numbers[current_start].first + numbers[end].first < current_target) {
            current_start++;
        }
        else end--;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/CSES/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/CSES/output.txt", "w", stdout);
    #endif
    
    int n; cin >> n;
    ll target;  
    cin >> target;
    vector<pii> numbers(n);

    for(int i=0;i<n;i++) {
        cin >> numbers[i].first;
        numbers[i].second = i;
    }
    
    sort(numbers.begin(), numbers.end());

    for(int i=0;i<n-3;i++) {
        for(int j= i+1; j < n-2; j++)
        if(checkForSum(numbers, i, j, n-1, target))
        return 0;
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}