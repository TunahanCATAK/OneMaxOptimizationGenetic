//
// Created by z003j23c on 9/11/2018.
//

#ifndef ONEMAXPROBLEM_SIMPLEPARENTSELECTIONSTRATEGY_H
#define ONEMAXPROBLEM_SIMPLEPARENTSELECTIONSTRATEGY_H

class SimpleParentSelectionStrategy : public ParentSelectionStrategy {

public:
    vector<Chromosome> FillMatingPool(Population& population, vector<Chromosome>& mating_pool){
        cout << population.population_average << endl;
        population.calculateProbabilities();

        sort(rbegin(population.population_pool), rend(population.population_pool));

        //print out for sorted list:
        cout << "Sorted List: " << endl;
        copy(begin(population.population_pool), end(population.population_pool), ostream_iterator<Chromosome>(
                cout, "\n"));

        for_each(begin(population.population_pool), end(population.population_pool),
                 [=](Chromosome chrom) {
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
        cout << "Mate Pool: (" << mating_pool.size() << ")" << endl;
        copy(begin(mating_pool), end(mating_pool), ostream_iterator<Chromosome>(cout, "\n"));

        population.population_pool = mating_pool;
    }


};


#endif //ONEMAXPROBLEM_SIMPLEPARENTSELECTIONSTRATEGY_H
