#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
template <typename T>
void update_scale(T &m1, T &m2, T m3 = 10);
void print_real(float number, int fieldspace, int precision);
int main(void)
{
    float a, b;
    cout << " Please input two real numbers";
    cin >> a >> b;

    print_real(a, 7, 3);
    print_real(b, 7, 3);

    // call the function update_scale with ONLY the actual parameters a  and b

    cout << "After using update_scale: " << endl;
    update_scale(a, b);

    print_real(a, 7, 3);
    print_real(b, 7, 3);
}

/* complete the body of the function */
void print_real(float number, int fieldspace, int precision)
{
    cout << setprecision(precision) << setw(fieldspace) << number << endl;
}
// add the function defintion (header+body) of the template function update_scale
template <typename T>
void update_scale(T &m1, T &m2, T m3)
{
    T temp_m1 = m1;           // Store original value of m1 for the calculations
    m1 = (m1 + m2) * m3;      // updating m1 by adding m1 and m2 and multiplying sum by m3
    m2 = (temp_m1 - m2) * m3; // updating m2 by subtracting original values of m1 and m2 and multiplying the difference by m3
    cout << "new m1 is:" << m1 << endl;
    cout << "new m2 is:" << m2 << endl;
}