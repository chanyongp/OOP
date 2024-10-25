#include <iostream>
#include <string> // 자료형 string 사용 가능하게 하는 라이브러리

using namespace std;

int calc(char a, char b) // 두 문자를 아스키코드로 정수로 변환 후 더하고, 일의 자리만 가져오는 함수
{
    return (int(a) + int(b)) % 10;
}

int main()
{
    string name1, name2;   // 두 글자로 된 이름 2개
    cin >> name1 >> name2; // 이름 2개 입력

    cout << name1.at(0) << " " << name2.at(0) << " " << name1.at(1) << " " << name2.at(1) << endl;                                                                       // 이니셜 교차 후 출력
    cout << calc(name1.at(0), 0) << " " << calc(name2.at(0), 0) << " " << calc(name1.at(1), 0) << " " << calc(name2.at(1), 0) << endl;                                   // 각 이니셜 아스키코드로 정수로 변환 후 출력
    cout << calc(name1.at(0), name2.at(0)) << " " << calc(name2.at(0), name1.at(1)) << " " << calc(name1.at(1), name2.at(1)) << endl;                                    // 문자 변환 후 이웃한 숫자끼리 더한 것 출력
    cout << calc(calc(name1.at(0), name2.at(0)), calc(name2.at(0), name1.at(1))) << " " << calc(calc(name2.at(0), name1.at(1)), calc(name1.at(1), name2.at(1))) << endl; // 위에서 얻은 숫자 중 이웃한 숫자끼리 더한 것 출력

    unsigned short answer = calc(calc(name1.at(0), name2.at(0)), calc(name2.at(0), name1.at(1))) * 10 + calc(calc(name2.at(0), name1.at(1)), calc(name1.at(1), name2.at(1))); // 두 숫자를 두 자리 수로 변환해서 저장
    unsigned short during_answer = answer - 1;                                                                                                                                // unsigned short형을 이용하여 0에서 1을 뺐을때 integer underflow 일어나게 함
    cout << "The chemistry between " << name1
         << " and " << name2
         << " is "
         << during_answer * 100 / 65535 + answer
         << "%." << endl;
    /*
    나누기 연산자 성질 이용하여 during_answer가 65535가 아닌 값들은 0이 되게 계산,
    최종적으로 두 수가 각각 0이면 100, 이외에는 answer가 나온다.
    */
    return 0;
}