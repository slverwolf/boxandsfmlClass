#pragma once
#include "box2d/box2d.h"
#include "scales.h"

//��������� � ��� ������������� ���� 
//x,y-���������� ������.
//w,h-�������� ������ � ������.
//� ��������.
void b2SetPol(b2World& world, int x, int y, int w, int h);
