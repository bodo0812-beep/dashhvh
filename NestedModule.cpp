#include "Client.h"
#include <iostream>

// ربط دالة النيستد التي عرفناها في Client.h
void DashClient::RunNested() {
    static bool active = false;
    active = !active; // تبديل الحالة

    if (active) {
        std::cout << "[DASH] Nested Shulkers: ENABLED" << std::endl;
        std::cout << "[DASH] Bypassing Container Restrictions..." << std::endl;
        // هنا سيوضع كود تزييف الـ Item ID لاحقاً
    } else {
        std::cout << "[DASH] Nested Shulkers: DISABLED" << std::endl;
    }
}