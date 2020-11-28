#define keystate 0x8000
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
	std::cout << u8"Pythagoras Calc\n\u00a9 Sharkbyteprojects\nEnter Numbers smaller than 100.0!\nOn GITHUB: https://github.com/Sharkbyteprojects\nDiscord: https://discord.gg/z8nVJ4yXZj\n" << std::endl;
	bool windowclosed{ false };
	trasfer.content = false;
	bool exit{ false };
	std::future<int> fut = std::async(windowBuilder, &windowclosed, &exit);
	std::future<void> helppagess = std::async(helppages, &windowclosed, &exit);
	while (!windowclosed && !exit)
	{
		trasfer.a.x = requestfloat("First  x Coordinate");
		if (windowclosed) { break; }
		trasfer.a.y = requestfloat("First  y Coordinate");
		if (windowclosed) { break; }
		trasfer.b.x = requestfloat("Second x Coordinate");
		if (windowclosed) { break; }
		trasfer.b.y = requestfloat("Second y Coordinate");
		if (windowclosed) { break; }
		trasfer.content = true;
		trasfer.ids++;
		std::cout << "Distance of the two Points: " << pythagoras(trasfer.a, trasfer.b) << " (Rounded to double)" << std::endl;
		std::cout << u8"Press \u0022a\u0022 or ALT to Enter new Data and press \u0022b\u0022 or ctrl to exit!" << std::endl;
		while (1) {
			if (GetKeyState('A') & keystate || GetKeyState(VK_MENU) & keystate)
			{
				break;
			}
			else if (GetKeyState('B') & keystate || GetKeyState(VK_CONTROL) & keystate) {
				exit = true;
				break;
			}
			else if (GetKeyState(VK_SHIFT) & keystate) {
			}
		}
	}
	std::cout << "\nRecieved WindowClosed\nWait for ending code" << std::endl;
	int returnvalue{ fut.get() };
	std::cout << "Endingcode: " << returnvalue << "\nWaiting for Stopping Helper" << std::endl;
	helppagess.get();
	std::cout << "Stopped, Closing" << std::endl;
	return 0;
}