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
    //float expected_number;

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

    std::vector<Chromosome> evoluation(const Chromosome& chrom){
        std::vector<Chromosome> chromosomes = std::vector<Chromosome>(2);

        int num = rand() % GENE_SIZE;
        for (int i = 0; i < GENE_SIZE; i++){
            if (i <= num){
                chromosomes[0].genes[i] = this->genes[i];
                chromosomes[1].genes[i] = chrom.genes[i];
            }
            else{
                chromosomes[0].genes[i] = chrom.genes[i];
                chromosomes[1].genes[i] = this->genes[i];
            }
        }

        return chromosomes;
    }


    bool operator<(const Chromosome& A) const{
        return std::round(expected_number) < std::round(A.expected_number);
    }

    friend std::ostream& operator<< (std::ostream& os, const Chromosome& obj) {
        std::for_each(std::begin(obj.genes), std::end(obj.genes), [](int i){ std::cout << i << ", ";});
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
                      [=](Chromosome &chro){ chro.calculateExpectedNumber(population_average);});
    }

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

        std::sort(std::rbegin(population.population_pool), std::rend(population.population_pool));

        //print out for sorted list:
        std::cout << "Sorted List: " << std::endl;
        std::copy(std::begin(population.population_pool), std::end(population.population_pool), std::ostream_iterator<Chromosome>(std::cout, "\n"));

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
        std::copy(std::begin(mate_pool), std::end(mate_pool), std::ostream_iterator<Chromosome>(std::cout, "\n"));

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

class Generation{
public:
    std::vector<Population> generations;

    Generation(Population& initial_pop){
        generations.push_back(initial_pop);
    }

    void evaluation(){
        //pre evaluation:
        Population the_next_generation;
        Mater mating_operator = Mater(generations.back());

        the_next_generation.population_size = 0;
        for (int i = 0; i < mating_operator.mate_pool.size()/2; i++) {
            std::pair<Chromosome, Chromosome> parents = mating_operator.pickParentsUp();
            std::vector<Chromosome> children = parents.first.evoluation(parents.second);

            std::for_each(std::begin(children), std::end(children),
                          [&the_next_generation](Chromosome chro){ the_next_generation.population_pool.push_back(chro);});
            the_next_generation.population_size += 2;
        }

        float average = the_next_generation.getPopulationAverage();
        std::cout << average << std::endl;
        generations.push_back(the_next_generation);
    }
};

int main(){
    /* initialize random seed: */
    srand (time(NULL));

    Population pop = Population(100);
    Generation gen = Generation(pop);
    gen.evaluation();
    gen.evaluation();
    gen.evaluation();
    gen.evaluation();
    gen.evaluation();
    gen.evaluation();
    gen.evaluation();
    gen.evaluation();
    gen.evaluation();
    gen.evaluation();
    gen.evaluation();
    gen.evaluation();
    gen.evaluation();

    std::for_each(std::begin(gen.generations), std::end(gen.generations), [](Population gen){ std::cout << "Average: " << gen.population_average << std::endl;});
    //Mater mater = Mater(pop);
};
