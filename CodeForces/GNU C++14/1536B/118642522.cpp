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
    string s;
    cin >> s;
    char a[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    map<string, bool> mp;
    for(int i = 0; i < s.size(); ++i){
        string cur;
        for(int j = i; j < s.size(); ++j){
            cur.push_back(s[j]);
            mp[cur] = true;
        }
    }
    for(int ln = 1; ln <= 3; ++ln){
        if(ln == 1){
            string cur;
            for(int i = 0; i < 26; ++i){
                cur.push_back(a[i]);
                if(!mp[cur]){
                    cout << cur << '\n';
                    return;
                }
                cur.pop_back();
            }
        }
        if(ln == 2){
            string cur;
            for(int i = 0; i < 26; ++i){
                cur.push_back(a[i]);
                for(int j = 0; j < 26; ++j){
                    cur.push_back(a[j]);
                    if(!mp[cur]){
                        cout << cur << '\n';
                        return;
                    }
                    cur.pop_back();
                }
                cur.pop_back();
            }
        }
        if(ln == 3){
            for(int i = 0; i < 26; ++i){
                string cur;
                cur.push_back(a[i]);
                for(int j = 0; j < 26; ++j){
                    cur.push_back(a[j]);
                    for(int k = 0; k < 26; ++k){
                        cur.push_back(a[k]);
                        if(!mp[cur]){
                            cout << cur << '\n';
                            return;
                        }
                        cur.pop_back();
                    }
                    cur.pop_back();
                }
            }
        }
    }
}

int main(){
    fast;
    int t;
    cin >> t;
    while(t--) solve();
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}