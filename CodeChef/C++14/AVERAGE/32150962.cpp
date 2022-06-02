#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll n, ans = 0;
    cin >> n; 
    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    vector<ll> vv;
    vector<ll> res;
    for(int i = 0; i < n; i++){
        if(vv.empty() == true){
            vv.push_back(v[i]);
            continue;
        }
        if(v[i] == vv.back()){
            res.push_back(v[i]);
            continue;
        }
        vv.push_back(v[i]);
    }
    ll nn = vv.size();
    for(int i = 1; i < nn - 1; i++){
        int lftpt = i - 1, rtpt = i + 1;
        while(lftpt >= 0 && rtpt < nn){
            ll sum = vv[lftpt] + vv[rtpt];
            if(sum == 2 * vv[i]){
                res.push_back(vv[i]);
                break;
            }
            if(sum > 2 * vv[i]){
                lftpt--;
            }
            else rtpt++;
        }
    }
    sort(res.begin(), res.end());
    for(int i = 0, j = 0; i < n && j < res.size();){
        if(v[i] == res[j]){
            ++ans;
            i++;
        }
        else if(v[i] < res[j]) ++i;
        else ++j;
    }
    


    cout << ans;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#