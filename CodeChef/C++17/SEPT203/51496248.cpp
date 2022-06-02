#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n;

void solve(){
    map<string, int> mp;
    string x;
    getline(cin, x);
    for(int j = 1; j <= n; ++j){
        getline(cin, x);
        string name;
        for(int i = x.size() - 1; i >= 0; --i){
            if(x[i] == ' ') break;
            x[i] = tolower(x[i]);
            name.push_back(x[i]);
        }
        reverse(name.begin(), name.end());
        mp[name]++;
    }
    for(auto k : mp)
        cout << k.first << " | " << k.second << '\n';
    
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(true){
        cin >> n;
        if(!n) exit(0);
        cout << "List " << t << ":\n";
        solve();
        ++t;
    }
    return 0;
}
