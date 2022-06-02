#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
 
int main(){
    fast;
    ll n;
    cin >> n;
    ll a[n], max = 0, max1 = 0, ans = 0, ans1 = 0, c = 0, max2 = 0;
    stack <pair<ll,ll> > stk; 
    // creating a stack to store two values the first will contian the position of opening breackets
    // while the second will contain the alternating depth of brackets 
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i){
        if(a[i] == 2){
            ans = (i - stk.top().first)+1; // ans contains the number of values b/w first type opening brackets, i.e,();
            stk.pop();
        }
        else if(a[i] == 4){
            ans1 = (i - stk.top().first)+1; // ans1 contians the number of values b/w the second type of opening brackets, i.e,[];
            stk.pop();
        }
        else if(stk.empty() == true)
            stk.push({i, 1});
        else{
            if(a[stk.top().first] == a[i])
                stk.push({i, stk.top().second}); // pushing the same value if the same type of brackets are found
            else if(a[stk.top().first] != a[i])
                stk.push({i, stk.top().second + 1}); // pushing +1 value if alternating brackets are found
        }
        if(stk.empty() == false)
            c = stk.top().second; 
        if(c > max)
            max = c; // max contains the maximum value of alternating depth
        if(ans > max1)
            max1 = ans; // max1 contains the maximum value of number of values b\w first type opening brackets ,i.e, ();
        if(ans1 > max2)
            max2 = ans1; // max2 contins the maximum value of number of values b/w the second type of opening brackets, i.e,[];
    }
    cout << max << ' ' << max1 << ' ' << max2;
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#