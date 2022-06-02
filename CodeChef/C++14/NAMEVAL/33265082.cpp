#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7; 

ll add(ll a, ll b){
    return((a % MOD + b % MOD) % MOD);
}
ll mul(ll a, ll b){
    return(((a % MOD) * (b % MOD)) % MOD);
}

ll binaryToDecimal(string n) 
{ 
    ll dec_value = 0; 
    ll base = 1;  
    while(n.size() != 0){ 
        char last_digit = n.back();
        int ldd = last_digit - 48; 
        n.pop_back(); 
        dec_value = add(dec_value, mul(ldd,base)); 
        base = mul(base,2); 
    }
    return dec_value; 
}

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        string a;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                a.push_back('0');
            else
                a.push_back('1');
        }
        cout << binaryToDecimal(a) << '\n';
    }
    return 0;
}