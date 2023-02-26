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
    TrieNode *v[2] = {NULL};
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
    void insert(int n)
    {
        TrieNode *p = root;
        for (int i = 31; i >= 0; i--)
        {
            bool t = n & (1 << i);
            // print(t);
            if (!p->v[t])
            {
                p->v[t] = new TrieNode;
            }
            p = p->v[t];
        }
        // nline;
    }
    int findmaxXOR(int n)
    {
        TrieNode *p = root;
        int cnt = 0;
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            if (!p)
                return -1;
            bool t = n & (1 << i);
            if (p->v[!t])
            {
                // cnt++;
                ans = ans + (1 << i);
                p = p->v[!t];
            }
            else
                p = p->v[t];
        }
        return ans;
    }
};
void solve()
{
    // vi nums = {0, 1, 2, 3, 4};
    vi nums = {5, 2, 4, 6, 6, 3};
    sort(range(nums));
    int n = siz(nums);
    // vvi q = {
    //     {1, 3},
    //     {3, 1},
    //     {5, 6}};

    vvi q = {
        {12, 4},
        {8, 1},
        {6, 3}};
    vi ans(siz(q));
    vector<pair<int, pair<int, int>>> v;
    // <m , <qindex , x>>
    for (int i = 0; i < siz(q); i++)
    {
        v.push_back({q[i][1], {i, q[i][0]}});
    }
    sort(v.begin(), v.end());
    trav(v)
    {
        print(x.first), print("-"), print(x.second.first), print(x.second.second), nline;
    }
    int i = 0;

    Trie t;
    trav(v)
    {
        int m = x.first, ind = x.second.first, val = x.second.second;
        deb3(m, ind, val);
        while (i < n and nums[i] <= m)
        {
            deb(nums[i]);
            t.insert(nums[i]);
            i++;
        }
        nline;
        ans[ind] = t.findmaxXOR(val);
    }
    linebreak1;
    trav(ans) print(x);
    linebreak1;
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

// given that we have to return the answer for all queries atlast, means we donot to give answer after each querry, so in simple words it means we do not need to be online for answering every query one-after-other-one-by-one mens that we donot need online algorithm to answer this question , so here we could offline means we will use idea of offline-querries, means we will process querries as per our convienient and profit, and this is only called designing doing offline-algorithms and here we can notice that our convinence will be ki we should have only those less numbers which are required for first offline querry..