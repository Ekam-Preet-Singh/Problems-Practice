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
Q45.) Kth smallest element in a row-column wise sorted matrix

INPUT:
2

4
16 28 60 64
22 41 63 91
27 50 87 93
36 78 87 94
3

5
7 17 27 36 38
14 23 35 38 43
19 26 42 49 50
23 33 48 52 53
30 40 52 56 64
13

OUTPUT:
Case #1: 27
Case #2: 38

*/

#define MAX 1000
int mat[MAX][MAX];

// A structure to store an entry of heap.  The entry contains
// a value from 2D array, row and column numbers of the value
class HeapNode
{
public:
    int val; // value to be stored
    int r;   // Row number of value in 2D array
    int c;   // Column number of value in 2D array
};

// A utility function to swap two HeapNode items.
void swap(HeapNode *x, HeapNode *y)
{
    HeapNode z = *x;
    *x = *y;
    *y = z;
}

// A utility function to minheapify the node harr[i] of a heap
// stored in harr[]
void minHeapify(HeapNode harr[], int i, int heap_size)
{
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    int smallest = i;
    if (l < heap_size && harr[l].val < harr[i].val)
    {
        smallest = l;
    }
    if (r < heap_size && harr[r].val < harr[smallest].val)
    {
        smallest = r;
    }
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        minHeapify(harr, smallest, heap_size);
    }
}

// A utility function to convert harr[] to a min heap
void buildHeap(HeapNode harr[], int n)
{
    int i = (n - 1) / 2;
    while (i >= 0)
    {
        minHeapify(harr, i, n);
        i--;
    }
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    // k must be greater than 0 and smaller than n*n
    if (k <= 0 || k > n * n)
    {
        return INT_MAX;
    }

    // Create a min heap of elements from first row of 2D array
    HeapNode harr[n];
    for (int i = 0; i < n; i++)
    {
        harr[i] = {mat[0][i], 0, i};
    }
    buildHeap(harr, n);

    HeapNode hr;
    for (int i = 0; i < k; i++)
    {
        // Get current heap root
        hr = harr[0];

        // Get next value from column of root's value. If the
        // value stored at root was last value in its column,
        // then assign INFINITE as next value
        int nextval = (hr.r < (n - 1)) ? mat[hr.r + 1][hr.c] : INT_MAX;

        // Update heap root with next value
        harr[0] = {nextval, (hr.r) + 1, hr.c};

        // Heapify root
        minHeapify(harr, 0, n);
    }

    // Return the value at last extracted root
    return hr.val;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    int r;
    cin >> r;
    cout << kthSmallest(mat, n, r) << endl;
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