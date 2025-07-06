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
    int target_sum; 
    cin >> target_sum;
    vector<int> numbers(n);

    for(int i=0;i<n;i++)
    cin >> numbers[i];

    int i = 0, j = 0;
    int count = 0;
    int current_sum = 0;
    while( j<n ) {
        // sum i to j
        current_sum+=numbers[j];
        while(current_sum > target_sum) {
            current_sum -= numbers[i];
            i++;
        }
        count+= (current_sum == target_sum);
        j++;
    }
    cout << count << endl;
    return 0;
}