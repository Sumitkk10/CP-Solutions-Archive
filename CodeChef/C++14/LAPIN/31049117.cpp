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
        string s;
        cin >> s;
        ll a[27] = {0}, b[27] = {0}, cnt = 0;
        for(int i = 0; i < s.size()/2; i++){
            a[s[i] - 97]++;
        }
        if(s.size()%2 == 0){
            for(int i = s.size()/2; i < s.size(); ++i){
                b[s[i] - 97]++;
            }
        }
        else{
            for(int i = s.size()/2 + 1; i < s.size(); ++i){
                b[s[i] - 97]++;
            }
        }
        for(int i = 0; i < 27; ++i){
            if(a[i] != b[i]){
                cout << "NO" << '\n';
                cnt++;
                break;
            }
        }
        if(cnt == 0)
            cout << "YES" << '\n';
    }
    return 0;
} 