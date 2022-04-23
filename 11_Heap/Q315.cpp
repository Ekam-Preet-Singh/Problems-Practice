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
Q315.) Merge “K” sorted arrays. [ IMP ]

INPUT:
2

3
1 2 3 4 5 6 7 8 9

4
1 2 3 4 2 2 3 4 5 5 6 6 7 8 9 9

OUTPUT:
Case #1: 1 2 3 4 5 6 7 8 9
Case #2: 1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9

*/

void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int n;
// declaring min heap node.
class MinHeapNode
{
public:
    // the element to be stored.
    int element;
    // index of the array from which the element is taken.
    int i;
    // index of the next element to be picked from array.
    int j;
};

// Function to swap two nodes.
void swap(MinHeapNode *x, MinHeapNode *y)
{
    MinHeapNode temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap
{
    MinHeapNode *harr;
    int heap_size;

public:
    // Constructor: creates a min heap of given size.
    // Constructor: Builds a heap from a given array a[] of given size.
    MinHeap(MinHeapNode a[], int size)
    {
        heap_size = size;
        harr = a;
        int i = (heap_size - 1) / 2;
        while (i >= 0)
        {
            MinHeapify(i);
            i--;
        }
    }

    // to heapify a subtree with root at given index.
    // a recursive method to heapify a subtree with root at given index.
    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && harr[l].element < harr[i].element)
        {
            smallest = l;
        }
        if (r < heap_size && harr[r].element < harr[smallest].element)
        {
            smallest = r;
        }
        if (smallest != i)
        {
            swap(&harr[i], &harr[smallest]);
            MinHeapify(smallest);
        }
    }

    // to get index of left child of node at index i.
    int left(int i) { return (2 * i + 1); }

    // to get index of right child of node at index i.
    int right(int i) { return (2 * i + 2); }

    // to get the root.
    MinHeapNode getMin() { return harr[0]; }

    // to replace root with new node x and heapify() new root.
    void replaceMin(MinHeapNode x)
    {
        harr[0] = x;
        MinHeapify(0);
    }
};

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        n = k;
        vector<int> output(n * k);

        // creating a min heap with k heap nodes. Every heap node
        // has first element of an array.
        MinHeapNode *harr = new MinHeapNode[k];
        for (int i = 0; i < k; i++)
        {
            // storing the first element.
            harr[i].element = arr[i][0];
            // index of array
            harr[i].i = i;
            // Index of next element to be stored from array
            harr[i].j = 1;
        }
        MinHeap hp(harr, k);

        // Now one by one we get the minimum element from min
        // heap and replace it with next element of its array.
        for (int count = 0; count < n * k; count++)
        {
            // getting the minimum element and storing it in output.
            MinHeapNode root = hp.getMin();
            output[count] = root.element;

            // finding the next element that will replace current root of heap.
            // The next element belongs to same array as the current root.
            if (root.j < n)
            {
                root.element = arr[root.i][root.j];
                root.j += 1;
            }
            // if root was the last element of its array, we store INT_MAX.
            else
            {
                root.element = INT_MAX;
            }

            // replacing root with next element of array.
            hp.replaceMin(root);
        }

        return output;
    }
};

void solve()
{
    int k;
    cin >> k;
    vector<vector<int>> arr(k, vector<int>(k, 0));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> arr[i][j];
        }
    }
    Solution obj;
    vector<int> output = obj.mergeKArrays(arr, k);
    printArray(output, k * k);
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