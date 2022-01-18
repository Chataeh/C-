#ifndef T_A_H
#define T_A_H
#include<iomanip>
#include"Time.h"
#include"T_Array.h"
#include<time.h>

enum SortingOrder { INCREASING, DECREASING};

template<typename T>
class T_Array//클래스 템플릿
{
public:
	T_Array(int n, string nm);//생성자
	~T_Array();//소멸자
	string getName() { return name; }//이름 반환
	void reserve(int new_capacity);//확장
	void insert(int i, T element);//삽입
	void remove(int i);//제거
	void shuffle();//위치 섞기
	T& at(int i);//인수 반환
	void set(int i, T& elemnet);//i번째 값 변경
	void selection_sort(SortingOrder sortOrder);//선택정렬
	void fprint(ostream& fout,int elements_per_line);//줄 수만큼 출력
	bool isValidIndex(int i);//인덱스 범위에 있는지 판별
	T& operator[](int index) { return t_array[index]; }//배열형태로 관리
	void quick_sort( SortingOrder sortOrder);//퀵정렬
	void _mergeSrot(T* array, T* temp_array, int left, int right,  SortingOrder sortOrder);
	void mergeSort( SortingOrder sortOrder);//병합정렬
private:
	T* t_array;
	int num_elements;//원소 수
	int capacity;//용량
	string name;
};

template <typename T>//템플릿 설정

T_Array<T>::T_Array(int new_capacity, string nm)//생성자
{
	t_array = (T*)new T[new_capacity];//주어진 크기에 대한 동적배열생성

	//초기화
	capacity = new_capacity;
	num_elements = 0;
	name = nm;
}

template <typename T>//템플릿 설정
T_Array<T>::~T_Array()//소멸자
{
	if (t_array != NULL)
	{
		delete[] t_array; //동적생성을 했기에 반환
	}
}

template <typename T>//템플릿 설정
bool T_Array<T>::isValidIndex(int index)
{
	if ((index >= 0) && (index <= num_elements))
		return true;
	else
		return false;
}

template <typename T>//템플릿 설정
void T_Array<T>::reserve(int new_capacity)//확장
{
	if (capacity >= new_capacity)
		return;//충분히 큰용량
	T* t_newGA = (T*) new T[new_capacity];//동적할당
	cout << getName() << "expands capacity to" << setw(3) << new_capacity << endl;

	for (int i = 0; i < num_elements; i++)
		t_newGA[i] = t_array[i];//확장한 배열에 재할당

	delete[] t_array;
	t_array = t_newGA;
	capacity = new_capacity;
}

template <typename T>
void T_Array<T>::remove(int i)//i번째 원소 삭제
{
	if (isValidIndex(i))
	{
		for (int j = i + 1; j < num_elements; j++)
			t_array[j - 1] = t_array[j];//앞으로 한자리씩 자리옮김 i제외하고
		num_elements--;

	}
	if (num_elements < (capacity / 2))//용량이 작아졌으면 줄여준다
	{
		int new_capacity=capacity/2;
		T* t_newGA = (T*) new T[new_capacity];//동적할당
		
		for(int i=0;i<num_elements;i++)
			t_newGA[i]=t_array[i];//i제외한 배열을 복사
		
		delete[] t_array;
		t_array = t_newGA;
		capacity = new_capacity;
	}
}


template<typename T>
void T_Array<T>::shuffle()//위치섞기
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

		swap(t_array[index1], t_array[index2]);//위치 교환
	}
}

template<typename T>
T& T_Array<T>::at(int i)//i번째 값 읽어서 반환
{
	if (isValidIndex(i))
		return t_array[i];
}

template<typename T>
void T_Array<T>::set(int i, T& element)//i번째 원소 인수로 변경
{
	if (isValidIndex(i))
		t_array[i] = element;
}


template <typename T>//템플릿 설정
void T_Array<T>::insert(int i, T new_element)//i위치에 삽입
{
	if (isValidIndex(i))
	{
		for (int j = num_elements - 1; j >= i; j--)
		{
			t_array[j + 1] = t_array[j];//i까지 한자리씩 위치를 올려서 옮겨줌
		}
		t_array[i] = new_element;//비어있는 i 자리에 대입
		num_elements++;//원소 수 가 늘어나므로 더해줌
	}
}


template <typename T>//템플릿 설정
void T_Array<T>::selection_sort( SortingOrder sortOrder)
{
	int min_index, max_index;

	for (int i = 0; i < num_elements - 1; i++)
	{
		if (sortOrder == INCREASING)
		{
			min_index = i;//최소위치 정의
			{
				for (int j = i + 1; j < num_elements; j++)
				{
					if (t_array[j]<t_array[min_index])//최소 값보다 더 작은 값일경우
					{
						min_index = j;
						
					}

				}
				if (min_index != i)//최소위치가 처음정의와 다른경우 위치교환
				{
					swap(t_array[min_index], t_array[i]);
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
						
						if (t_array[j]>t_array[max_index])//최대 값보다 더 큰 값일경우
						{
							max_index = j;
						}

					}
					if (max_index != i)//최대위치가 처음정의와 다른경우 위치교환
					{
						swap(t_array[max_index], t_array[i]);
					}
				}
			}
		}
	}
}

template <typename T>//템플릿 설정
void T_Array<T>::fprint(ostream& fout, int elements_per_line)
{
	int count = 0;
	while (count < num_elements)
	{
		for (int i = 0; i < elements_per_line; i++)//라인 수 만큼 출력
		{
			fout << t_array[count] << " ";
			count++;
			if (count % elements_per_line == 0)//라인 수 만큼출력 후 
				fout << endl;//줄 바꿈
		}
	}
	fout << endl;
}

template<typename T>
int _partition(T* array, int size, int left, int right, int pivotIndex, SortingOrder sortOrder)
{

	int newpi;
	T pivotValue;

	pivotValue = array[pivotIndex];

	swap(array[pivotIndex], array[right]);//기준위치와 맨오른쪽 위치 교환

	newpi = left;//초기newpi left로 설정


	for (int i = left; i <= right - 1; i++)
	{
		if (sortOrder == INCREASING)//오름차순
		{
			
			if (array[i]<= pivotValue)//기준값보다 minkey값이 더작을경우
			{
				swap(array[i], array[newpi]);//i번째위치와 newpi의 위치를 교환
				newpi++;
			}
		}

		else
		{
			if (array[i] > pivotValue)//기준값보다 큰 값들
			{
				swap(array[i], array[newpi]);//newpi위치로 이동
				newpi++;
			}
		}

	}
	swap(array[newpi], array[right]);//오른쪽으로 보냈던 기준 값 newpi와 위치교환

	return newpi;
}


template <typename T>
void _quick_sort(T* array, int size, int left, int right, SortingOrder sortOrder)
{
	int pi, newpi;

	if (left >= right)
		return;
	else
		pi = (left + right) / 2;//기준값 

	newpi = _partition(array, size, left, right, pi, sortOrder);//newpi설정

	if (left < (newpi - 1))//왼쪽부분 시행
		_quick_sort(array, size, left, newpi - 1, sortOrder);
	if ((newpi + 1) < right)//오른쪽부분실행
		_quick_sort(array, size, newpi + 1, right, sortOrder);
}

template <typename T>
void T_Array<T>::quick_sort(SortingOrder sortOrder)
{
	int pi, newpi;

	_quick_sort(t_array, num_elements, 0, num_elements - 1, sortOrder);
}

template<typename T>
void T_Array<T> ::_mergeSrot(T* array, T* temp_array, int left, int right, SortingOrder sortOrder)
{

	if (left >= right)
		return;

	int i, j, k, mid = (left + right) / 2;//분할
	_mergeSrot(array, temp_array, left, mid,  sortOrder);//mid보다 낮은부분 분할
	_mergeSrot(array, temp_array, mid + 1, right, sortOrder);//mid보다 큰 부분 분할

	for (i = mid; i >= left; i--)
		temp_array[i] = array[i];//왼쪽부분 분할한것들을 temp배열에 넣어줌
	for (j = 1; j <= right - mid; j++)
		temp_array[right - j + 1] = array[j + mid];//오른쪽부분 분할한것들을 temp배열에 넣어줌


	for (i = left, j = right, k = left; k <= right; k++)
	{
		if (sortOrder == INCREASING)
		{
			

			if (temp_array[i] < temp_array[j])//크기비교
				array[k] = temp_array[i++];//작을시 왼쪽
			else
				array[k] = temp_array[j--];//클경우 오른쪽
		}
		else
		{

			if (temp_array[i]> temp_array[j])
				array[k] = temp_array[i++];//클경우 왼쪽
			else
				array[k] = temp_array[j--];//작을경우 오른쪽
		}

	}

}

template<typename T>
void T_Array<T>::mergeSort( SortingOrder sortOrder)
{
	T* temp_array = (T*)new T[num_elements];

	_mergeSrot(t_array, temp_array, 0, num_elements - 1,  sortOrder);
}

#endif