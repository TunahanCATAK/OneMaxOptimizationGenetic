//
// Created by z003j23c on 9/11/2018.
//

#ifndef ONEMAXPROBLEM_SIMPLECROSSOVERSTRATEGY_H
#define ONEMAXPROBLEM_SIMPLECROSSOVERSTRATEGY_H

#include "../../main.cpp"

    class SimpleCrossOverStrategy : public SimpleCrossOverStrategy {

    public:
        std::vector<Chromosome> CreateChildren(vector<Chromosome> mating_pool){
            Population children_for_next_gen;
            for (int i = 0; i < mating_pool.size()/2; i++) {
                std::vector<Chromosome> parents = PickParentsUp(mating_pool);
                vector<Chromosome> children = PerformCrossOver(parents);

                fill(begin(children), end(children), back_inserter(children_for_next_gen.population_pool));
                children_for_next_gen.population_size += 2; //TODO check if it is still needed
            }

            return children_for_next_gen;
        }

    };




#endif //ONEMAXPROBLEM_SIMPLECROSSOVERSTRATEGY_H
