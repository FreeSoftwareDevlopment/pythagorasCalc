#include <shellapi.h>
#ifndef keystate
#define keystate 0x8000
#endif
#ifndef VK_F1
#include <Windows.h>
#endif
void helppages(bool* windowclosed, bool* doexit) {
	while (!*windowclosed && !*doexit) {
		if (GetKeyState(VK_F4) & keystate) {
			ShellExecute(0, 0, L"https://github.com/Sharkbyteprojects", 0, 0, SW_SHOW);
		}
		else if (GetKeyState(VK_F1) & keystate) {
			ShellExecute(0, 0, L"https://github.com/FreeSoftwareDevlopment/pythagorasCalc", 0, 0, SW_SHOW);
		}
		else if (GetKeyState(VK_F3) & keystate) {
			ShellExecute(0, 0, L"https://discord.gg/z8nVJ4yXZj", 0, 0, SW_SHOW);
		}
	}
	return;
}

void notifyer(bool types) {
	std::string shs{ "" };
	if (types) {
		shs = " or Press SHIFT to write the data out";
	}
	std::cout << u8"Press \u0022a\u0022 or ALT to Enter new Data and press \u0022b\u0022 or ctrl to exit!" << shs << std::endl;
}
