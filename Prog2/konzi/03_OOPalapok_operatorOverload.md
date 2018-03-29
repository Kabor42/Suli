---
title: OOP alapok es Operator overload
date: 2018.02.26
author: Dobra Gabor
tags: ['c++', 'prog', 'prog2', 'konzi']
---

# Bevezeto

[cppftw.org]

```c++
class X {
 public:
    void valami() {
        std::cout << "X" << std::endl;
    }
};

int main() {
    X x;  // peldany <> objektum
    x.valami();
}
```

Elkulonitheto a publikus es a provat resze.
Ez konyen beallithato a **public** **private** kulcsszoval.

Public
: Ezt latja a program tobbi resze

Private
: Ezt csak a class latja, adatrejtes
: Csak a class-hoz tartozo fuggvenyekkel tudjuk elerni.



