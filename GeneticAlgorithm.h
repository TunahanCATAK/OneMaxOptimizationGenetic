//
// Created by z003j23c on 9/11/2018.
//

#ifndef ONEMAXPROBLEM_GENETICALGORITHM_H
#define ONEMAXPROBLEM_GENETICALGORITHM_H

#include "GeneticStrategies/."
#include <stdlib.h>     /* srand, rand */
#include <ostream>
#include <vector>
#include "GeneticCore/Chromosome.h"
#include "GeneticStrategies/CrossOverStrategies/CrossOverStrategy.h"
#include "GeneticStrategies/MutationStrategies/MutationStrategy.h"
#include "GeneticStrategies/SurvivalStrategies/SurvivalSelectionStrategy.h"
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
            generation++;
            return max_generation_count-- != 0;
        }

        void setParentSelectionStrategy(ParentSelectionStrategy* rep) {
            this->parentSelectionStrategy = rep;
        }

        void setCrossOverStrategy(CrossOverStrategy xover) {
            this->xOverStrategy = xover;
        }

        void setMutationStrategy(MutationStrategy mutation) {
            this->mutationStrategy = mutation;
        }

        void setSurvivalSelectionStrategy(SurvivalSelectionStrategy survival) {
            this->survivalStrategy = survival;
        }

        void startEvolution(){
            while(moreGenerations()){
                //ParentSelection
                parentSelectionStrategy.FillMatingPool(generations[generation] , mating_pool);
                //CrossOver
                std::vector<Chromosome> new_population = xOverStrategy.PerformCrossOverForPopulation(mating_pool);
                //Mutation
                mutationStrategy.Mutate(new_population);
                //SurvivalSelection
                auto survived_chromosomes = survivalStrategy.PerformSurvivalSelection(new_population);
                generations.push_back(survived_chromosomes);
            }
            //pre evaluation:
            Population the_next_generation;
            Mater mating_operator = Mater(generations.back());

            the_next_generation.population_size = 0;
            for (int i = 0; i < mating_operator.mate_pool.size()/2; i++) {
                std::pair<Chromosome, Chromosome> parents = mating_operator.pickParentsUp();
                std::vector<Chromosome> children = parents.first.performCrossOver(parents.second);

                std::for_each(std::begin(children), std::end(children),
                              [&the_next_generation](
                                      Chromosome chro){ the_next_generation.population_pool.push_back(chro);});
                the_next_generation.population_size += 2;
            }

            float average = the_next_generation.getPopulationAverage();
            std::cout << average << std::endl;
            generations.push_back(the_next_generation);
        }
    };




#endif //ONEMAXPROBLEM_GENETICALGORITHM_H
