#pragma once
#include "box2d/box2d.h"
#include "scales.h"

//Поместить в мир прямоугольное тело 
//x,y-координаты центра.
//w,h-половины ширины и высоты.
//В пикселях.
void b2SetPol(b2World& world, int x, int y, int w, int h);
