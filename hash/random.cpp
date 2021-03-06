#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

/*
 * argument list
 * 0:
 * 1: [seed]
 */
int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  auto seed = argc > 1 ? stoi(argv[1]) : 0;
  mt19937 engine(seed);
  string buf;

  cerr << "loading headers..." << endl;

  cin >> buf;
  cin >> buf;
  auto n_vs = stoull(buf);
  cin >> buf;
  auto n_es = stoull(buf);

  vector<uint64_t> _is(n_vs);
  vector<uint64_t> is(n_vs);
  vector<uint64_t> vs(n_vs);
  vector<vector<uint64_t>> es(n_vs, vector<uint64_t>());

  cerr << "loading vertices..." << endl;

  for(auto i = 0ull; i < n_vs; i++) {
    _is[i] = i;
  }
  engine.seed(seed); shuffle(_is.begin(), _is.end(), engine);
  for(auto i = 0ull; i < n_vs; i++) {
    is[_is[i]] = i;
  }

  cin >> buf;
  auto prev = 0ull;
  for(auto i = 0ull; i < n_vs - 1; i++) {
    cin >> buf;
    auto curr = stoul(buf);
    vs[i] = curr - prev;
    prev = curr;
  }
  vs[n_vs - 1] = n_es - prev;

  cerr << "#vertices: " << n_vs << endl;
  cerr << "#edges: " << n_es << endl;

  cerr << "loading edges..." << endl;

  for(auto i = 0ull; i < n_vs; i++) {
    for(auto j = 0ull; j < vs[i]; j++) {
      cin >> buf;
      es[is[i]].emplace_back(is[stoul(buf)]);
    }
  }

  cerr << "shuffling..." << endl;

  engine.seed(seed); shuffle(vs.begin(), vs.end(), engine);
  prev = 0;
  for(auto &v: vs) {
    prev = v += prev;
  }

  cerr << "sorting..." << endl;

  for(auto &e: es) {
    sort(e.begin(), e.end());
  }

  cerr << "storing..." << endl;

  cout << "AdjacencyGraph\n";
  cout << n_vs << "\n";
  cout << n_es << "\n";

  {
    vs.pop_back();
    cout << 0 << "\n";
    for(auto v: vs) {
      cout << v << "\n";
    }
  }
  for(auto e: es) {
    for(auto v: e) {
      cout << v << "\n";
    }
  }
  cout << flush;
}
