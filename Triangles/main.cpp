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
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair
const long long int MOD = 1e9 + 7, OO = 0x3f3f3f3f;
const long long int LOO = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;
const int N = 1e5 + 7;

void setIO(string name = "")
{
    Code By Abou_Hawis 
    if (sz(name))
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}




int main()
{
    setIO("triangles");

    int N;
    cin >> N;

    vector<pair<int,int>> points(N);

    for(auto &[x , y] : points)
    {
        cin >> x >> y;
    }

    sort(all(points));

    int total = 0;
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = i +1 ; j < N ;j++)
        {
            for(int k = 0 ; k < N ;k++)
            {
                if( k!= i && k!=j &&points[i].s == points[j].s && ((points[k].f == points[i].f) || (points[k].f == points[j].f)) )
                {
                    int area = abs((points[j].f - points[i].f) * (points[k].s - points[i].s));
                    total = max(total , area);
                }
            }
        }
    }
    cout << total ;

    return 0;
}