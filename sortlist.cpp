#include <bits/stdc++.h>
using namespace std;

#define lb lower_bound
#define ub upper_bound
#define sz(x) x.size()

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
#define deb(x) cout << #x << " = " << x << endl
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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *getmid(ListNode *head)
{
    debline(head->val);
    ListNode *s = head;
    ListNode *f = head;
    while (f and f->next and f->next->next)
    {
        s = s->next;
        f = f->next->next;
    }

    return s;
}
ListNode *merge(ListNode *l, ListNode *r)
{
    ListNode *p1 = l;
    ListNode *p2 = r;
    ListNode *head = new ListNode(-1);
    ListNode *curr = head;
    while (p1 and p2)
    {
        if (p1->val < p2->val)
        {
            curr->next = p1;
            p1 = p1->next;
        }
        else
        {
            curr->next = p2;
            p2 = p2->next;
        }
        curr = curr->next;
    }
    if (p1)
        curr->next = p1;
    if (p2)
        curr->next = p2;

    return head->next;
}
ListNode *fn(ListNode *l)
{
    if (!l)
        return NULL;
    if (!l->next)
    {
        return l;
    }
    ListNode *mid = getmid(l);
    deb(mid->val);
    ListNode *left = l;
    ListNode *right = mid->next;
    mid->next = NULL;

    // linebreak1;
    // while (left)
    // {
    //     print(left->val);
    //     left = left->next;
    // }
    // nline;
    // while (right)
    // {
    //     print(right->val);
    //     right = right->next;
    // }
    // linebreak1;

    ListNode *lf = fn(left);
    ListNode *rt = fn(right);
    return merge(lf, rt);
    // return NULL;
}

void solve()
{
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(7);

    ListNode *ans = fn(head);
    print("h");
    linebreak1;
    while (ans)
    {
        print(ans->val);
        ans = ans->next;
    }
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