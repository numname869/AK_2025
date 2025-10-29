
#include <iostream>
#include <iostream> 
#include <bitset> 
#include <limits> 
#include <iomanip> 
#include <vector>
#include <algorithm>
#include <cmath>
#include "Data.h"
#include <fstream>
#include <vector>
#include <string>
// systemy liczbiowe adytywne





template<typename T>
void show_32_bits(T tmp) {
    const unsigned int tmpSize = 32;
    unsigned long int bits = *(unsigned long int*)(&tmp);
    std::bitset<tmpSize> tmpBits(bits);
    std::cout << tmpBits << "\t" << tmpSize << " bits" << "\t"
        << std::fixed << std::setprecision(20) << tmp << std::endl;
}

template<typename T>
void show_64_bits(T tmp) {
    const unsigned int tmpSize = 64;
    unsigned long long int bits = *(unsigned long long int*)(&tmp);
    std::bitset<tmpSize> tmpBits(bits);
    std::cout << tmpBits << "\t" << tmpSize << " bits" << "\t"
        << std::fixed << std::setprecision(20) << tmp << std::endl;
}

bool sum_and_compare(double a, double b, double expected, double epsilon = 1e-10) {
    double sum = a + b;
    std::cout << "a = "; show_64_bits(a);
    std::cout << "b = "; show_64_bits(b);
    std::cout << "sum = "; show_64_bits(sum);
    std::cout << "expected = "; show_64_bits(expected);

    double absError = std::fabs(sum - expected);
    std::cout << "Absolute error = " << std::setprecision(20) << absError << std::endl;

    return absError < epsilon;
}

void sum_loop_example_double(int iterations = 100) {
    double suma = 0.0;
    double oczekiwanaWartosc = 0.1 * iterations;

    std::cout << "\n--- Pêtla sumowania 0.1 " << iterations << " razy ---\n";
    for (int i = 0; i < iterations; i++) {
        suma += 0.1;
        double roznica = std::abs(suma - 0.1 * (i + 1));
        std::cout << "Iteracja " << i + 1 << ": suma = " << std::setprecision(20) << suma
            << ", oczekiwana = " << 0.1 * (i + 1)
            << ", ró¿nica = " << roznica << std::endl;
    }
}

void sum_loop_example_float(int iterations = 100) {
    float suma = 0.0;
    float oczekiwanaWartosc = 0.1 * iterations;

    std::cout << "\n--- Pêtla sumowania 0.1 " << iterations << " razy ---\n";
    for (int i = 0; i < iterations; i++) {
        suma += 0.1;
        double roznica = std::abs(suma - 0.1 * (i + 1));
        std::cout << "Iteracja " << i + 1 << ": suma = " << std::setprecision(20) << suma
            << ", oczekiwana = " << 0.1 * (i + 1)
            << ", ró¿nica = " << roznica << std::endl;
    }
}


double eval(const std::vector<double>& nums) {
    double sum = 0.0;
    for (double v : nums) sum += v;
    return sum;
}

void AllPermutationsRecursive(int k, std::vector<int>& idx, std::vector<double> x, std::ofstream& file)
{
    if (k == 1)
    {
        for (int v : idx) std::cout << "x" << v << " ";
        double sum = 0.0;
		for (int v : idx) sum += x[v];
	  std::cout << sum << " ";
        
        double errorAbs = std::fabs(sum - (double)exact);
        std::cout << errorAbs << " ";
        std::cout << "\n";

        Result r;
		for (int v : idx) r.perm.push_back(x[v]);
		r.approx = sum;
        r.errorAbs = errorAbs;
        results.push_back(r);

        file << "\"";  
        for (size_t i = 0; i < idx.size(); i++) {
            file << "x"<< idx[i] + 1;
            if (i != idx.size() - 1) file << " ";
        }
        file << "\"," << r.approx << "," << r.errorAbs << "\n";
	}
	else
    {
        AllPermutationsRecursive(k - 1, idx, x, file);

			for (int i = 0; i < k - 1; i++)
			{
				if (k % 2 == 0) std::swap(const_cast<int&>(idx[i]), const_cast<int&>(idx[k - 1]));
				else std::swap(const_cast<int&>(idx[0]), const_cast<int&>(idx[k - 1]));
				AllPermutationsRecursive(k - 1, idx, x, file);
			}
    }

}

void ToBinary(int n, int Decimal)
{
	int binaryNum[32];

}

int main()
{

    int a = -91; // Przyk³adowa zmienna typu int.
    show_32_bits(a); // Wywo³anie funkcji show_32_bits zmienn¹ a.
    int b = 91; // Przyk³adowa zmienna typu int.
    show_32_bits(b); // Wywo³anie funkcji show_32_bits zmienn¹ b.
    int c = std::numeric_limits<int>::min(); // Pobranie minimalnej wartoœci typu int.
    show_32_bits(c); // Wywo³anie funkcji show_32_bits zmienn¹ c.
    int d = std::numeric_limits<int>::max(); // Pobranie maksymalnej wartoœci typu int.
    show_32_bits(d); // Wywo³anie funkcji show_32_bits zmienn¹ d.
    double e = -100; // Przyk³adowa zmienna typu double.
    show_64_bits(e); // Wywo³anie funkcji show_64_bits zmienn¹ e.
    double f = std::numeric_limits<double>::max(); // Pobranie maksymalnej wartoœci typu double.
    show_64_bits(f); // Wywo³anie funkcji show_64_bits zmienn¹ f.
    std::cout << std::setprecision(20);

    std::cout << "Int\n";
    std::cout << "Min : " << std::numeric_limits<int>::min() << "\n";
    std::cout << "Max: " << std::numeric_limits<int>::max() << "\n\n";

    std::cout << std::scientific << std::setprecision(6); // notacja naukowa

    std::cout << "Float\n";
    std::cout << "Min : " << -std::numeric_limits<float>::max() << "\n";
    std::cout << "Max: " << std::numeric_limits<float>::max() << "\n\n";

    std::cout << "Double\n";
    std::cout << "Min : " << -std::numeric_limits<double>::max() << "\n";
    std::cout << "Max: " << std::numeric_limits<double>::max() << "\n\n";

    std::cout << "Long Double\n";
    std::cout << "Min : " << -std::numeric_limits<long double>::max() << "\n";
    std::cout << "Max: " << std::numeric_limits<long double>::max() << "\n";

    //sum_loop_example_double();
    sum_loop_example_float();


    std::ofstream file("results.csv");
    file << "Permutation,ErrorAbs\n";
	AllPermutationsRecursive(5, idx, x, file);
    file.close();
    return 0;



}
