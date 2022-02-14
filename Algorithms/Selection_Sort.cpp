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
Selection Sort

The selection sort algorithm sorts an array by repeatedly finding the minimum element
(considering ascending order) from unsorted part and putting it at the beginning.
The algorithm maintains two subarrays in a given array.
1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.
In every iteration of selection sort, the minimum element (considering ascending order)
from the unsorted subarray is picked and moved to the sorted subarray.

*/

class Solution
{
public:
    /*
    A sorting algorithm is said to be stable if two objects with equal
    or same keys appear in the same order in sorted output as they appear in the input array to be sorted.

    Any comparison based sorting algorithm which is not stable by nature can be modified
    to be stable by changing the key comparison operation so that the comparison of two keys
    considers position as a factor for objects with equal key or by tweaking it in a way such that its meaning doesn’t change
    and it becomes stable as well
    */
    void stableSelectionSort(int a[], int n)
    {
        // Iterate through array elements
        for (int i = 0; i < n - 1; i++)
        {

            // Loop invariant : Elements till a[i - 1]
            // are already sorted.

            // Find minimum element from
            // arr[i] to arr[n - 1].
            int min = i;
            for (int j = i + 1; j < n; j++)
            {
                if (a[min] > a[j])
                {
                    min = j;
                }
            }

            // Move minimum element at current i.
            int key = a[min];
            while (min > i)
            {
                a[min] = a[min - 1];
                min--;
            }
            a[i] = key;
        }
    }

    int select(int arr[], int i)
    {
        int max = arr[0], ind = 0;
        // Find the minimum element in unsorted array
        for (int j = 1; j <= i; j++)
        {
            if (arr[j] > max)
            {
                ind = j;
                max = arr[j];
            }
        }
        return ind;
    }

    void swap(int *xp, int *yp)
    {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }

    void selectionSort(int arr[], int n)
    {
        int i, j;
        // One by one move boundary of unsorted subarray
        for (i = n - 1; i >= 0; i--)
        {
            // Find the minimum element in unsorted array
            int j = select(arr, i);
            // Swap the found minimum element with the first element
            swap(&arr[i], &arr[j]);
        }
    }
};

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[1] << " ";
    cout << endl;
}

void solve()
{
    int n, i;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];

    Solution ob;
    ob.selectionSort(arr, n);
    printArray(arr, n);
    ob.stableSelectionSort(arr, n);
    printArray(arr, n);
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