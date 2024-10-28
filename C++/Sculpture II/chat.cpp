#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// Structure to represent a block
struct Block
{
    long long x_left, x_right;  // Compressed indices for left and right edges
    int h;
};

const int MAXN = 400010;  // Adjusted maximum number of unique positions
struct SegmentTree
{
    struct Node
    {
        long long max_height;
        long long lazy;
    } tree[4 * MAXN];

    SegmentTree()
    {
        for (int i = 0; i < 4 * MAXN; ++i)
        {
            tree[i].max_height = 0;
            tree[i].lazy = -1;
        }
    }

    void push(int node, int l, int r)
    {
        if (tree[node].lazy != -1)
        {
            tree[node].max_height = tree[node].lazy;
            if (l != r)
            {  // If not a leaf node
                tree[2 * node].lazy = tree[node].lazy;
                tree[2 * node + 1].lazy = tree[node].lazy;
            }
            tree[node].lazy = -1;
        }
    }

    void update(int node, int l, int r, int ul, int ur, long long val)
    {
        push(node, l, r);
        if (r < ul || l > ur) return;
        if (l >= ul && r <= ur)
        {
            tree[node].lazy = val;
            push(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(2 * node, l, mid, ul, ur, val);
        update(2 * node + 1, mid + 1, r, ul, ur, val);
        tree[node].max_height =
            max(tree[2 * node].max_height, tree[2 * node + 1].max_height);
    }

    long long query(int node, int l, int r, int ql, int qr)
    {
        push(node, l, r);
        if (r < ql || l > qr) return 0;
        if (l >= ql && r <= qr) return tree[node].max_height;
        int mid = (l + r) / 2;
        return max(query(2 * node, l, mid, ql, qr),
                   query(2 * node + 1, mid + 1, r, ql, qr));
    }
} segTree;

int main()
{
    ifstream fin("artin.txt");
    ofstream fout("artout.txt");

    int N;
    fin >> N;

    vector<long long> x_positions;
    vector<Block> blocks(N);

    for (int i = 0; i < N; ++i)
    {
        long long t, w;
        int h;
        fin >> t >> w >> h;
        long long x_right = -t;
        long long x_left = -t - w;
        x_positions.push_back(x_left);
        x_positions.push_back(x_right);
        blocks[i] = {x_left, x_right, h};
    }

    // Coordinate compression
    sort(x_positions.begin(), x_positions.end());
    x_positions.erase(unique(x_positions.begin(), x_positions.end()),
                      x_positions.end());

    int K = x_positions.size();
    // Build mapping from x positions to indices
    auto get_index = [&](long long x)
    {
        return lower_bound(x_positions.begin(), x_positions.end(), x) -
               x_positions.begin();
    };

    long long max_height = 0;

    for (const auto &block : blocks)
    {
        int l = get_index(block.x_left);
        int r = get_index(block.x_right) - 1;

        // Query maximum height in the range [l, r]
        long long current_max = segTree.query(1, 0, K - 1, l, r);
        long long new_height = current_max + block.h;
        // Update the range [l, r] to new_height
        segTree.update(1, 0, K - 1, l, r, new_height);
        max_height = max(max_height, new_height);
    }

    fout << max_height << endl;

    fin.close();
    fout.close();

    return 0;
}