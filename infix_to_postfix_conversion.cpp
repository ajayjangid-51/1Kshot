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

bool isoperator(char c)
{
    if (c == '^' or c == '+' or c == '-' or c == '*' or c == '/' or c == '(' or c == ')' or c == ' ')
        return 1;
    return 0;
}
int opPrecedence(string c)
{
    if (c == "^")
        return 3;
    if (c == "*" or c == "/")
        return 2;
    return 1;
}

void solve()
{
    string s("a+b*(c^d-e)^(f+g*h)-i ");
    stack<string> pre, op, post;

    // string a = to_string('c');

    // debline(a);
    // a = 'c';
    // debline(a);
    // operator precedence (^*/+-)
    for (char g : s)
    {
        string x(1, g);

        // if (!(x >= "a" and x <= "z"))
        if (isoperator(g))
        {
            if (x == ")")
            {
                while (!op.empty() and op.top() != "(")
                {
                    // pre
                    string s2 = pre.top();
                    pre.pop();
                    string s1 = pre.top();
                    pre.pop();

                    pre.push((op.top() + s1 + s2));
                    // post
                    s2 = post.top();
                    post.pop();
                    s1 = post.top();
                    post.pop();
                    post.push((s1 + s2 + op.top()));
                    op.pop();
                }
                op.pop();
            }
            else
            {
                if (x == "(")
                    op.push("(");
                else
                {

                    while (!op.empty() and op.top() != "(" and (opPrecedence(op.top()) >= opPrecedence(x)))
                    {
                        // pre
                        string s2 = pre.top();
                        pre.pop();
                        string s1 = pre.top();
                        pre.pop();

                        pre.push((op.top() + s1 + s2));
                        // post
                        s2 = post.top();
                        post.pop();
                        s1 = post.top();
                        post.pop();
                        post.push((s1 + s2 + op.top()));
                        op.pop();
                    }
                    // if (x == '+')
                    //     op.push("+");
                    // else
                    //     op.push("-");
                    // op.push(to_string(x));
                    op.push(x);
                }

                /*   else if (x == "+" or x == "-")
                  {
                      // while (!op.empty() and (op.top() == "+" or op.top() == "-"))
                      while (!op.empty() and op.top() != "(" and (opPrecedence(op.top()) >= opPrecedence(x)))
                      {
                          // pre
                          string s2 = pre.top();
                          pre.pop();
                          string s1 = pre.top();
                          pre.pop();

                          pre.push((op.top() + s1 + s2));
                          // post
                          s2 = post.top();
                          post.pop();
                          s1 = post.top();
                          post.pop();
                          post.push((s1 + s2 + op.top()));
                          op.pop();
                      }
                      // if (x == '+')
                      //     op.push("+");
                      // else
                      //     op.push("-");
                      // op.push(to_string(x));
                      op.push(x);
                  }
                  else if (x == "*" or x == "/")
                  {
                      // while (!op.empty() and ((op.top() == "*" or op.top() == "/")))
                      while (!op.empty() and op.top() != "(" and (opPrecedence(op.top()) >= opPrecedence(x)))
                      {
                          // pre
                          string s2 = pre.top();
                          pre.pop();
                          string s1 = pre.top();
                          pre.pop();

                          pre.push((op.top() + s1 + s2));
                          // post
                          s2 = post.top();
                          post.pop();
                          s1 = post.top();
                          post.pop();
                          post.push((s1 + s2 + op.top()));
                          op.pop();
                      }
                      // if (x == '*')
                      //     op.push("*");
                      // else
                      //     op.push("/");
                      // op.push(to_string(x));
                      op.push(x);
                  }
                  else
                  {
                      op.push("^");
                  } */
            }
        }
        else
        {
            // pre.push(to_string(x));
            pre.push(x);
            post.push(x);
        }
    }
    deb(pre.size());
    deb(post.size());
    debline(pre.top());
    debline(post.top());
    linebreak1;
    while (!pre.empty())
    {
        debline(pre.top());
        pre.pop();
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