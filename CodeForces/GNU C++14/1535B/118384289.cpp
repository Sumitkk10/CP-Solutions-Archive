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
    int a[n];
    vector<int> odd, even;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(a[i] % 2) odd.push_back(a[i]);
        else even.push_back(a[i]);
    }
    int ans = 0;
    for(int i = 0; i < even.size(); ++i)
        for(int j = 0; j < odd.size(); ++j)
            ++ans;
    for(int j = 0; j < odd.size(); ++j){
        for(int k = j + 1; k < odd.size(); ++k)
            if(__gcd(odd[j], 2*odd[k]) > 1)
                ++ans;
    }
    for(int j = 0; j < even.size(); ++j)
        for(int k = j + 1; k < even.size(); ++k)
            ++ans;
    cout << ans << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}