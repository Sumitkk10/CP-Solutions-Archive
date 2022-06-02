#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e4 + 3;

int main(){
    fast;
    ll n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; ++i) 
        cin >> a[i];
    sort(a, a+n, greater<>());
    for(int i = 0; i < n - 2; ++i){
        if(a[i + 1] + a[i + 2] > a[i]){
            cout << "YES\n";
            cout << a[i] << " " << a[i + 1] << " " << a[i + 2] << "\n";
            return 0;
        }
    }
    cout << "NO\n";
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}