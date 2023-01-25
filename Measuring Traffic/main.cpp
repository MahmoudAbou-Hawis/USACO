#include <bits/stdc++.h>
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define So_Far cout.tie(0);
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
const long long int MOD=1e9+7, OO=0x3f3f3f3f;
const long long int  LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;
void setIO(string name = "") {
    Code By So_Far
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("traffic");
    int n;
    cin>>n;
    vector<pair<string,pi>>street(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin>>street[i].first >> street[i].second.first >> street[i].second.second;
    }
    int low  = -OO;
    int high = OO;
    for(int i = n-1 ; i >= 0 ; i--)
    {
        if(street[i].first == "none" )
        {
            low  = max(low , street[i].s.f);
            high = min(high,street[i].s.s);
        }
        else if(street[i].first =="off")
        {
            low  += street[i].second.f;
            high += street[i].second.s;
        }
        else
        {
            low  -=  street[i].second.s;
            high -=  street[i].second.f;
            low = max(0,low);
        }
    }
    cout << low << " "<< high <<'\n';
     low  = -OO;
     high = OO;
    for(int i = 0 ; i < n ; i++)
    {
        if(street[i].first == "none" )
        {
            low  = max(low , street[i].s.f);
            high = min(high,street[i].s.s);
        }
        else if(street[i].first =="on")
        {
            low  += street[i].second.f;
            high += street[i].second.s;
        }
        else
        {
            low  -=  street[i].second.s;
            high -=  street[i].second.f;
            low = max(0,low);
        }
    }
    cout<< low << " "<< high ;

    return 0;
}
