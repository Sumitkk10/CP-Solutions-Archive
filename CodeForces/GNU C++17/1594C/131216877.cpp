#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    char x;
    cin >> n >> x;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> pos;
    bool ok = 0;
    for(int i = 1; i <= n; ++i){
        if(s[i] != x){
            pos.push_back(i);
            if(i == n)
                ok = 1;
        }
    }
    if(!pos.size()){
        cout << "0\n";
        return;
    }
    if(ok){
        map<int, bool> mp;
        for(auto k : pos)
            mp[k] = true;
        for(int i = 1; i <= n; ++i){
            if(mp[i]) continue;
            bool shit = 0;
            for(auto k : pos){
                if(k % i == 0){
                    shit = true;
                    break;
                }
            }
            if(!shit){
                cout << "1\n";
                cout << i << '\n';
                return;
            }
        }
        cout << "2\n";
        cout << n << ' ';
        for(int j = 1; j < n; ++j){
            if(n % j != 0){
                cout << j << '\n';
                return;
            }
        }
        return;
    }
    else{
        cout << "1\n";
        cout << n << "\n";
    }
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
