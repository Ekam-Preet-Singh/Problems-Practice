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
Q426.) Palindrome Partitioning Problem

INPUT:
2

ababbbabbababa

aaabba

OUTPUT:
Case #1: 3
Case #2: 1

*/

class Solution
{
public:
    int palindromicPartition(string str)
    {
        int n = str.size();

        /* Create two arrays to build the solution in bottom up manner
          C[i] = Minimum number of cuts needed for palindrome partitioning
                    of substring str[0..i]
          P[i][j] = true if substring str[i..j] is palindrome, else false
          Note that C[i] is 0 if P[0][i] is true */
        int C[n];
        bool P[n][n];

        int i, j, k, L;
        for (i = 0; i < n; i++)
        {
            P[i][i] = true;
        }

        for (L = 2; L <= n; L++)
        {
            for (i = 0; i < n - L + 1; i++)
            {
                j = i + L - 1; // set ending index

                // If L is 2, then we just need to compare two characters. Else
                // need to check two corner characters and value of P[i+1][j-1]
                if (L == 2)
                {
                    P[i][j] = (str[i] == str[j]);
                }
                else
                {
                    P[i][j] = ((str[i] == str[j]) & P[i + 1][j - 1]);
                }
            }
        }

        for (i = 0; i < n; i++)
        {
            if (P[0][i])
                C[i] = 0;
            else
            {
                C[i] = INT_MAX;
                for (j = 0; j < i; j++)
                {
                    if (P[j + 1][i] == true & C[j] + 1 < C[i])
                    {
                        C[i] = C[j] + 1;
                    }
                }
            }
        }
        return C[n - 1];
    }
};

void solve()
{
    string str;
    cin >> str;

    Solution ob;
    cout << ob.palindromicPartition(str) << "\n";
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