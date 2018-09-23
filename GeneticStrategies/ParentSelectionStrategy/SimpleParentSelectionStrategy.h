//
// Created by z003j23c on 9/11/2018.
//

#ifndef ONEMAXPROBLEM_SIMPLEPARENTSELECTIONSTRATEGY_H
#define ONEMAXPROBLEM_SIMPLEPARENTSELECTIONSTRATEGY_H

#include <iterator>

class SimpleParentSelectionStrategy : public ParentSelectionStrategy {

public:
    void FillMatingPool(Population& population, std::vector<Chromosome>& mating_pool) {
        std::cout << population.population_average << std::endl;
        population.calculateProbabilities();

        sort(rbegin(population.population_pool), rend(population.population_pool));

        //print out for sorted list:
        std::cout << "Sorted List: " << std::endl;
        copy(begin(population.population_pool), end(population.population_pool), std::ostream_iterator<Chromosome>(
                std::cout, "\n"));

        for_each(begin(population.population_pool), end(population.population_pool),
                 [&](Chromosome chrom) { // TODO check if = was correct
                          if (round(chrom.expected_number) > 0) {
                              for (int i = 0; i < round(chrom.expected_number); i++) {
                                  if (mating_pool.size() < population.population_size) {
                                      mating_pool.push_back(chrom);
                                  }
                              }
                          } else {
                              for (int i = 0; i < round(chrom.expected_number) + 1; i++) {
                                  if (mating_pool.size() < population.population_size) {
                                      mating_pool.push_back(chrom);
                                  }
                              }
                          }
                      });

        //print out for mate pool:
        std::cout << "Mate Pool: (" << mating_pool.size() << ")" << std::endl;
        copy(begin(mating_pool), end(mating_pool), std::ostream_iterator<Chromosome>(std::cout, "\n"));

        //population.population_pool = mating_pool; //TODO check if it is needed
    }


};


#endif //ONEMAXPROBLEM_SIMPLEPARENTSELECTIONSTRATEGY_H
