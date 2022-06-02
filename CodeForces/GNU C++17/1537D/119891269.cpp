#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e9 + 5;
const int MOD = 1e9 + 7;
map<int, bool> mp;

bool isPrime(long long x){
    for(long long i = 2; i*i <= x; ++i)
        if(x % i == 0)
            return false;
    return true;
}

void solve(){
    long long n;
    cin >> n;
    if(isPrime(n)){
        cout << "Bob\n";
        return;
    }
    if(n % 2 == 1){
        cout << "Bob\n";
        return;
    }
    if(mp[n]){
        cout << "Bob\n";
        return;
    }
    cout << "Alice\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    for(long long int i = 2; i <= N; i *= 4)
        mp[i] = true;
    while(t--)
        solve();
    return 0;
}
