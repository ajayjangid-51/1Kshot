#include <bits/stdc++.h>
using namespace std;

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
#define siz(x) x.size()
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
#define deb(x) cout << #x << "= " << x << "\n"
#define deb2(a, b) cout << #a << "= " << a << " | " << #b << "= " << b << "\n"
#define deb3(a, b, c) cout << #a << "= " << a << " | " << #b << "= " << b << " | " << #c << "=" << c << "\n"
#define debpair(pair) cout << #pair << ".first = " << pair.first << " " << #pair << ".second = " << pair.second << endl
#define linebreak1 cout << "\n"                              \
                        << "_______________________________" \
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
// this below method wont;t work bcoz of this such testcases:-
/* vector<vs> v = {{"David", "David0@m.co", "David1@m.co"},
                    {"David", "David3@m.co", "David4@m.co"},
                    {"David", "David4@m.co", "David5@m.co"},
                    {"David", "David2@m.co", "David3@m.co"},
                    {"David", "David1@m.co", "David2@m.co"}}; */

void solve()
{
    // vector<vs> v = {
    //     {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
    //     {"John", "johnsmith@mail.com", "john00@mail.com"},
    //     {"Mary", "mary@mail.com"},
    //     {"John", "johnnybravo@mail.com"}};
    vector<vs> v = {{"David", "David0@m.co", "David1@m.co"},
                    {"David", "David3@m.co", "David4@m.co"},
                    {"David", "David4@m.co", "David5@m.co"},
                    {"David", "David2@m.co", "David3@m.co"},
                    {"David", "David1@m.co", "David2@m.co"}};

    map<string, int>
        m;
    int maxi = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j < v[i].size(); j++)
        {
            if (m.find(v[i][j]) != m.end())
            {
                t = m[v[i][j]];
                break;
            }
        }
        if (t != -1)
        {
            for (int j = 1; j < v[i].size(); j++)
            {
                m[v[i][j]] = t;
            }
        }
        else
        {
            for (int j = 1; j < v[i].size(); j++)
            {
                m[v[i][j]] = i;
                maxi = max(maxi, i);
            }
        }
    }
    // vector<vs> ans;
    // map<int, vs> ans;
    map<int, set<string>> ans;
    // trav(m)
    // {
    //     ans.push_back({v[x.second][0]});

    // }
    linebreak1;
    trav(m)
    {
        print(x.first), print('-');
        print(x.second);
        // trav2(x.second) print(y);
        nline;
    }
    linebreak1;
    trav(m)
    {
        ans[x.second].insert(x.first);
    }
    linebreak1;
    trav(ans)
    {
        trav2(x.second) print(y);
        nline;
    }
    linebreak1;
    vector<vs> res;
    trav(ans)
    {
        // set<string> t = x.second;
        // vs t(x.second.begin(), x.second().end());
        vs t;
        trav2(x.second) t.push_back(y);
        // for()
        // deb(x.first);
        // t.push_back(v[x.first][0]);
        // t = t + x.second;
        t.insert(t.begin(), v[x.first][0]);

        res.push_back(t);
    }
    linebreak1;
    trav(res)
    {
        trav2(x) print(y);
        nline;
    }
    linebreak1;
}

int main()
{
    io_faster
    file();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        print("hello");
    }
    return 0;
}