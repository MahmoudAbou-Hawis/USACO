#include <bits/stdc++.h>
using namespace std;
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Abou_Hawis cout.tie(0);
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
const long long int MOD=1e9 + 7, OO=0x3f3f3f3f;
const long long int  LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;
const int N = 1e5 + 7 ;

void setIO(string name = "") {
    Code By Abou_Hawis
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main()
{
    setIO("triangles");
    int number_of_points;
    cin >> number_of_points;
    vector<pair<ll,ll>>points(number_of_points);
    for(int i = 0 ; i < number_of_points ; i++)
    {
        cin >> points[i].first  >> points[i].second ;
    }
    sort(all(points));
    ll max_area = 0;
    for(int i = 0 ; i < number_of_points ; i++)
    {
        for(int j = 0 ; j < number_of_points ;j++)
        {
            if(points[j].first - points[i].first == 0) 
            {
                for(int k = 0 ; k < number_of_points; k++)
                {
                    if(points[k].s == points[j].s || points[k].s == points[i].s)
                    {
                        max_area = max(max_area,abs(points[k].f - points[i].f) * abs(points[j].s - points[i].s));
                    }
                }
            }
            else if(points[j].second - points[i].second == 0)
            {
                for(int k = j+1 ; k < number_of_points; k++)
                {
                    if(points[k].f == points[j].f || points[k].f == points[i].f)
                    {
                        max_area = max(max_area,abs(points[k].s - points[i].s) * abs(points[j].f - points[i].f));
                    }
                }
            }
        }
    }
    cout << max_area;
    return 0;   
}