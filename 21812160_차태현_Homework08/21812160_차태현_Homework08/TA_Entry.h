#ifndef TA_H
#define TA_H

#include<iostream>
#include<iomanip>
#include"T_Entry.h"
#include<time.h>
#include<string>
#include<fstream>

using namespace std;

enum SortingDirection { INCREASING, DECREASING };

template<typename K>
class TA_Entry
{
public:
	TA_Entry(int n, string nm);//생성자
	~TA_Entry();//소멸자
	int size() { return num_elements; }//크기 반환
	bool empty() { return num_elements == 0; }//비었는가 확인
	string getName() { return name; }//이름 반환
	void reserve(int new_capcity);//확장
	void insert(int i, K element);//i번째 원소 삽입
	void remove(int i);//i번째 제거
	K& at(int i);//i번째 값 받아오기
	void set(int i, K& element);//값 설성
	K getMin(int begin, int end);//최소값 찾기
	K getMax(int begin, int end);//최대값 찾기
	void shuffle();//섞기
	int sequential_search(K search_key);//순차탐색
	int binary_search(K search_key);//이진탐색
	void selection_srot(SortingDirection sd);//선택정렬
	void quick_sort(SortingDirection sd);//퀵정렬
	void fprint(ofstream& fout, int elements_per_line);//출력
	void fprintSample(ofstream& fout, int elements_per_line, int num_sample_lines);//샘플출력
	bool isValidIndex(int i);//인덱스 범위에 있는지 판별
	K & operator[](int index) { return t_GA[index]; }//배열형태로 반환
protected:
	K* t_GA;
	int num_elements;//원소 수
	int capacity;//용량
	string name;//이름
};

template<typename K>
TA_Entry<K>::TA_Entry(int n, string nm)//생성자
{
	t_GA = (K*)new K[n];//동적할당

	//초기화
	capacity = n;
	name = nm;
	num_elements = 0;
}

template<typename K>
TA_Entry<K>::~TA_Entry()
{
	if (t_GA != NULL)
	{
		delete[] t_GA;//동적배열 존재시 반환
	}
}

template<typename K>
void TA_Entry<K>::reserve(int new_capacity)//용량확장
{
	if (capacity >= new_capacity)//기존용량이 더 클시
		return;
	K* t_newGA = (K*) new K[new_capacity];//동적생성
	cout << getName() << "expands capacity to" << setw(3) << new_capacity << endl;

	for (int i = 0; i < num_elements; i++)
	{
		t_newGA[i] = t_GA[i];//동적생성한 메모리에 원래의 값대입
	}
	delete[] t_GA;//이전의 반환
	t_GA = t_newGA;//새로 동적할당한 배열을 기존의 배열에 삽입
	capacity = new_capacity;//용량 변경

}
template<typename K>
bool TA_Entry<K>::isValidIndex(int index)
{
	if ((index >= 0) && (index <= num_elements))// index범위 판별
		return true;
	else
		return false;
}

template<typename K>
void TA_Entry<K>::insert(int i, K element)//삽입
{
	if (isValidIndex(i))
	{
		for (int j = num_elements - 1; j >= i; j--)
		{
			t_GA[j + 1] = t_GA[j];//i위치이후의 값들은 위치를 한자리씩 더해줌
		}
		t_GA[i] = element;//i번째에 원소삽입
		num_elements++;//총 크기 증가
	}

}

template<typename K>
void TA_Entry<K>::remove(int i)
{
	if (isValidIndex(i))
	{
		for (int j = i + 1; j < num_elements; j++)
		{
			t_GA[j - 1] = t_GA[j];//i자리부터 원래의자리에서 -1씩해줘서 대입
		}
		num_elements--;//크기 -1
	}
	if (num_elements < (capacity / 2))//크기가 용량의 반보다 적을경우
	{
		int new_capacity = capacity / 2;//새로운 용량생성
		K* t_newGA = (K*)new K[new_capacity];//동적할당

		for (int i = 0; i < num_elements; i++)
			t_newGA[i] = t_GA[i];//새로운 동적배열에 기존 값 대입

		delete[] t_GA;//기존배열 동적 반환
		t_GA = t_newGA;//기존배열에 새로운 동적배열 대입
		capacity = new_capacity;//용량 변경
	}
}

template<typename K>
K& TA_Entry<K>::at(int i)
{
	if (isValidIndex(i))//정상범위일시
		return t_GA[i];//i번째 값반환
}

template<typename K>
void TA_Entry<K>::set(int i, K& element)
{
	if (isValidIndex(i))//정상범위일시
		t_GA[i] = element;//i번째 element로 변경
}

template<typename K>
void TA_Entry<K>::shuffle()
{
	srand(time(NULL));
	int index1, index2;
	int rand1, rand2;

	for (int i = 0; i < num_elements; i++)
	{
		rand1 = rand();
		rand2 = rand();
		index1 = ((rand1 << 15) | rand2) % num_elements;//원소수 보다 작은 난수생성

		rand1 = rand();
		rand2 = rand();
		index2 = ((rand1 << 15) | rand2) % num_elements;//원소수 보다 작은 난수생성

		swap(t_GA[index1], t_GA[index2]);//위치 교환
	}
}
template<typename K>
K TA_Entry<K>::getMin(int begin, int end)
{
	K* min;

	min = t_GA[0];//초기설정
	for (int i = begin; i < end; i++)//전체를 반복
	{
		if (t_GA[i] < min)//최대값 찾기
			min = t_GA[i];
	}
	return min;//최소값 반환
}

template<typename K>
K TA_Entry<K>::getMax(int begin, int end)
{
	K* max;

	max = t_GA[0];//초기설정
	for (int i = begin; i < end; i++)//전체를 반복
	{
		if (t_GA[i] > max)//최대값 찾기
			max = t_GA[i];
	}
	return max;//최대값 반환
}

template<typename K>
int TA_Entry<K>::sequential_search(K search_key)
{
	for (int i = 0; i < num_elements; i++)
	{
		if (t_GA[i] == search_key)
			return i;//찾은경우 i 반환
	}
	return -1;//못 찾을 경우 -1반환
}

template<typename K>
int TA_Entry<K>::binary_search(K search_key)
{
	int low, mid, high, loop = 1;
	low = 0;
	high = num_elements - 1;

	while (low <= high)
	{
		cout << setw(2) << loop << "-th loop: current search range [" << setw(3) << low << "," << high << "]" << endl;

		mid = (low + high) / 2;//중간을 mid로 설정
		if (t_GA[mid] == search_key)//mid위치와 search_key값과 같을시 
			return mid;//위치반환
		else if (t_GA[mid] > search_key)//더 클경우 영역이 mid보다 더 낮은위치기때문에
			high = mid - 1;//high위치변경
		else
			low = mid + 1;//mid보다 더 큰위치의 영역에 있는경우
		loop++;//루프횟수 추가
	}
	return -1;
}

template<typename K>
void TA_Entry<K>::selection_srot(SortingDirection sd)
{
	int min_index, max_index;

	for (int i = 0; i < num_elements - 1; i++)
	{
		if (sd == INCREASING)
		{
			min_index = i;//최소위치 정의
			{
				for (int j = i + 1; j < num_elements; j++)
				{
					if (t_GA[j] < t_GA[min_index])//최소 값보다 더 작은 값일경우
					{
						min_index = j;
					}

				}
				if (min_index != i)//최소위치가 처음정의와 다른경우 위치교환
				{
					swap(t_GA[min_index], t_GA[i]);
				}
			}
		}

		else
		{
			max_index = i;
			{
				{
					for (int j = i + 1; j < num_elements; j++)
					{
						if (t_GA[i] > t_GA[max_index])//최대 값보다 더 큰 값일경우
						{
							max_index = j;
						}

					}
					if (max_index != i)//최대위치가 처음정의와 다른경우 위치교환
					{
						swap(t_GA[max_index], t_GA[i]);
					}
				}
			}
		}
	}
}

template<typename K>
int partition(K* array, int size, int left, int right, int pivotIndex, SortingDirection sd)
{
	int newpi;
	K pivotValue;

	pivotValue = array[pivotIndex];//기준값 설정

	swap(array[pivotIndex], array[right]);//기준위치와 맨오른쪽 위치 교환

	newpi = left;//초기newpi left로 설정

	for (int i = left; i <= right - 1; i++)
	{
		if (sd == INCREASING)//오름차순
		{
			if (array[i] <= pivotValue)
			{
				swap(array[i], array[newpi]);//i번째위치와 newpi의 위치를 교환
				newpi++;
			}
		}
		else
			if (array[i] > pivotValue)
			{
				swap(array[i], array[newpi]);//newpi위치로 이동
				newpi++;
			}

	}
	swap(array[newpi], array[right]);//오른쪽으로 보냈던 기준 값 newpi와 위치교환
}

template<typename K>
void _quick_sort(K* array, int size, int left, int right, SortingDirection sd)
{
	int pi, newpi;

	if (left >= right)
		return;
	else
		pi = (left + right) / 2;//기준값 설정

	newpi = partition(array, size, left, right, pi, sd);//파티션을통한 newpi 설정

	if (left < (newpi - 1))//왼쪽부분 시행
		quick_sort(array, size, left, newpi - 1, sd);
	if ((newpi + 1) < right)//오른쪽부분실행
		quick_sort(array, size, newpi + 1, right, sd);

}

template<typename K>
void TA_Entry<K>::quick_sort(SortingDirection sd)
{
	int pi, newpi;

	_quick_sort(t_GA, num_elements, 0, num_elements - 1, sd);
}

template<typename K>
void TA_Entry<K>::fprint(ofstream& fout, int elements_per_line)
{
	int count = 0;

	while (count < num_elements)//원소수 만큼 반복
	{
		for (int i = 0; i < elements_per_line; i++)//라인수 만큼출력
		{
			fout << t_GA[count] << " ";//출력
			count++;
			if (count % elements_per_line == 0)//라인 수만큼 출력 시 줄바꿈
				fout << endl;
		}
	}
	fout << endl;
}

template<typename K>
void TA_Entry<K>::fprintSample(ofstream& fout, int elements_per_line, int num_sample_lines)
{
	int count = 0;

	for (int i = 0; i < num_sample_lines; i++)//앞쪽 샘플출력
	{
		for (int j = 0; j < elements_per_line; j++)
		{
			fout << t_GA[count] << " ";
			count++;
			if (count % elements_per_line == 0)//라인 수만큼 출력 시 줄바꿈
				fout << endl;
		}
		fout << endl;
	}

	count = num_elements - (elements_per_line * num_sample_lines);//뒷쪽 샘플을 위한 count 재정의
	fout << " . . . . . " << endl;

	for (int i = count; i < num_elements; i++)//뒷쪽 샘플출력
	{
		for (int j = 0; j < elements_per_line; j++)
		{
			fout << t_GA[count] << " ";
			count++;
			if (count % elements_per_line == 0)//라인 수만큼 출력 시 줄바꿈
				fout << endl;
		}
		fout << endl;
	}
}
#endif