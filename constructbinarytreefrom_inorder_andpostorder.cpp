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
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *fn(int &p, int i, int j, vi &in, vi &po)
{
    debline(p);
    if (i > j)
        return NULL;
    if (i == j)
    {
        deb2(smile, p);
        TreeNode *t = new TreeNode(po[p]);
        // p--;
        return t;
    }
    TreeNode *t = new TreeNode(po[p]);
    debline(t->val);
    for (int i1 = i; i1 <= j; i1++)
    {
        // if (in[i1] == po[p + 1])
        if (in[i1] == po[p])
        {
            p--;

            deb(i1);
            // p--;
            t->right = fn(p, i1 + 1, j, in, po);
            // if (t->right)
            //     p--;
            t->left = fn(p, i, i1 - 1, in, po);
        }
    }
    // return NULL;
    return t;

    // t->left = fn()
}

void dfs(TreeNode *node)
{
    if (!node)
        return;
    print(node->val);
    dfs(node->left);
    dfs(node->right);
}
void solve()
{
    vi in = {9, 3, 15, 20, 7};
    vi po = {9, 15, 7, 20, 3};
    int n = siz(in);
    int p = n - 1;
    TreeNode *root = fn(p, 0, n - 1, in, po);
    dfs(root);
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