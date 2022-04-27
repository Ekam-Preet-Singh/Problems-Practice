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
Q393.) LCS (Longest Common Subsequence) of three strings

INPUT:
2

5 8 13
geeks geeksfor geeksforgeeks

2 8 15
gh umeaylnl fdxfircvscxggbw

OUTPUT:
Case #1: 5
Case #2: 0

*/

int memo[101][101][101];

int solve(string &A, string &B, string &C, int i, int j, int k, int n1, int n2, int n3)
{
    if (i == n1 || j == n2 || k == n3)
    {
        return 0;
    }

    if (memo[i][j][k] != -1)
    {
        return memo[i][j][k];
    }

    // if all the characters are same, we can include them in the longest length
    // and check for the longest length in state (i + 1, j + 1, k + 1)
    if (A[i] == B[j] and A[i] == C[k])
    {
        return memo[i][j][k] = 1 + solve(A, B, C, i + 1, j + 1, k + 1, n1, n2, n3);
    }

    // if the characters do not match, we simply call for all the possible recursions
    // and store the maximum we get out of them
    return memo[i][j][k] = max({solve(A, B, C, i + 1, j, k, n1, n2, n3),
                                solve(A, B, C, i, j + 1, k, n1, n2, n3),
                                solve(A, B, C, i, j, k + 1, n1, n2, n3),
                                solve(A, B, C, i + 1, j + 1, k, n1, n2, n3),
                                solve(A, B, C, i + 1, j, k + 1, n1, n2, n3),
                                solve(A, B, C, i, j + 1, k + 1, n1, n2, n3)});
}

int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
    for (int i = 0; i < n1; ++i)
    {
        for (int j = 0; j < n2; ++j)
        {
            for (int k = 0; k < n3; ++k)
            {
                memo[i][j][k] = -1;
            }
        }
    }
    return solve(A, B, C, 0, 0, 0, n1, n2, n3);
}

void solve()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    string A, B, C;
    cin >> A >> B >> C;
    cout << LCSof3(A, B, C, n1, n2, n3) << endl;
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