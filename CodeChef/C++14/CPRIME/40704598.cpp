#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 105;
const int MOD = 1e9 + 7;

bool is_prime(ll x){
    if(x == 1) return false;
    if(x <= 3) return true;
    for(int i = 2; i*i <= x; ++i)
        if(x % i == 0)
            return false;
    return true;
}

bool check(string s){
    ll num = stoll(s);
    if(!is_prime(num))
        return false;
    int i = 0, j = s.size() - 1;
    while(i <= j){
        if(s[i] != s[j])
            return false;
        ++i, --j;
    }
    return true;
}

void solve(){
    string s;
    cin >> s;
    if(check(s))
        cout << "Yes\n"; 
    else
        cout << "No\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}
