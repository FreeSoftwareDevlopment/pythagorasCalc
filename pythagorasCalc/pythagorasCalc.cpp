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
	const char* gidi{ "\nOn GITHUB : https://github.com/Sharkbyteprojects\nDiscord: https://discord.gg/z8nVJ4yXZj" };
	std::cout << u8"Pythagoras Calc\n\u00a9 Sharkbyteprojects\nEnter Numbers smaller than 100.0 (Bigger numbers can not complete displayed on the virsual window)!"
		<< gidi
		<< "\nPress F1 to open the Source Page\nPress F3 to Open Discord\nPress F4 to Open Sharkbyteprojects GitHub Page\n" << std::endl;
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
		double distance = pythagoras(trasfer.a, trasfer.b);
		std::cout << "Distance of the two Points: " << distance << " (Rounded to double)" << std::endl;
		notifyer(true);
		bool outwritecomplete{ false };
		while (1) {
			if (GetKeyState('A') & keystate || GetKeyState(VK_MENU) & keystate || windowclosed)
			{
				break;
			}
			else if (GetKeyState('B') & keystate || GetKeyState(VK_CONTROL) & keystate) {
				exit = true;
				break;
			}
			else if (GetKeyState(VK_SHIFT) & keystate && !outwritecomplete) {
				std::string filename;
				std::cout << "Enter Filename: " << std::endl;
				std::cin >> filename;
				if (!std::cin.fail()) {
					std::ofstream outfile(filename.c_str());
					if (!outfile.fail()) {
						outfile << u8"\u00a9 Sharkbyteprojects\nDistance:\t" << distance
							<< "\nPoint 1:\t(" << trasfer.a.x << "|" << trasfer.a.y
							<< ")\nPoint 2:\t(" << trasfer.b.x << "|" << trasfer.b.y << ")\n"
							<< gidi << std::endl;
						outwritecomplete = true;
					}
					else {
						std::cerr << "Failed File writeing" << std::endl;
					}
					outfile.close();
				}
				else {
					std::cerr << "Wrong format" << std::endl;
				}
				notifyer(false);
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