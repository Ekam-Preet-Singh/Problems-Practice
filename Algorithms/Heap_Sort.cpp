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
Heap Sort

Heap sort is a comparison-based sorting technique based on Binary Heap data structure.
It is similar to selection sort where we first find the minimum element and place the minimum element at the beginning.
We repeat the same process for the remaining elements.

A complete binary tree is a binary tree in which every level,
except possibly the last, is completely filled, and all nodes are as far left as possible
A Binary Heap is a Complete Binary Tree where items are stored in a special order such that the value in a parent node is greater(or smaller) than the values in its two children nodes.
The former is called max heap and the latter is called min-heap.
The heap can be represented by a binary tree or array.

The process of reshaping a binary tree into a Heap data structure is known as ‘heapify’.
A binary tree is a tree data structure that has two child nodes at max.
If a node’s children nodes are ‘heapified’, then only ‘heapify’ process can be applied over that node.
A heap should always be a complete binary tree.
Starting from a complete binary tree, we can modify it to become a Max-Heap by running a function called ‘heapify’ on all the non-leaf elements of the heap.

Algorithm
1. Build a max heap from the input data.
2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. Finally, heapify the root of the tree.
3. Repeat step 2 while the size of the heap is greater than 1.

Pseudo Code:
heapify(array)
   Root = array[0]
   Largest = largest( array[0] , array [2 * 0 + 1]. array[2 * 0 + 2])
   if(Root != Largest)
       Swap(Root, Largest)

*/

class Solution
{
public:
    void swap(int *a, int *b)
    {
        int c = *a;
        *a = *b;
        *b = c;
    }

    // Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)
    {
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        int largest = i;

        // if left or right child is greater than current element,
        // we store its position.
        if (l < n && arr[largest] < arr[l])
        {
            largest = l;
        }
        if (r < n && arr[largest] < arr[r])
        {
            largest = r;
        }

        // if largest is not equal to i, we swap the values at their position.
        if (largest != i)
        {
            swap(&arr[i], &arr[largest]);
            // calling function recursively for the largest variable.
            heapify(arr, n, largest);
        }
    }

    // Function to build a Heap from array.
    void buildHeap(int arr[], int n)
    {
        // calling heapify function for values from half to first index.
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    }

    // Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        // calling function to build heap with array.
        buildHeap(arr, n);
        for (int i = n - 1; i >= 0; i--)
        {
            // swapping values at current and first index.
            swap(&arr[0], &arr[i]);
            // calling heapify function for first index.
            heapify(arr, i, 0);
        }
    }
};

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Solution ob;
    ob.heapSort(a, n);
    printArray(a, n);
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