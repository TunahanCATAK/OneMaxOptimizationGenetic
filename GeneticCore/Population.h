//
// Created by z003j23c on 9/11/2018.
//

#ifndef ONEMAXPROBLEM_POPULATION_H
#define ONEMAXPROBLEM_POPULATION_H

#include "Chromosome.h"



template <class T>
class Population {
public:
    typedef Chromosome<T> ChromosomeType;

public:
    int population_size;
    float population_average;

    std::vector<ChromosomeType> population_pool;

    Population() = delete;
    Population(int);

    Population(const Population<T>&);
    Population(Population<T>&&) noexcept;

    Population<T>& operator=(const Population<T>& other);

    void calculateProbabilities();
    float getPopulationAverage();

private:
    void log(const char*);
};



#endif //ONEMAXPROBLEM_POPULATION_H
