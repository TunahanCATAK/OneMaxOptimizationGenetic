////
//// Created by z003j23c on 9/11/2018.
////
//
//#include <functional>
//#include <iterator>
//#include <random>
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <stdlib.h>     /* srand, rand */
//#include "Chromosome.h"
//
//template <class T>
//Chromosome<T>::Chromosome() : Chromosome(5){}
//
//template <class T>
//Chromosome<T>::Chromosome(std::vector<T> _genes) {
//    gene_size = _genes.size();
//    genes = _genes;
//}
//
//template <class T>
//Chromosome<T>::Chromosome(int _gene_size) : genes(_gene_size, new T()) {
//    gene_size = _gene_size;
//
////    for(int i = 0; i < gene_size; i++){
////        int num = rand() % 10 + 1;
////        genes[i] = num;
////    }
//}
//template <class T>
//float Chromosome<T>::calculateFitness(){
//    auto fitt_val = std::count(std::begin(genes), std::end(genes), 1);
//    return fitt_val;
//}
//template <class T>
//void Chromosome<T>::calculateExpectedNumber(float average){
//    this->expected_number = calculateFitness()/average;
//    //DEBUG INFO:
//    std::cout << "Chromosom: ";
//
//    std::for_each(std::begin(genes), std::end(genes),
//                  [=](int i){ std::cout << i << " "; });
//
//    std::cout << "  -> " << this->expected_number << std::endl;
//}
//template <class T>
//bool Chromosome<T>::operator<(const Chromosome<T>& left) const{
//    return std::round(expected_number) < std::round(left.expected_number);
//}
//
