#include <iostream>
#include <iomanip>
#include <emmintrin.h>  // dla __m128i (SSE)
#include <immintrin.h>  // dla __m256i (AVX)
#include <string>

struct tmpData {
    char a;     // 1 bajt
    double b;   // 8 bajtów
    int c;      // 4 bajty
    double d;   // 8 bajtów
    char e;     // 1 bajt
};


// Funkcja testuj¹ca wyrównanie dla dowolnego typu T
template<typename T>
void test_alignment(const std::string& type_name) {
    T tmp; // zmienna testowa
    long long adres = reinterpret_cast<long long>(&tmp);

    std::cout << "\n========================================================\n";
    std::cout << " Typ: " << type_name << " (adres zmiennej: " << adres << ")\n";
    std::cout << "========================================================\n";
    std::cout << std::left << std::setw(12) << "Granica"
        << std::setw(25) << "Adres"
        << std::setw(25) << "Dopasowanie" << std::endl;
    std::cout << "--------------------------------------------------------\n";

    for (int i = 0; i < 8; ++i) {
        int granica = 1 << i;
        bool dopasowany = (adres % granica == 0);

        std::cout << std::left << std::setw(12) << granica
            << std::setw(25) << adres
            << std::setw(25)
            << (dopasowany ? "TAK" : "NIE")
            << std::endl;
    }
}

int main() {
    std::cout << "Analiza dopasowania adresów zmiennych do granic (potêgi 2)\n";
    std::cout << "============================================================\n";

    test_alignment<char>("char");
    test_alignment<int>("int");
    test_alignment<float>("float");
    test_alignment<double>("double");
    test_alignment<__m128i>("__m128i (SSE)");
    test_alignment<__m256i>("__m256i (AVX)");



    std::cout << sizeof(tmpData) << std::endl;
    return 0;


}
