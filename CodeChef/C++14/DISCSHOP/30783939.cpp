#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int main(){
    fast;
    ll n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        ll n = 0, min = 10000000001;
        for(int i = 0; i < s.size(); ++i){
            n = 0;
            for(int j = 0; j < s.size(); ++j){
                if(i==j) continue;
                else{
                    n = (n*10) + (s[j]-48);
                }
            }
            if(n < min) 
                min = n;
        }
        cout << min << '\n';
    }
    return 0;
} 