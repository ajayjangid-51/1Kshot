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

void fn2(TreeNode *node)
{
    if (!node)
        return;
    int t = node->val;
    if (node->left)
    {
        node->left->val = t;
        fn2(node->left);
        t = 0;
    }
    if (node->right)
    {
        node->right->val = t;
        fn2(node->right);
    }
}

int fn(TreeNode *node)
{
    if (!node)
        return 0;
    if (!node->left and !node->right)
    {
        debline(node->val);
        return node->val;
    }
    int l = fn(node->left);
    int r = fn(node->right);
    if (node->val > (l + r))
    {
        debline(node->val);
        int t = node->val;
        if (node->left)
        {

            node->left->val = t;
            fn2(node->left);
            t = 0;
        }

        if (node->right)
        {

            node->right->val = t;
            fn2(node->right);
        }
    }
    else
    {
        deb(node->val);
        node->val = (l + r);
        // deb(node->val);
    }
    return node->val;
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
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(35);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(2);

    /*  TreeNode *root = new TreeNode(16);
     root->right = new TreeNode(576);
     root->right->left = new TreeNode(232);
     root->right->left->right = new TreeNode(468);
  */

    fn(root);
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