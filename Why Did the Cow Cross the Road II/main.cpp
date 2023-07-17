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
    Code By Abou_Hawis if (sz(name))
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

enum PointsState 
{
    NOT_INTERSECT,
    INTERSECT
};

PointsState IsCross(pi first_point , pi second_point)
{
    if(second_point.first < first_point.second && second_point.second > first_point.second) 
    {
        return INTERSECT;
    }
    else
    {
        return NOT_INTERSECT;
    }
}

int main()
{
    setIO("circlecross");
    string st;
    cin >> st;
    vector<pi> cross_points(26, {-1, -1});
    for (int i = 0; i < 52; i++)
    {
        if (cross_points[st[i] - 'A'].first == -1)
        {
            cross_points[st[i] - 'A'].first = i;
        }
        else
        {
            cross_points[st[i] - 'A'].second = i;
        }
    }
    sort(all(cross_points));
    int cnt = 0;
    for (char start = 'A'; start < 'Z' ; start++)
    {
        for (char end = start + 1; end <= 'Z'; end++)
        {
            if(cross_points[end - 'A'].first> cross_points[start - 'A'].second)
            {
                break;
            }
            if (IsCross(cross_points[start - 'A'], cross_points[end - 'A']) == INTERSECT)
            {
                cnt++;
            }
        }
    }
    cout << cnt ;
    return 0;
}