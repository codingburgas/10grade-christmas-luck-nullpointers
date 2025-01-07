
#ifndef UTILITIES_H
#define UTILITIES_H

#include "Species.h"
#include <vector>
#include <string>

// Helper function for population growth (recursive calculation)
long calculatePopulation(long initialPopulation, double growthRate, int years);

// Function to sort species based on criteria
void sortSpecies(std::vector<Species>& speciesList, const std::string& criteria);

// Function to search for species by specific key and value
void searchSpecies(const std::vector<Species>& speciesList, const std::string& key, const std::string& value);

#endif // UTILITIES_H