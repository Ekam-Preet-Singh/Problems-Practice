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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

/*
Q20.) Rearrange the array in alternating positive and negative items with O(1) extra space

INPUT:
5

6
1 2 3 -4 -1 4

10
-5 -2 5 2 4 7 1 8 0 -8

4
-2 3 4 -1

3
-2 3 1

10
-5 3 4 5 -6 -2 8 9 -1 -4

OUTPUT:
Case #1:
Given array is 
1 2 3 -4 -1 4 
Rearranged array is 
-1 2 -4 4 1 3 
Case #2:
Given array is 
-5 -2 5 2 4 7 1 8 0 -8 
Rearranged array is 
0 1 -2 2 -5 7 -8 5 4 8 
Case #3:
Given array is 
-2 3 4 -1 
Rearranged array is 
-2 3 -1 4 
Case #4:
Given array is 
-2 3 1 
Rearranged array is 
-2 3 1 
Case #5:
Given array is 
-5 3 4 5 -6 -2 8 9 -1 -4 
Rearranged array is 
-2 3 -6 5 -5 9 -1 8 -4 4 

*/

// Function to rearrange positive and negative
// integers in alternate fashion. The below
// solution doesn't maintain original order of
// elements
void rearrange(int arr[], int n)
{
    int i = 0, j = n - 1;

    // shift all negative values to the end
    while (i < j)
    {
        while (i <= n - 1 and arr[i] > 0)
        {
            i += 1;
        }
        while (j >= 0 and arr[j] < 0)
        {
            j -= 1;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    // i has index of leftmost
    // negative element
    if (i == 0 || i == n)
        return;

    // start with first positive
    // element at index 0

    // Rearrange array in alternating
    // positive &
    // negative items
    int k = 0;
    while (k < n && i < n)
    {
        // swap next positive
        // element at even position
        // from next negative element.
        swap(arr[k], arr[i]);
        i = i + 1;
        k = k + 2;
    }
}

// Utility function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int m = 0; m < n; m++)
        cin >> arr[m];

    cout << "Given array is \n";
    printArray(arr, n);

    rearrange(arr, n);

    cout << "Rearranged array is \n";
    printArray(arr, n);
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    clock_t begin = clock();
    file_i_o();
#endif

    ll t = 1;
    ll case_num = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << case_num++ << ":\n";
        solve();
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}