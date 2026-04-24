#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
            
            build(arr, leftChild, start, mid);
            build(arr, rightChild, mid + 1, end);
            
            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
            
            if (start <= idx && idx <= mid) {
                update(leftChild, start, mid, idx, val);
            } else {
                update(rightChild, mid + 1, end, idx, val);
            }
            
            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0; 
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        
        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;
        
        int p1 = query(leftChild, start, mid, l, r);
        int p2 = query(rightChild, mid + 1, end, l, r);
        
        return p1 + p2;
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        if (n > 0) {
            build(arr, 0, 0, n - 1);
        }
    }

    void update(int idx, int val) {
        if (idx < 0 || idx >= n) return;
        update(0, 0, n - 1, idx, val);
    }

    int query(int l, int r) {
        if (l < 0 || r >= n || l > r) return 0;
        return query(0, 0, n - 1, l, r);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(arr);

    cout << "Sum of values in given range (1 to 3): " << segTree.query(1, 3) << endl;

    segTree.update(1, 10);
    cout << "Value at index 1 updated to 10" << endl;

    cout << "Sum of values in given range (1 to 3): " << segTree.query(1, 3) << endl;

    return 0;
}
