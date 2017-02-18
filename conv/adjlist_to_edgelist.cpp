#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string buf;

  cerr << "loading headers..." << endl;

  cin >> buf;
  cin >> buf;
  auto n_vs = stoull(buf);
  cin >> buf;
  auto n_es = stoull(buf);

  vector<uint64_t> vs(n_vs);
  vector<vector<uint64_t>> es(n_vs, vector<uint64_t>());

  cerr << "loading vertices..." << endl;

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
      es[i].emplace_back(stoul(buf));
    }
  }

  cerr << "stroing..." << endl;

  for(auto i = 0ull; i < n_vs; i++) {
    for(auto j = 0ull; j < vs[i]; j++) {
      cout << i << "\t" << es[i][j] << "\n";
    }
  }
  cout << flush;
}
