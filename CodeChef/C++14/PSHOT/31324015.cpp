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
        ll n, c = 0, a= 0, b = 0;
        cin >> n;
        string s;
        cin >> s;
        ll cnt = 0, cnt1 = 0;
        for(int i = 0; i < 2*n; ++i){
            if(i%2 == 0){
                cnt++;
                if(s[i] == '1')
                    a++;
            }
            else{
                cnt1++;
                if(s[i] == '1')
                    b++;
            }
            if(a-b > n-cnt1){
                cout << i + 1 << '\n';
                c++;
                break;
            }
            else if(b-a > n-cnt){
                cout << i+1 << '\n';
                c++;
                break;
            } 
        }
        if(c == 0)
            cout << 2*n << '\n';
    }
    return 0;
}