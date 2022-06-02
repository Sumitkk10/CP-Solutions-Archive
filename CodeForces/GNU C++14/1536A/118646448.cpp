#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e4 + 3;

void solve(){
    int n;
    cin >> n;
    vector<int> a;
    map<int, int> mp;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        a.push_back(x);
        mp[x] = true;
    }
    while(true){
        if(a.size() > 300) break;
        set<int> s;
        for(int i = 0; i < a.size(); ++i){
            for(int j = i + 1; j < a.size(); ++j){
                if(!mp[abs(a[i] - a[j])]){
                    s.insert(abs(a[i] - a[j]));
                    mp[abs(a[i] - a[j])] = true;
                }
            }
        }
        for(auto k : s)
            a.push_back(k);
        if(s.size() == 0) break;
    }
    if(a.size() > 300){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << a.size() << '\n';
    for(auto k : a) cout << k << ' ';
    cout << '\n';
}

int main(){
    fast;
    int t;
    cin >> t;
    while(t--) solve();
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}