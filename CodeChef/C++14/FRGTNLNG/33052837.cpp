#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        string s[n];
        ll e[n];
        for(int i = 0; i < n; ++i){
            cin >> s[i];
            e[i] = -1;
        }
        for(int i = 0; i < k; ++i){
            ll x;
            cin >> x;
            for(int j = 0; j < x; ++j){
                string a;
                cin >> a;
                for(int l = 0; l < n; ++l){
                    if(a == s[l]){
                        e[l] = 1;
                        s[l] = "my_name_is_sumit";
                    }
                }
            }   
        }
        for(int i = 0; i < n; ++i){
            if(e[i] == 1)
                cout <<"YES ";
            else
                cout << "NO ";  
        }
        cout << endl;
    }
    return 0;
}