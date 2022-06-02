#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < a.size(); ++i){
        a[i] = tolower(a[i]);
    }
    for(int i = 0; i < b.size(); ++i){
        b[i] = tolower(b[i]);
    }
    if(a == b){
        cout << "EQUAL\n";
        return;
    }
    cout << (a > b ? "GREATER\n" : "SMALLER\n");
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
