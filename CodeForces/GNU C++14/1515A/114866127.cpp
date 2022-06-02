#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, x;
    cin >> n >> x;
    int a[n], sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
    }
    if(sum == x){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    sort(a, a + n, greater<int>());
    sum = 0;
    vector<int> v;
    for(int i = 0; i < n; ++i){
        if(a[i] == x or sum + a[i] == x){ 
            v.push_back(a[i]);
            continue;
        }
        cout << a[i] << ' ';
        sum += a[i];
    }
    for(auto k : v)
        cout << k << ' ';
    cout << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
