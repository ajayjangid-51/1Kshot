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
void solve()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    // ListNode *th = head->next->next;
    ListNode *th = head->next;
    head->next->next->next = new ListNode(4);
    // ListNode *th = head->next->next->next;
    head->next->next->next->next = new ListNode(5);

    int n = 0;
    ListNode *p = head;
    while (p)
    {
        n++;
        p = p->next;
    }
    debline(n);
    int k = 2;
    int t = n / k;
    deb(t);
    ListNode *s = head;
    ListNode *e = NULL;
    while (t--)
    {
        ListNode *p = s;
        ListNode *c = p->next;

        int t1 = k - 1;
        while (t1--)
        {
            ListNode *n = c->next;

            c->next = p;
            p = c;
            c = n;
        }
        // deb(p->val);
        // deb(c->val);
        // deb(n->val);
        s->next = c;
        if (e)
        {
            e->next = p;
        }
        // s = n;
        e = s;
        s = c;
        // c = s;
        // s = c;
    }
    // print('Hi');
    linebreak1;
    p = th;
    deb(p->val);
    while (p)
    {
        print(p->val);
        p = p->next;
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