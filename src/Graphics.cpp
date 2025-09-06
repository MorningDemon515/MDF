#include "Graphics.h"

LRESULT CALLBACK WndProc(
		HWND hwnd,
		UINT msg,
		WPARAM wParam,
		LPARAM lParam
		);

Graphics::Graphics(HINSTANCE hinstance ,int width, int height)
{
	WNDCLASS wc;
	wc.style = CS_HREDRAW|CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hinstance;
    wc.hIcon = LoadIcon(0, IDI_APPLICATION);
    wc.hCursor = LoadCursor(0, IDC_ARROW);
    wc.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
    wc.lpszMenuName = 0;
    wc.lpszClassName = "MDF-Class";

    RegisterClass(&wc);

    WindowHandle = CreateWindowA(
        "MDF-Class",
        "",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        width,
        height,
        0,
        0,
        hinstance,
        0
    );

    ShowWindow(WindowHandle,SW_SHOW);
    UpdateWindow(WindowHandle);

	hIns = hinstance;

	LONG style = GetWindowLong(WindowHandle, GWL_STYLE);
	style &= ~(WS_MAXIMIZEBOX | WS_SIZEBOX);	
	SetWindowLong(WindowHandle, GWL_STYLE, style);		
}

Graphics::~Graphics()
{
	DestroyWindow(WindowHandle);
	UnregisterClass("MDF-Class", hIns);
}

int Graphics::EnterMsgLoop(
	bool (*ptr_display) (float timeDelta)
)
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	static float lastTime = (float)timeGetTime(); 

	while(msg.message != WM_QUIT)
	{
		if(::PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
		}
		else
        {	
			float currTime  = (float)timeGetTime();
			float timeDelta = (currTime - lastTime)*0.001f;

			ptr_display(timeDelta);

			lastTime = currTime;
        }
    }
    return msg.wParam;
}

void Graphics::SetTitle(const char* title)
{
	SetWindowText(WindowHandle, title);
}

LRESULT CALLBACK WndProc(
		HWND hwnd,
		UINT msg,
		WPARAM wParam,
		LPARAM lParam
		)
{
	switch(msg)
    {

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        break;

    }

    return DefWindowProc(
        hwnd,
        msg,
        wParam,
        lParam
    );
}