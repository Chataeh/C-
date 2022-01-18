#ifndef T_A_H
#define T_A_H
#include<iomanip>
#include"Date.h"
#include"Time.h"
#include"Template class T_Array.h"

enum SortingOrder{INCREASING,DECREASING};

template<typename T, typename K>
class T_Array//클래스 템플릿
{
public:
	T_Array(int n, string nm);//생성자
	~T_Array();//소멸자
	int size() { return num_elements; }//크기 설정
	bool empty() { return num_elements == 0; }//원소가 없을시 비어있음
	string getName() { return name; }//이름 반환
	void insert(int i, T element);//삽입
	int sequential_search(K search_key);//순차탐색
	int binary_search(K search_key);//이진탐색
	void selection_sort(string keyName, SortingOrder sortOrder);//선택정렬
	void print(int elements_per_line);//줄 수만큼 출력
	bool isValidIndex(int i);//인덱스 범위에 있는지 판별
	T& operator[](int index) { return t_array[index]; }//배열형태로 관리
	void quick_sort(string keyName, SortingOrder sortOrder);//퀵정렬
	void _quick_sort(T* array, int size, int left, int right, SortingOrder sortOrder, string keyName);
	int _partition(T* array, int size, int left, int right, int pivotIndex, SortingOrder sortOrder, string keyName);
	void _mergeSrot(T* array,T* temp_array, int left, int right,string Keyname, SortingOrder sortOrder);
	void mergeSort(string keyName, SortingOrder sortOrder);//병합정렬
private:
	T* t_array;
	int num_elements;//원소 수
	int capacity;//용량
	string name;
};

template <typename T,typename K>//템플릿 설정

T_Array<T, K>::T_Array(int new_capcity, string nm)//생성자
{
	t_array = (T*)new T[new_capcity];//주어진 크기에 대한 동적배열생성
	
	//초기화
	capacity = new_capcity;
	num_elements = 0;
	name = nm;
}

template <typename T, typename K>//템플릿 설정
T_Array<T, K>::~T_Array()//소멸자
{
	if (t_array != NULL)
	{
		delete[] t_array; //동적생성을 했기에 반환
	}
}

template <typename T, typename K>//템플릿 설정
bool T_Array<T, K>::isValidIndex(int index)
{
	if ((index >= 0) && (index <= num_elements))
		return true;
	else
		return false;
}
template <typename T, typename K>//템플릿 설정
void T_Array<T, K>::insert(int i, T new_element)//i위치에 삽입
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

template <typename T, typename K>//템플릿 설정
int T_Array<T, K>::sequential_search(K search_key)
{
	int index;
	string keytype;
	K key, valuekey;
	keytype = typeid(K).name();//객체형식확인
	if (keytype == "int")//int 즉 학번일시
	{
		for (int index = 0; index < num_elements; index++)
		{
			t_array[index].getKey(keytype, &key);
			valuekey = (K)key;
			if (valuekey == search_key)//위치의 인덱스의 키가 search_key와 같을시
				return index;//위치 변환
		}
	}
	return -1;//찾지 못함
}

template <typename T, typename K>//템플릿 설정
int T_Array<T, K>::binary_search(K search_Key)
{
	int low, mid, high;
	int loop = 1;

	low = 0;
	high = num_elements - 1;

	while(low <= high)
	{
		cout << setw(2) << loop << "-th loop: current search range [" << setw(3) << low << "," << high << "]" << endl;

		mid = (low + high) / 2;//중간을 mid로 설정
		if (t_array[mid] == search_Key)//mid위치와 key값과 같을시 
			return mid;//위치반환
		else if (t_array[mid] > search_Key)//더 클경우 영역이 mid보다 더 낮은위치기때문에
			high = mid - 1;//high위치변경
		else
			low = mid + 1;//mid보다 더 큰위치의 영역에 있는경우
		loop++;
	}

}

template <typename T, typename K>//템플릿 설정
void T_Array<T, K>::selection_sort(string keyName, SortingOrder sortOrder)
{
	int min_index, max_index;

	K minKey, maxKey, key;

	for (int i = 0; i < num_elements - 1; i++)
	{
		if (sortOrder == INCREASING)
		{
			min_index = i;//최소위치 정의
			t_array[i].getKey(keyName, &key);//키 설정
			minKey = (K)key;//형 변환 후 대입
			{
				for (int j = i + 1; j < num_elements; j++)
				{
					t_array[j].getKey(keyName, &key);
					if ((K)key < minKey)//최소 값보다 더 작은 값일경우
					{
						min_index = j;
						minKey = (K)key;
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
			t_array[i].getKey(keyName, &key);
			maxKey = (K)key;//형 변환 후 대입
			{
				{
					for (int j = i + 1; j < num_elements; j++)
					{
						t_array[j].getKey(keyName, &key);
						if ((K)key > maxKey)//최대 값보다 더 큰 값일경우
						{
							max_index = j;
							maxKey = (K)key;
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
template <typename T, typename K>//템플릿 설정
void T_Array<T, K>::print(int elements_per_line)
{
	int count = 0;
	while (count < num_elements)
	{
		for (int i = 0; i < elements_per_line; i++)//라인 수 만큼 출력
		{
			cout << t_array[count] << " ";
			count++;
			if (count % elements_per_line == 0)//라인 수 만큼출력 후 
				cout << endl;//줄 바꿈
		}
	}
	cout << endl;
}

template<typename T,typename K>
int T_Array<T, K>::_partition(T* array, int size, int left, int right, int pivotIndex, SortingOrder sortOrder, string keyName)
{

	int newpi;
	K key, valuekey, minkey, maxkey;

	array[pivotIndex].getKey(keyName, &key);//키 이름에 따라 맞는 기준값설정
	valuekey = (K)key;//기준값을 받아와 K형으로 변환하여 저장
	
	swap(array[pivotIndex], array[right]);//기준위치와 맨오른쪽 위치 교환

	newpi = left;//초기newpi left로 설정


	for (int i = left; i <= right - 1; i++)
	{
		if (sortOrder == INCREASING)//오름차순
		{
			array[i].getKey(keyName, &key);//i번째 값을위해 키값을 받아옴
			minkey = (K)key;//받아온 키값을 미리 지정한 변수 minkey에 저장
			if ( minkey<= valuekey)//기준값보다 minkey값이 더작을경우
			{
				swap(array[i], array[newpi]);//i번째위치와 newpi의 위치를 교환
				newpi++;
			}
		}


		else
		{
			array[i].getKey(keyName, &key);//i번째 값을위해 키값을 받아옴
			maxkey = (K)key;//받아온 키값을 미리 지정한 변수 maxkey에 저장
			if (valuekey < maxkey)//기준값보다 큰 값들
			{
				swap(array[i], array[newpi]);//newpi위치로 이동
				newpi++;
			}
		}
		
	}
	swap(array[newpi], array[right]);//오른쪽으로 보냈던 기준 값 newpi와 위치교환

	return newpi;
}


template <typename T,typename K>
void T_Array<T, K>::_quick_sort(T* array, int size, int left, int right, SortingOrder sortOrder, string keyName)
{
	int pi, newpi;

	if (left >= right)
		return;
	else
		pi = (left + right) / 2;//기준값 

	newpi = _partition(array, size, left, right, pi, sortOrder, keyName);//newpi설정

	if (left < (newpi - 1))//왼쪽부분 시행
		_quick_sort(array, size, left, newpi - 1, sortOrder, keyName);
	if((newpi+1)<right)//오른쪽부분실행
		_quick_sort(array, size,newpi + 1, right,sortOrder, keyName);
}

template <typename T, typename K>
void T_Array<T, K>::quick_sort(string keyName, SortingOrder sortOrder)
{
	int pi, newpi;
	
	_quick_sort(t_array, num_elements, 0, num_elements - 1, sortOrder, keyName);
}

template<typename T , typename K>
void T_Array<T, K> ::_mergeSrot(T* array ,T* temp_array,int left, int right, string keyName,SortingOrder sortOrder)
{
	K key,Lkey, Rkey;
	
	if (left >= right)
		return;

	int i, j, k, mid = (left + right) / 2;//분할
	_mergeSrot(array,temp_array, left, mid, keyName,sortOrder);//mid보다 낮은부분 분할
	_mergeSrot(array, temp_array, mid + 1, right, keyName,sortOrder);//mid보다 큰 부분 분할

	for (i = mid; i >= left; i--)
		temp_array[i] = array[i];//왼쪽부분 분할한것들을 temp배열에 넣어줌
	for (j = 1; j <= right - mid; j++)
		temp_array[right - j + 1] = array[j + mid];//오른쪽부분 분할한것들을 temp배열에 넣어줌


	for (i = left, j = right, k = left; k <= right; k++)
	{
		if (sortOrder == INCREASING)
		{
			temp_array[i].getKey(keyName, &key);//키를 통해 어떤값으로 비교할지 설정
			Lkey = (K)key;

			temp_array[j].getKey(keyName, &key);
			Rkey = (K)key;

			if (Lkey < Rkey)//크기비교
				array[k] = temp_array[i++];//작을시 왼쪽
			else
				array[k] = temp_array[j--];//클경우 오른쪽
		}
		else
		{
			temp_array[i].getKey(keyName, &key);//키를 통해 어떤값으로 비교할지 설정
			Lkey = (K)key;

			temp_array[j].getKey(keyName, &key);
			Rkey = (K)key;

			if (Lkey > Rkey)
				array[k] = temp_array[i++];//클경우 왼쪽
			else
				array[k] = temp_array[j--];//작을경우 오른쪽
		}

	}

}

template<typename T,typename K>
void T_Array<T, K>::mergeSort(string keyName, SortingOrder sortOrder)
{
	T* temp_array = (T*)new T[num_elements];

	_mergeSrot(t_array,temp_array, 0, num_elements - 1, keyName,sortOrder);
}

#endif