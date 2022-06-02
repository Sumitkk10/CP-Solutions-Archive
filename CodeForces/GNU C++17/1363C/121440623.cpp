#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e3 + 5;
const int MOD = 1e9 + 7;
int n, x, deg[N];

void solve(){
    cin >> n >> x;
    for(int i = 1; i <= n; ++i) deg[i] = 0;
    for(int i = 1; i <= n - 1; ++i){
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    if(deg[x] <= 1){
        cout << "Ayush\n";
        return;
    }
    cout << (n % 2 ? "Ashish\n" : "Ayush\n");
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
