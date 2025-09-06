#ifndef RENDERER_H
#define RENDERER_H

#include <windows.h>
#include <d3d9.h>

class Renderer
{
public:
    IDirect3D9* d3d9;
	IDirect3DDevice9* device;

	Renderer(){};
	Renderer(HWND hwnd,int width, int height);
	~Renderer();

};

#endif 