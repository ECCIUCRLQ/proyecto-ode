#include "bmp_file.h"

int BMPFile::readFile(std::string img) {
  std::ifstream read_img;
  read_img.open(img);
  if(!read_img.is_open()){
    std::cout << "No se pudo abrir la imagen" << std::endl;
    return 1;
  }
  std::cout << "Se abrió la imagen" << std::endl;
  read_img.read(header.arr, 14);
  read_img.read(inf.arr, 40);
  size_pixels = inf.width * inf.height;

  char arr[size_pixels*3];
  read_img.read(arr, size_pixels*3);

  // Ajusta el formato de los valores de los pixeles leidos
  pixels = new uint8_t[size_pixels*3];
  for (int value = 0; value < size_pixels*3; value++) {
    pixels[value] = arr[value];
  }
  return 0;
}

int BMPFile::setNewFile(std::string new_name){
  // Crea la nueva imagen editada
  std::ofstream new_img;
  new_img.open(new_name);
  if(!new_img.is_open()){
    std::cout << "No se pudo abrir la nueva imagen" << std::endl;
    return 1;
  }
  // Escribe la información al nuevo BMP
  std::cout << "Guardando nueva imagen" << std::endl;
  new_img.write(header.arr, 14);
  new_img.write(inf.arr, 40);
  char arr[size_pixels*3];
  // Ajusta el formato de los valores de los pixeles guardados
  for (int value = 0; value < size_pixels*3; value++) {
    arr[value] = pixels[value];
  }
  new_img.write(arr, size_pixels*3);
  new_img.close();
  return 0;
}

void BMPFile::setTones(){
  uint8_t _rgb;
  uint8_t _r;
  uint8_t _g;
  uint8_t _b;
  for(int pos = 0; pos < size_pixels*3; pos+=3){
    _rgb = (pixels[pos] + pixels[pos+1] + pixels[pos+2]) / 3;
    _b = pixels[pos];
    _g = pixels[pos+1];
    _r = pixels[pos+2];

    // Organiza los pixeles según su valores RGB
    if(_rgb < 85) {rgb.black.insert(std::pair<uint8_t, int>(_rgb, pos));}
    else if(_rgb < 170) {rgb.mid.insert(std::pair<uint8_t, int>(_rgb, pos));}
    else {rgb.white.insert(std::pair<uint8_t, int>(_rgb, pos));}
    // Organiza los pixeles según su valores R
    if(_r < 85) {r.black.insert(std::pair<uint8_t, int>(_r, pos));}
    else if(_r < 170) {r.mid.insert(std::pair<uint8_t, int>(_r, pos));}
    else {r.white.insert(std::pair<uint8_t, int>(_r, pos));}
    // Organiza los pixeles según su valores G
    if(_g < 85) {g.black.insert(std::pair<uint8_t, int>(_g, pos));}
    else if(_g < 170) {g.mid.insert(std::pair<uint8_t, int>(_g, pos));}
    else {g.white.insert(std::pair<uint8_t, int>(_g, pos));}
    // Organiza los pixeles según su valores B
    if(_b < 85) {b.black.insert(std::pair<uint8_t, int>(_b, pos));}
    else if(_b < 170) {b.mid.insert(std::pair<uint8_t, int>(_b, pos));}
    else {b.white.insert(std::pair<uint8_t, int>(_b, pos));}
  }
}

void BMPFile::applyFilter(int color, int _tone, int increment) {

  tone used_color;
  std::multimap<uint8_t, int> used_tone; 
  switch (color) {
    case 1:
      used_color = r;
    break;
    case 2:
      used_color = g;
    break;
    case 3:
      used_color = b;
    break;
    default:
      used_color = rgb;
    break;
  }

  switch (_tone) {
    case 0:
      used_tone = used_color.white;
    break;
    case 1:
      used_tone = used_color.mid;
    break;
    default:
      used_tone = used_color.black;
    break;
  }

  // Crea un arreglo con los pixels a modificar de la imagen
  int siz = used_tone.size();
  support = new uint8_t[siz * 3];
  int i = 0;
  for(const auto& n : used_tone){
    support[i] = pixels[n.second];
    support[i+1] = pixels[n.second+1];
    support[i+2] = pixels[n.second+2];
    i+=3;
  }

  if (increment > 0) {
    uint8_t inc = (increment > 255)? 255 : increment;

    addValues(support, inc, siz, color);
  } 
  else {
    increment = (increment < -255)? 255 : abs(increment);
    subValues(support, increment, siz, color);
  }

  i = 0;
  for(const auto& n : used_tone){
    pixels[n.second] = support[i];
    pixels[n.second+1] = support[i+1];
    pixels[n.second+2] = support[i+2];
    i += 3;
  }
}
