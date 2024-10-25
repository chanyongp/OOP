#include <iostream>

using namespace std;

int main()
{
    char name[100];                  // 영어로 된 이름
    int birth_year;                  // 태어난 연도
    int student_id;                  // 학번
    scanf("%s", name);               // 이름 입력
    cin >> birth_year >> student_id; // 띄어쓰기 기준으로 연도, 학번 입력

    cout << "My name is " << name << "." << endl;                      // name 변수 출력하고 한 줄 띄움
    cout << "I am " << 2024 - birth_year + 1 << " years old." << endl; // birth_year 변수 이용하여 한국식 나이 출력 후 한 줄 띄움
    cout << "My student ID is " << student_id << "." << endl;          // student_id 변수 출력 후 한 줄 띄우고 0 반환
    return 0;
}