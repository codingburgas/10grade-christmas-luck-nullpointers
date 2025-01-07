#include "Utilities.h"
#include <algorithm>

// Helper function for population growth (recursive calculation)
long calculatePopulation(long initialPopulation, double growthRate, int years) {
    if (years == 0) // Base case: when years are 0
        return initialPopulation;
    // Recursive calculation for population growth
    return static_cast<long>(calculatePopulation(initialPopulation, growthRate, years - 1) * (1 + growthRate));
}

// Function to sort species based on criteria
void sortSpecies(std::vector<Species>& speciesList, const std::string& criteria) {
    if (criteria == "taxonomy") { // Sort by taxonomy
        std::sort(speciesList.begin(), speciesList.end(), [](const Species& a, const Species& b) {
            return a.kingdom < b.kingdom || (a.kingdom == b.kingdom && a.genus < b.genus) ||
                (a.kingdom == b.kingdom && a.genus == b.genus && a.name < b.name);
            });
    }
    else if (criteria == "lifespan") { // Sort by lifespan
        std::sort(speciesList.begin(), speciesList.end(), [](const Species& a, const Species& b) {
            return a.lifespan > b.lifespan;
            });
    }
    else if (criteria == "population") { // Sort by population
        std::sort(speciesList.begin(), speciesList.end(), [](const Species& a, const Species& b) {
            return a.population > b.population;
            });
    }
}

// Function to search for species by specific key and value
void searchSpecies(const std::vector<Species>& speciesList, const std::string& key, const std::string& value) {
    for (const auto& species : speciesList) {
        if ((key == "name" && species.name == value) ||       // Search by name
            (key == "habitat" && species.habitat == value) || // Search by habitat
            (key == "genus" && species.genus == value)) {     // Search by genus
            species.display(); // Display the matched species
            std::cout << "-----------------------------\n"; // Separator
        }
    }
}