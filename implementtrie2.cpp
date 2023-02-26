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
#define size(x) x.size()
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
#include <bits/stdc++.h>

struct TrieNode
{
    TrieNode *v[26] = {NULL};
    int cnt[26] = {0};
    int e = 0;
};

class Trie
{

private:
    TrieNode *root = NULL;

public:
    Trie()
    {
        // Write your code here.
        root = new TrieNode;
    }

    void insert(string &word)
    {
        TrieNode *p = root;
        for (int i = 0; i < size(word); i++)
        {
            int ci = word[i] - 'a';
            if (p->v[word[i] - 'a'])
            {
                // p->cnt = p->cnt + 1;
                p->cnt[ci]++;
                p = p->v[word[i] - 'a'];
            }
            else
            {
                p->cnt[ci]++;
                p->v[word[i] - 'a'] = new TrieNode;
                // p->cnt = p->cnt + 1;
                p = p->v[word[i] - 'a'];
            }
        }
        p->e = 1;
    }

    int countWordsEqualTo(string &word)
    {
        TrieNode *p = root;
        int count = 0;
        for (int i = 0; i < size(word); i++)
        {
            int ci = word[i] - 'a';
            if (!p->v[ci])
                return 0;
            count = p->cnt[ci];
            p = p->v[ci];
        }

        if (p->e)
            return count;
        else
            return 0;
    }

    int countWordsStartingWith(string &word)
    {
        TrieNode *p = root;
        int count = 0;
        for (int i = 0; i < size(word); i++)
        {
            int ci = word[i] - 'a';
            if (!p->v[ci])
                return 0;
            count = p->cnt[ci];
            p = p->v[ci];
        }
        return count;
    }

    void erase(string &word)
    {
        TrieNode *p = root;
        int count = 0;
        for (int i = 0; i < size(word); i++)
        {
            int ci = word[i] - 'a';
            if (!p->v[ci])
                return;
            p->cnt[ci]--;
            count = p->cnt[ci];
            p = p->v[ci];
        }
        if (p->e and count < 2)
            p->e = 0;
    }
};

void solve()
{
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