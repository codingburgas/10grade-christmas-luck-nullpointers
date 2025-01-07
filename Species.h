#ifndef SPECIES_H
#define SPECIES_H

#include <string>
#include <iostream>

// Structure to store species data
struct Species {
    std::string name;
    std::string kingdom;
    std::string genus;
    std::string habitat;
    int lifespan; // in years
    long population;

    // Function to display species information
    void display() const;
};

#endif // SPECIES_H