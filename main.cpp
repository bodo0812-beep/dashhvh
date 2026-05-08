#include <windows.h>
#include <iostream>
#include "Client.h"

// دالة التهيئة والتحكم (Logic)
void InitializeDASH(HMODULE hModule) {
    // فتح نافذة Console لعرض الرسائل داخل اللعبة
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);

    DashClient::Init();

    std::cout << "\n[DASH Client 32-bit Loaded Successfully]" << std::endl;
    std::cout << "[Z] -> Execute DUPE (التدبيل)" << std::endl;
    std::cout << "[P] -> Execute NESTED (النيستد)" << std::endl;
    std::cout << "[END] -> Unload Hack (الخروج)" << std::endl;

    // حلقة التحكم بالأزرار
    while (true) {
        // زر END لإنهاء الهاك وإغلاق الـ Console
        if (GetAsyncKeyState(VK_END) & 0x8000) break;

        // زر Z لتفعيل/تعطيل التدبيل
        if (GetAsyncKeyState('Z') & 0x0001) {
            DashClient::RunDupe();
        }

        // زر P لتفعيل/تعطيل النيستد
        if (GetAsyncKeyState('P') & 0x0001) {
            DashClient::RunNested();
        }

        Sleep(10); // لتقليل استهلاك المعالج
    }

    // إغلاق الـ Console وتنظيف الذاكرة عند الخروج
    if (f) fclose(f);
    FreeConsole();
    FreeLibraryAndExitThread(hModule, 0);
}

// --- الجزء الأهم لمنع الـ Crash وللعمل كـ DLL ---
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        // إنشاء خيط (Thread) منفصل لتشغيل الهاك
        // هذا يمنع اللعبة من التجمد ويسمح للهاك بالعمل بجانبها
        HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)InitializeDASH, hModule, 0, NULL);
        if (hThread) CloseHandle(hThread);
        break;
    }
    return TRUE;
}