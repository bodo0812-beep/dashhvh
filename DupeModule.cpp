#include "Client.h"
#include <iostream>
#include <windows.h>

// سنقوم ببرمجة الدالة التي عرفناها في Client.h هنا
void DashClient::RunDupe() {
    static bool isEnabled = false;
    isEnabled = !isEnabled; // تبديل الحالة عند كل ضغطة

    if (isEnabled) {
        std::cout << "[DASH] Duplication Mode: ON" << std::endl;
        std::cout << "[DASH] Sending Dupe Packets..." << std::endl;
        
        // هنا سيتم وضع كود الـ Packets الفعلي لاحقاً
        // مثال: SendPacket(new PlayerActionPacket(DROP_ITEM));
        
        Sleep(50); 
    } else {
        std::cout << "[DASH] Duplication Mode: OFF" << std::endl;
    }
}