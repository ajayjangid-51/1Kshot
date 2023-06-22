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
#define onered cout << "🔴"
#define twoblue cout << "🔵"
#define threeyellow cout << "🟡"
#define fourpurple cout << "🟣"
#define fivebrown cout << "🟤"
#define sixgreen cout << "🟢"
#define sevenwhite cout << "⚪"
#define eightwheel cout << "🛞"
#define ninering cout << "⭕"
#define tenpoint cout << "👉"
#define elevenhand cout << "🤚🏻"
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
    string s("adefaddaccc");
    cin >> s;
    int n = s.size();

    vi cstart(26, -1);
    for (int i = 0; i < n; i++)
    {
        if (cstart[s[i] - 'a'] == -1)
            cstart[s[i] - 'a'] = i;
    }

    vi cend(26, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        if (cend[s[i] - 'a'] == -1)
            cend[s[i] - 'a'] = i;
    }
    trav(cend) print(x);
    linebreak1;
    vector<pii> v;
    // for (int ch = 0; ch < 26; ch++)
    for (int j = 0; j < n; j++)
    {

        int ch = s[j] - 'a';
        if (cstart[ch] == -1)
            continue;
        int st = cstart[ch], end = cend[ch];
        deb2(st, end);
        for (int i = st + 1; i < end; i++)
        // for(int i = 0;i<n;i++)
        {
            int ind = s[i] - 'a';
            st = min(st, cstart[ind]);
            end = max(end, cend[ind]);
            // deb(i);
            // if (ind == ch)
            // {
            //     st = min(st, i);
            // }
            // if (st != n and i < end)
            // {
            //     debline(cend[ind]);
            //     st = min(st, cstart[ind]);
            //     // cstart[ch] = st;
            //     end = max(end, cend[ind]);
            //     // cend[ch] = end;
            // }
        }
        deb2(st, end);
        cstart[ch] = min(cstart[ch], st);
        cend[ch] = max(end, cend[ch]);
        if (st != n)
            v.push_back({st, end});
    }

    linebreak1;
    trav(v) print(x.first), print(x.second), nline;
    // v.push_back({2, 3});
    sort(v.begin(), v.end(), [](pii &a, pii &b)
         {
            if(a.second == b.second) return a.first<b.first;
            else if (a.second < b.second) return true;
                 return false; });
    linebreak1;
    trav(v) print(x.first), print(x.second), nline;

    pii prev = v[0];
    vector<string> ans;
    debpair(prev);
    ans.push_back(s.substr(prev.first, (prev.second - prev.first + 1)));
    // deb(ans[0]);

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].first > prev.second)
        {
            // prev = v[i];
            prev = v[i];
            onered;
            ans.push_back(s.substr(prev.first, (prev.second - prev.first + 1)));
        }
        else if (v[i].first >= prev.first and v[i].first < prev.second)
        {
            prev = {prev.first, v[i].second};
            ans.pop_back();
            ans.push_back(s.substr(prev.first, (prev.second - prev.first + 1)));
        }
    }

    linebreak1;
    trav(ans) print(x);
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