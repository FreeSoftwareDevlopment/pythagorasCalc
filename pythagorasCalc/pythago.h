#pragma once
#include <math.h>
#ifndef dataclassi
#include "dataclass.h"
#endif

double pythagoras(coordin a, coordin b) {
	double ax{ (double)a.x };
	double ay{ (double)a.y };
	double by{ (double)b.y };
	double bx{ (double)b.x };
	std::cout << "Calc with Values: {" << ax << ";" << ay << ";" << bx << ";" << by << "}" << std::endl;
	return sqrt(pow((ax - bx), 2) + pow((ay - by), 2));
}