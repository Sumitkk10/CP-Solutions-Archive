#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll t;
    cin >> t;
    string s;
    cin >> s;
    while(t--){
        string a;
        cin >> a;
        for(int i = 0; i < a.size(); ++i){
            if(a[i] == '_')
                a[i] = ' ';
            else{
                if(a[i] >= 'A' && a[i] <= 'Z'){
                    a[i] = tolower(a[i]);
                    a[i] = a[i] - 'a';
                    a[i] = s[a[i]];
                    a[i] = toupper(a[i]);
                }
                else if(a[i] >= 'a' && a[i] <= 'z'){
                    a[i] = a[i] - 'a';
                    a[i] = s[a[i]];
                }
            }
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}