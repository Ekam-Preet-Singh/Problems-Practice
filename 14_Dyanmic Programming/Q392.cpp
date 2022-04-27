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
Q392.) Space Optimized Solution of LCS

INPUT:
3

ABCDGH
AEDFHR

ABCDGH
ACDGHR

AGGTAB
GXTXAYB

OUTPUT:
Case #1: 3
Case #2: 5
Case #3: 4

*/

class Solution
{
public:
    // Returns length of LCS
    // for X[0..m-1], Y[0..n-1]
    int lcs(string &X, string &Y)
    {

        // Find lengths of two strings
        int m = X.length(), n = Y.length();

        int L[2][n + 1];

        // Binary index, used to
        // index current row and
        // previous row.
        bool bi;

        for (int i = 0; i <= m; i++)
        {

            // Compute current
            // binary index
            bi = i & 1;

            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                {
                    L[bi][j] = 0;
                }

                else if (X[i - 1] == Y[j - 1])
                {
                    L[bi][j] = L[1 - bi][j - 1] + 1;
                }

                else
                {
                    L[bi][j] = max(L[1 - bi][j], L[bi][j - 1]);
                }
            }
        }

        // Last filled entry contains
        // length of LCS
        // for X[0..n-1] and Y[0..m-1]
        return L[bi][n];
    }
};

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    Solution ob;
    cout << ob.lcs(s1, s2) << endl;
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