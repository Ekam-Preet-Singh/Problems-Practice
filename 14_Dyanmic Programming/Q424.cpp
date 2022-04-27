#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007
#define inf 1e18
#define endl "\n"
#define pb push_back
#define vi vector<ll>
#define vs vector<string>
#define pii pair<ll, ll>
#define ump unordered_map
#define mp make_pair
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll, vi, greater<ll>>
#define all(n) n.begin(), n.end()
#define ff first
#define ss second
#define mid(l, r) (l + (r - l) / 2)
#define bitc(n) __builtin_popcount(n)
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define looprev(i, a, b) for (int i = (a); i >= (b); i--)
#define iter(container, it) for (__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...)                             \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
#define logarr(arr, a, b)            \
    for (int z = (a); z <= (b); z++) \
        cout << (arr[z]) << " ";     \
    cout << endl;
template <typename T>
T gcd(T a, T b)
{
    if (a % b)
        return gcd(b, a % b);
    return b;
}
template <typename T>
T lcm(T a, T b) { return (a * (b / gcd(a, b))); }
vs tokenizer(string str, char ch)
{
    std::istringstream var((str));
    vs v;
    string t;
    while (getline((var), t, (ch)))
    {
        v.pb(t);
    }
    return v;
}

void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << *it << " = " << a << endl;
    err(++it, args...);
}
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

/*
Q424.) Optimal Strategy for a Game

INPUT:
6

6
10 22 5 75 65 80

7
2 30 15 10 8 25 80

7
100 30 15 10 8 25 80

5
90 80 70 60 50

4
5 3 7 10

4
8 15 3 7

OUTPUT:
Case #1: 177
Case #2: 105
Case #3: 153
Case #4: 210
Case #5: 15
Case #6: 22

*/

class Solution
{
public:
    long long maximumAmount(int arr[], int n)
    {
        // creating a table to store solutions of subproblems.
        int table[n][n];

        // filling table using above recursive formula. Note that the
        // table is filled in diagonal fashion, from diagonal elements
        // to table[0][n-1] which is the result.
        for (int gap = 0; gap < n; ++gap)
        {
            for (int i = 0, j = gap; j < n; ++i, ++j)
            {
                // Here x is value of table[i + 2][j], y istable[i + 1][j - 1] and
                //  z is table[i][j - 2] in above recursive formula.

                int x = ((i + 2) <= j) ? table[i + 2][j] : 0;
                int y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0;
                int z = (i <= (j - 2)) ? table[i][j - 2] : 0;

                table[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
            }
        }
        // returning the result.
        return table[0][n - 1];
    }
};

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Solution ob;
    cout << ob.maximumAmount(a, n) << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    file_i_o();

    ll t = 1;
    ll case_num = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << case_num++ << ": ";
        solve();
    }

    return 0;
}