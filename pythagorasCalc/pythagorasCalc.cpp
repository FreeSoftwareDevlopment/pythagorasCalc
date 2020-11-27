#include "Header.h"
float requestfloat(const char tosay[]) {
	std::cout << tosay << ": " << std::endl;
	float inputvalue{ 0 };
	std::cin >> inputvalue;
	if (std::cin.fail()) {
		std::cerr << "Input a Number Like 1.0!" << std::endl;
		return 0.0f;
	}
	return inputvalue;
}
int main()
{
	std::cout << u8"Pythagoras Calc\n\u00a9 Sharkbyteprojects\nEnter Numbers smaller than 1.0!" << std::endl;
	bool windowclosed{ false };
	trasfer.content = false;
	bool exit{ false };
	std::future<int> fut = std::async(windowBuilder, &windowclosed, &exit);
	while (!windowclosed && !exit)
	{
		trasfer.a.x = requestfloat("First  x Coordinate");
		trasfer.a.y = requestfloat("First  y Coordinate");
		trasfer.b.x = requestfloat("Second x Coordinate");
		trasfer.b.y = requestfloat("Second y Coordinate");
		trasfer.content = true;
		trasfer.ids++;
		std::cout << "Distance of the two Points: " << pythagoras(trasfer.a, trasfer.b) << " (Rounded to double)" << std::endl;
		std::cout << "Press A to Enter new Data and press B to exit!" << std::endl;
		while (1) {
			if (GetKeyState('A') & 0x8000)
			{
				break;
			}
			else if (GetKeyState('B') & 0x8000) {
				exit = true;
				break;
			}
		}
	}
	std::cout << "\nRecieved WindowClosed\nWait for ending code" << std::endl;
	int returnvalue{ fut.get() };
	std::cout << "Endingcode: " << returnvalue << std::endl;
	return 0;
}