#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, k;

int query(int i){
    cout << i << endl;
    int x;
    cin >> x;
    return x;
}

void solve(){
    cin >> n >> k;
    int cur = 0;
    for(int i = 0; i < n; ++i){
        bool ok = query(cur ^ i);
        if(ok == 1)
            return;
        cur = i;
    }
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
