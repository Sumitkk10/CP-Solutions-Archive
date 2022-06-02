#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll n, m;
    cin >> n >> m;
    priority_queue<ll> a;
    for(int i = 0; i < n+m; ++i){
        ll x;
        cin >> x;
        if(x != -1){
            a.push(x);
        }
        else if(x == -1){
            cout << a.top() << '\n';
            a.pop();
        }
    }
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#
