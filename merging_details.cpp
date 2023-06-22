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
class dsu
{
public:
    int n; // no. of sets/groups. initially every element is individual set/group
    vector<int> parent;
    vector<int> size; // size[set] gives no. of elements in this disjointset( this is set but this disjoint with any other set wich might have common with it , and this presence of common between two will not be possible bcoz he set is disjoint by birth.)
    int components;   // gives no. of component in the container at any instant of time.

    // constructor:-
    dsu(int N)
    {
        n = N;
        components = n;
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    // find() function to find the parent of any element
    int find(int e)
    {
        while (parent[e] != e)
        {
            e = parent[e];
        }
        return e;
    }

    // unite() function to unite two sets.
    void unite(int a, int b)
    {
        // here in this question unite(a,b) means "a" meh "b" ko attach krdo.(koi size-vize nhi dekhni).
        int a_parent = find(a);
        int b_parent = find(b);
        if (a_parent == b_parent)
            return;
        // join shorter to bigger one.
        /* if (size[a_parent] < size[b_parent])
        {
            swap(a_parent, b_parent);
        }
        size[a_parent] += size[b_parent]; */
        parent[b_parent] = a_parent;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<vs> v(n);
    // vector<vs> v = {
    //     {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
    //     {
    //         "John",
    //         "johnsmith@mail.com",
    //         "john00@mail.com",
    //     },
    //     {"Mary", "mary@mail.com"},
    //     {"John", "johnnybravo@mail.com"}};

    // int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vs tmp(m);
        for (int j = 0; j < m; j++)
        {
            cin >> tmp[j];
        }
        v[i] = tmp;
        // v.push_back(tmp);
    }

    onered;
    dsu d(n);
    // map<email , set_no.> mp  // mp is used to denote that which element belongs to which set-no.
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < v[i].size(); j++)
        {
            string x = v[i][j];
            if (mp.find(x) != mp.end())
            { // means this email is already asigned any group previously so what we have to do is ki yeh jo new set_no. hai esko previous wale meh assign krdo.
                debline(x);
                d.unite(d.find(mp[x]), d.find(i));
            }
            // else
            mp[x] = d.find(i);
            // mp[x] = i;
        }
    }
    linebreak1;

    for (int i = 0; i < n; i++)
    {
        print(i), print("-"), print(d.find(i)), nline;
        // debline(d.parent[i]);
    }
    // map<string,
    map<int, set<string>> mp2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < v[i].size(); j++)
        {
            mp2[d.find(i)].insert(v[i][j]);
        }
    }
    onered;
    vector<vector<string>> ans;
    trav(mp2)
    {
        vs t;
        print(v[x.first][0]);
        t.push_back(v[x.first][0]);
        trav2(x.second) t.push_back(y);
        ans.push_back(t);
        nline;
    }

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