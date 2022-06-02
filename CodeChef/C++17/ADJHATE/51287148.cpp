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
    int a[n + 1];
    vector<int> odd, even;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if(a[i] % 2)
            odd.push_back(a[i]);
        else
            even.push_back(a[i]);
    }
    if(!odd.size() or !even.size()) cout << "-1\n";
    else{
        for(auto k : odd) cout << k << ' ';
        for(auto k : even) cout << k << ' ';
        cout << "\n";
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
