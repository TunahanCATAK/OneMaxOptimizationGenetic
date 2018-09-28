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
template <typename T>
Chromosome<T>::Chromosome() : Chromosome(5){}
template <typename T>
Chromosome<T>::Chromosome(std::vector<T> _genes) {
    gene_size = _genes.size();
    genes = _genes;
}
template <typename T>
Chromosome<T>::Chromosome(int _gene_size) : genes(_gene_size, new T()) {
    gene_size = _gene_size;

//    for(int i = 0; i < gene_size; i++){
//        int num = rand() % 10 + 1;
//        genes[i] = num;
//    }
}
template <typename T>
float Chromosome<T>::calculateFitness(){
    auto fitt_val = std::count(std::begin(genes), std::end(genes), 1);
    return fitt_val;
}
template <typename T>
void Chromosome<T>::calculateExpectedNumber(float average){
    this->expected_number = calculateFitness()/average;
    //DEBUG INFO:
    std::cout << "Chromosom: ";

    std::for_each(std::begin(genes), std::end(genes),
                  [=](int i){ std::cout << i << " "; });

    std::cout << "  -> " << this->expected_number << std::endl;
}
template <typename T>
bool Chromosome<T>::operator<(const Chromosome<T>& left) const{
    return std::round(expected_number) < std::round(left.expected_number);
}

