#include "Client.h"
#include <iostream>

// تعريف القيم
std::string DashClient::Name = "DASH";
std::string DashClient::Version = "1.0";

void DashClient::Init() {
    std::cout << "--- " << Name << " CLIENT LOADED ---" << std::endl;
}

// دالة التدبيل
void DashClient::RunDupe() {
    // هذا المكان مخصص للكود الذي يرسل حزم التدبيل للسيرفر
    std::cout << "[DEBUG] Sending Dupe Packets..." << std::endl;
}

// دالة النيستد
void DashClient::RunNested() {
    // هذا المكان مخصص للكود الذي يلغي قيود وضع الشيلكرات داخل بعضها
    std::cout << "[DEBUG] Bypassing Container Restrictions..." << std::endl;
}