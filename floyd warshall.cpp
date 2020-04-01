#include <bits/stdc++.h>
using namespace std;

#define MAX 100
#define INF 10000000
typedef long long ll;

bool distance_check(ll dist_u_k, ll dist_k_v, ll dist_u_v) {
    if (dist_u_v > dist_u_k + dist_k_v) {
        return true;
    }
    return false;
}

void floyd_warshall(int v, ll adj[][MAX]) {

    ll dist[v][v];
    for (int i = 0; i < v; i ++) {
        for (int j = 0; j < v; j ++) {
            dist[i][j] = adj[i][j];
        }
    }

    for (int k = 0; k < v; k ++) {
                for (int i = 0; i < v; i ++) {
            for (int j = 0; j < v; j ++) {

                if (distance_check(dist[i][k], dist[k][j], dist[i][j])) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < v; i ++) {
        for (int j = 0; j < v; j ++) {
            if (dist[i][j] == INF) {
                cout << "INF" << " ";
            }
            else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main () {

    int t;
    cin >> t;

    int v;
    while (t --) {
        cin >> v;

        ll adj_matrix[v][MAX];
        string s;
        for (int i = 0; i < v; i ++) {
            for (int j = 0; j < v; j ++) {
                cin >> s;
                if (isdigit(s[0])) {
                    adj_matrix[i][j] = atoi(s.c_str());
                }
                else {
                    adj_matrix[i][j] = INF;
                }
            }
        }

        floyd_warshall(v, adj_matrix);
    }

    return 0;
}
