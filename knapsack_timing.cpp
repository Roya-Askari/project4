///////////////////////////////////////////////////////////////////////////////
// maxprotein_timing.cc
//
// Example code showing how to run each algorithm while measuring
// elapsed times precisely. You should modify this program to gather
// all of your experimental data.
//
///////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

#include "knapsack.hpp"
#include "timer.hpp"

using namespace std;

void print_bar() {
  cout << string(79, '-') << endl;
}

int main() {

  const int n_request = 10000,
    total_kcal = 4209;

  auto all_foods = load_usda_abbrev("ABBREV.txt");
  assert( all_foods );

  int n = std::min(n_request, int(all_foods->size()));
  assert(n <= n_request);

  auto n_foods = filter_food_vector(*all_foods, 0, INT_MAX, n);
  assert( n_foods );
  assert( int(n_foods->size()) <= n );

  double elapsed;
  Timer timer;

  print_bar();
  cout << "n_request=" << n_request
       << ", n=" << n
       << ", total_kcal=" << total_kcal << endl;

  print_bar();
  timer.reset();
  auto knapsack_solution = knapsack_max_protein(*n_foods, total_kcal);
  elapsed = timer.elapsed();
  assert(knapsack_solution);
  cout << "knapsack solution:" << endl;
  print_food_vector(*knapsack_solution);

  print_bar();
  cout << "elapsed time=" << elapsed << " seconds" << endl << endl;

  print_bar();

  return 0;
}
