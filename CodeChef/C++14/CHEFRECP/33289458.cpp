#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 9;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a[n];
        ll hash[10001] = {0};
        vector<ll> ans;
        for(int i = 0; i < n; ++i){
            cin >> a[i]; 
            hash[a[i]]++;

        }
        int y = 0, cnt = 0;
        for(int i = 0; i < n; ++i){
            cnt = 0;
            for(int j = i + 1; j < n; ++j){
                if(a[i] != a[j])
                    ++cnt;
                if(cnt > 0 && a[i] == a[j]){
                    cout << "NO\n";
                    ++y;
                    break;
                }
            }
            if(y > 0)
                break;
        }
        if( y == 0){
            for(int i = 0; i < 10001; ++i){
                if(hash[i] > 0)
                    ans.push_back(hash[i]);
            }
            sort(ans.begin(), ans.end());
            int d = 0;
            for(int i = 0; i < ans.size()-1; ++i){
                if(ans[i] == ans[i+1]){
                    ++d;
                    cout << "NO\n";
                    break;
                }
            }
            if(d == 0)
                cout << "YES\n";
        }
    }
    return 0;
}