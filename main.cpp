#include <iostream>
#include <memory>

#include "canvas.h"

void ejemplo_smart_pointer() {
  int* ptr;
  ptr = new int;
  auto ptr2 = ptr;
  delete ptr;
  
  std::unique_ptr<int> uptr;        // int* ptr;
  uptr = std::make_unique<int>(44); // ptr = new int;
  
  auto uptr2 = std::move(uptr);
  
  std::shared_ptr<int> sptr;        // int* ptr;
  sptr = std::make_shared<int>(44); // ptr = new int;
  
  auto sptr2 = sptr;
  auto sptr3 = sptr;
  auto sptr4 = sptr;
}

void ejemplo_1() {
  Canvas c;
  c.add(new Circle(10, 20));
  c.add(new Rectangle(34, 20));
  c.add(new Circle(1, 5));
  c.add(new Rectangle(3, 7));
  
  c.draw();
}


int main() {
  ejemplo_1();
  return 0;
}
