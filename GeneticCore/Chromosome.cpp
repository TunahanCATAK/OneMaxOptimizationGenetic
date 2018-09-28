//
// Created by z003j23c on 9/11/2018.
//

#include <functional>
#include <iterator>
#include <random>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include "Chromosome.h"

Chromosome::Chromosome() : Chromosome(5) {}

Chromosome::Chromosome(std::vector<int> _genes) {
    gene_size = _genes.size();
    genes = _genes;
}

Chromosome::Chromosome(int _gene_size) : genes(_gene_size, 0) {
    gene_size = _gene_size;

    for(int i = 0; i < gene_size; i++){
        int num = rand() % 10 + 1;
        genes[i] = num;
    }
}

float Chromosome::calculateFitness(){
    auto fitt_val = std::count(std::begin(genes), std::end(genes), 1);
    return fitt_val;
}

void Chromosome::calculateExpectedNumber(float average){
    this->expected_number = calculateFitness()/average;
    //DEBUG INFO:
    std::cout << "Chromosom: ";

    std::for_each(std::begin(genes), std::end(genes),
                  [=](int i){ std::cout << i << " "; });

    std::cout << "  -> " << this->expected_number << std::endl;
}

bool Chromosome::operator<(const Chromosome& left) const{
    return std::round(expected_number) < std::round(left.expected_number);
}

