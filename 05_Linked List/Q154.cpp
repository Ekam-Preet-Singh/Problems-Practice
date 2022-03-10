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
Q154.) Clone a linked list with next and random pointer

INPUT:
2

4 2
1 2 3 4
1 2 2 4

4 2
1 3 5 9
1 1 3 4

OUTPUT:
Case #1: 1
Case #2: 1

*/

struct Node
{
    int data;
    Node *next;
    Node *arb;

    Node(int x)
    {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

class Solution
{
public:
    Node *copyList(Node *head)
    {
        if (head == NULL)
        {
            return head;
        }

        Node *t = head;
        while (t != NULL)
        {
            // making an identical list merged with original list.
            // creating the copy of node 1 and inserting it between node 1
            //& node 2in original Linked List, creating a copy of 2 and
            // inserting it between 2 & 3 and continuing this.
            Node *n = new Node(t->data);
            n->next = t->next;
            t->next = n;
            t = n->next;
        }

        t = head;
        Node *head2 = head->next;
        while (t != NULL)
        {
            // setting the arbitrary(random) pointers of duplicate list.
            // this works because original->next is nothing but copy of original
            // and Original->random->next is nothing but copy of random.
            if (t->arb == NULL)
            {
                t->next->arb = NULL;
            }
            else
            {
                t->next->arb = t->arb->next;
            }

            t = t->next->next;
        }

        t = head;
        while (t != NULL)
        {
            // separating the 2 merged lists (duplicate and original).
            head = t->next->next;

            if (head)
            {
                t->next->next = head->next;
            }
            else
            {
                t->next->next = NULL;
            }
            t->next = head;
            t = head;
        }
        // returning the cloned list.
        return head2;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        int k;
        if (temp->arb == NULL)
            k = -1;
        else
            k = temp->arb->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}

void append(Node **head_ref, Node **tail_ref, int new_data)
{

    Node *new_node = new Node(new_data);
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
    }
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

bool validation(Node *head, Node *res)
{

    Node *temp1 = head;
    Node *temp2 = res;

    int len1 = 0, len2 = 0;
    while (temp1 != NULL)
    {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        len2++;
        temp2 = temp2->next;
    }
    if (len1 != len2)
        return false;

    temp1 = head;
    temp2 = res;
    map<Node *, Node *> a;
    while (temp1 != NULL)
    {

        if (temp1 == temp2)
            return false;

        if (temp1->data != temp2->data)
            return false;
        if (temp1->arb != NULL and temp2->arb != NULL)
        {
            if (temp1->arb->data != temp2->arb->data)
                return false;
        }
        else if (temp1->arb != NULL and temp2->arb == NULL)
            return false;
        else if (temp1->arb == NULL and temp2->arb != NULL)
            return false;
        a[temp1] = temp2;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    temp1 = head;
    temp2 = res;
    while (temp1 != NULL)
    {

        if (temp1->arb != NULL and temp2->arb != NULL)
        {
            if (a[temp1->arb] != temp2->arb)
                return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

void solve()
{
    int i, n, l, k;
    Node *generated_addr = NULL;
    generated_addr = NULL;
    struct Node *head = NULL, *tail = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;
    cin >> n >> k;
    for (i = 1; i <= n; i++)
    {
        cin >> l;
        append(&head, &tail, l);
        append(&head2, &tail2, l);
    }
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;

        Node *tempA = head;
        Node *temp2A = head2;
        int count = -1;

        while (tempA != NULL)
        {
            count++;
            if (count == a - 1)
                break;
            tempA = tempA->next;
            temp2A = temp2A->next;
        }
        Node *tempB = head;
        Node *temp2B = head2;
        count = -1;

        while (tempB != NULL)
        {
            count++;
            if (count == b - 1)
                break;
            tempB = tempB->next;
            temp2B = temp2B->next;
        }

        if (a <= n)
        {
            tempA->arb = tempB;
            temp2A->arb = temp2B;
        }
    }

    generated_addr = head;
    Solution ob;
    struct Node *res = ob.copyList(head);
    if (validation(head2, res) && validation(head, res))
        cout << validation(head2, res) << endl;
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