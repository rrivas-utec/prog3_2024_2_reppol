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

  // Constructor Copia
  Canvas(const Canvas& other) {
    shape_list = new Shape*[other.n];
    n = other.n;
    for (int i = 0; i < n; ++i)
      shape_list[i] = other.shape_list[i]->clone();
  }

  // Asignacion Copia
  Canvas& operator=(const Canvas& other) {
    if (this == &other) return *this;
    // Borra la información anterior
    for (int i = 0; i < n; ++i) {
      delete shape_list[i];
    }
    delete [] shape_list;
    // Asignar informacion del other
    shape_list = new Shape*[other.n];
    n = other.n;
    for (int i = 0; i < n; ++i)
      shape_list[i] = other.shape_list[i]->clone();
    // Retornar a si mismo
    return *this;
  }

  Canvas(Canvas&& other) noexcept {
    std::swap(n, other.n);
    std::swap(shape_list, other.shape_list);
  }

  Canvas& operator= (Canvas&& other) noexcept {
    if (this == &other) return *this;
    // Borra la información anterior
    for (int i = 0; i < n; ++i) {
      delete shape_list[i];
    }
    shape_list = nullptr;
    n = 0;

    std::swap(n, other.n);
    std::swap(shape_list, other.shape_list);

    return *this;
  }

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
    delete [] shape_list;
  }
};

#endif//PROG3_2024_2_REPOSITORIO_POLIMORFICO_CANVAS_H
