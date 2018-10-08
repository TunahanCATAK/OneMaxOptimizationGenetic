//
// Created by z003j23c on 9/11/2018.
//

#ifndef ONEMAXPROBLEM_POPULATION_H
#define ONEMAXPROBLEM_POPULATION_H

#include "Chromosome.h"

class Population {

public:
    int population_size;
    float population_average;

    template <typename T>
    std::vector<Chromosome<T>> population_pool;

    Population();
    Population(int);

    Population(const Population&);
    Population(Population&&) noexcept;

    Population& operator=(const Population& other);

    void calculateProbabilities();
    float getPopulationAverage();

private:
    void log(const char*);
};



#endif //ONEMAXPROBLEM_POPULATION_H
