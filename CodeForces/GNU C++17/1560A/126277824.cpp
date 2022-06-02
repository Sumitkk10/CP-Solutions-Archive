#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<int> v;

bool check(ll x){
    if(x % 10 == 3) return false;
    if(x % 3 == 0) return false;
    return true;
}

void solve(){
    int n;
    cin >> n;
    cout << v[n - 1] << "\n";
}

int main(){
    fast;
    for(int i = 1; i < N; ++i){
        if(check(i))
            v.push_back(i);
        if(v.size() > 1005) break;
    }
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
