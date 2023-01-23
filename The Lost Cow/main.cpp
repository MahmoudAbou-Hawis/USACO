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
void setIO(string name = "") {
    Code By So_Far
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
int main() {
    setIO("lostcow");
    int x,y;
    cin>>x>>y;
    int ans = 0;
    for(int i = 0 ; i <12 && x!=y;i++)
    {
        if((i&1 && y >= (x-(1<<i)) && y < x) || (!(i&1) && y <= ((1<<i)+x) && y >x))
        {
            break;
        }
        ans += 2*(1<<i);
    }
    ans+=abs(x-y);
    cout<<ans;
    return 0;
}

