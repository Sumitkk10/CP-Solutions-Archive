#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e4 + 3;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        string s, ss;
        cin >> s >> ss;
        string ans, anss;
        for(auto i : s)
            if(i != ',') ans.pb(i);
        for(auto i : ss)
            if(i != ',') anss.pb(i);
        if(ans.size() != anss.size()) cout << "different\n";
        else{
            bool ok = 0;
            for(int i = 0; i < ans.size(); ++i){
                if(ans[i] != anss[i]){
                    ok = true;
                    cout << "different\n";
                    break;
                }
            }
            if(!ok) cout << "equal\n"; 
        }
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}