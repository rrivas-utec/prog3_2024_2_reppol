//
// Created by rudri on 8/31/2024.
//

#ifndef PROG3_2024_2_REPOSITORIO_POLIMORFICO_CANVAS_H
#define PROG3_2024_2_REPOSITORIO_POLIMORFICO_CANVAS_H

#include "figura.h"

class Canvas {
  Shape** shape_list = nullptr; // Arreglo de figuras
  int n = 0;
public:
  Canvas() = default;
  void add(Shape* s) {
    // Arreglo temporal
    auto temp = new Shape*[n+1];
    // Transferir los Shapes desde el atributo shape_list hacia temp
    for (int i = 0; i < n; ++i) {
      temp[i] = shape_list[i];
    }
    temp[n] = s;
    delete [] shape_list;
    shape_list = temp;
    ++n;
  }
  
  void draw() {
    for (int i = 0; i < n; ++i) {
      shape_list[i]->draw();
    }
  }
  
  ~Canvas() {
    
    for (int i = 0; i < n; ++i) {
      delete shape_list[i];
    }
    delete [] shape_list; }
};

#endif//PROG3_2024_2_REPOSITORIO_POLIMORFICO_CANVAS_H
