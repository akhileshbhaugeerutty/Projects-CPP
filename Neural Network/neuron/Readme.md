# C++ Projet

> Le projet consiste à implémenter un réseau de neurones capable d’apprendre à classifier des images en fonction de leurs contenus.

## How-to

Pour lancer ce projet, il vous faut insérer les dossiers respectifs `iris_training` et `MNIST_training` et le fichier `train-label-idx1-ubyte` dans un dossier à la racine appelé `training`

le projet aura donc cette arborescense : 
```bash
.
├── Makefile
├── Readme.md
├── include
│   └── googletest
├── src
│   ├── apprentissage
│   ├── fonction_activation
│   ├── image
│   ├── input
│   ├── iris
│   ├── main.cc
│   ├── nn1
│   ├── perceptron
│   ├── tanh
│   └── utils
├── tests
│   └── unittest.cc
└── training
    ├── MNIST_training
    ├── iris_training
    ├── train-labels-idx1-ubyte
```

Pour lancer le projet et voir les tests se lancer, tapez la commande `make` dans le terminal. Les tests dépendent de googletest inclut dans le projet, pour afficher un rendu comme celui-ci (le test met en moyenne 50 secondes à tourner):
```sh
➜  neuron git:(develop) ✗ make
/Library/Developer/CommandLineTools/usr/bin/make test
... # output de make caché
./unittest
Running main() from include/googletest/src/gtest_main.cc
[==========] Running 11 tests from 6 test suites.
[----------] Global test environment set-up.
[----------] 2 tests from Utils
[ RUN      ] Utils.ReadFile
[       OK ] Utils.ReadFile (0 ms)
[ RUN      ] Utils.getRand
[       OK ] Utils.getRand (0 ms)
[----------] 2 tests from Utils (0 ms total)

[----------] 3 tests from Iris
[ RUN      ] Iris.Constructor
[       OK ] Iris.Constructor (0 ms)
[ RUN      ] Iris.Operator
[       OK ] Iris.Operator (0 ms)
[ RUN      ] Iris.Label
[       OK ] Iris.Label (0 ms)
[----------] 3 tests from Iris (1 ms total)

[----------] 2 tests from Image
[ RUN      ] Image.Operator
[       OK ] Image.Operator (0 ms)
[ RUN      ] Image.Label
[       OK ] Image.Label (1 ms)
[----------] 2 tests from Image (1 ms total)

[----------] 2 tests from Tanh
[ RUN      ] Tanh.Operator
[       OK ] Tanh.Operator (0 ms)
[ RUN      ] Tanh.Prim
[       OK ] Tanh.Prim (0 ms)
[----------] 2 tests from Tanh (0 ms total)

[----------] 1 test from Perceptron
[ RUN      ] Perceptron.Constructor
[       OK ] Perceptron.Constructor (0 ms)
[----------] 1 test from Perceptron (0 ms total)

[----------] 1 test from Apprentissage
[ RUN      ] Apprentissage.image
Rate   : 11.0083% out of 60000 tests
                            
                            
                            
                            
                            
                            
             *****          
            *##########***  
          **##############  
         *##########*#***   
         *###*****          
          ###               
          *##*              
           ###              
      **   *##**            
      ##*   *###            
      ##*    *##*           
      ##*     ###           
      *###    *##*          
       ###***####*          
       *#########           
        *######*            
         *##***             
                            
                            
                            
                            
[       OK ] Apprentissage.image (40237 ms)
[----------] 1 test from Apprentissage (40237 ms total)

[----------] Global test environment tear-down
[==========] 11 tests from 6 test suites ran. (40241 ms total)
[  PASSED  ] 11 tests.
```

Si vous souhaitez faire tourner le test seul, tapez ```make main```.

un test tournera à chaque fois que vous taperez `./neuron`