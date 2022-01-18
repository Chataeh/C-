/**
*�����̸�"21812160_������_LAB05 "
*���α׷��� ���� �� �⺻ ���:
*  Ŭ������ ��ӹ޾� �л����� ���.
*
*���α׷� �ۼ���: 21812160 ������(2021�� 09��29��),
*���� ���� �� ����: 2021�� 9�� 29�� (������)
*/
#include <iostream>
#include <fstream>
#include <string>
#include<time.h>
#include "StudentArray.h"
#define NUM_STUDENTS 10 //�л� ������
int main()
{
    srand(time(0));
    
    StudentArray studentArray(NUM_STUDENTS);//��ü�� �迭�� ����
    Student st;
    ofstream fout;
    int st_ids[NUM_STUDENTS];//�й��� �������
    fout.open("output.txt");//���Ͽ���
   
    genST_ids(NUM_STUDENTS, st_ids);//�����й� ����
    fout << "Initializing student array (num_students: " << NUM_STUDENTS << ")" << endl;
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        st = genRandStudent(st_ids[i]);//�л����� ��������
        studentArray[i] = st;//�л���������
    }
    fout << studentArray;//�л����� ���
  
    fout << "\nSorting studentArray by student id : " << endl;
    studentArray.sortBy_ST_ID();//�й������� ����
    fout << studentArray;
   
    fout << "\nSorting studentArray by student name : " << endl;
    studentArray.sortByName();//�̸������� ����
    fout << studentArray;
    
    fout << "\nSorting studentArray by GPA : " << endl;
    studentArray.sortByGPA();//���������� ����
    fout << studentArray;
   
    fout << "\nSorting studentArray by BirthDate : " << endl;
    studentArray.sortByBirthDate();//���� ����������
    fout << studentArray;
    
    fout << endl;
    fout.close();//���� �ݱ�
}