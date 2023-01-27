#include <bits/stdc++.h>
using namespace std;

#define lb lower_bound
#define ub upper_bound
#define sz(x) x.size()

#define ll long long
#define pint unsigned int
#define pb push_back
#define vb vector<bool>
#define vi vector<int>
#define vs vector<string>
#define vvi vector<vi>
#define vvb vector<vb>
#define pii pair<int, int>
#define endl "\n"
#define nline cout << "\n"
#define print(x) cout << x << " "
#define trav(a) for (auto x : a)
#define trav2(a) for (auto y : a)
#define range(arr) arr.begin(), arr.end()
#define leftpoint "👈"
#define rightpoint "👉"
#define downpoint "👇"
#define uppoint "👆"
#define fire "🔥"
#define star "⭐"
#define smile "😃"
#define smile2 "👺"
#define debline(x) cout << "👉Line-" << __LINE__ << ": " << #x << " = " << x << endl
#define linebreak2(x) cout << "🟢" << #x << " = " << x << "________________🟢 " << endl
#define all(x) x.begin() x.end()
#define deb(x) cout << #x << " = " << x << endl
#define debpair(pair) cout << #pair << ".first = " << pair.first << " " << #pair << ".second = " << pair.second << endl
#define linebreak1 cout << "_______________________________" \
                        << "\n"                              \
                           "\n"
#define forn(i, start, n) for (auto i = start; i < n; i++)
#define io_faster                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

const int MOD = 1000000007;
double PI = 4 * atan(1);

void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void solve()
{
    // vvi A = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    vvi A = {{0, 2, 3}, {2, 5, 3}};
    vector<vi> v;
    trav(A)
    {
        v.push_back({x[0], -x[2], x[1]});
        v.push_back({x[1], x[2], x[0]});
    }
    sort(v.begin(), v.end());
    trav(v)
    {
        print(x[0]), print(x[1]), print(x[2]), nline;
    }

    // set<int> s;
    // set<pii> s;
    set<vector<int>> s;
    vector<pii> ans;
    s.insert({0, 0, 0});
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i][1] < 0)
        {
            int top = (*s.rbegin())[0];
            if (-v[i][1] > top)
            {
                ans.push_back({v[i][0], -v[i][1]});
            }
            // s.insert({v[i][0], -v[i][1], v[i][2]});
            // s.insert({v[i][2], -v[i][1], v[i][0]});
            s.insert({-v[i][1], v[i][0], v[i][2]});
        }
        else
        {
            // print(v[i].second), print(","), print(v[i].first), nline;
            // print(smile);
            // print(smile2);
            // auto it = s.find({v[i].second, v[i].first});
            print(v[i][2]), print(","), print(v[i][1]), print(v[i][0]), nline;
            auto it = s.find({v[i][1], v[i][2], v[i][0]});
            // if (it != s.end())
            s.erase(it);
            int top = (*s.rbegin())[0];
            debline(top);
            debline(v[i][1]);
            if (top != v[i][1] and v[i][1] > top)
                ans.push_back({v[i][0], top});
        }
    }
    linebreak1;
    trav(ans)
    {
        print(x.first);
        print(x.second);
        nline;
    }
}
int main()
{
    io_faster
    file();
    int t = 1;
    //	cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}