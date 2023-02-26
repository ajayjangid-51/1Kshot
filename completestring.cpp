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
struct TrieNode
{
    TrieNode *v[26] = {NULL};
    bool end = 0;
};
class Trie
{
private:
public:
    TrieNode *root = NULL;
    Trie()
    {
        root = new TrieNode;
    }
    void insert(string word)
    {
        TrieNode *p = root;
        for (int i = 0; i < siz(word); i++)
        {
            // deb(word[i]);
            int ind = word[i] - 'a';
            // deb(ind);
            if (!p->v[ind])
                p->v[ind] = new TrieNode;
            p = p->v[ind];
        }
        p->end = 1;
    }
    bool find(string word)
    {
        TrieNode *p = root;
        for (int i = 0; i < siz(word); i++)
        {
            int ind = word[i] - 'a';
            if (!p->v[ind])
                return 0;
            p = p->v[ind];
            if (!p->end)
                return 0;
        }
        return p->end;
    }
};

void solve()
{
    // vector<string> v = {"n", "ni", "nin", "ninj", "ninja", "ninga"};
    // vector<string> v = {"ak", "szhkb", "a", "g", "hy"};
    vector<string> v = {"vfjq", "kez", "vfj", "dotkr", "vfjqo"};
    Trie t;
    deb(t.root);

    trav(v)
    {
        // deb(x);
        t.insert(x);
    }
    bool f = 0;
    string ans;
    trav(v)
    {
        if (t.find(x))
        {
            f = 1;
            if (siz(x) == siz(ans))
            {
                deb2(x, ans);
                ans = min(ans, x);
            }
            else
            {
                // ans = max(ans, x);
                if (siz(x) > siz(ans))
                    ans = x;
            }
        }
    }
    if (f)
        debline(ans);
    else
        debline("None");
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