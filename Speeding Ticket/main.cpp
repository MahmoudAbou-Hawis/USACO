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
    setIO("speeding");
    int n,m;
    cin>>n>>m;
    vector<pi>RoadSeg(n);
    vector<pi>CowSeg(m);
    int result=0;
    for(int i = 0 ; i < n ; i++)
    {
        cin>>RoadSeg[i].f>>RoadSeg[i].s;
    }
    for(int i = 0 ; i < n ; i++)
    {
        cin>>CowSeg[i].f >> CowSeg[i].s;
    }
    int CowDist   = CowSeg[0].f;
    int RoadSDist = RoadSeg[0].f;
    int i = 0;
    int j = 0;
    while(CowDist + RoadSDist < 200)
    {
        result = max(result , CowSeg[i].s - RoadSeg[j].s);
        if(CowDist == RoadSDist && CowDist != 100)
        {
            i++;j++;
            CowDist+=CowSeg[i].f;
            RoadSDist+=RoadSeg[j].f;
        }
        else if(CowDist > RoadSDist)
        {
            j++;
            RoadSDist+=RoadSeg[j].f;
        }
        else
        {
            i++;
            CowDist+=CowSeg[i].f;
        }
    }
    result = max(result , CowSeg[m-1].s - RoadSeg[n-1].s);
    cout<<result;
    return 0;
}

