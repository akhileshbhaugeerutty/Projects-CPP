#include "apprentissage/apprentissage.hpp"
#include <iostream>

int main()
{
    int indice;
    std::cout << std::endl << "###########################" << std::endl;
    std::cout << "########### IRIS ##########" << std::endl;
    std::cout << "###########################" << std::endl;
    indice = getRand(0, 150);
    Iris iris(indice);
    std::cout<< "# Flower indice: " << indice << std::endl;
    std::cout<< "# Flower label: " << FLOWERS[(int) iris.get_label()] << std::endl;
    std::cout<< "# First indice : " << iris[0] << std::endl;

    std::cout << std::endl << "###########################" << std::endl;
    std::cout << "########## IMAGE ##########" << std::endl;
    std::cout << "###########################" << std::endl;
    indice = getRand(0, 60000);
    Image image(indice);
    std::cout<< "# Indice: " << indice << std::endl;
    std::cout<< "# Label : " << (char) ('0' + image.get_label()) <<std::endl;
    std::cout<< "# First indice : " << (char) ('0' + image[0]) << std::endl;
    std::cout << image.print();

    std::cout << std::endl << "###########################" << std::endl;
    std::cout << "##### LEARNING PATTERN ####" << std::endl;
    std::cout << "###########################" << std::endl;

    Tanh tan;
    tan.prim(1);
    NN1 n(IMAGE, 10);
    int inputSize = 60000;

    Apprentissage pattern(&n, IMAGE, inputSize);
    pattern.apprendre_base(100000, 1);
    double rate = pattern.evaluer();
    rate /= inputSize;
    std::cout << "# rate   : " << rate * 100 << "% out of " << inputSize << " tests" << std::endl;
    std::cout << "# result : " << (char) ('0' + n.evaluation(image)) << std::endl;
    std::cout << "# Expected : " << (char) ('0' + image.get_label()) << std::endl;
}