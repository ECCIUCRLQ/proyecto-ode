# pragma once

#include <cstdint>
#include <cstdio>
#include <fstream>
#include <string>
#include <iostream>
#include <inttypes.h>
#include <map>

extern "C" void addValues(uint8_t* values, uint8_t increment, int size, int color);
extern "C" void subValues(uint8_t* values, uint8_t increment, int size, int color);

// Estructur básica con la ingormación de un archivo BMP de 24 bits de color
struct DIBHeader {
  union {
    char arr[40];
    struct {
      uint32_t bits_DIB = 40;
      uint32_t width;
      uint32_t height;
      uint16_t color_planes = 1; // Tiene que ser 1
      uint16_t bits_pixels = 24; // Solo se aceptan imagenes de 24 bits de color
      uint32_t compression = 0;
      uint32_t raw_size;
      uint32_t print_width;
      uint32_t print_height;
      uint32_t pallette_n;
      uint32_t import_colors;
    };
  };
};
// Estructura básica de un BMP con colores de 24 bits
struct BMPHeader {
  union {
    char arr[14];
    struct {
      uint16_t ID;
      uint32_t size;
      uint32_t unused;
      uint32_t start_data;
    };
  };
};

// Agrupador de pixeles según su tono
struct tone {
  std::multimap<uint8_t, int> white;
  std::multimap<uint8_t, int> mid;
  std::multimap<uint8_t, int> black;
};

// Clase para guardar imagenes de tipo BMP
class BMPFile{
private:
  uint8_t* support;         // Arreglo donde guardar los pixeles que se van a modificar
public:
  BMPHeader header = {0};   // Caracteristicas principales de un archivo BMP
  DIBHeader inf = {0};      // Representa la información de la imagen
  uint8_t* pixels;          // Los pixeles que componen la imagen
  tone rgb;                 // Conjunto de pixels agrupados según su tono
  tone r;                   // Pixeles según su cantidad de rojo
  tone g;                   // Pixeles según su cantidad de verde
  tone b;                   // Pixeles según su cantidad de azul
  uint32_t size_pixels;

  // Lee la imagen y la guarda en memoria
  int readFile(std::string img);

  // Organiza los pixeles según sus tonos
  void setTones();

  // Guarda la imagen nuevo con el filtro aplicado
  int setNewFile(std::string new_name);

  // Aumenta o diminuye los valores de un tone de la imagen
  // RGB = default, R = 1, G = 2, B = 3;
  // White = 0, Mid = 1, Black = default
  void applyFilter(int color, int _tone, int increment);
};
