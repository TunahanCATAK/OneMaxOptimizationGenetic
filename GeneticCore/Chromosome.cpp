////
//// Created by z003j23c on 9/11/2018.
////
//
#include <functional>
#include <iterator>
#include <random>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include "Chromosome.h"
#include <string>

template class Chromosome<int>;
template class Chromosome<double>;
template class Chromosome<bool>;
template class Chromosome<std::string>;

template <class T>
float Chromosome<T>::calculateFitness(){
    auto fitt_val = std::bind(FitnessFunc,this);
    return fitt_val();
    //return fitt_val;
}

template <class T>
Chromosome<T>::Chromosome() : Chromosome(0) { }

template <class T>
Chromosome<T>::Chromosome(int gene_size){
    this->gene_size = gene_size;
    this->genes = std::vector<T>(gene_size);
}

template <class T>
bool Chromosome<T>::operator<(const Chromosome<T>& left) const{
    return std::round(expected_number) < std::round(left.expected_number);
}



