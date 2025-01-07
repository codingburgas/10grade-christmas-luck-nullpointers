#include "Species.h"
#include "Utilities.h"
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    // Sample data
    std::vector<Species> speciesList = {
        {"Lion", "Animalia", "Panthera", "Savanna", 12, 20000},
        {"Tiger", "Animalia", "Panthera", "Forest", 15, 3200},
        {"Blue Whale", "Animalia", "Balaenoptera", "Ocean", 90, 15000},
        {"Penguin", "Animalia", "Spheniscidae", "Antarctica", 20, 500000}
    };

    int choice; // Variable for user selection
    do {
        std::cout << "Species Data Management System\n"; // Menu header
        std::cout << "1. Display all species\n";         // Option to display all species
        std::cout << "2. Sort species\n";                // Option to sort species
        std::cout << "3. Search species\n";              // Option to search for species
        std::cout << "4. Calculate population growth\n"; // Option to calculate population growth
        std::cout << "5. Exit\n";                        // Option to exit
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            // Display information about all species
            for (const auto& species : speciesList) {
                species.display(); // Output data for each species
                std::cout << "-----------------------------\n"; // Separator
            }
            break;
        case 2: {
            // Sort species based on criteria
            std::string criteria;
            std::cout << "Enter criteria (taxonomy/lifespan/population): ";
            std::cin >> criteria; // Read sorting criteria
            sortSpecies(speciesList, criteria); // Sort the species
            std::cout << "Species sorted by " << criteria << "!\n"; // Confirmation message
            break;
        }
        case 3: {
            // Search for a species
            std::string key, value; // Key and value for searching
            std::cout << "Enter search key (name/habitat/genus): ";
            std::cin >> key; // Read search key
            std::cout << "Enter search value: ";
            std::cin >> value; // Read search value
            searchSpecies(speciesList, key, value); // Perform the search
            break;
        }
        case 4: {
            // Calculate population growth
            std::string speciesName; // Species name for population calculation
            double growthRate;       // Annual growth rate
            int years;               // Number of years to calculate for
            std::cout << "Enter species name: ";
            std::cin >> speciesName; // Read the species name
            std::cout << "Enter annual growth rate (e.g., 0.05 for 5%): ";
            std::cin >> growthRate; // Read the growth rate
            std::cout << "Enter number of years: ";
            std::cin >> years; // Read the number of years

            // Find the species in the list
            auto it = std::find_if(speciesList.begin(), speciesList.end(), [&speciesName](const Species& s) {
                return s.name == speciesName;
                });

            if (it != speciesList.end()) { // Calculate future population if species is found
                long futurePopulation = calculatePopulation(it->population, growthRate, years);
                std::cout << "Population of " << speciesName << " after " << years << " years: " << futurePopulation << "\n";
            }
            else { // Species not found message
                std::cout << "Species not found.\n";
            }
            break;
        }
        case 5:
            std::cout << "Exiting...\n"; // Exit message
            break;
        default:
            std::cout << "Invalid choice. Try again.\n"; // Invalid choice message
        }
    } while (choice != 5); // Loop until user chooses to exit

    return 0;
}