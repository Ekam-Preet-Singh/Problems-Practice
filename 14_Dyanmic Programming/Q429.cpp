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
Q429.) Boolean Parenthesization Problem

INPUT:
2

7
T|T&F^T

5
T^F|F

OUTPUT:
Case #1: 4
Case #2: 2

*/

class Solution
{
public:
    int countWays(int N, string S)
    {
        int i, j, len;
        int dpTrue[N][N], dpFalse[N][N];

        for (i = 0; i < N; i += 2)
        {
            if (S[i] == 'T')
            {
                dpTrue[i][i] = 1;
                dpFalse[i][i] = 0;
            }
            else
            {
                dpTrue[i][i] = 0;
                dpFalse[i][i] = 1;
            }
        }
        int x = 2;
        while (x < N)
        {
            for (i = 0; (i + x) < N; i += 2)
            {
                dpTrue[i][i + x] = dpFalse[i][i + x] = 0;
                for (j = i + 1; j < (i + x); j += 2)
                {
                    if (S[j] == '|')
                    {
                        dpTrue[i][i + x] = (dpTrue[i][i + x] + dpTrue[i][j - 1] * dpTrue[j + 1][i + x] + dpTrue[i][j - 1] * dpFalse[j + 1][i + x] + dpFalse[i][j - 1] * dpTrue[j + 1][i + x]) % 1003;
                        dpFalse[i][i + x] = (dpFalse[i][i + x] + dpFalse[i][j - 1] * dpFalse[j + 1][i + x]) % 1003;
                    }
                    else if (S[j] == '&')
                    {
                        dpTrue[i][i + x] = (dpTrue[i][i + x] + dpTrue[i][j - 1] * dpTrue[j + 1][i + x]) % 1003;
                        dpFalse[i][i + x] = (dpFalse[i][i + x] + dpFalse[i][j - 1] * dpFalse[j + 1][i + x] + dpTrue[i][j - 1] * dpFalse[j + 1][i + x] + dpFalse[i][j - 1] * dpTrue[j + 1][i + x]) % 1003;
                    }
                    else
                    {
                        dpTrue[i][i + x] = (dpTrue[i][i + x] + dpFalse[i][j - 1] * dpTrue[j + 1][i + x] + dpTrue[i][j - 1] * dpFalse[j + 1][i + x]) % 1003;
                        dpFalse[i][i + x] = (dpFalse[i][i + x] + dpFalse[i][j - 1] * dpFalse[j + 1][i + x] + dpTrue[i][j - 1] * dpTrue[j + 1][i + x]) % 1003;
                    }
                }
            }
            x = x + 2;
        }
        return dpTrue[0][N - 1] % 1003;
    }
};

void solve()
{
    int N;
    cin >> N;
    string S;
    cin >> S;

    Solution ob;
    cout << ob.countWays(N, S) << "\n";
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