#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll n, u, w;
    cin >> n;
    ll max = 0, ans = 1, c = 0;
    string s;
    cin >> s;
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            int g = j;
            for(int k = i; k <= j; ++k){
                if(s[k] != s[g]){
                    ++c;
                    break;
                }
                --g;
                if(g<0)
                    break;
            }
            if(c == 0){
                ans = (j-i)+1;
            }
            c = 0;
            if(ans > max){
                max = ans;
                u = j;
                w = i;
            }
        }
    }
    cout << max << '\n';
    for(int i = w; i <= u; ++i)
        cout << s[i];
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#
