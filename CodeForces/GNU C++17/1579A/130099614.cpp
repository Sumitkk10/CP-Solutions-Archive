#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    string s;
    cin >> s;
    if(s.size() % 2){
        cout << "NO\n";
        return;
    }
    int ct1 = 0, ct2 = 0, ct3 = 0;
    for(auto k : s){
        ct1 += (k == 'A');
        ct2 += (k == 'B');
        ct3 += (k == 'C');
    }
    cout << (ct2 == ct1 + ct3 ? "YES\n" : "NO\n");
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
