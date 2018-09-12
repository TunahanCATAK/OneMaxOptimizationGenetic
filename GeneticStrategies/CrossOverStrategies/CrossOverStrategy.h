//
// Created by z003j23c on 9/11/2018.
//

#ifndef ONEMAXPROBLEM_CROSSOVERSTRATEGY_H
#define ONEMAXPROBLEM_CROSSOVERSTRATEGY_H

#include <vector>
#include <stdlib.h>
    class CrossOverStrategy {
    public:

    public:
        virtual Population CreateChildren(std::vector<Chromosome>) = 0;

        virtual std::vector<Chromosome> PerformCrossOver(std::vector<Chromosome>) = 0;

        virtual std::vector<Chromosome> PickParentsUp(std::vector<Chromosome> mating_pool){
            int rand1 = rand() % mating_pool.size();
            int rand2 = rand() % mating_pool.size();

//            std::pair<Chromosome, Chromosome> result;
//            result.first = mating_pool[rand1];
//            result.second = mating_pool[rand2];
            std::vector<Chromosome> result;
            result.push_back(mating_pool[rand1]);
            result.push_back(mating_pool[rand2]);

            return result;
        };
    };



#endif //ONEMAXPROBLEM_CROSSOVERSTRATEGY_H
