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
#define print2(a, b) cout << a << " - " << b << "\n"
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
class dsu
{
private:
    /* data */
public:
    int n;
    int noofcomponents;
    int xtraedges = 0;
    vi justparent;
    vi size;

    dsu(int N)
    {
        n = N; // no.of individual nodes in graph:-
        noofcomponents = N;
        justparent.resize(n);
        for (int i = 0; i < n; i++)
            justparent[i] = i;
        size.assign(n, 1);
        print("hello");
    }

    int find(int x)
    {
        while (justparent[x] != x)
            x = justparent[x];
        return x;
    }

    bool areinsame(int nodea, int nodeb)
    {
        return (find(nodea) == find(nodeb));
    }

    void unite(int nodea, int nodeb)
    {
        deb2(nodea, nodeb);
        if (areinsame(nodea, nodeb))
        {
            xtraedges++;
            return;
        }

        deb("hi");
        noofcomponents--;
        int c1 = find(nodea);
        int c2 = find(nodeb);
        if (size[c1] < size[c2])
            swap(c1, c2);

        size[c1] += size[c2];
        justparent[c2] = c1;
        // justparent[c1] = c2;
    }

    int sizee(int component)
    {
        return size[component];
    }
};

void solve()
{
    // vector<vs> v = {{"David", "David0@m.co", "David1@m.co"},
    //                 {"David", "David3@m.co", "David4@m.co"},
    //                 {"David", "David4@m.co", "David5@m.co"},
    //                 {"David", "David2@m.co", "David3@m.co"},
    //                 {"David", "David1@m.co", "David2@m.co"}};
    vector<vs> v = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"Johnb", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}};
    int n = v.size();
    dsu d(n);
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < v[i].size(); j++)
        {
            if (mp.find(v[i][j]) != mp.end())
            {
                d.unite(i, mp[v[i][j]]);
            }
            else
            {

                print(smile2);

                print(v[i][j]), nline;
                mp[v[i][j]] = i;
            }
        }
    }
    debline(d.noofcomponents);
    debline(d.xtraedges);
    // vector<vs> ans(d.noofcomponents);
    map<int, vs> ans;
    linebreak1;
    trav(mp)
    {
        print2(x.first, x.second);
        // deb(x.second);
        // deb(d.find(x.second));
        // ans[v[d.find(x.second)][0]].push_back(x.first);
        ans[d.find(x.second)].push_back(x.first);
        // ans[d.find(x.second)].push_back(x.first);
    }
    linebreak1;
    vector<vs> res;
    trav(ans)
    {
        // res.push_back({y);
        // vs t = {x.first , x.second};
        vs t = x.second;
        // t.insert(t.begin(), v[d.find(x.first)][0]);
        // t.insert(t.begin(), v[mp[x.second[0]]][0]);
        t.insert(t.begin(), v[mp[x.second.back()]][0]);
        res.push_back(t);
    }
    linebreak1;

    trav(res)
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