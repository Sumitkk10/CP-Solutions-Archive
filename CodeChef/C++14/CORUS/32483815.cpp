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
        ll n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        ll hash[27] = {0};
        ll a[q];
        for(int i = 0; i < n; ++i){
            // cout << s[i] << ' ';
            s[i] = s[i] - 'a';
            hash[s[i]]++;
        }
        for(int i = 0; i < q; ++i)
            cin >> a[i];
        ll k = 0, x = 0, mx = 0;
        while(k < q){
            for(int i = 0; i < 27; ++i){
                if(hash[i] < a[k])
                    x = 0;
                else
                    x = hash[i] - a[k]; 
                if(x > 0)
                    mx += x;
            }
            cout << mx << '\n';
            mx = 0;
            ++k;
        }
    }
    return 0;
}
//                              This_Code_Is_Written_By_Sumit!!