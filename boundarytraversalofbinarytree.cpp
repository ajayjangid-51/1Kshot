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
#define linebreak1 cout << "_______________________________" \
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

void inorder(TreeNode *node, vi &v)
{
    if (!node)
        return;
    inorder(node->left, v);
    if (!node->left and !node->right)
    {
        v.push_back(node->val);
    }
    inorder(node->right, v);
}
void solve()
{

    /*  TreeNode *root = new TreeNode(10);
     root->left = new TreeNode(5);
     root->right = new TreeNode(20);
     root->left->left = new TreeNode(3);
     root->left->right = new TreeNode(8);
     root->right->left = new TreeNode(18);
     root->right->right = new TreeNode(25);
     root->left->right->left = new TreeNode(7);
  */

    /*  TreeNode *root = new TreeNode(100);
     root->left = new TreeNode(50);
     root->right = new TreeNode(150);
     root->left->left = new TreeNode(25);
     root->left->right = new TreeNode(75);
     root->right->left = new TreeNode(140);
     root->right->right = new TreeNode(200);
     root->left->left->right = new TreeNode(30);
     root->left->right->left = new TreeNode(70);
     root->left->right->right = new TreeNode(80);
     root->left->left->right->right = new TreeNode(35); */

    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(4);
    // root->right = new TreeNode(NULL);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(8);
    // root->right->right = new TreeNode();

    // first traverse all left
    // then lead nodes
    // then all right in reverse or atlast get it to reverse
    TreeNode *p = root;
    vi ans;
    // while (p->left or p->right)
    while (p and p->left)
    {
        ans.push_back(p->val);
        if (p->left)
            p = p->left;
        else
            p = p->right;
    }
    inorder(root, ans);

    stack<int> s;
    p = root->right;
    // while (p->left or p->right)
    while (p and p->right)
    {
        s.push(p->val);
        if (p->right)
            p = p->right;
        else
            p = p->left;
    }
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    trav(ans) print(x);
    nline;
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