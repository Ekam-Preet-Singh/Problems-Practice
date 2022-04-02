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
Q214.) Check preorder is valid or not

INPUT:
2

5
40 30 35 80 100

6
1 2 3 4 5 6

OUTPUT:
Case #1: 35 30 100 80 40
Case #2: 6 5 4 3 2 1

*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

// A Stack has array of Nodes, capacity, and top
typedef struct Stack
{
    int top;
    int capacity;
    Node **array;
} Stack;

// A utility function to create a new tree node
Node *newNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to create a stack of given capacity
Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (Node **)malloc(stack->capacity * sizeof(Node *));
    return stack;
}

// A utility function to check if stack is full
int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// A utility function to check if stack is empty
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// A utility function to push an item to stack
void push(Stack *stack, Node *item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// A utility function to remove an item from stack
Node *pop(Stack *stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

// A utility function to get top node of stack
Node *peek(Stack *stack)
{
    return stack->array[stack->top];
}

bool canRepresentBST(int pre[], int n)
{
    // Create an empty stack
    stack<int> s;

    // Initialize current root as minimum possible
    // value
    int root = INT_MIN;

    // Traverse given array
    for (int i = 0; i < n; i++)
    {
        // If we find a node who is on right side
        // and smaller than root, return false
        if (pre[i] < root)
            return false;

        // If pre[i] is in right subtree of stack top,
        // Keep removing items smaller than pre[i]
        // and make the last removed item as new
        // root.
        while (!s.empty() && s.top() < pre[i])
        {
            root = s.top();
            s.pop();
        }

        // At this point either stack is empty or
        // pre[i] is smaller than root, push pre[i]
        s.push(pre[i]);
    }
    return true;
}

// A utility function to print postorder traversal of a Binary Tree
void printPostorder(Node *node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

// Function that constructs BST from its preorder traversal.
Node *post_order(int pre[], int size)
{
    if (canRepresentBST(pre, size) == false)
    {
        cout << "NO";
        return NULL;
    }

    // creating a stack of capacity equal to size of array.
    Stack *stack = createStack(size);

    // first element of preorder traversal is always root of BST.
    Node *root = newNode(pre[0]);

    // pushing root into the stack.
    push(stack, root);

    int i;
    Node *temp;

    // iterating over rest of the array elements.
    for (i = 1; i < size; ++i)
    {
        temp = NULL;

        // we keep on popping from stack while data at top of stack is less
        // than the current array element.
        while (!isEmpty(stack) && pre[i] > peek(stack)->data)
            temp = pop(stack);

        // we make this greater value as the right child and push it into stack.
        if (temp != NULL)
        {
            temp->right = newNode(pre[i]);
            push(stack, temp->right);
        }

        // if current array element is less than data at top of stack, we make
        // it as the left child of the stack's top node and push it into stack.
        else
        {
            peek(stack)->left = newNode(pre[i]);
            push(stack, peek(stack)->left);
        }
    }
    return root;
}

void solve()
{
    int n;
    // Input the size of the array
    cin >> n;
    int arr[n];

    // Input the array
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    printPostorder(post_order(arr, n));
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