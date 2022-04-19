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
Q235.) Maximum sum of absolute difference of an array

INPUT:
2

4
1 2 4 8

10
1 2 3 4 5 6 7 8 9 0

OUTPUT:
Case #1: 18
Case #2: 50

*/

int MaxSumDifference(int a[], int n)
{
    // final sequence stored in the vector
    vector<int> finalSequence;

    // sort the original array
    // so that we can retrieve
    // the large elements from
    // the end of array elements
    sort(a, a + n);

    // In this loop first we will insert
    // one smallest element not entered
    // till that time in final sequence
    // and then enter a highest element
    // (not entered till that time) in
    // final sequence so that we
    // have large difference value. This
    // process is repeated till all array
    // has completely entered in sequence.
    // Here, we have loop till n/2 because
    // we are inserting two elements at a
    // time in loop.
    for (int i = 0; i < n / 2; ++i)
    {
        finalSequence.push_back(a[i]);
        finalSequence.push_back(a[n - i - 1]);
    }

    // If there are odd elements, push the
    // middle element at the end.
    if (n % 2 != 0)
    {
        finalSequence.push_back(a[n / 2]);
    }

    // variable to store the
    // maximum sum of absolute
    // difference
    int MaximumSum = 0;

    // In this loop absolute difference
    // of elements for the final sequence
    // is calculated.
    for (int i = 0; i < n - 1; ++i)
    {
        MaximumSum = MaximumSum + abs(finalSequence[i] - finalSequence[i + 1]);
    }

    // absolute difference of last element
    // and 1st element
    MaximumSum = MaximumSum + abs(finalSequence[n - 1] - finalSequence[0]);

    // return the value
    return MaximumSum;
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << MaxSumDifference(a, n) << endl;
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