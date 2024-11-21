class Solution {
public:
    int countUnguarded(int rows, int cols, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // Constants for marking grid cells
        const int WALL = -2;
        const int GUARD = 2;
        const int GUARDED = 1;

        // Initialize the grid with zeros (0 for unguarded cells)
        vector<vector<int>> grid(rows, vector<int>(cols, 0));

        // Place walls on the grid
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = WALL;
        }

        // Place guards on the grid
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = GUARD;
        }

        // Directions for moving: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Mark all cells guarded by each guard
        for (const auto& guard : guards) {
            int x = guard[0], y = guard[1];

            for (const auto& [dx, dy] : directions) {
                int nx = x, ny = y;

                // Move in the current direction until a wall or another guard is hit
                while (true) {
                    nx += dx;
                    ny += dy;

                    if (nx < 0 || ny < 0 || nx >= rows || ny >= cols || grid[nx][ny] == WALL || grid[nx][ny] == GUARD) {
                        break;
                    }

                    grid[nx][ny] = GUARDED;
                }
            }
        }

        // Count unguarded cells
        int unguardedCount = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 0) {
                    ++unguardedCount;
                }
            }
        }

        return unguardedCount;
    }
};
