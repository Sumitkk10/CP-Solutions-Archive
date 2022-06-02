#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    long long int n;
    cin >> n;
    int c[n + 1];
    int a = -1, b = -1;
    for(int i = 0; i < n; ++i){
        cin >> c[i];
        if(c[i] == 3) a = i;
        if(c[i] == 5) b = i;
    } 
    if(a == -1 or b == -1) cout << "-1\n";
    else if(abs(b - a) != 2) cout << "-1\n";
    else cout << c[min(b, a) + 1] << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
