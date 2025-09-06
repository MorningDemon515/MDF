#include "Graphics.h"
#include "Renderer.h"

IDirect3DDevice9* Device;

#pragma comment(lib, "winmm.lib")

bool Render(float timeDelta);

int WINAPI WinMain(HINSTANCE hinstance,
				   HINSTANCE prevInstance, 
				   PSTR cmdLine,
				   int showCmd)
{
	Graphics grap = Graphics(hinstance, 800, 600);
    Renderer renderer = Renderer(grap.WindowHandle, 800, 600);

	grap.SetTitle("MDF - Direct3D 9");
    
	Device = renderer.device;
    grap.EnterMsgLoop(Render);
    
	return 0;

}

bool Render(float timeDelta)
{
    Device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	Device->Present(0, 0, 0, 0);
	return true;
}
