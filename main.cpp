#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

// Struct to store species data
struct Species {
    std::string name;
    std::string kingdom;
    std::string genus;
    std::string habitat;
    int lifespan; // in years
    long population;

    void display() const {
        std::cout << "Name: " << name
            << "\nKingdom: " << kingdom
            << "\nGenus: " << genus
            << "\nHabitat: " << habitat
            << "\nLifespan: " << lifespan
            << " years\nPopulation: " << population << "\n";
    }
};

// Helper functions for population growth (recursive calculation)
long calculatePopulation(long initialPopulation, double growthRate, int years) {
    if (years == 0)
        return initialPopulation;
    return static_cast<long>(calculatePopulation(initialPopulation, growthRate, years - 1) * (1 + growthRate));
}

// Sort species
void sortSpecies(std::vector<Species>& speciesList, const std::string& criteria) {
    if (criteria == "taxonomy") {
        std::sort(speciesList.begin(), speciesList.end(), [](const Species& a, const Species& b) {
            return a.kingdom < b.kingdom || (a.kingdom == b.kingdom && a.genus < b.genus) ||
            (a.kingdom == b.kingdom && a.genus == b.genus && a.name < b.name);
            });
    }
    else if (criteria == "lifespan") {
        std::sort(speciesList.begin(), speciesList.end(), [](const Species& a, const Species& b) {
            return a.lifespan > b.lifespan;
            });
    }
    else if (criteria == "population") {
        std::sort(speciesList.begin(), speciesList.end(), [](const Species& a, const Species& b) {
            return a.population > b.population;
            });
    }
}

// Search species
void searchSpecies(const std::vector<Species>& speciesList, const std::string& key, const std::string& value) {
    for (const auto& species : speciesList) {
        if ((key == "name" && species.name == value) ||
            (key == "habitat" && species.habitat == value) ||
            (key == "genus" && species.genus == value)) {
            species.display();
            std::cout << "-----------------------------\n";
        }
    }
}

int main() {
    // Sample data
    std::vector<Species> speciesList = {
        {"Lion", "Animalia", "Panthera", "Savanna", 12, 20000},
        {"Tiger", "Animalia", "Panthera", "Forest", 15, 3200},
        {"Blue Whale", "Animalia", "Balaenoptera", "Ocean", 90, 15000},
        {"Penguin", "Animalia", "Spheniscidae", "Antarctica", 20, 500000}
    };

    int choice; // Declare the user selection variable
    do { // Display the data types menu
        std::cout << "Species Data Management System\n"; // Display all types
        std::cout << "1. Display all species\n";
        std::cout << "2. Sort species\n"; 
        std::cout << "3. Search species\n";
        std::cout << "4. Calculate population growth\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        // Perform action according to selection
        switch (choice) {
        case 1: 
            // Display information about all types
            for (const auto& species : speciesList) {
                species.display(); // Outputs the data for the current view
                std::cout << "-----------------------------\n"; // Separator between types
            }
            break;
        case 2: { 
            // Sort the types
            std::string criteria;
            std::cout << "Enter criteria (taxonomy/lifespan/population): ";
            std::cin >> criteria; // Read the criterion
            sortSpecies(speciesList, criteria); // Call the sort function
            std::cout << "Species sorted by " << criteria << "!\n"; // Confirmation of successful sorting
            break;
        }
        case 3: { 
            // Search for types
            std::string key, value; // Key and value to search for
            std::cout << "Enter search key (name/habitat/genus): ";
            std::cin >> key; // Read the key
            std::cout << "Enter search value: ";
            std::cin >> value; // Read the value
            searchSpecies(speciesList, key, value); // Call the search function
            break;
        }
        case 4: {
            // Calculate population growth
            std::string speciesName; // Type name
            double growthRate; // Annual growth rate
            int years; // Number of years for the calculation
            std::cout << "Enter species name: ";
            std::cin >> speciesName; // Четене на името
            std::cout << "Enter annual growth rate (e.g., 0.05 for 5%): ";
            std::cin >> growthRate; // Read the percentage
            std::cout << "Enter number of years: ";
            std::cin >> years; // Read the number of years

            // Find the type in the list
            auto it = std::find_if(speciesList.begin(), speciesList.end(), [&speciesName](const Species& s) {
                return s.name == speciesName;
                });

            if (it != speciesList.end()) { // Calculate the future population if the species is found
                long futurePopulation = calculatePopulation(it->population, growthRate, years);
                std::cout << "Population of " << speciesName << " after " << years << " years: " << futurePopulation << "\n";
            }
            else { // Type missing message
                std::cout << "Species not found.\n";
            }
            break;
        }

        // Изход от програмата
        case 5: 
            std::cout << "Exiting...\n";
            break;
        default: // Invalid selection message
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5); // Continues the loop until the choice is 5 (Exit)

    return 0; // End of program
}