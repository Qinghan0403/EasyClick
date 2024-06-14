#include <iostream>
#include <windows.h>

int main()
{
    // 标记是否开始连点
    bool isClicking = false;

    // 循环检测按键状态并连点
    while (true)
    {
        // 检测F4键状态
        if (GetAsyncKeyState(VK_F4) & 0x8000)
        {
            // 如果已经开始连点则停止连点
            if (isClicking)
            {
                isClicking = false;
                std::cout << "停止连点" << std::endl;
            }
            // 如果还未开始连点则开始连点
            else
            {
                isClicking = true;
                std::cout << "开始连点" << std::endl;
            }

            // 等待一段时间，避免按键连续触发
            Sleep(500);
        }

        // 如果已开始连点，则执行点击操作
        if (isClicking)
        {
            // 获取当前鼠标坐标
            POINT cursorPos;
            GetCursorPos(&cursorPos);

            // 执行点击操作
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, cursorPos.x, cursorPos.y, 0, 0);

            // 暂停一段时间（单位：毫秒）
            Sleep(1000);
        }
    }

    return 0;
}

