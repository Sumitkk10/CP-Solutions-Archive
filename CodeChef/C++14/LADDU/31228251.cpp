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
        ll n, sum = 0;
        cin >> n;
        string s, a;
        cin >> s;
        for(int i = 0; i < n; ++i){
            cin >> a;
            if(a == "CONTEST_WON"){
                ll b;
                cin >> b;
                sum += 300;
                if(b<20)
                    sum += 20-b;
            }
            else if(a == "TOP_CONTRIBUTOR")
                sum += 300;
            else if(a == "BUG_FOUND"){
                ll c;
                cin >> c;
                if(c >= 50)
                    sum+= c;
            }
            else if(a == "CONTEST_HOSTED")
                sum += 50;
        }
        if(s == "INDIAN")
            cout << sum/200 << '\n';
        else
            cout << sum/400 << '\n';
    }
    return 0;
} 