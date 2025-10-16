#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int N, Q;
char map[51][51];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int dist[51][51][6];

struct Edge {
	int y;
	int x;
	int cost;
	int jump;
};
struct cmp {
	bool operator()(Edge a, Edge b) {
		return a.cost > b.cost;
	}
};

void solution(int sy, int sx, int ey, int ex) {
	priority_queue<Edge, vector<Edge>, cmp> pq;
	pq.push({ sy,sx,0,1 });
	dist[sy][sx][1] = 0;

	while (pq.size()) {
		Edge now = pq.top();
		pq.pop();

		// 가지치기
		//if (now.cost > dist[now.y][now.x]) continue;

		for (int i = 0; i < 4; i++) {
			int cnt = 1;
			while (1) {
				if (cnt > 5) break;
				int ny = now.y + dy[i] * cnt;
				int nx = now.x + dx[i] * cnt;

				if (ny < 0 || ny >= N || nx < 0 || nx >= N) break;
				//if (now.cost > dist[ny][nx]) { cnt++; continue; }
				if (map[ny][nx] == '#') break;
				if (map[ny][nx] == '.') {
					int nc;
					// 현재 점프가 뛰어야할 점프력과 같을 때
					if (now.jump == cnt) {
						nc = now.cost + 1;
					}
					// 현재 점프가 뛰어야할 점프력보다 낮을 때
					else if (now.jump < cnt) {
						int temp = 0;
						for (int ret = now.jump + 1; ret <= cnt; ret++) {
							temp += ret * ret;
						}
						nc = now.cost + temp + 1;
					}
					// 현재 점프가 뛰어야할 점프력보다 높을 때
					else if (now.jump > cnt) {
						nc = now.cost + 2;
					}
					if (nc < dist[ny][nx][cnt]) {
						dist[ny][nx][cnt] = nc;
						if (ny == ey && nx == ex) {
							nc = min(nc, dist[ny][nx][cnt]);
						}
						pq.push({ ny,nx,nc,cnt });
					}
				}
				cnt++;
			}
			
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
 		}
	}
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1 -= 1; c1 -= 1; r2 -= 1; c2 -= 1;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 1; k <= 5; k++)
				{
					dist[i][j][k] = 21e8;
				}
				
			}
		}
		solution(r1,c1,r2,c2);
		int ans = 21e8;

		for (int a = 1; a <= 5; a++) {
			ans = min(ans, dist[r2][c2][a]);
		}

		if (ans == 21e8) cout << -1 << "\n";

		else cout << ans << "\n";
	}
	return 0;
}
