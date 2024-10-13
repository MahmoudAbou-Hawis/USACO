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

set<int>result;


void get_result(vector<int> x , vector<int> y ,int steps,int milk)
{
    if(steps == 5)
    {
        result.insert(milk);
        return;
    }
    if(steps & 1)
    {
        for(int i = x.size() -1 ; i >= 0 ; i--)
        {
            int current_gallon = x[i];
            x.pop_back();
            vector<int> z = y;
            z.pb(current_gallon);
            get_result(x,z,steps +1 , milk - current_gallon);
        }
    }
    else
    {
        for(int i = y.size() -1 ; i >= 0 ; i--)
        {
            int current_gallon = y[i];
            y.pop_back();
            vector<int> z = x;
            z.pb(current_gallon);
            get_result(z,y,steps +1 , milk + current_gallon);
        }
    }
}

int main()
{
    setIO("backforth");
     
    vector<int> x(10);
    vector<int> y(10);

    for(auto &i : x)
    {
        cin >> i;
    }

    for(auto &i : y)
    {
        cin >> i;
    }

    get_result(x,y,1,1000);


    cout << result.size();



    return 0;
}