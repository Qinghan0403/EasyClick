#include <iostream>
#include <windows.h>

int main()
{
    // ����Ƿ�ʼ����
    bool isClicking = false;

    // ѭ����ⰴ��״̬������
    while (true)
    {
        // ���F4��״̬
        if (GetAsyncKeyState(VK_F4) & 0x8000)
        {
            // ����Ѿ���ʼ������ֹͣ����
            if (isClicking)
            {
                isClicking = false;
                std::cout << "ֹͣ����" << std::endl;
            }
            // �����δ��ʼ������ʼ����
            else
            {
                isClicking = true;
                std::cout << "��ʼ����" << std::endl;
            }

            // �ȴ�һ��ʱ�䣬���ⰴ����������
            Sleep(500);
        }

        // ����ѿ�ʼ���㣬��ִ�е������
        if (isClicking)
        {
            // ��ȡ��ǰ�������
            POINT cursorPos;
            GetCursorPos(&cursorPos);

            // ִ�е������
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, cursorPos.x, cursorPos.y, 0, 0);

            // ��ͣһ��ʱ�䣨��λ�����룩
            Sleep(1000);
        }
    }

    return 0;
}

