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
//
vector<vector<string>> ans;

void dfs(vs v, unordered_map<string, int> &m, unordered_set<string> &st, string &b)
{
    // if (v.back() == b)
    // {

    //     return;
    // }
    for (int i = 0; i < v.back().size(); i++)
    {
        string t = v.back();
        debline(t);

        for (char c = 'a'; c <= 'z'; c++)
        {
            t[i] = c;
            if (t == b)
            {
                vs vtmp = v;
                vtmp.push_back(t);
                reverse(range(vtmp));
                ans.push_back(vtmp);
            }
            else if (st.find(t) != st.end())
            {
                if (m[t] < m[v.back()])
                {
                    vs vtmp = v;
                    vtmp.push_back(t);
                    dfs(vtmp, m, st, b);
                }
            }
        }
    }
}
void solve()
{
    string b, e;
    cin >> b >> e;
    vs wordlist;
    string s;
    while (cin >> s)
    {
        wordlist.push_back(s);
    }
    unordered_set<string> st;
    trav(wordlist) st.insert(x);
    //
    trav(wordlist) print(x);
    nline;
    // step1:-
    unordered_map<string, int> m;
    queue<pair<string, int>> q;
    q.push({b, 0});
    while (!q.empty())
    {
        pair<string, int> f = q.front();
        m[f.first] = f.second;
        q.pop();
        for (int i = 0; i < f.first.size(); i++)
        {
            string t = f.first;
            for (char c = 'a'; c <= 'z'; c++)
            {
                t[i] = c;
                if (st.find(t) != st.end())
                {
                    // if (t == e)
                    //     continue;
                    st.erase(t);
                    q.push({t, f.second + 1});
                }
            }
        }
    }

    trav(m) deb2(x.first, x.second);
    trav(wordlist) st.insert(x);

    dfs({e}, m, st, b);
    debline(ans.size());

    linebreak1;
    trav(ans)
    {
        trav2(x) print(y);
        nline;
    }
}

int main()
{
    io_faster
    file();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}