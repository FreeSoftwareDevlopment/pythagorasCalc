#pragma once
#define dataclassi 0xFF
class coordin {
public:
	float x{ 0.0f };
	float y{ 0.0f };
};
class integertrans {
public:
	int ids{ 0 };
	coordin a;
	coordin b;
	bool content{ false };
};