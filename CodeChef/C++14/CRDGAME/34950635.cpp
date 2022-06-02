#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9+ 7; 

int main() 
{ 
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a[n], b[n], sum = 0, sum1 = 0, chef = 0, morty = 0;
        for(int i = 0; i < n; ++i){
            cin >> a[i] >> b[i];
            while(a[i] > 0){
                ll dig = a[i]%10;
                sum += dig;
                a[i] /= 10;
            }
            while(b[i] > 0){
                ll dig1 = b[i]%10;
                sum1 += dig1;
                b[i] /= 10;
            }
            if(sum > sum1)
                chef++;
            else if(sum1 > sum)
                morty++;
            else{
                chef++;
                morty++;
            }
            sum = 0;
            sum1 = 0;
        }
        if(chef > morty)
            cout << "0" << " " << chef << "\n";
        else if(morty > chef)
            cout << "1" << " " << morty << "\n";
        else
            cout << "2" << " " << morty << "\n";
    }
    return 0; 
} 