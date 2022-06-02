#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;
const int N = 10 + 5;
const int MOD = 1e9 + 7;

bool possible(pair<long long int, long long int> str, pair<long long int, long long int> end1, string s, long long int time){
    long long int x = 0, y = 0;
    for(auto k : s){
        if(k == 'U')
            ++y;
        else if(k == 'D')
            --y;
        else if(k == 'L')
            --x;
        else
            ++x;
    }
    x *= time / s.size();
    y *= time / s.size();
    long long int rem = time % s.size();
    for(int i = 0; i < rem; ++i){
        if(s[i] == 'U')
            ++y;
        else if(s[i] == 'D')
            --y;
        else if(s[i] == 'L')
            --x;
        else
            ++x;
    }
    x += str.first;
    y += str.second;
    return (abs(x - end1.first) + abs(y - end1.second) <= time);
}

void solve(){
    pair<long long int, long long int> str;
    pair<long long int, long long int> end1;
    cin >> str.first >> str.second;
    cin >> end1.first >> end1.second;
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long int low = 0, high = 1e18, ok = -1;
    while(low <= high){
        long long int mid = low + (high - low) / 2;
        if(possible(str, end1, s, mid)){
            ok = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << ok << '\n';
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}