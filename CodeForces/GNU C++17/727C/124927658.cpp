#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    ll n, sum1, sum2, sum3;
    cin >> n;
    vector<ll> v;
    for(int i = 1; i <= n - 2; i += 3){
        cout << "? " << i << " " << i + 1 << endl;
        cin >> sum1;
        cout << "? " << i << " " << i + 2 << endl;
        cin >> sum2;
        cout << "? " << i + 1 << " " << i + 2 << endl;
        cin >> sum3;
        ll third = -(sum1 - sum2 - sum3)/2;
        ll second = sum3 - third;
        ll first = sum1 - second;
        v.push_back(first);
        v.push_back(second);
        v.push_back(third);
    }
    if(n % 3 != 0){
        int req = n % 3;
        int i = n - req + 1;
        if(i + 1 <= n){
            cout << "? " << i << " " << i + 1 << endl;
            int x;
            cin >> x;
            cout << "? " << i << " " << i - 1 << endl;
            int xx;
            cin >> xx;
            v.push_back(xx - v[v.size() - 1]);
            v.push_back(x - v[v.size() - 1]);
        }
        else{
            cout << "? " << i << " " << i - 1 << endl;
            int x;
            cin >> x;
            v.push_back(x - v[v.size() - 1]);
        }
    }
    cout << "! ";
    for(auto k : v)
        cout << k << " ";
    cout << endl;
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
