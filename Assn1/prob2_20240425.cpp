#include <iostream>
#include <iomanip> //setprecision 포함하는 라이브러리
using namespace std;

double exact(double x) // x^2 정확한 값 계산하는 함수
{
    return x * x;
}

double approximate(double x0, double x, double h) // 테일러 전개를 이용한 x^2 근사값 계산하는 함수
{
    return x0 * x0 + (((x0 + h) * (x0 + h) - x0 * x0) / h) * (x - x0);
}

int main()
{
    double x0, x, h;
    cin >> x0 >> x >> h; // 띄어쓰기 기준으로 x0, x, h 입력받음

    cout << "Exact answer is " << setprecision(5) << exact(x) << endl;            // 유효숫자 5자리 내로 정확한 값 계산
    cout << "Approximate answer is " << setprecision(5) << approximate(x0, x, h); // 유효숫자 5자리 내로 근사값 계산
    return 0;
}
