//
// Created by rudri on 8/31/2024.
//

#ifndef PROG3_2024_2_REPOSITORIO_POLIMORFICO_FIGURA_H
#define PROG3_2024_2_REPOSITORIO_POLIMORFICO_FIGURA_H

#include <iostream>

struct Shape {
  Shape() = default;
  Shape(int pos_x, int pos_y): pos_x(pos_x), pos_y(pos_y) {}
  virtual void draw() = 0;
  virtual Shape* clone() = 0;
  virtual ~Shape() = default;
protected:
  int pos_x = 0;
  int pos_y = 0;
};

class Circle: public Shape {
public:
  Circle(int pos_x, int pos_y): Shape(pos_x, pos_y) {}
  void draw() override {
    std::cout << "Draw Circle, position: " << pos_x << ", " << pos_y << std::endl;
  }
  Circle* clone() override {
    return new Circle(this->pos_x, this->pos_y);
  }
};

class Rectangle: public Shape {
public:
  Rectangle(int pos_x, int pos_y): Shape(pos_x, pos_y) {}
  void draw() override {
    std::cout << "Draw Rectangle, position: " << pos_x << ", " << pos_y << std::endl;
  }
  Rectangle* clone() override {
    return new Rectangle(this->pos_x, this->pos_y);
  }
};

#endif//PROG3_2024_2_REPOSITORIO_POLIMORFICO_FIGURA_H
