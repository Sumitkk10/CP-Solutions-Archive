#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e6 + 3;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        map<char, int> mp;
        for(int i = 0; i < s.size(); ++i) mp[s[i]]++;
        ll str, end;
        cin >> str >> end;
        ll q;
        cin >> q;
        while(q--){
            ll a, b;
            cin >> a >> b;
            ll diff = str - a;
            ll diff1 = end - b;
            if(str < a){
                if(mp['R'] < abs(diff)) cout << "NO\n";
                else{
                    if(end > b){
                        if(mp['D'] < abs(diff1)) cout << "NO\n";
                        else cout << "YES " <<  abs(diff) + abs(diff1) << "\n";
                    }
                    else{
                        if(mp['U'] < abs(diff1)) cout << "NO\n";
                        else cout << "YES " <<  abs(diff) + abs(diff1) << "\n";
                    }
                }
            }
            else{
                if(mp['L'] < abs(diff)) cout << "NO\n";
                else{
                    if(end > b){
                        if(mp['D'] < abs(diff1)) cout << "NO\n";
                        else cout << "YES " << abs(diff) + abs(diff1) << "\n";
                    }
                    else{
                        if(mp['U'] < abs(diff1)) cout << "NO\n";
                        else cout << "YES " << abs(diff) + abs(diff1) << "\n";
                    }
                }
            }

        }
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}