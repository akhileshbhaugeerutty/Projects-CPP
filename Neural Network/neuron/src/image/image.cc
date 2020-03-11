#include "image.hpp"
#include <iostream>
#include <string>

// class Image : public Input
// {
// private:
//   /* data */
//   char label;
// public:
//   Image(int);
//   ~Image();
//   double operator [](int);
//   char get_label();
// };
int ptoi(char* p) /*transforme un pointeur binaire en int */
{/*& 0xff” masks the variable so it leaves only the value in the last 8 bits, and ignores all the rest of the bits*/
    return ((p[0] & 0xff) << 24) | ((p[1] & 0xff) << 16) | 
            ((p[2] & 0xff) <<  8) | ((p[3] & 0xff) <<  0);
}

char retrieveLabel(int imageIndice)
{
    char  p[4];
    int   totalFiles;
/*open for reading, open in binary mode */
    std::ifstream ifs((MNIST_FOLDER + "train-labels.idx1-ubyte").c_str(), std::ios::in | std::ios::binary);
    ifs.ignore(4);
    ifs.read(p, 4); 
    totalFiles = ptoi(p); /*nombre fichier total*/
    if (imageIndice != 0 && imageIndice < totalFiles) 
        totalFiles = imageIndice;

    ifs.ignore(totalFiles); /*On saute le nombre d'indice (= 1) */
    ifs.read(p, 1); /*On prend la chaine */
    ifs.close();
    return p[0]; /*c'est l'indice */
}

void retrieveTable(int imageFile, double* table)
{
    char p[IMAGE_TABLE_SIZE * IMAGE_TABLE_SIZE]; /*tableau 28*28, mis tout en ligne */
    std::ifstream ifs((MNIST_FOLDER + "training" + std::to_string(imageFile)).c_str(), std::ios::in | std::ios::binary);
    ifs.ignore(1078); /*Les pixels se trouvent à partid de 1079*/

    ifs.read(p, IMAGE_TABLE_SIZE * IMAGE_TABLE_SIZE);

    for (int pix = 0;  pix < IMAGE_TABLE_SIZE * IMAGE_TABLE_SIZE; ++pix)
      table[pix] = p[pix];

    ifs.close();
}

Image::Image(int imageIndice)
{
  //assert(imageIndice >= 0 && imageIndice < 60000)// ; /*arrête le programme si faux */

  retrieveTable(imageIndice, table);
  label = retrieveLabel(imageIndice);
}

std::string Image::print()
{
  std::string str;
  for (int li = IMAGE_TABLE_SIZE - 1; li > 0; --li)
  {
    for (int col = 0; col < IMAGE_TABLE_SIZE; ++ col)
    {
      double pix = table[li * IMAGE_TABLE_SIZE + col];
      char toPrint;
      if (pix == 0)
        toPrint = ' ';
      else if (pix < 0)
        toPrint = '#';
      else
        toPrint = '*';
      str += toPrint;
    }
    str += "\n";
  }
  return str;
}

double Image::operator[](int indice)
{
  if (indice < 0 || indice >= IMAGE_TABLE_SIZE * IMAGE_TABLE_SIZE)
    return 0;
  double ret = table[indice] / 255; /*on divise par 255 parce que tanh donne des valeurs complètement absurde */
  return ret;
}