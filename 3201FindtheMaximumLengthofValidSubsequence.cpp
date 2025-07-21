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
#define linebreak1 cout << "\n" << "_______________________________" << "\n""\n"
#define forn(i, start, n) for (auto i = start; i < n; i++)
#define io_faster ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);

const int MOD = 1000000007;
double PI = 4 * atan(1);

void file()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
    #endif
}

vector<int> takeVectorInput(){
    string vectorAsString;
    cin >> vectorAsString;
    vectorAsString.erase(remove(vectorAsString.begin(), vectorAsString.end(), '['), vectorAsString.end());
    vectorAsString.erase(remove(vectorAsString.begin(), vectorAsString.end(), ']'), vectorAsString.end());
    // vectorAsString.erase(remove(vectorAsString.begin(), vectorAsString.end(), ','), vectorAsString.end());
    // deb(vectorAsString);
    vector<int> vec;
    stringstream ss(vectorAsString);
    int temp;
    while (ss >> temp) {
        vec.push_back(temp);
        if (ss.peek() == ',') {
            ss.ignore();
        }
    }
    return vec;
}
void printVector(vector<int> &v){
    // cout << "vector = [";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) {
            cout << ",";
        }
    }
    // cout << "]" << endl;
}
void solve()
{
    vector<int> vec1 = takeVectorInput();
    // vetor<int> vec2 = takeVectorInput();
    // vector<int> vec3 = takeVectorInput(); 

    printVector(vec1);

    
    // int a = 3131 , b = 7883;
    // deb2(a,b);
}

int main()
{
    io_faster
    file();
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}