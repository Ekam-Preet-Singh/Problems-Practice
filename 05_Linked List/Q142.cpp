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
Q142.) Write a Program to check whether the Singly Linked list is a palindrome or not.

INPUT:
4

5
1 2 3 4 5

3
1 2 1

4
1 2 3 4

6
6 5 4 4 5 6

OUTPUT:
Case #1: 0
Case #2: 1
Case #3: 0
Case #4: 1

*/

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to reverse a linked list.
    Node *reverse_list(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Function to check whether two lists are identical.
    bool is_identical(Node *n1, Node *n2)
    {
        // iterating over both lists and returning 0 if data at any node
        // is not equal in both lists.
        for (; n1 && n2; n1 = n1->next, n2 = n2->next)
        {
            if (n1->data != n2->data)
            {
                return 0;
            }
        }
        // returning 1 if data at all nodes are equal.
        return 1;
    }

    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        int size = 0;
        Node *ptr;
        // finding number of nodes in the list.
        for (ptr = head; ptr; ptr = ptr->next)
        {
            size++;
        }

        if (size < 2)
        {
            return 1;
        }

        // now, we split list into 2 halves. In case of odd number of elements,
        // first half will have the middle element.

        ptr = head;
        int mid_pt = (size - 1) / 2;

        // using a pointer to get to middle element to get the second half of list.
        while (mid_pt--)
        {
            ptr = ptr->next;
        }

        // ptr now holds address of last element of first half.

        // storing the elements of second half separately in head2.
        Node *head2 = ptr->next;
        ptr->next = NULL;

        // we reverse the second half of list.
        head2 = reverse_list(head2);

        // we check whether both halves are identical (for odd number of elements
        // first half will have one extra element).
        bool ret = is_identical(head, head2);

        // we reverse back the second half of list and connect it to the first half.
        head2 = reverse_list(head2);
        ptr->next = head2;

        // returning 1 if list is palindrome else 0.
        return ret;
    }
};

void solve()
{
    int i, n, l, firstdata;
    struct Node *head = NULL, *tail = NULL;
    cin >> n;
    cin >> firstdata;
    head = new Node(firstdata);
    tail = head;
    for (i = 1; i < n; i++)
    {
        cin >> l;
        tail->next = new Node(l);
        tail = tail->next;
    }
    Solution obj;
    cout << obj.isPalindrome(head) << endl;
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