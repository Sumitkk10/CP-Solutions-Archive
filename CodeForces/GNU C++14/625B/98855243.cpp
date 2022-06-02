#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<iomanip>
#include<map>
#include<deque>
#include<queue>
#include<set>
using namespace std;

typedef long long int ll;

int main(){
    ll c=0;
    string a,b;
    cin>>a>>b;
    ll i=a.find(b);
    while(i!=string::npos){
        c++;
        i=a.find(b, i+b.size());
    }
    cout<<c<<endl;
return 0;}