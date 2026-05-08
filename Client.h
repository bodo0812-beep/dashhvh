#pragma once
#include <string>

// كلاس DASH الأساسي لتنظيم المعلومات
class DashClient {
public:
    static std::string Name;    // اسم الهاك: DASH
    static std::string Version; // الإصدار: 1.0
    static std::string Author;  // المبدع: Master DASH

    // دوال التحكم الأساسية
    static void Init();
    static void OnTick(); // تنفذ باستمرار

    // الدوال التي سنناديها عند ضغط الأزرار (Z و P)
    static void RunDupe();   // دالة التدبيل
    static void RunNested(); // دالة النيستد
};