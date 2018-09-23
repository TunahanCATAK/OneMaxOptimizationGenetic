//
// Created by z003j23c on 9/11/2018.
//

#ifndef ONEMAXPROBLEM_GENETICALGORITHM_H
#define ONEMAXPROBLEM_GENETICALGORITHM_H

#include <stdlib.h>     /* srand, rand */
#include <ostream>
#include <vector>
#include "GeneticCore/Chromosome.h"
#include "GeneticStrategies/CrossOverStrategies/CrossOverStrategy.h"
#include "GeneticStrategies/MutationStrategies/MutationStrategy.h"
#include "GeneticStrategies/SurvivalStrategies/SurvivalSelectionStrategy.h"
#include "GeneticStrategies/ParentSelectionStrategy/ParentSelectionStrategy.h"
    class GeneticAlgorithm {

    public:
        int max_generation_count;
        int generation = 0;
        std::vector<Population> generations;
        std::vector<Chromosome> mating_pool;
        ParentSelectionStrategy* parentSelectionStrategy;
        CrossOverStrategy* xOverStrategy;
        MutationStrategy* mutationStrategy;
        SurvivalSelectionStrategy* survivalStrategy;

        GeneticAlgorithm(Population& initial_pop, unsigned int max_gen_size) : max_generation_count(max_gen_size){
            generations.push_back(initial_pop);
        }

        bool moreGenerations(){
            return max_generation_count-- != 0;
        }

        void setParentSelectionStrategy(ParentSelectionStrategy* rep) {
            this->parentSelectionStrategy = rep;
        }

        void setCrossOverStrategy(CrossOverStrategy* xover) {
            this->xOverStrategy = xover;
        }

        void setMutationStrategy(MutationStrategy* mutation) {
            this->mutationStrategy = mutation;
        }

        void setSurvivalSelectionStrategy(SurvivalSelectionStrategy* survival) {
            this->survivalStrategy = survival;
        }

        void startEvolution(){
            while(moreGenerations()){
                //ParentSelection
                parentSelectionStrategy->FillMatingPool(generations[generation] , mating_pool);
                //CrossOver
                Population new_population = xOverStrategy->CreateChildren(mating_pool);
                //survivalStrategy->pickIndividuals4NextGen()
                generations.push_back(new_population);
                //Mutation
                //mutationStrategy.Mutate(new_population); TODO Not yet Implemented
                //SurvivalSelection
                //auto survived_chromosomes = survivalStrategy.PerformSurvivalSelection(new_population); //TODO Not yet implemented
                //generations.push_back(survived_chromosomes);
                generation++;
            }

        }
    };




#endif //ONEMAXPROBLEM_GENETICALGORITHM_H
