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
Q391.) Longest Increasing Subsequence

INPUT:
2

6
5 8 3 7 9 1

16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15

OUTPUT:
Case #1: 3
Case #2: 6

*/

class Solution
{
public:
    // binary search function finds the position of the first integer
    // in arr[] which is greater than or equal to 'value'.
    int binarySearch(int arr[], int l, int h, int value)
    {
        // if new value is greater than all array values,
        // then it is placed at the end.
        if (value > arr[h])
        {
            return h + 1;
        }

        // binary search algorithm.
        while (h > l)
        {
            int middle = (h + l) / 2;

            if (arr[middle] == value)
            {
                return middle;
            }

            if (arr[middle] > value)
            {
                h = middle;
            }

            else
            {
                l = middle + 1;
            }
        }

        return h;
    }

    // Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // tail[i] holds the last value in a subsequence of length i+1.
        int tail[n];
        tail[0] = a[0];

        // the position of last filled index in tail[].
        int lastIndex = 0;

        for (int i = 1; i < n; i++)
        {
            // getting the furthest possible index for a[i].
            int index = binarySearch(tail, 0, lastIndex, a[i]);

            tail[index] = a[i];
            // updating lastIndex.
            lastIndex = max(lastIndex, index);
        }
        // returning the result.
        return lastIndex + 1;
    }
};

void solve()
{
    int n;
    // taking size of array
    cin >> n;
    int a[n];

    // inserting elements to the array
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Solution ob;
    // calling method longestSubsequence()
    cout << ob.longestSubsequence(n, a) << endl;
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