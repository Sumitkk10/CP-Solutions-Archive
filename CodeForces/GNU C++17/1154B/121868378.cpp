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
    set<int> s;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        s.insert(a[i]);
    }
    if(s.size() > 3){
        cout << "-1\n";
        return;
    }
    else if(s.size() == 3){
        vector<int> v;
        for(auto k : s)
            v.push_back(k);
        if(v[2] - v[1] == v[1] - v[0])
            cout << v[2] - v[1] << '\n';
        else cout << "-1\n";
        return;
    }
    else if(s.size() == 2){
        vector<int> v;
        for(auto k : s)
            v.push_back(k);
        if((v[1] - v[0]) % 2)
            cout << v[1] - v[0] << '\n';
        else 
            cout << (v[1] - v[0]) / 2 << '\n';
        return;
    }
    cout << "0\n";
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}