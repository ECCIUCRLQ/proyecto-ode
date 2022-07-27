/*
  Camera user program.

  Authors:	David Sánchez
			Oscar Quesada
			Esteban Porras

  This is the user program that makes use of a driver
  that communicates with a virtual camera device called
  ODEcam and allows an user to simulate taking pictures
  and applying filters to them.

*/
#define WR_VALUE _IOW('a', 'a', int32_t *)
#define RD_VALUE _IOR('b', 'b', int32_t *)
#define READ_VALUE_FROM_PCI_DEVICE _IOR('b', 'b', int32_t *)

#include <cstdint>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "bmp_file.h"

int main (int argc, char* argv[]){
  if (argc <= 2){
    std::cout << "Faltan argumentos..." << std::endl;
    std::cout << "<image dir> <new_img_name>" << std::endl;
    return 0;
  }

  std::string img = argv[1];
  BMPFile bmp;
  bmp.readFile(img);
  bmp.setTones();

  std::cout << "FILTROS:" << std::endl;
  std::cout << "0- Contraste  1- Brillo   2- Saturacion" << std::endl;
  std::cout << "3- Vintage    4- HeatMap  5- Amaro" << std::endl;
  std::cout << "6- 1977       7- Rojizo   8- Azulado" << std::endl;
  std::cout << "9- Desaturar 10- PopArt  11- Negativo" << std::endl;

  int filtro;
  std::cin >> filtro;

  // RGB = default, R = 1, G = 2, B = 3;
  // White = 0, Mid = 1, Black = default
  switch (filtro) {
    case 0:
      // CONTRASTE
      bmp.applyFilter(0, 2, -10);
      bmp.applyFilter(0, 0, 10);
    break;
    case 1:
      // BRILLO
      bmp.applyFilter(0, 2, 20);
      bmp.applyFilter(0, 1, 20);
      bmp.applyFilter(0, 0, 20);
    break;
    case 2:
      // SATURACION
      bmp.applyFilter(1, 1, 40);
      bmp.setTones();
      bmp.applyFilter(2, 1, 40);
      bmp.applyFilter(3, 1, 40);
      bmp.applyFilter(1, 0, 50);
      bmp.applyFilter(2, 0, 50);
      bmp.applyFilter(3, 0, 50);
    break;
    case 3:
      // VINTAGE
      bmp.applyFilter(3, 0, -40);
      bmp.applyFilter(3, 1, -40);
    break;
    case 4:
      // HEATMAP
      bmp.applyFilter(1, 0, 100);
      bmp.applyFilter(1, 1, -100);
      bmp.applyFilter(1, 2, -100);
      bmp.setTones();
      bmp.applyFilter(2, 1, 100);
      bmp.applyFilter(2, 2, -100);
      bmp.applyFilter(2, 0, -100);
      bmp.setTones();
      bmp.applyFilter(3, 2, 100);
      bmp.applyFilter(3, 0, -100);
      bmp.applyFilter(3, 1, -100);
      bmp.setTones();
    break;
    case 5:
      // AMARO
      bmp.applyFilter(3, 0, 130);
      bmp.applyFilter(3, 2, -50);
      bmp.applyFilter(3, 1, -50);
    break;
    case 6:
      // 1977
      bmp.applyFilter(3, 0, 20);
      bmp.applyFilter(1, 2, 20);
      bmp.applyFilter(2, 2, -20);
    break;
    case 7:
      // ROJIZO
      bmp.applyFilter(1, 0, 50);
      bmp.applyFilter(1, 1, 50);
      bmp.applyFilter(1, 2, 50);
    break;
    case 8:
      // AZULADO
      bmp.setTones();
      bmp.applyFilter(3, 0, 100);
      bmp.applyFilter(3, 1, 100);
      bmp.applyFilter(3, 2, 100);
    break;
    case 9:
      // DESATURAR
      bmp.applyFilter(1, 1, -40);
      bmp.setTones();
      bmp.applyFilter(2, 1, -40);
      bmp.applyFilter(3, 1, -40);
      bmp.applyFilter(1, 0, -50);
      bmp.applyFilter(2, 0, -50);
      bmp.applyFilter(3, 0, -50);
    break;
    case 10:
      // POPART
      bmp.applyFilter(1, 2, 255);
      bmp.applyFilter(1, 0, 230);
      bmp.applyFilter(0, 1, 230);
    break;
    case 11:
      // NEGATIVO
      bmp.applyFilter(1, 0, -100);
      bmp.applyFilter(2, 0, -100);
      bmp.applyFilter(3, 0, -100);
      bmp.setTones();
      bmp.applyFilter(1, 1, -27);
      bmp.applyFilter(2, 1, -27);
      bmp.applyFilter(3, 1, -27);
      bmp.setTones();
      bmp.applyFilter(1, 2, 100);
      bmp.applyFilter(2, 2, 100);
      bmp.applyFilter(3, 2, 100);
      bmp.setTones();
      bmp.applyFilter(1, 2, 100);
      bmp.applyFilter(2, 2, 100);
      bmp.applyFilter(3, 2, 100);
      bmp.setTones();
      bmp.applyFilter(1, 1, 27);
      bmp.applyFilter(2, 1, 27);
      bmp.applyFilter(3, 1, 27);

    break;
  }

  bmp.setNewFile(argv[2]);

  return 0;
}
