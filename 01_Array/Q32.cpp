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
Q32.) Three way partitioning of an array around a given value

INPUT:
2

5
1 2 3 3 4
1 2

3
1 2 3
1 3

OUTPUT:
Case #1: 1
Case #2: 1

*/

class Solution
{
public:
    // Function to partition the array around the range such
    // that array is divided into three parts.
    void threeWayPartition(vector<int> &array, int a, int b)
    {
        int n = array.size();
        // Using two pointers which help in finding the index with which
        // the elements need to be swapped if they are not in correct position.
        int start = 0, end = n - 1;

        for (int i = 0; i <= end;)
        {
            // If current element is smaller than lower range, we swap
            // it with value on next available smallest position.
            if (array[i] < a)
            {
                swap(array[i++], array[start++]);
            }

            // If current element is greater than higher range, we swap
            // it with value on next available greatest position.
            else if (array[i] > b)
            {
                swap(array[i], array[end--]);
            }

            // Else we just move ahead in the array.
            else
            {
                i++;
            }
        }
    }
};

void solve()
{
    int N;
    cin >> N;

    vector<int> array(N);
    unordered_map<int, int> ump;

    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
        ump[array[i]]++;
    }

    int a, b;
    cin >> a >> b;

    vector<int> original = array;

    int k1 = 0, k2 = 0, k3 = 0;
    int kk1 = 0;
    int kk2 = 0;
    int kk3 = 0;

    for (int i = 0; i < N; i++)
    {
        if (original[i] > b)
            k3++;
        else if (original[i] <= b and original[i] >= a)
            k2++;
        else if (original[i] < b)
            k1++;
    }

    Solution ob;
    ob.threeWayPartition(array, a, b);

    for (int i = 0; i < k1; i++)
    {
        if (array[i] < b)
            kk1++;
    }

    for (int i = k1; i < k1 + k2; i++)
    {
        if (array[i] <= b and array[i] >= a)
            kk2++;
    }

    for (int i = k1 + k2; i < k1 + k2 + k3; i++)
    {
        if (array[i] > b)
            kk3++;
    }
    bool ok = 0;
    if (k1 == kk1 and k2 == kk2 and k3 == kk3)
        ok = 1;

    for (int i = 0; i < array.size(); i++)
        ump[array[i]]--;

    for (int i = 0; i < array.size(); i++)
        if (ump[array[i]] != 0)
            ok = 0;

    if (ok)
        cout << 1 << endl;
    else
        cout << 0 << endl;
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