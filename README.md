# MacroBoX
### A lightweight abstraction layer for MacroLibX

---

## What is MacroBoX?

MacroBoX is a small library built on top of **MacroLibX** that aims to make it more pleasant and consistent to use.\
It is entirely written in C and in line with the 42 norm, allowing you to easily edit it and extend it to your needs and preferences.

MacroBoX is still in beta, bugs are to be expected.
The creator is always available for any feedback and questions (@daemonic._ on discord).

---

## What does it provide?

### Simplified application initialization

A single function will initialize the MacroLibX, MacroBoX itself and create a window.


### Overhauled drawing system

With MacroBoX, you can draw pixels, rectangles, lines, text and more on the screen or a region.\
Regions are MacroBoX's images, which can be used to draw stuff separately from the main screen.


### A new input system

This one uses input polling rather than event based handling. In simpler terms, it allows you to check the state of the keyboard and mouse at any given time, rather than shoving everything in a function.\
It also comes with macros for every key, mouse button and window event.


### A full vector library

4 different vector types are provided (2D and 3D, containing ints or doubles), along with more than 40 functions each to manipulate them.\
There is also 12 extra structs to store multiple vectors together.


### And some other small stuff

Some math helper functions (lerp, clamp, move_towards, etc)\
Some time helper values (delta_time, update_count, etc)

---

## Instructions

before using MacroBoX, make sure to compile it, run it:

```sh
make
```

you can then use it in your projects by including it:

```c
#include "MacroBoX/includes/mbx.h"
```
