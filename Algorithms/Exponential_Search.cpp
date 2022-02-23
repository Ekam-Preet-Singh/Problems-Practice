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
Exponential Search


Exponential search is also known as doubling or galloping search.
This mechanism is used to find the range where the search key may present.
If L and U are the upper and lower bound of the list, then L and U both are the power of 2.
For the last section, the U is the last position of the list.
For that reason, it is known as exponential.
After finding the specific range, it uses the binary search technique to find the exact location of the search key.

Time Cpmplexity: O(nlogn) - O(1)
Space Complexity: O(1) or O(nlogn){Recursiver approach}

Pseudo Code:

Begin
   if start <= end then
      mid := start + (end - start) /2
      if array[mid] = key then
         return mid location
      if array[mid] > key then
         call binarySearch(array, mid+1, end, key)
      else when array[mid] < key then
         call binarySearch(array, start, mid-1, key)
   else
      return invalid location
End

*/

// A recursive binary search function. It returns
// location of x in  given array arr[l..r] is
// present, otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
        {
            return mid;
        }

        // If element is smaller than mid, then it
        // can only be present n left subarray
        if (arr[mid] > x)
        {
            return binarySearch(arr, l, mid - 1, x);
        }

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not present
    // in array
    return -1;
}

// Returns position of first occurrence of
// x in array
int exponentialSearch(int arr[], int n, int x)
{
    // If x is present at first location itself
    if (arr[0] == x)
    {
        return 0;
    }

    // Find range for binary search by
    // repeated doubling
    int i = 1;
    while (i < n && arr[i] <= x)
    {
        i = i * 2;
    }

    //  Call binary search for the found range.
    return binarySearch(arr, i / 2, min(i, n - 1), x);
}

void solve()
{
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    int key;
    cin >> key;

    int result = exponentialSearch(arr, N, key);
    (result == -1) ? cout << "Element is not present in array" : cout << "Element is present at index " << result;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    file_i_o();

    ll t = 1;
    // ll case_num = 1;
    cin >> t;
    while (t--)
    {
        // cout << "Case #" << case_num++ << ": ";
        solve();
    }

    return 0;
}