class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        queue<pair<int, int>> queue;
        int delta[4][2] = {{ 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 }};
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    queue.push({ i, j });
                } else {
                    mat[i][j] = INT_MAX;
                }
            }
        }

        while(!queue.empty()) {
            pair<int, int> rc = queue.front();
            queue.pop();
            int r = rc.first, c = rc.second;
            for (int i = 0; i < 4; i++) {
                int nr = r + delta[i][0], nc = c + delta[i][1];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && mat[nr][nc] > mat[r][c] + 1) {
                    mat[nr][nc] = mat[r][c] + 1;
                    queue.push({ nr, nc });
                }
            }
        }

        return mat;
    }
};
