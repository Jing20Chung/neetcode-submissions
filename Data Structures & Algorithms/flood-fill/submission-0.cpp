class Solution {
private:
    void dfs(vector<vector<int>>& image, int r, int c, const int oriColor, const int newColor) {
        if (r >= image.size() || r < 0 || c >= image[0].size() || c < 0 || image[r][c] != oriColor) return;
        image[r][c] = newColor;
        dfs(image, r + 1, c, oriColor, newColor);
        dfs(image, r - 1, c, oriColor, newColor);
        dfs(image, r, c + 1, oriColor, newColor);
        dfs(image, r, c - 1, oriColor, newColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oriColor = image[sr][sc];
        if (color == oriColor) return image;
        dfs(image, sr, sc, oriColor, color);
        return image;
    }
};