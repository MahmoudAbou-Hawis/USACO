#include <bits/stdc++.h>
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define So_Far cout.tie(0);
#define fi(i,s,e) for(int i =s;i<e;i++)
#define fd(i,e,s) for(int i=e;i>=s;i--)
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

ll n, m , result = INT64_MAX;
vector<array<ll ,4>> chosed;
vector<array<ll ,4>> air_condation;
vector<tuple<ll,ll,ll>> cows;

void check()
{
    map<ll,ll> point_degree;
    ll cost = 0;
    for(auto &[ai,bi,pi,m] : chosed)
    {
        for(int i = ai ; i <=bi ; i++)
        {
            point_degree[i] += pi;
        }
        cost += m;
    }
    bool valid = true;

    for(auto &[a,b,d] : cows)
    {
        for(int i = a ; i <=b ; i++)
        {
           if(d > point_degree[i])
           {
                valid = false;
                break;
           }
        }
    }
    if(valid)
    {
        result = min(result,cost);
    }
}

void search(int idx)
{
    if(idx == m)
    {   
        check();
        return;
    }
    chosed.pb(air_condation[idx]);
    search(idx +1);
    chosed.pop_back();
    search(idx +1);
}

int main()
{
    setIO("");
    cin >> n >> m;
    int a,b,c,d;
    
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a >> b >> c;
        cows.pb({a,b,c});
    }
    ;

    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b >> c >> d;
        std::array<ll, 4> arr  = {a, b, c, d};
        air_condation.push_back(arr);
    }   

    search(0);

    cout << result;
    return 0;
}