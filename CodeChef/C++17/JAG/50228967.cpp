#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, w[N];

void solve(){
    cin >> n;
    map<int, int> mp;
    for(int i = 1; i <= n; ++i){
        cin >> w[i];
        mp[w[i] - i]++;
    }
    if(mp.size() == 1){
        for(auto k : mp)
            cout << k.second << "\n";
        return;
    }
    cout << "1\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
