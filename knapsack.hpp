///////////////////////////////////////////////////////////////////////////////
// knapsack.hpp
//
// Solve the maximum-protein-diet problem described in maxprotein.hh
// using dynamic programming.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <memory>

#include "maxprotein.hh"

std::unique_ptr<FoodVector> knapsack_max_protein(const FoodVector& all_foods,
						 int total_kcal) {

  assert(total_kcal >= 0);

  // TODO: implement this function, then delete this comment
  return std::unique_ptr<FoodVector>(new FoodVector());
}
