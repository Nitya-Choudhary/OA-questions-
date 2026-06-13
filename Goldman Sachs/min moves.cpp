#include <bits/stdc++.h>
using namespace std;

int getMinimumMoves(vector<vector<int>>& maze, int k) {

    int n = maze.size();
    int m = maze[0].size();

    if(maze[0][0] == 1 || maze[n-1][m-1] == 1)
        return -1;

    vector<vector<int>> dist(
        n,
        vector<int>(m, -1)
    );

    queue<pair<int,int>> q;

    q.push({0,0});
    dist[0][0] = 0;

    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};

    while(!q.empty()) {

        auto [r,c] = q.front();
        q.pop();

        if(r == n-1 && c == m-1)
            return dist[r][c];

        for(int dir=0; dir<4; dir++) {

            for(int step=1; step<=k; step++) {

                int nr = r + dr[dir]*step;
                int nc = c + dc[dir]*step;

                if(nr<0 || nr>=n || nc<0 || nc>=m)
                    break;

                if(maze[nr][nc] == 1)
                    break;

                if(dist[nr][nc] != -1)
                    continue;

                dist[nr][nc] =
                    dist[r][c] + 1;

                q.push({nr,nc});
            }
        }
    }

    return -1;
}
