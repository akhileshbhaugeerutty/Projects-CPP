#ifndef NEURON_SRC_SIGMOIDE_SIGMOIDE_HPP
#define NEURON_SRC_SIGMOIDE_SIGMOIDE_HPP


#include <math.h>
#include "../fonction_activation/fonction_activation.hpp"


class sigmoide : public Fonction_activation
{
    public:

    private:
        double operator ()(double);
        double prim(double);
};

#endif // NEURON_SRC_SIGMOIDE_SIGMOIDE_HPP
