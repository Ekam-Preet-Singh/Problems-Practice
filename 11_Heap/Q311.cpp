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
Q311.) Sort an Array using heap. (HeapSort)

INPUT:
2

10
0 47 8 2 87 91 9 4 77 1

11
1 3 5 4 6 13 10 9 8 15 17

OUTPUT:
Case #1: 0 1 2 4 8 9 47 77 87 91
Case #2: 1 3 4 5 6 8 9 10 13 15 17

*/

class Solution
{
protected:
    // Heapify function to maintain heap property.
    std::vector<int> heap;
    void heapify(int index)
    {
        for (int i = index; i < heap.size(); i = index)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < heap.size() && right < heap.size())
            {
                int temp = std::min(std::min(heap[left], heap[right]), heap[index]);
                if (temp == heap[left])
                {
                    std::swap(heap[left], heap[index]);
                    index = left;
                }
                else if (temp == heap[right])
                {
                    std::swap(heap[right], heap[index]);
                    index = right;
                }
                else
                {
                    break;
                }
            }
            else if (left < heap.size() && right >= heap.size())
            {
                int temp = std::min(heap[left], heap[index]);
                if (temp == heap[left])
                {
                    std::swap(heap[left], heap[index]);
                    index = left;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    int extract_top()
    {
        int res = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        this->heapify(0);
        return res;
    }
    // Function to build a Heap from array.
    void buildHeap(int val)
    {
        this->heap.push_back(val);
        int n = this->heap.size();
        for (int i = n - 1; i > 0; i = floor((i - 1) / 2))
        {
            if (heap[floor((i - 1) / 2)] > heap[i])
            {
                std::swap(heap[floor((i - 1) / 2)], heap[i]);
            }
            else
            {
                break;
            }
        }
    }

public:
    // Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            this->buildHeap(arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = this->extract_top();
        }
    }
};

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
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
    ob.heapSort(arr, n);
    printArray(arr, n);
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