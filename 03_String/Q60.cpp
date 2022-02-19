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
Q60.) Find next greater number with same set of digits. [Very Very IMP]

INPUT:
3

6
1 2 3 6 5 4

3
3 2 1

9
1 5 8 5 1 3 4 6 7

OUTPUT:
Case #1: 1 2 4 3 5 6 
Case #2: 1 2 3 
Case #3: 1 5 8 5 1 3 4 7 6 

*/

class Solution
{
public:
    vector<int> nextPermutation(int n, vector<int> arr)
    {
        // If number of digits is 1 then just return the vector
        if (n == 1)
            return arr;

        // Start from the right most digit and find the first
        // digit that is
        // smaller than the digit next to it.
        int i = 0;
        for (i = n - 1; i > 0; i--)
        {
            if (arr[i] > arr[i - 1])
            {
                break;
            }
        }

        // If there is a possibility of a next greater element
        if (i != 0)
        {
            // Find the smallest digit on right side of (i-1)'th
            // digit that is
            // greater than number[i-1]
            for (int j = n - 1; j >= i; j--)
            {
                if (arr[i - 1] < arr[j])
                {
                    // Swap the found smallest digit i.e. arr[j]
                    // with arr[i-1]
                    swap(arr[i - 1], arr[j]);
                    break;
                }
            }
        }

        // Reverse the digits after (i-1) because the digits
        // after (i-1) are in decreasing order and thus we will
        // get the smallest element possible from these digits
        reverse(arr.begin() + i, arr.end());

        // If i is 0 that means elements are in decreasing order
        // Therefore, no greater element possible then we just
        // return the lowest possible
        // order/element formed from these digits by just
        // reversing the vector

        return arr;
    }
};

void solve()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    Solution ob;
    vector<int> ans = ob.nextPermutation(N, arr);
    for (int u : ans)
        cout << u << " ";
    cout << "\n";
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