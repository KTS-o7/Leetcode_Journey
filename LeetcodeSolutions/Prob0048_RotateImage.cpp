class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int temp;
    for(int i = 0; i < n / 2; i++)
        for(int j = i; j < n - i - 1; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = temp;
        }
}

};

// Time Complexity: O(n^2)
// Space Complexity: O(1)

// Logic Explained :
// 1. We can rotate the matrix layer by layer, where each layer is defined by the top, left, bottom, and right edges.
// 2. We first rotate the outermost layer, then the next outermost layer, and so on, until we rotate the innermost layer.
// 3. To rotate a layer, we perform a four-way swap of elements, moving elements from the top edge to the right edge, from the right edge to the bottom edge, from the bottom edge to the left edge, and from the left edge to the top edge.
// 4. The outer loop iterates over the layers, starting from the outermost layer and moving towards the innermost layer. hence we iterate from i = 0 to n/2.
// 5. The inner loop iterates over the elements in the current layer, starting from the top-left corner and moving towards the top-right corner. Hence we iterate from j = i to n - i - 1.
// 6. In each iteration of the inner loop, we perform a four-way swap of elements, moving elements from the top edge to the right edge, from the right edge to the bottom edge, from the bottom edge to the left edge, and from the left edge to the top edge.
// 7. After rotating all the layers, the matrix will be rotated by 90 degrees clockwise.