//
// Created by z003j23c on 9/11/2018.
//

#include <iterator>
#include <random>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include "Mater.h"

class Mater{
public:
    std::vector<Chromosome> mate_pool;

    Mater(Population& population){
        std::cout << population.population_average << std::endl;
        population.calculateProbabilities();

        std::sort(std::rbegin(population.population_pool), std::rend(population.population_pool));

        //print out for sorted list:
        std::cout << "Sorted List: " << std::endl;
        copy(std::begin(population.population_pool), std::end(population.population_pool), std::ostream_iterator<Chromosome>(
                std::cout, "\n"));

        std::for_each(std::begin(population.population_pool), std::end(population.population_pool),
                      [=](Chromosome chrom){
                        if (std::round(chrom.expected_number) > 0){
                            for (int i = 0; i < std::round(chrom.expected_number); i++){
                                if (mate_pool.size() < population.population_size){
                                    mate_pool.push_back(chrom);
                                }
                            }
                        }
                        else{
                            for (int i = 0; i < std::round(chrom.expected_number) + 1; i++){
                                if (mate_pool.size() < population.population_size){
                                    mate_pool.push_back(chrom);
                                }
                            }
                        }


                      });

        //print out for mate pool:
        std::cout << "Mate Pool: (" << mate_pool.size() << ")" << std::endl;
        copy(std::begin(mate_pool), std::end(mate_pool), std::ostream_iterator<Chromosome>(std::cout, "\n"));

        population.population_pool = mate_pool;
    }

    std::pair<Chromosome, Chromosome> pickParentsUp(){

        int rand1 = rand() % mate_pool.size();
        int rand2 = rand() % mate_pool.size();

        std::pair<Chromosome, Chromosome> result;
        result.first = mate_pool[rand1];
        result.second = mate_pool[rand2];

        return result;
    }
};