#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    string s, p;
    cin >> s >> p;
    if(s == p){
        cout << "YES\n";
        return;
    }
    map<char, int> mpp;
    for(int i = 0; i < s.size(); ++i)
        mpp[p[i]]++;
    if(mpp['0'] > 0 and mpp['1'] > 0){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
