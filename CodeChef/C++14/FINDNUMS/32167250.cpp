#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
ll MOD = 15746;

int main(){
    fast;
    ll s,p,k, cnt = 0, cnt1 = 0, cnt2 = 0;
    cin >> s >> p >> k; 
    if(k == 1 && s != p)
        cout << "NO";
    else if(k == 1 && s == p)
        cout << s;
    else if(k == 2){
        for(int i = 1; i < s-1; ++i){
            ll ans = s-i;
            if(ans*i == p){
                ++cnt;
                cout << i << ' ' << ans;
                break;
            }
        }
        if(cnt == 0)
            cout << "NO";
    }
    else if(k == 3){
        for(int i = 1; i < s-1; ++i){
            for(int j = 1; j <= s-i; ++j){
                ll ans1 = s-(i+j);
                if((ans1*i*j) == p){
                    cnt1++;
                    cout << i << ' ' << j << ' ' << ans1;
                    break;
                }
            }
            if(cnt1 > 0)
                break; 
        }
        if(cnt1 == 0)
            cout << "NO";
    }
    else{
        for(int i = 1; i < s-1; ++i){
            for(int j = 1; j <= s-i; ++j){
                for(int r = 1; r < s-(i+j); ++r){
                    ll ans2 = s-(i+j+r);
                    if((ans2*i*j*r) == p){
                        cnt2++;
                        cout << i << ' ' << j << ' ' << r << ' ' << ans2;
                        break;
                    }
                }
                if(cnt2 > 0)
                    break;
            }
            if(cnt2 > 0)
                break;
        }
        if(cnt2 == 0)
            cout << "NO";
    }
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#
