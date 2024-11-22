#include <bits/stdc++.h>
using namespace std;

#define lb lower_bound
#define ub upper_bound
// #define size(x) x.size()

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
#define linebreak1 cout << "_______________________________" << "\n""\n"
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
void solve(){
    vector<vector<int>> mat = {{1,2,-1}, {4, -1 , 6}, {7 , 8, 9}};
    vector<vector<int>> ans = mat;
    vector<int> maxi = ans[0];
    for(int i= 0;i<ans[0].size();i++){
        for(int j= 0;j<ans.size();j++){
            
        maxi[i] = max(maxi[i], ans[j][i]);
        }
    }

   for(int i = 0;i<ans[0].size();i++){
    for(int j= 0;j<ans.size();j++){
        if(ans[j][i] == -1){

        ans[j][i] = maxi[i];
        }
    }
   }
   for(auto x:ans){
     for(auto y:x){
        cout << y << ",";
     }
     cout << endl;

   }
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