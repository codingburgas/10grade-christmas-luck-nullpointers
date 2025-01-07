#include "Species.h"

// Function to display species information
void Species::display() const {
    std::cout << "Name: " << name
        << "\nKingdom: " << kingdom
        << "\nGenus: " << genus
        << "\nHabitat: " << habitat
        << "\nLifespan: " << lifespan
        << " years\nPopulation: " << population << "\n";
}