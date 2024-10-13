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

int n , b;
vector<pair<int ,int>> cows_points;

bool left_upper(pair<int,int> a , pair<int,int> b)
{
    return b.first < a.first && b.second < a.second;
}


bool left_down(pair<int,int> a , pair<int,int> b)
{
    return b.first < a.first && b.second > a.second;
}


bool right_upper(pair<int,int> a , pair<int,int> b)
{
    return b.first > a.first && b.second < a.second;
}

bool right_down(pair<int,int> a , pair<int,int> b)
{
    return b.first > a.first && b.second > a.second;
}



int main()
{
    setIO("balancing");
    cin >> n >> b;
    int x1,y1;

    set<int> vfence;
	set<int> hfence;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> x1 >> y1;
        cows_points.pb({x1,y1});
        hfence.insert(y1+1);
        vfence.insert(x1 +1);
        
    }
    sort(all(cows_points));

    int low = INT32_MAX;
	for (int i : vfence) {
		for (int j : hfence) {
            int lu = 0;
            int ld = 0;
            int ru = 0;
            int rd = 0;
            for(int k = 0; k < n ; k++)
            {
                if(right_upper({i,j}, cows_points[k]) == true)
                {
                    ru++;
                }
                else if(right_down({i,j}, cows_points[k]) == true)
                {
                    rd++;
                }
                else if(left_down({i,j}, cows_points[k]) == true)
                {
                    ld++;
                }
                else
                {
                    lu++;
                }
            }
            low = min(max({lu,ld,ru,rd}),low);
        }
    }
    cout << low;
    return 0;
}