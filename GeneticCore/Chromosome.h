//
// Created by z003j23c on 9/11/2018.
//

#ifndef ONEMAXPROBLEM_CHROMOSOME_H
#define ONEMAXPROBLEM_CHROMOSOME_H


class Chromosome {

public:
    int gene_size;
    std::vector<int> genes;
    float expected_number;

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
        auto fitt_val = std::count(std::begin(genes), std::end(genes), 1);
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

    std::vector<Chromosome> performCrossOver(std::function<std::vector<Chromosome>(Chromosome, Chromosome)> func){
        std::vector<Chromosome> chromosomes = std::vector<Chromosome>(2);
        func(this);
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


#endif //ONEMAXPROBLEM_CHROMOSOME_H
