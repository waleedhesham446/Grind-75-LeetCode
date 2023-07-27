class Solution {
public:
    int start_color;
    int m;
    int n;
    int new_color;

    void dfs(int r, int c, vector<vector<int>>& image) {
        if (r < 0 || r >= m || c < 0 || c >= n || image[r][c] != this->start_color) {
            return;
        }
        
        image[r][c] = this->new_color;
        dfs(r-1, c, image);
        dfs(r+1, c, image);
        dfs(r, c-1, image);
        dfs(r, c+1, image);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        this->m = image.size();
        this->n = image[0].size();
        this->start_color = image[sr][sc];
        this->new_color = color;

        if (new_color != start_color) {
            dfs(sr, sc, image);        
        }

        return image;
    }
};
