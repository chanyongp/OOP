#include <iostream>
#include <iomanip> //유효숫자
#include <cstring> //c-style string
#include <cmath>   //pow(), sqrt() 함수
using namespace std;
// 구조체를 student_info로 부르기 위해 typedef를 사용한다.
typedef struct student_info // 학생 정보 구조체
{
    int id;                 // 학번
    char name[11];          // 이름
    int midterm_exam_score; // 중간고사 점수
    int final_exam_score;   // 기말고사 점수
    short retake;           // 재수강 여부
} student_info;

int alphabet_exist(char name[11]) // 이름이 알파벳으로만 구성되는지 판별하는 함수
{
    for (int i = 0; i < strlen(name); i++)
    {
        int num_distinguish = name[i] - '0'; // 0~9에 해당하는 숫자인지 판별하는데 사용
        // a~z 또는 A~Z에 포항되지 않거나 이름에 숫자 들어갔을때 0 반환
        if (!((int(name[i]) >= 41 && int(name[i]) <= 90) || (int(name[i]) >= 97 && int(name[i]) <= 122)) || ((num_distinguish >= 0) && (num_distinguish <= 9)))
            return 0;
    }
    // 위 조건에 해당되지 않을 경우, 즉 알파벳으로만 구성될 경우 1 반환
    return 1;
}
int find_index(student_info *list, int student_num, int target) // list에서 id값이 target일때의 인덱스를 반환하는 함수
{
    for (int i = 0; i < student_num; i++)
    {
        // list의 인덱스 i에서의 id값이 target과 같다면 인덱스 i 반환
        if (list[i].id == target)
        {
            return i;
        }
    }
    // target이 없을 경우 -1 반환
    return -1;
}

float avg_score(student_info *list, int student_num) // 평균 점수 계산하는 함수
{
    int sum = 0; // 학생 점수 총합

    for (int i = 0; i < student_num; i++)
    {
        // 각 학생의 중간고사, 기말고사 점수 더하기
        sum += list[i].midterm_exam_score;
        sum += list[i].final_exam_score;
    }
    float avg = sum / student_num; // 평균 = 학생 점수 총합 / 전체 학생 수
    return avg;
}

float std_deviation(student_info *list, int student_num) // 표준편차 계산하는 함수
{
    int sum = 0; // 학생 점수 총합
    for (int i = 0; i < student_num; i++)
    {
        // 각 학생의 중간고사, 기말고사 점수 더하기
        sum += list[i].midterm_exam_score;
        sum += list[i].final_exam_score;
    }
    int avg = sum / student_num; // 평균 = 학생 점수 총합 / 전체 학생 수
    float process_stdiv = 0;     // 표준편차 계산 시 사용할 편차의 제곱의 합
    for (int i = 0; i < student_num; i++)
    {
        // 편차의 제곱(각 학생의 점수 총합에 평균을 빼고 제곱한 것)을 process_stdiv에 더한다.
        process_stdiv += pow(list[i].midterm_exam_score + list[i].final_exam_score - avg, 2);
    }
    float stdiv = sqrt(process_stdiv / student_num); // 표준편차 = (편차의 제곱의 함 / 전체 학생 수)의 제곱근
    return stdiv;
}
// list1, list2에 해당하는 값들을 parameter로 받는다.
void swap(student_info *list1, student_info *list2) // 두 구조체 요소 상호교환하는 함수
{
    student_info temp;
    // 임시로 선언한 구조체 temp 이용해서 list1, list2 요소값 교환
    temp = *list1;
    *list1 = *list2;
    *list2 = temp;
}

// mutable하기 때문에 정렬시 main 함수 내의 list에 적용된다.
void Bubble_sort(student_info *list, int student_num) // 버블정렬 알고리즘으로 총 점수는 내림차순으로, 같을 경우 학번은 오름차순으로 정렬하는 함수
{
    // 내림차순 정렬
    for (int i = 0; i < student_num; i++)
    {
        for (int j = 0; j < student_num - 1 - i; j++)
        {
            if ((list[j].midterm_exam_score + list[j].final_exam_score) < (list[j + 1].midterm_exam_score + list[j + 1].final_exam_score))
            {
                swap(&list[j + 1], &list[j]); // list[j + 1]와 list[j] 주소값 전달해서 각 요소값 교환
            }
            // 점수 같을 시 학번 기준 오름차순 정렬
            else if (((list[j].midterm_exam_score + list[j].final_exam_score) == (list[j + 1].midterm_exam_score + list[j + 1].final_exam_score)) && (list[j].id > list[j + 1].id))
            {
                swap(&list[j + 1], &list[j]); // list[j + 1]와 list[j] 주소값 전달해서 각 요소값 교환
            }
        }
    }
}

// cf) 학생 순서에 규칙은 없고, 동점자는 없다.
// 시행 전에 코드 상에서 먼저 list에 관해 Bubble_sort 진행
void grade_distinguish(student_info *list, int student_num) // 등급 판별해서 출력하는 함수
{
    for (int i = 0; i < student_num; i++)
    {
        // 총점이 150점 초과이고, 재수강하지 않으며, (총점이 상위 30% 이내 또는 (학생 수 * 30%가 1 미만일때 1등))이면 A
        if ((list[i].midterm_exam_score + list[i].final_exam_score > 150) && list[i].retake == 0 && ((i + 1) <= 0.3 * student_num || (0.3 * student_num < 1 && (i + 1) == 1)))
        {
            std::cout << list[i].id << " " << list[i].name << " " << (list[i].midterm_exam_score + list[i].final_exam_score) << " " << list[i].retake << " A" << endl;
        }
        // 총점이 150점 초과이고, 재수강하며, (총점이 상위 30% 이내 또는 (학생 수 * 30%가 1 미만일때 1등))이면 B
        else if ((list[i].midterm_exam_score + list[i].final_exam_score > 150) && list[i].retake == 1 && ((i + 1) <= 0.3 * student_num || (0.3 * student_num < 1 && (i + 1) == 1)))
        {
            std::cout << list[i].id << " " << list[i].name << " " << (list[i].midterm_exam_score + list[i].final_exam_score) << " " << list[i].retake << " B" << endl;
        }
        // 총점이 100점 초과이고, 재수강하지 않으며, (총점이 상위 70% 이내 또는 (학생 수 * 70%가 2 미만일때 2등))이면 B
        else if ((list[i].midterm_exam_score + list[i].final_exam_score > 100) && list[i].retake == 0 && ((i + 1) <= 0.7 * student_num || (0.7 * student_num < 2 && (i + 1) == 2)))
        {
            std::cout << list[i].id << " " << list[i].name << " " << (list[i].midterm_exam_score + list[i].final_exam_score) << " " << list[i].retake << " B" << endl;
        }
        // 총점이 100점 초과이고, 재수강하며, (총점이 상위 70% 이내 또는 (학생 수 * 70%가 2 미만일때 2등))이면 C
        else if ((list[i].midterm_exam_score + list[i].final_exam_score > 100) && list[i].retake == 1 && ((i + 1) <= 0.7 * student_num || (0.7 * student_num < 2 && (i + 1) == 2)))
        {
            std::cout << list[i].id << " " << list[i].name << " " << (list[i].midterm_exam_score + list[i].final_exam_score) << " " << list[i].retake << " C" << endl;
        }
        // 총점이 50점 초과이고, 재수강하지 않으며, (총점이 상위 90% 이내 또는 (학생 수 * 90%가 3 미만일때 3등))이면 C
        else if ((list[i].midterm_exam_score + list[i].final_exam_score > 50) && list[i].retake == 0 && ((i + 1) <= 0.9 * student_num || (0.9 * student_num < 3 && (i + 1) == 3)))
        {
            std::cout << list[i].id << " " << list[i].name << " " << (list[i].midterm_exam_score + list[i].final_exam_score) << " " << list[i].retake << " C" << endl;
        }
        // A, B, C 그 무엇도 받지 못할 경우 D
        else
        {
            std::cout << list[i].id << " " << list[i].name << " " << (list[i].midterm_exam_score + list[i].final_exam_score) << " " << list[i].retake << " D" << endl;
        }
    }
}

int main()
{
    student_info list[100]; // 구조체 배열 100명 크기로 선언
    int student_num = 0;    // 학생 수
    while (true)
    {
        int menu_num; // 메뉴 번호
        // 구조체 요소 값을 임시로 입력받아 저장해둘 변수 선언
        int temp_id;
        char temp_name[11];
        int temp_midterm_exam_score;
        int temp_final_exam_score;
        short temp_retake;
        std::cout << "----------MENU----------\n";
        std::cout << "1. Add a student" << endl;
        std::cout << "2. Edit the score of a student" << endl;
        std::cout << "3. Print aveage score" << endl;
        std::cout << "4. Print scores list" << endl;
        std::cout << "5. Pring grades list" << endl;
        std::cout << "6. Exit" << endl;
        std::cout << "------------------------\n";
        std::cout << "Selection: ";
        std::cin >> menu_num; // 메뉴 번호 입력

        if (menu_num == 1) // 메뉴 번호가 1일 경우
        {
            // list[student_num] = new student_info; // 구조체 할당
            std::cout << "Student id: ";
            std::cin >> temp_id; // 학번 임시로 입력
            // 만약 temp_id가 8자리 양의 정수가 아니면 while문 처음으로 돌아간다.
            if (!(temp_id > 9999999 && temp_id < 100000000))
            {
                std::cout << "Failed to add: invalid student id!" << endl;
                continue;
            }
            std::cout << "Name: ";
            std::cin >> temp_name; // 이름 임시로 입력
            // 만약 temp_name 글자 수가 10을 넘어서거나 alphabet_exist 함수에서 알파벳이 아닌 문자가 포함되어 있다고 판별할 경우 while문 처음으로 돌아간다.
            if ((strlen(temp_name) > 10) || alphabet_exist(temp_name) == 0)
            {
                std::cout << "Failed to add: invalid name!" << endl;
                continue;
            }
            std::cout << "Midterm exam score: ";
            std::cin >> temp_midterm_exam_score; // 중간고사 점수 임시로 입력
            // 중간고사 점수의 범위가 0~100이 아닐 경우 while문 처음으로 돌아간다.
            if (!(temp_midterm_exam_score >= 0 && temp_midterm_exam_score <= 100))
            {
                std::cout << "Failed to add: invalid midterm exam score!" << endl;
                continue;
            }
            std::cout << "Final exam score: ";
            std::cin >> temp_final_exam_score; // 기말고사 점수 임시로 입력
            // 기말고사 점수의 범위가 0~100이 아닐 경우 while문 처음으로 돌아간다.
            if (!(temp_final_exam_score >= 0 && temp_final_exam_score <= 100))
            {
                std::cout << "Failed to add: invalid final exam score!" << endl;
                continue;
            }
            std::cout << "Retake: ";
            std::cin >> temp_retake; // 재수강 여부 임시로 입력
            // temp_retake값이 0 또는 1이 아니라면 while문 처음으로 돌아간다.
            if (!(temp_retake == 0 || temp_retake == 1))
            {
                std::cout << "Failed to add: invalid retake value!" << endl;
                continue;
            }
            // 위 조건 모두 만족시 임시로 저장해둔 요소값들을 구조체 배열에 assign한다.
            list[student_num].id = temp_id;
            strcpy(list[student_num].name, temp_name);
            list[student_num].midterm_exam_score = temp_midterm_exam_score;
            list[student_num].final_exam_score = temp_final_exam_score;
            list[student_num].retake = temp_retake;
            std::cout << "The student is added!" << endl;

            student_num++; // 학생 수를 1명 증가시킨다.
            continue;      // while문 처음으로 돌아간다.
        }
        else if (menu_num == 2) // 메뉴 번호가 2일 경우
        {
            std::cout << "--------Function--------\n";
            std::cout << "1. Edit the midterm exam score" << endl;
            std::cout << "2. Edit the final exam score" << endl;
            std::cout << "------------------------\n";
            int menu2_num; // 중간, 기말고사 중 하나 수정할 수 있도록 메뉴 번호 추가로 선언
            std::cout << "Selection: ";
            std::cin >> menu2_num; // 메뉴 번호 입력
            std::cout << "Student id: ";
            std::cin >> temp_id; // 학번 임시로 입력
            // 학번이 8자리 양의 정수가 아닌 경우 while문 처음으로 돌아간다.
            if (!(temp_id > 9999999 && temp_id < 100000000))
            {
                std::cout << "Failed to add: invalid student id!" << endl;
                continue;
            }
            // temp_id와 일치하는 학번이 있다면 인덱스를 얻어오도록 find_index를 student_index에 assign한다.
            int student_index = find_index(list, student_num, temp_id);
            // 일치하는 학번이 존재할 경우
            if (student_index != -1)
            {
                std::cout << "Score: ";
                // 메뉴 번호가 1번이면 임시로 중간고사 점수 값을 입력받는다.
                if (menu2_num == 1)
                {
                    std::cin >> temp_midterm_exam_score;
                    // 중간고사 점수 값의 범위가 0~100이 아닌 경우 중단하고 while문 처음으로 돌아간다.
                    if (!(temp_final_exam_score >= 0 && temp_midterm_exam_score <= 100))
                    {
                        std::cout << "Failed to add: invalid exam score!" << endl;
                        continue;
                    }
                    // 조건 만족시 구조체 배열 값에 임시 점수 값을 할당시킨다.
                    list[student_index].midterm_exam_score = temp_midterm_exam_score;
                }
                // 메뉴 번호가 2번이면 임시로 기말고사 점수 값을 입력받는다.
                else if (menu2_num == 2)
                {
                    std::cin >> temp_final_exam_score;
                    // 기말고사 점수 값의 범위가 0~100이 아닌 경우 중단하고 while문 처음으로 돌아간다.
                    if (!(temp_final_exam_score >= 0 && temp_final_exam_score <= 100))
                    {
                        std::cout << "Failed to add: invalid exam score!" << endl;
                        continue;
                    }
                    // 조건 만족시 구조체 배열 값에 임시 점수 값을 할당시킨다.
                    list[student_index].final_exam_score = temp_final_exam_score;
                }
                std::cout << "Score edinting done!\n";
                continue;
            }
            // 일치하는 학번이 없을 경우 중단하고 while문 처음으로 돌아간다.
            else
            {
                std::cout << "Can't find the student id: " << temp_id << endl;
                continue;
            }
        }
        else if (menu_num == 3) // 메뉴 번호가 3일 경우
        {
            // 학생 수가 0일 경우 각각 0을 출력한다.
            if (student_num == 0)
            {
                std::cout << "Average score: 0" << endl;
                std::cout << "Standard deviation: 0" << endl;
            }
            // 학생 수가 0이 아닐 경우 유효숫자 5자리로 avg_score, std_deviation을 이용해서 평균, 표준편차를 출력한다.
            else
            {
                std::cout << "Average score: " << setprecision(5) << avg_score(list, student_num) << endl;
                std::cout << "Standard deviation: " << setprecision(5) << std_deviation(list, student_num) << endl;
            }
        }
        else if (menu_num == 4) // 메뉴 번호가 4일 경우
        {
            Bubble_sort(list, student_num); // 학생 정보을 담은 구조체 배열을 총 점수 기준 내림차순으로, 같을 경우 학번 기준 오름차순으로 정렬한다.
            // 정렬한 배열을 출력한다.
            for (int i = 0; i < student_num; i++)
            {
                std::cout << list[i].id << " " << list[i].name << " " << list[i].midterm_exam_score << " " << list[i].final_exam_score << " " << (list[i].midterm_exam_score + list[i].final_exam_score) << endl;
            }
            std::cout << "Finished printing the list!" << endl;
        }
        else if (menu_num == 5) // 메뉴 번호가 5일 경우
        {
            Bubble_sort(list, student_num);       // 학생 정보을 담은 구조체 배열을 총 점수 기준 내림차순으로, 같을 경우 학번 기준 오름차순으로 정렬한다.
            grade_distinguish(list, student_num); // 정렬한 배열을 기준으로 grade_distinguish를 이용해 등급표를 출력한다.
            std::cout << "Finished printing the list!" << endl;
        }
        else if (menu_num == 6) // 메뉴 번호가 6일 경우
        {
            std::cout << "Good Bye!";
            break; // while문에서 빠져나온다.
        }
    }

    return 0;
}
