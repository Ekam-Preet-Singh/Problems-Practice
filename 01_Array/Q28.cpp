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
Q28.) Find the triplet that sum to a given value

INPUT:
3

6 13
1 4 45 6 10 8

5 10
1 2 4 3 6

9 793
998 550 557 562 628 468 542 130 241

OUTPUT:
Case #1: 1
Case #2: 1
Case #3: 0

*/

class Solution
{
public:
    // Function to find if there exists a triplet in the
    // array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        int l, r;
        // Sorting the elements.
        sort(A, A + n);

        // Traversing the array elements.
        for (int i = 0; i < n - 2; i++)
        {
            // Taking two pointers. One at element after ith index and another
            // at the last index.
            l = i + 1;
            r = n - 1;
            while (l < r)
            {
                // If sum of elements at indexes i, l and r is equal
                // to required number, we return true.
                if (A[i] + A[l] + A[r] == X)
                {
                    return true;
                }
                // Else if the sum is less than required number, it means we need
                // to increase the sum so we increase the left pointer l.
                else if (A[i] + A[l] + A[r] < X)
                {
                    l++;
                }
                // Else the sum is more than required number and we need to
                // decrease the sum so we decrease the right pointer r.
                else
                {
                    r--;
                }
            }
        }

        // returning false if no triplet sum equal to required number is present.
        return false;
    }
};

void solve()
{
    int n, X;
    cin >> n >> X;
    int i, A[n];
    for (i = 0; i < n; i++)
        cin >> A[i];
    Solution ob;
    cout << ob.find3Numbers(A, n, X) << endl;
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