#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e4 + 3;

int main(){
    fast;
    ll t; 
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        string s[n];
        ll Gryffindor = 0, Slythrin = 0, Ravenclaw = 0, Hufflepuff = 0;
        for(int i = 0; i < n; ++i){ 
            cin >> s[i];
            if(s[i] == "Courage" || s[i] == "Bravery" || s[i] == "Chivalry" || s[i] == "Daring") ++Gryffindor;
            else if(s[i] == "Resourcefulness" || s[i] == "Cunning" || s[i] == "Ambition" || s[i] == "Determination") ++Slythrin;
            else if(s[i] == "Intelligence" || s[i] == "Wit" || s[i] == "Wisdom" || s[i] == "Creativity") ++Ravenclaw;
            else  ++Hufflepuff;
        }
        // cout << Gryffindor << " " << Slythrin << " " << Ravenclaw << " " << Hufflepuff << "\n";
        if(max(Hufflepuff, max(Gryffindor, max(Slythrin, Ravenclaw))) == Gryffindor) cout << "Gryffindor\n";
        else if(max(Hufflepuff, max(Gryffindor, max(Slythrin, Ravenclaw))) == Hufflepuff) cout << "Hufflepuff\n";
        else if(max(Hufflepuff, max(Gryffindor, max(Slythrin, Ravenclaw))) == Ravenclaw) cout << "Ravenclaw\n";
        else cout << "Slytherin\n";
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}