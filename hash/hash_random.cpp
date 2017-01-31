#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


/*
 * argument list
 * 0:
 * 1: [seed]
 */
int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  mt19937 engine(argc > 1 ? stoi(argv[1]) : 0);
  string buf;

  cerr << "loading headers..." << endl;

  cin >> buf;
  cin >> buf;
  auto n_vs = stoull(buf);
  cin >> buf;
  auto n_es = stoull(buf);

  vector<uint32_t> is(n_vs);
  vector<uint32_t> vs(n_vs);
  vector<vector<uint32_t>> es(n_vs, vector<uint32_t>());

  cerr << "loading vertices..." << endl;

  for(auto i = 0; i < n_vs; i++) {
    is[i] = i;
  }
  shuffle(is.begin(), is.end(), engine);

  auto prev = 0;
  for(auto i = 0; i < n_vs; i++) {
    cin >> buf;
    auto curr = stoul(buf);
    vs[i] = curr - prev;
    prev = curr;
  }

  cerr << "#vertices: " << n_vs << endl;
  cerr << "#edges: " << n_es << endl;

  cerr << "loading edges..." << endl;
  
  for(auto i = 0; i < n_vs; i++) {
    for(auto j = 0; j < vs[i]; j++) {
      cin >> buf;
      es[is[i]].emplace_back(is[stoul(buf)]);
    }
  }

  cerr << "shuffling..." << endl;

  shuffle(vs.begin(), vs.end(), engine);
  prev = 0;
  for(auto &v: vs) {
    prev = v += prev;
  }

  cerr << "sorting..." << endl;

  for(auto &e: es) {
    sort(e.begin(), e.end());
  }

  cerr << "storing..." << endl;

  cout << "AdjacencyGraph" << endl;
  cout << n_vs << endl;
  cout << n_es << endl;
  for(auto v: vs) {
    cout << v << endl;
  }
  for(auto e: es) {
    for(auto v: e) {
      cout << v << endl;
    }
  }
}

