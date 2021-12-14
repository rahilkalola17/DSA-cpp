#include<iostream>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::make_pair;

#define pii pair<ll,ll>
#define MOD 1000000007
#define ll long long int

ll dfs(ll i, ll j, vector<pii>** graph, ll** visited) {
	visited[i][j] = 1;
	ll answer = 1;

	for(ll k{}; k < graph[i][j].size(); k++) {
        ll x {graph[i][j][k].first};
        ll y {graph[i][j][k].second};
        if(!visited[x][y]) answer = (answer+dfs(x, y, graph, visited)) % MOD;
    }
    return answer;
}

void fillGraph(vector<pii>** graph, ll** board, ll m, ll n) {
	for (ll i{}; i < n; ++i) {
		for (ll j {}; j < m; ++j) {
			if (board[i][j] == 1) {
				graph[i][j].push_back(make_pair(i, j));
				if (i + 2 < n && j + 1 < m && board[i + 2][j + 1] == 1) graph[i][j].push_back(make_pair(i + 2, j + 1));
				if (i + 2 < n && j - 1 >= 0 && board[i + 2][j - 1] == 1) graph[i][j].push_back(make_pair(i + 2, j - 1));
				if (i - 2 >= 0 && j + 1 < m && board[i - 2][j + 1] == 1) graph[i][j].push_back(make_pair(i - 2, j + 1));
				if (i - 2 >= 0 && j - 1 >= 0 && board[i - 2][j - 1] == 1) graph[i][j].push_back(make_pair(i - 2, j - 1));
				if (i + 1 < n && j + 2 < m && board[i + 1][j + 2] == 1) graph[i][j].push_back(make_pair(i + 1, j + 2));
				if (i + 1 < n && j - 2 >= 0 && board[i + 1][j - 2] == 1) graph[i][j].push_back(make_pair(i + 1, j - 2));
				if (i - 1 >= 0 && j + 2 < m && board[i - 1][j + 2] == 1) graph[i][j].push_back(make_pair(i - 1, j + 2));
				if (i - 1 >= 0 && j - 2 >= 0 && board[i - 1][j - 2] == 1) graph[i][j].push_back(make_pair(i - 1, j - 2));
			}
		}
	}
	return;
}

int main() {
	//calculate factorial
	ll *factorial{new ll[1000000]};
    factorial[1] = 1;
    for(ll i = 2; i < 1000000; i++) factorial[i] = (factorial[i - 1] * i) % MOD;

	ll t;
	cin>>t;
	while(t--) {
		ll n, m;
		ll q;
		cin >> n >> m >> q;

		//Create a board
		ll** board{new ll*[n]};
		for (ll i{}; i < n; ++i) {
			board[i] = {new ll[m]};
			for (ll j{}; j < m; ++j) board[i][j] = 0;
		}

		//Fill the board
		while(q--) {
			ll x, y;
			cin >> x >> y;
			board[x - 1][y - 1] = 1;
		}

		//Creating a graph
		vector<pii>** graph{new vector<pii>*[n]};
		for (ll i{}; i < n; ++i) graph[i] = new vector<pii>[m];

		//Fill the graph
		fillGraph(graph, board, m, n);

		ll** visited {new ll*[n]};
		for (ll i{}; i < n; ++i) {
			visited[i] = new ll[m];;
			for (ll j{}; j < m; ++j) visited[i][j] = 0;
		}

		ll ans {1};
		for (ll i {}; i < n; ++i) {
			for (ll j {}; j < m; ++j) {
				if (visited[i][j] == 0 && board[i][j] == 1) {
					ans = (ans*factorial[dfs(i, j, graph, visited)]) % MOD;
				}
			}
		}
		cout << ans << endl;
	}
	return 0 ;
}
