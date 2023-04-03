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
    linebreak1;
    trav(wordlist) print(x);
    linebreak1;
    set<string> st;
    trav(wordlist) st.insert(x);
    // st.insert(e);

    linebreak1;
    trav(st) print(x);
    linebreak1;

    vector<vs> ans;
    queue<vs> q;
    int currlevel = 1;
    int shortestlevel = INT_MAX;
    q.push({b});
    vs visitedwordsincurrentlevel;

    while (!q.empty())
    {
        vs f = q.front();

        q.pop();
        if (f.size() > currlevel) // it means level is increased, mtlb now we are on the next level ,as we have finished the currentlevel.
        {
            for (auto x : visitedwordsincurrentlevel)
            {
                st.erase(x);
            }
            visitedwordsincurrentlevel.clear();
            if (f.size() > shortestlevel)
                break;
            else
                currlevel = f.size();

            // break;
        }
        // debline(t);
        string t = f.back();

        // deb2(smile2, t);
        for (int i = 0; i < t.size(); i++)
        {
            t = f.back();

            for (char c = 'a'; c <= 'z'; c++)
            {
                t[i] = c;
                // debline(t);
                if (st.find(t) != st.end())
                {
                    vs tmpv = f;
                    tmpv.push_back(t);
                    if (t != e)
                    {
                        debline(t);

                        // st.erase(t); // don't directly erase it, just put it in any bucket and erease all in bucket when particular level is over.
                        visitedwordsincurrentlevel.push_back(t);
                        q.push(tmpv);
                    }
                    else
                    {
                        // shortestlevel = tmpv.size();
                        shortestlevel = currlevel;
                        ans.push_back(tmpv);
                    }
                }
            }
            linebreak1;
        }
    }
    debline(ans.size());
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