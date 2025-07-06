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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/CSES/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/CSES/output.txt", "w", stdout);
    #endif

    int n, k; cin >> n >> k;
    vector<pii> movie_timings(n);
    
    for(int i = 0; i < n ;i++) {
        cin >> movie_timings[i].first;
        cin >> movie_timings[i].second;
    }

    // sort based on end time 
    sort(movie_timings.begin(), movie_timings.end(), [](pii a, pii b){
        return ((a.second < b.second) || (a.second == b.second && 
        a.first < b.first));
    });
    
    // movie being watched
    multiset<int> parralle_movies;

    for(int i=0;i<k;i++) {
        parralle_movies.insert(0);
    }

    int movie_count = 0;

    for(int i=0;i<n;i++) {
        auto it = parralle_movies.upper_bound(movie_timings[i].first);

        if(it != parralle_movies.begin()) {
            it--;
            movie_count++;
            parralle_movies.erase(it);
            parralle_movies.insert(movie_timings[i].second);
        }

    }

    cout << movie_count << endl;
    return 0;
}