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
    std::vector<Chromosome> population_pool;

    Population(){}

    Population(const Population &pop){
        population_pool = pop.population_pool;
        population_size = pop.population_size;
        population_average = pop.population_average;
    }

    Population(int pop_size){
        population_size = pop_size;
        population_pool = std::vector<Chromosome>(population_size);

        getPopulationAverage();
    }

    void calculateProbabilities(){
        std::for_each(std::begin(population_pool), std::end(population_pool),
                      [=](Chromosome &chro){ chro.calculateExpectedNumber(population_average);});
    }

    float getPopulationAverage(){
        int sum = 0;
        std::for_each(std::begin(population_pool), std::end(population_pool),
                      [&sum](Chromosome chro){ sum += chro.calculateFitness(); });

        population_average = (float)sum/population_size;

        return population_average;
    }
};


#endif //ONEMAXPROBLEM_POPULATION_H
