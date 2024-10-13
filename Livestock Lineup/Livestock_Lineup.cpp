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
vector<string> names={"Beatrice","Sue","Belinda","Bessie","Betsy","Blue","Bella","Buttercup"};
vector<vector<string>> valid_combination;

int visited[8] = {0};

vector<string> cows;
map<string,vector<string>> m;
void check(vector<string> &c)
{
    bool valid = true;
    for(int i = 0 ; i < sz(c) && valid; i++)
    {
        for(auto &ele : m[c[i]])
        {
            if(((i - 1 ) >= 0 && c[i-1] == ele ) || ((i+1) < 8 && c[i+1] == ele))
            {

            }
            else
            {
                valid = false;
                break;
            }
        }
    }
    if(valid)
    {
        valid_combination.pb(c);
    }
}

void build(vector<string> &s)
{
    if(s.size() == 8)
    {
        check(s);
        return;
    }

    for(int i = 0 ; i < 8 ; i++)
    {
        if(visited[i] == 1) continue;
        visited[i] = 1;
        s.push_back(names[i]);
        build(s);
        visited[i] = 0;
        s.pop_back();
    }
}



int main()
{
    setIO("lineup");
    int n;
    cin >> n;
    string cow1;
    string cow2;
    string nothing;
    for(int i = 0 ; i < n ;i++)
    {
        for(int j = 0 ; j < 6 ;j++)
        {
            if(j == 0)
            {
                cin >> cow1;
                continue;
            }
            if(j == 5)
            {
                cin >> cow2;
                continue;
            }
            cin >> nothing;
        }
        m[cow1].push_back(cow2);
        m[cow2].push_back(cow1);
    }
    build(cows);

    sort(all(valid_combination));

    for(auto &i : valid_combination[0])
    {
        cout << i << '\n';
    }
    return 0;
}