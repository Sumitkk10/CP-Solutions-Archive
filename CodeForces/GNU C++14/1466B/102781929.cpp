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
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    set<int> s;
    s.insert(a[0]);
    for(int i = 1; i < n; ++i){
        if(a[i] == a[i - 1])
            ++a[i];
        else if(a[i - 1] == a[i] + 1)
            ++a[i];
        s.insert(a[i]);
    }
    cout << s.size() << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();    
    return 0;
}
