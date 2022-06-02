#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    long long n;
    cin >> n;
    int a[3] = {5, 15, 75};
    int ct = 0;
    for(int i = 0; i < 3; ++i)
        if(n % a[i] == 0) ++ct;
    cout << ct << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}