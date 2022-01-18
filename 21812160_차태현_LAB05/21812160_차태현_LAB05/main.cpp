/**
*파일이름"21812160_차태현_LAB05 "
*프로그램의 목적 및 기본 기능:
*  클래스를 상속받아 학생정보 출력.
*
*프로그램 작성자: 21812160 차태현(2021년 09월29일),
*최종 수정 및 보완: 2021년 9월 29일 (차태현)
*/
#include <iostream>
#include <fstream>
#include <string>
#include<time.h>
#include "StudentArray.h"
#define NUM_STUDENTS 10 //학생 수설정
int main()
{
    srand(time(0));
    
    StudentArray studentArray(NUM_STUDENTS);//객체를 배열로 생성
    Student st;
    ofstream fout;
    int st_ids[NUM_STUDENTS];//학번을 저장공간
    fout.open("output.txt");//파일열기
   
    genST_ids(NUM_STUDENTS, st_ids);//랜덤학번 생성
    fout << "Initializing student array (num_students: " << NUM_STUDENTS << ")" << endl;
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        st = genRandStudent(st_ids[i]);//학생정보 랜덤생성
        studentArray[i] = st;//학생정보저장
    }
    fout << studentArray;//학생정보 출력
  
    fout << "\nSorting studentArray by student id : " << endl;
    studentArray.sortBy_ST_ID();//학번순으로 정렬
    fout << studentArray;
   
    fout << "\nSorting studentArray by student name : " << endl;
    studentArray.sortByName();//이름순으로 정렬
    fout << studentArray;
    
    fout << "\nSorting studentArray by GPA : " << endl;
    studentArray.sortByGPA();//학점순으로 정렬
    fout << studentArray;
   
    fout << "\nSorting studentArray by BirthDate : " << endl;
    studentArray.sortByBirthDate();//생일 순으로정렬
    fout << studentArray;
    
    fout << endl;
    fout.close();//파일 닫기
}