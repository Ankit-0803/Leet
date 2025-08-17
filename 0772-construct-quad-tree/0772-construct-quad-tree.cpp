/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    // Helper function to build Quad Tree from subgrid
    Node* build(vector<vector<int>>& grid, int x, int y, int length) {
        // Check if all elements in the current subgrid are the same
        bool same = true;
        int first = grid[x][y];
        for (int i = x; i < x + length; i++) {
            for (int j = y; j < y + length; j++) {
                if (grid[i][j] != first) {
                    same = false;
                    break;
                }
            }
            if (!same) break;
        }
        // Case 1: All values are the same -> leaf node
        if (same) {
            return new Node(first == 1, true);
        }
        // Case 2: Not the same -> split into 4 quadrants
        int half = length / 2;
        Node* topLeft     = build(grid, x, y, half);
        Node* topRight    = build(grid, x, y + half, half);
        Node* bottomLeft  = build(grid, x + half, y, half);
        Node* bottomRight = build(grid, x + half, y + half, half);
        // Internal node with 4 children
        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return build(grid, 0, 0, n);
    }
};
