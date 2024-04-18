#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
using namespace std;

int main()
{
	HWND hwnd = NULL; // 窗口句柄
	POINT point; // 鼠标坐标
	bool isstart = false; // 开启或关闭
	int ms = 0; // 按下或弹起的间隔
	// 使用说明
	cout << "使用说明：按F8获取目标窗口句柄（确定目标窗口），按F9设置频率单位为ms，推荐20ms（默认为0），按鼠标中键开启或关闭,开启后按住鼠标左键连点，按住鼠标右键右连点。" << endl;
	while (true)
	{
		if (GetAsyncKeyState(VK_MBUTTON)) // 设置开启或关闭
		{
			isstart = !isstart;
			if (isstart)
			{
				cout << "已打开" << endl;
				Sleep(1000);
			}
			else
			{
				cout << "未打开" << endl;
				Sleep(1000);
			}
		}
		if (GetAsyncKeyState(VK_F8))
		{
			// 获取窗口句柄
			hwnd = GetForegroundWindow();
			if (hwnd != NULL)
			{
				cout << hwnd << endl;
				char className[256];
				GetClassNameA(hwnd, className, sizeof(className)); // 获取窗口类名（自己方便、确定获取）
				cout << "窗口类名: " << className << endl;
			}
			// 防误触
			Sleep(200);
		}
		if (GetAsyncKeyState(VK_F9)) // 获取按下或弹起间隔
		{
			cout << "输入延迟ms(按下和弹起都是这个延迟)" << endl;
			cin >> ms;
		}
		if (isstart && hwnd != NULL && GetAsyncKeyState(VK_LBUTTON))
		{
			// 获取鼠标坐标
			GetCursorPos(&point);
			// 转化为窗口内的相对坐标
			ScreenToClient(hwnd, &point);
			// 模拟左键点击按下事件
			PostMessageA(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(point.x, point.y));
			// 按下间隔
			Sleep(ms);
			// 模拟左键点击释放事件
			PostMessageA(hwnd, WM_LBUTTONUP, 0, MAKELPARAM(point.x, point.y));
			// 弹起间隔
			Sleep(ms);
		}
		else if (isstart && hwnd != NULL && GetAsyncKeyState(VK_RBUTTON))
		{
			// 获取鼠标坐标
			GetCursorPos(&point);
			// 转化为窗口内的相对坐标
			ScreenToClient(hwnd, &point);
			// 模拟左键点击按下事件
			PostMessageA(hwnd, WM_RBUTTONDOWN, MK_RBUTTON, MAKELPARAM(point.x, point.y));
			// 按下间隔
			Sleep(ms);
			// 模拟左键点击释放事件
			PostMessageA(hwnd, WM_RBUTTONUP, 0, MAKELPARAM(point.x, point.y));
			// 弹起间隔
			Sleep(ms);
		}
	}
}
