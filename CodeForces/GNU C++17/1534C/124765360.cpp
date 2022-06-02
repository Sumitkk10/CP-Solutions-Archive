#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
ll parent[N];

ll find(int a){
    while(1){
        if(a == parent[a]) return a;
        else{
            parent[a] = parent[parent[a]];
            a = parent[a];
        }
    }
}

void merge(int u, int v){
    int a = find(u), b = find(v);
    if(a == b) return;
    parent[a] = b;
}

ll power(ll x, ll y){
    x %= MOD;
    ll ans = 1;
    while(y){
        if(y & 1)
            ans = (ans * x) % MOD;
        y >>= 1LL;
        x = (x * x) % MOD;
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    int a[n + 1][3];
    for(int i = 1; i <= n; ++i)
        parent[i] = i;
    for(int i = 1; i <= n; ++i)
        cin >> a[i][1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i][2];
    map<int, int> mp;
    for(int i = 1; i <= n; ++i)
        merge(a[i][1], a[i][2]);
    for(int i = 1; i <= n; ++i)
        mp[find(i)]++;
    cout << power(2, mp.size()) << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}