#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <list>
#include <algorithm>
using namespace std;

int limit_prefix = 10;
int n;

class Telegraph
{
	public:
		int cost, idx;

	Telegraph()
	{
		this->cost = 0;
		this->idx = 0;
	}

	Telegraph(int cost, int idx)
	{
		this->cost = cost;
		this->idx = idx;
	}
};

class compare
{
	public:
		bool operator()(Telegraph *a, Telegraph *b)
		{
			return a->cost > b->cost;
		}
};

int common_prefix_length(int64_t idx1, int64_t idx2)
{
	int len = limit_prefix;
	while (idx1 != idx2)
	{
		idx1 /= limit_prefix;
		idx2 /= limit_prefix;
		len--;
	}

	return len;
}

void dijkstra(multiset<Telegraph*> &graph, vector<Telegraph*> &vmap, priority_queue< Telegraph *, vector< Telegraph*>, compare> &ord, Telegraph *current)
{
	for (Telegraph* tg : graph)
	{
		int weight = current->cost + tg->cost;
		if (vmap[tg->idx]->cost == -1 || vmap[tg->idx]->cost > weight)
		{
			ord.push(new Telegraph(weight, tg->idx));
			vmap[tg->idx]->cost = weight;
			vmap[tg->idx]->idx = current->idx;
		}
	}
}

vector<Telegraph*> build_graph(vector<int64_t> &tgphs, map<int64_t, int> &connections, priority_queue< Telegraph *, vector< Telegraph*>, compare> &ord, vector< int > &speed)
{
	vector<Telegraph*> vmap(n);
	for (int i = 0; i < n; i++)
	{
		vmap[i] = new Telegraph(-1, -1);
	}

	ord.push(new Telegraph(0, 0));
	while (!ord.empty())
	{
		Telegraph *current = ord.top();
		ord.pop();
		if (current->idx == n - 1)
			break;
		multiset<Telegraph*> graph;
		int64_t x = tgphs[current->idx];
		int64_t replaced_x, test1, test2;
		for (int i = 0; i < limit_prefix; i++)
		{
			test1 = (int64_t) pow(10, i);
			int prefix_el = x / test1 % 10;
			for (int j = 0; j < limit_prefix; j++)
			{
				replaced_x = x - prefix_el *test1 + j * test1;
				auto iter = connections.find(replaced_x);
				if (iter != connections.end() && x != replaced_x)
				{
					int pref_len = common_prefix_length(x, replaced_x);
					graph.insert(new Telegraph(speed[pref_len], iter->second));
				}
			}

			for (int j = i + 1; j < limit_prefix; j++)
			{
				test2 = (int64_t) pow(10, j);
				int prefix_el_2 = x / test2 % 10;
				replaced_x = x - prefix_el *test1 + prefix_el_2 *test1 - prefix_el_2 *test2 + prefix_el * test2;
				auto iter = connections.find(replaced_x);
				if (iter != connections.end() && x != replaced_x)
				{
					int pref_len = common_prefix_length(x, replaced_x);
					graph.insert(new Telegraph(speed[pref_len], iter->second));
				}
			}
		}

		dijkstra(graph, vmap, ord, current);
	}

	return vmap;
}

int main()
{
	vector<int> speed(limit_prefix);
	cin >> n;
	for (int i = 0; i < limit_prefix; i++)
	{
		cin >> speed[i];
	}

	vector<int64_t> tgphs(n);
	map<int64_t, int> connections;
	priority_queue<Telegraph*, vector<Telegraph*>, compare> ord;
	for (int i = 0; i < n; i++)
	{
		cin >> tgphs[i];
		connections[tgphs[i]] = i;
	}

	vector<Telegraph*> vmap = build_graph(tgphs, connections, ord, speed);

    
	cout << vmap[n - 1]->cost << endl;
	if (vmap[n - 1]->cost == -1)
		return 0;

	vector<int> path;
	
	path.push_back(n);

	int current = n - 1;

	while (current > 0)
	{
		path.push_back(vmap[current]->idx + 1);
		current = vmap[current]->idx;
	}

	cout << path.size() << endl;

	reverse(path.begin(), path.end());
	
    for (int i = 0 ; i < path.size(); i++) {
        cout << path[i] << " ";
    }
	return 0;
}