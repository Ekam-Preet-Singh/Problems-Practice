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
Q304.) First negative integer in every window of size “k”

INPUT:
2

5
-8 2 3 -6 10
2

8
12 -1 -7 8 -15 30 16 28
3

OUTPUT:
Case #1: -8 0 -6 -6
Case #2: -1 -1 -7 -15 -15 0

*/

// function to find the first negative
// integer in every window of size k
vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k)
{
    // A Double Ended Queue, Di that will store indexes of
    // useful array elements for the current window of size k.
    // The useful elements are all negative integers.
    deque<long long int> Di;
    vector<long long> ans;

    /* Process first k (or first window) elements of array */
    long long int i;
    for (i = 0; i < k; i++)
        // Add current element at the rear of Di
        // if it is a negative integer
        if (arr[i] < 0)
        {
            Di.push_back(i);
        }

    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for (; i < n; i++)
    {
        // if Di is not empty then the element at the
        // front of the queue is the first negative integer
        // of the previous window
        if (!Di.empty())
        {
            ans.push_back(arr[Di.front()]);
        }

        // else the window does not have a
        // negative integer
        else
        {
            ans.push_back(0);
        }

        // Remove the elements which are out of this window
        while ((!Di.empty()) && Di.front() < (i - k + 1))
        {
            Di.pop_front(); // Remove from front of queue
        }

        // Add current element at the rear of Di
        // if it is a negative integer
        if (arr[i] < 0)
        {
            Di.push_back(i);
        }
    }

    // Print the first negative
    // integer of last window
    if (!Di.empty())
    {
        ans.push_back(arr[Di.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    return ans;
}

void solve()
{
    long long int n;
    cin >> n;
    long long int arr[n];
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long int k;
    cin >> k;

    vector<long long> ans = printFirstNegativeInteger(arr, n, k);
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
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