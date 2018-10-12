//
// Created by z003j23c on 9/11/2018.
//

#include "Chromosome.h"
#include <vector>
#include "Population.h"

template class Population<int>;
template class Population<double>;
template class Population<bool>;
template class Population<std::string>;

template <class T>
Population<T>::Population(const Population& other) {
    log("Copy Constructure for Population is called");
    population_size = other.population_size;
    population_pool = std::move(other.population_pool);
    getPopulationAverage();
}

template <class T>
Population<T>::Population(int pop_size) {
    population_size = pop_size;
    population_pool = std::vector<ChromosomeType>(population_size);

    getPopulationAverage();
}

template <class T>
Population<T>::Population(Population<T> &&other) noexcept {
    log("Move Constructure of Population is Called");
    population_pool = std::move(other.population_pool);
    population_size = other.population_size;
    getPopulationAverage();
}

template <class T>
Population<T>& Population<T>::operator=(const Population<T>& other){
    log("Copy Assignment for Population is Called");
    population_size = other.population_size;
    population_pool = std::move(other.population_pool);
    getPopulationAverage();
    return *this;
}

/*
void Population::calculateProbabilities(){
    std::for_each(std::begin(population_pool), std::end(population_pool),
                  [=](Chromosome &chro){ chro.calculateExpectedNumber(population_average);});
}
*/

template <class T>
float Population<T>::getPopulationAverage(){
    int sum = 0;
    std::for_each(std::begin(population_pool), std::end(population_pool),
                  [&sum](ChromosomeType chro){ sum += chro.calculateFitness(); });

    population_average = (float)sum/population_pool.size();

    return population_average;
}

template <class T>
void Population<T>::log(const char* msg){
    std::cout << msg << std::endl;
}