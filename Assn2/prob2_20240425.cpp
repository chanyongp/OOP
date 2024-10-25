#include <iostream>
#include <iomanip> //유효숫자
#include <cctype>  //문자 종류 판단하는 함수
#include <string>  //string 클래스

using namespace std;

// 노이즈 문자 : #, $, %, &, *
float noise_calc(string str) // 암호문에서 노이즈 비율을 계산하는 함수
{
    int noise_cnt = 0; // 노이즈 문자 수
    for (int i = 0; i < str.length(); i++)
    {
        // str의 인덱스 i에서의 요소가 노이즈 문자에 해당되는지 판단 후, 해당될 경우 노이즈 문자 수에 1을 더한다.
        if (str.at(i) == '#' || str.at(i) == '$' || str.at(i) == '%' || str.at(i) == '&' || str.at(i) == '*')
        {
            noise_cnt++;
        }
    }
    float noise_rate = float(noise_cnt) / str.length() * 100; // 노이즈 비율 = 노이즈 문자 수 / 총 문자 수 * 100
    return noise_rate;
}

void decoding(string str) // 암호문 해독 및 예외처리를 진행하는 함수
{
    string hex_digits; // 16진수 숫자들을 저장할 string
    for (int i = 0; i < str.length(); i++)
    {
        // str[i]가 숫자(0~9)이거나 대문자 알파벳이면 hex_digits의 맨 뒤에 붙인다.
        if (isdigit(str[i]) || (isxdigit(str[i]) && isupper(str[i])))
        {
            hex_digits.push_back(str[i]);
        }
    }
    if (hex_digits.length() == 0) // 16진수가 str에 없을 경우(for문 거쳐도 hex_digits 길이 == 0) 암호문 출력 없이 예외 처리한다.
    {
        cout << "Undecryptable: where are the hexadecimal digits!" << endl;
        return;
    }
    else if (hex_digits.length() % 2 != 0) // 16진수 숫자의 개수가 홀수일 경우 암호문 출력 후 예외 처리한다.
    {
        cout << "Hexadecimal digits: " << hex_digits << endl;
        cout << "Undecryptable: the number of hexadecimal digits is odd!" << endl;
        return;
    }
    cout << "Hexadecimal digits: " << hex_digits << endl; // 16진수 숫자에 해당되는 문자들의 문자열

    string result; // 해독된 암호문을 저장할 string

    for (int j = 0; j < hex_digits.length(); j += 2)
    {
        string temp = hex_digits.substr(j, 2);         // index가 j인 부분부터 두개의 문자를 temp에 assign한다.
        int dec = int(strtol(temp.c_str(), NULL, 16)); // 16진수, string인 temp를 10진수 정수, const char*로 변환한다.
        // 2개씩 묶은 문자들을 정수로 변환한 것이 ASCII TABLE 범위 밖일 경우 예외 처리한다.
        if (dec < 0 || dec > 127)
        {
            cout << "Undecryptable: invalid hexadecimal digits pair!" << endl;
            return;
        }
        result.push_back(char(dec)); // char로 변환하여 result의 맨 뒤에 붙인다.
    }
    cout << "Decryption result: " << result << endl; // 모든 예외처리에 해당되지 않을 경우 해독된 암호문을 출력한다.
}

int main()
{
    cout << "Enter a cyphertext" << endl;
    string line;       // 한 줄씩 입력받을 때 사용할 string
    string cyphertext; // 암호문

    while (true)
    {
        getline(cin, line);      // 입력 스트림 cin에서 문자를 읽어 line에 저장. 구분 문자는 '\n'
        cyphertext.append(line); // 암호문에 line을 추가한다.
        // 만일 line이 ..으로 끝나면 반복문에서 빠져나온다.
        int linelength = line.size();
        if (line.at(linelength - 1) == '.' && line.at(linelength - 2) == '.')
            break;
        cyphertext.append("\n"); // 암호문에 개행문자를 추가한다.
    }
    cout << "Ciphertext noise rate: " << setprecision(5) << noise_calc(cyphertext) << "%" << endl; // 유효숫자 5자리로 노이즈 비율을 출력한다.
    decoding(cyphertext);                                                                          // 암호문 해독을 진행한다.

    cout << "Decryptor turn off!"; // 노이즈 비율과 해독 결과 출력을 마치고 종료한다.
    return 0;
}