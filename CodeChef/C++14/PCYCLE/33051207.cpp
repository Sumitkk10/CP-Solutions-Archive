#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll n;
    cin >> n;
    vector<ll> cycle, a(n+1);
    cycle.push_back(-1);
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int k = 1, d = 0, cnt = 0, s = -1;
    for(int i = 1; i <= n; i += 0){
        if(s == -1){
            for(int j = 0; j < cycle.size(); ++j){
                if(i == cycle[j]){
                    ++d;
                    break;
                }
            }
            if(d > 0){
                d = 0;
                ++i;
                continue;
            }
            k = i;
            cycle.push_back(k);
        }
        ++s;
        i = a[i];
        cycle.push_back(i);
        if(i == k){
            s = -1;
            i = k + 1;
            ++cnt;
        }
        d = 0;
    }
    cout << cnt << endl;
    s = -1, k = 1, d = 0;
    vector<ll> cyc;
    cyc.push_back(-1);
    for(int i = 1; i <= n; i += 0){
        if(s == -1){
            for(int j = 0; j < cyc.size(); ++j){
                if(i == cyc[j]){
                    ++d;
                    break;
                }
            }
            if(d > 0){
                d = 0;
                ++i;
                continue;
            }
            k = i;
            cout << k << ' '; 
            cyc.push_back(k);
        }
        ++s;
        i = a[i];
        cyc.push_back(i);
        cout << i << ' ';
        if(i == k){
            s = -1;
            i = k + 1;
            cout << endl;
        }
    }
    return 0;
}