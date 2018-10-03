//
// Created by z003j23c on 9/11/2018.
//

#ifndef ONEMAXPROBLEM_CHROMOSOME_H
#define ONEMAXPROBLEM_CHROMOSOME_H

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
template <class T>
class Chromosome {

public:
    int gene_size;
    std::vector<T> genes;
    float expected_number;
    Chromosome(): Chromosome(0) { }
    float (*FitnessFunc)(Chromosome<T>*);

public:
    Chromosome(std::vector<T>);
    Chromosome(int gene_size) {
        this->gene_size = gene_size;

        this->genes = std::vector<T>(gene_size);
    };

    //TODO: is it really needed at here? 
    Chromosome(const Chromosome<T> &) = default;

    float calculateFitness(){
        auto fitt_val = this->FitnessFunc(this);
        return fitt_val;
    }

    void calculateExpectedNumber(float);

    bool operator< (const Chromosome<T>&) const;
    friend std::ostream& operator<< (std::ostream& os, const Chromosome<T>& obj) {
        std::for_each(std::begin(obj.genes), std::end(obj.genes), [](int i){ std::cout << i << ", ";});
        return os;
    }
};


#endif //ONEMAXPROBLEM_CHROMOSOME_H
