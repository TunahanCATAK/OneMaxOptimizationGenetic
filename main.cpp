//
// Created by z003j23c on 9/4/2018.
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>
#include <iterator>
#include <ostream>

static int GENE_SIZE = 5;

class Chromosome{
public:
    int gene_size;
    std::vector<int> genes;
    float expected_number;

    Chromosome() : Chromosome(5){
    }

    Chromosome(std::vector<int> _genes){
        gene_size = _genes.size();
        genes = _genes;
    }

    Chromosome(int _gene_size){
        gene_size = _gene_size;
        genes = std::vector<int>(gene_size);
        for(int i = 0; i < gene_size; i++){
            int num = rand() % 10 + 1;
            genes[i] = num;
        }
    }

    Chromosome(const Chromosome &chrom) = default;

    float calculateFitness(){
        int fitt_val = std::count(std::begin(genes), std::end(genes), 1);
        return fitt_val;
    }

    void calculateExpectedNumber(float average){
        this->expected_number = calculateFitness()/average;
        //DEBUG INFO:
        std::cout << "Chromosom: ";

        std::for_each(std::begin(genes), std::end(genes),
                      [=](int i){ std::cout << i << " "; });

        std::cout << "  -> " << this->expected_number << std::endl;
    }

    bool operator<(const Chromosome& A) const{
        std::cout << expected_number << " - " << A.expected_number << std::endl;
        return std::round(expected_number) < std::round(A.expected_number);
    }

    friend std::ostream& operator<< (std::ostream& os, const Chromosome& obj) {
        std::copy(std::begin(obj.genes), std::end(obj.genes), std::ostream_iterator<Chromosome>(os, ", "));
        return os;
    }

};

class Population{
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
                      [=](Chromosome chro){ chro.calculateExpectedNumber(population_average);});
    }



private:
    float getPopulationAverage(){
        int sum = 0;
        std::for_each(std::begin(population_pool), std::end(population_pool),
                      [&sum](Chromosome chro){ sum += chro.calculateFitness(); });

        population_average = (float)sum/population_size;
    }

};

class Mater{
public:
    std::vector<Chromosome> mate_pool;

    Mater(Population& population){
        std::cout << population.population_average << std::endl;
        population.calculateProbabilities();

        std::sort(std::begin(population.population_pool), std::end(population.population_pool));

        std::copy(std::begin(population.population_pool), std::end(population.population_pool), std::ostream_iterator<Chromosome>(std::cout, ", "));

    }
};

std::vector<std::vector<int>> createAMatingPool(std::vector<std::vector<int>> pop, std::vector<int> actual_count){
    std::vector<std::vector<int>> pool;
    std::vector<std::vector<int>>::const_iterator it = pop.begin();

    std::for_each(std::begin(actual_count), std::end(actual_count),
                  [&](int i) {
                      if (i > 0) {
                          for (int j = 0; j < i; ++j) {
                              pool.push_back(*it);
                          }
                      }
                      ++it;
                  });

    //DEBUG INFO
    std::cout << "mating pool: ";
    std::for_each(std::begin(pool), std::end(pool), [](std::vector<int> i){
        std::for_each(std::begin(i), std::end(i), [](int j){
            std::cout << j  << " "; } );
    std::cout << std::endl;});
    std::cout << "\n";

    return  pool;

}

int calculateFitness(std::vector<int> chromosome){
    int fitt_val = std::count(std::begin(chromosome), std::end(chromosome), 1);

    std::cout << "fitness value: " << fitt_val << std::endl;

    return fitt_val;
}

std::vector<int> calculateFitness(std::vector<std::vector<int>> pop){
    std::vector<int> fitt_values(pop.size());

    for (int i = 0; i < pop.size(); ++i) {
        fitt_values[i] = calculateFitness(pop.at(i));
    }

    return fitt_values;
}

void mutation(std::vector<int> &chromosome){
    //DEBUG INFO
    std::cout << "before mutation: ";
    std::for_each(std::begin(chromosome), std::end(chromosome), [](int i){ std::cout << i << " "; });
    std::cout << "\n";

    int x = rand() % (chromosome.size() - 1);
    int num = rand() % 10 + 1;
    chromosome.at(x) = num;

    //DEBUG INFO
    std::cout << "after mutation: ";
    std::for_each(std::begin(chromosome), std::end(chromosome), [](int i){ std::cout << i << " "; });
    std::cout << "\n";
}

void startEvol(std::vector<std::vector<int>> pop, int termination_condition){
    bool isTerminated = false;

    while(!isTerminated){
        std::vector<int> fitt_value_vec;
        std::vector<int> actual_counts;
        std::vector<float> expected_counts;
        std::vector<std::vector<int>> mating_pool;

        fitt_value_vec = calculateFitness(pop);
        int sum = std::accumulate(std::begin(fitt_value_vec), std::end(fitt_value_vec), 0);
        float average = std::roundf(((float)sum / pop.size())*100) / 100;

        std::for_each(std::begin(fitt_value_vec), std::end(fitt_value_vec),
                      [&expected_counts, average](int i){expected_counts.push_back(((float)i / average));});
        //DEBUG INFO
        std::cout << "expected counts: ";
        std::for_each(std::begin(expected_counts), std::end(expected_counts), [](float i){ std::cout << i << " "; });
        std::cout << "\n";

        //DEBUG INFO
        std::cout << "\nEXpected Count: " << std::accumulate(std::begin(expected_counts), std::end(expected_counts), 0.0f) << std::endl;


        std::for_each(std::begin(fitt_value_vec), std::end(fitt_value_vec),
                      [&actual_counts, average](int i){actual_counts.push_back(std::round((float)i / average));});
        //DEBUG INFO
        std::cout << "actual counts: ";
        std::for_each(std::begin(actual_counts), std::end(actual_counts), [](int i){ std::cout << i << " "; });
        std::cout << "\n";

        //DEBUG INFO
        std::cout << "\nActual Count: " << std::accumulate(std::begin(actual_counts), std::end(actual_counts), 0) << std::endl;

        //create a mating pool
        mating_pool = createAMatingPool(pop, actual_counts);
    }


}

int main(){

    /* initialize random seed: */
    srand (time(NULL));

/*
    //initialize the first population.
    int num, pop_size = 5, N = 5;
    std::vector<std::vector<int>> population(pop_size, std::vector<int>(N));
    for (int j = 0; j < pop_size; ++j) {
        for (int i = 0; i < N; ++i) {
            num = rand() % 10 + 1;
            population[j][i] = num;
        }
    }

    startEvol(population, N);
*/

    Population pop = Population(100);
    Mater mater = Mater(pop);

};