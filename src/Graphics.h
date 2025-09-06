#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <windows.h>

class Graphics
{
private:
	HINSTANCE hIns;

public:
	HWND WindowHandle;

	Graphics(){};
	Graphics(HINSTANCE hinstance ,int width, int height);
	~Graphics();

	int EnterMsgLoop(
		bool (*ptr_display) (float timeDelta)
		);

	void SetTitle(const char* title);
};

#endif GRAPHICS_H