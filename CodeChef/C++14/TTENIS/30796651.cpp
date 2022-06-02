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
        ll sum = 0, sum1 = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '0') sum++;
            else sum1++;
        }
        if(sum1 - sum >= 2) cout << "WIN\n";
        else if(sum - sum1 >= 2) cout << "LOSE\n";
    }
    return 0;
}