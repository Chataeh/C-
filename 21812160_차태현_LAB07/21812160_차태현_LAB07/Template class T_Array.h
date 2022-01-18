#ifndef T_A_H
#define T_A_H
#include<iomanip>
#include"Date.h"
#include"Time.h"
#include"Template class T_Array.h"

enum SortingOrder{INCREASING,DECREASING};

template<typename T, typename K>
class T_Array//Ŭ���� ���ø�
{
public:
	T_Array(int n, string nm);//������
	~T_Array();//�Ҹ���
	int size() { return num_elements; }//ũ�� ����
	bool empty() { return num_elements == 0; }//���Ұ� ������ �������
	string getName() { return name; }//�̸� ��ȯ
	void insert(int i, T element);//����
	int sequential_search(K search_key);//����Ž��
	int binary_search(K search_key);//����Ž��
	void selection_sort(string keyName, SortingOrder sortOrder);//��������
	void print(int elements_per_line);//�� ����ŭ ���
	bool isValidIndex(int i);//�ε��� ������ �ִ��� �Ǻ�
	T& operator[](int index) { return t_array[index]; }//�迭���·� ����
	void quick_sort(string keyName, SortingOrder sortOrder);//������
	void _quick_sort(T* array, int size, int left, int right, SortingOrder sortOrder, string keyName);
	int _partition(T* array, int size, int left, int right, int pivotIndex, SortingOrder sortOrder, string keyName);
	void _mergeSrot(T* array,T* temp_array, int left, int right,string Keyname, SortingOrder sortOrder);
	void mergeSort(string keyName, SortingOrder sortOrder);//��������
private:
	T* t_array;
	int num_elements;//���� ��
	int capacity;//�뷮
	string name;
};

template <typename T,typename K>//���ø� ����

T_Array<T, K>::T_Array(int new_capcity, string nm)//������
{
	t_array = (T*)new T[new_capcity];//�־��� ũ�⿡ ���� �����迭����
	
	//�ʱ�ȭ
	capacity = new_capcity;
	num_elements = 0;
	name = nm;
}

template <typename T, typename K>//���ø� ����
T_Array<T, K>::~T_Array()//�Ҹ���
{
	if (t_array != NULL)
	{
		delete[] t_array; //���������� �߱⿡ ��ȯ
	}
}

template <typename T, typename K>//���ø� ����
bool T_Array<T, K>::isValidIndex(int index)
{
	if ((index >= 0) && (index <= num_elements))
		return true;
	else
		return false;
}
template <typename T, typename K>//���ø� ����
void T_Array<T, K>::insert(int i, T new_element)//i��ġ�� ����
{
	if (isValidIndex(i))
	{
		for (int j = num_elements - 1; j >= i; j--)
		{
			t_array[j + 1] = t_array[j];//i���� ���ڸ��� ��ġ�� �÷��� �Ű���
		}
		t_array[i] = new_element;//����ִ� i �ڸ��� ����
		num_elements++;//���� �� �� �þ�Ƿ� ������
	}
}

template <typename T, typename K>//���ø� ����
int T_Array<T, K>::sequential_search(K search_key)
{
	int index;
	string keytype;
	K key, valuekey;
	keytype = typeid(K).name();//��ü����Ȯ��
	if (keytype == "int")//int �� �й��Ͻ�
	{
		for (int index = 0; index < num_elements; index++)
		{
			t_array[index].getKey(keytype, &key);
			valuekey = (K)key;
			if (valuekey == search_key)//��ġ�� �ε����� Ű�� search_key�� ������
				return index;//��ġ ��ȯ
		}
	}
	return -1;//ã�� ����
}

template <typename T, typename K>//���ø� ����
int T_Array<T, K>::binary_search(K search_Key)
{
	int low, mid, high;
	int loop = 1;

	low = 0;
	high = num_elements - 1;

	while(low <= high)
	{
		cout << setw(2) << loop << "-th loop: current search range [" << setw(3) << low << "," << high << "]" << endl;

		mid = (low + high) / 2;//�߰��� mid�� ����
		if (t_array[mid] == search_Key)//mid��ġ�� key���� ������ 
			return mid;//��ġ��ȯ
		else if (t_array[mid] > search_Key)//�� Ŭ��� ������ mid���� �� ������ġ�⶧����
			high = mid - 1;//high��ġ����
		else
			low = mid + 1;//mid���� �� ū��ġ�� ������ �ִ°��
		loop++;
	}

}

template <typename T, typename K>//���ø� ����
void T_Array<T, K>::selection_sort(string keyName, SortingOrder sortOrder)
{
	int min_index, max_index;

	K minKey, maxKey, key;

	for (int i = 0; i < num_elements - 1; i++)
	{
		if (sortOrder == INCREASING)
		{
			min_index = i;//�ּ���ġ ����
			t_array[i].getKey(keyName, &key);//Ű ����
			minKey = (K)key;//�� ��ȯ �� ����
			{
				for (int j = i + 1; j < num_elements; j++)
				{
					t_array[j].getKey(keyName, &key);
					if ((K)key < minKey)//�ּ� ������ �� ���� ���ϰ��
					{
						min_index = j;
						minKey = (K)key;
					}

				}
				if (min_index != i)//�ּ���ġ�� ó�����ǿ� �ٸ���� ��ġ��ȯ
				{
					swap(t_array[min_index], t_array[i]);
				}
			}
		}

		else
		{
			max_index = i;
			t_array[i].getKey(keyName, &key);
			maxKey = (K)key;//�� ��ȯ �� ����
			{
				{
					for (int j = i + 1; j < num_elements; j++)
					{
						t_array[j].getKey(keyName, &key);
						if ((K)key > maxKey)//�ִ� ������ �� ū ���ϰ��
						{
							max_index = j;
							maxKey = (K)key;
						}

					}
					if (max_index != i)//�ִ���ġ�� ó�����ǿ� �ٸ���� ��ġ��ȯ
					{
						swap(t_array[max_index], t_array[i]);
					}
				}
			}
		}
	}
}
template <typename T, typename K>//���ø� ����
void T_Array<T, K>::print(int elements_per_line)
{
	int count = 0;
	while (count < num_elements)
	{
		for (int i = 0; i < elements_per_line; i++)//���� �� ��ŭ ���
		{
			cout << t_array[count] << " ";
			count++;
			if (count % elements_per_line == 0)//���� �� ��ŭ��� �� 
				cout << endl;//�� �ٲ�
		}
	}
	cout << endl;
}

template<typename T,typename K>
int T_Array<T, K>::_partition(T* array, int size, int left, int right, int pivotIndex, SortingOrder sortOrder, string keyName)
{

	int newpi;
	K key, valuekey, minkey, maxkey;

	array[pivotIndex].getKey(keyName, &key);//Ű �̸��� ���� �´� ���ذ�����
	valuekey = (K)key;//���ذ��� �޾ƿ� K������ ��ȯ�Ͽ� ����
	
	swap(array[pivotIndex], array[right]);//������ġ�� �ǿ����� ��ġ ��ȯ

	newpi = left;//�ʱ�newpi left�� ����


	for (int i = left; i <= right - 1; i++)
	{
		if (sortOrder == INCREASING)//��������
		{
			array[i].getKey(keyName, &key);//i��° �������� Ű���� �޾ƿ�
			minkey = (K)key;//�޾ƿ� Ű���� �̸� ������ ���� minkey�� ����
			if ( minkey<= valuekey)//���ذ����� minkey���� ���������
			{
				swap(array[i], array[newpi]);//i��°��ġ�� newpi�� ��ġ�� ��ȯ
				newpi++;
			}
		}


		else
		{
			array[i].getKey(keyName, &key);//i��° �������� Ű���� �޾ƿ�
			maxkey = (K)key;//�޾ƿ� Ű���� �̸� ������ ���� maxkey�� ����
			if (valuekey < maxkey)//���ذ����� ū ����
			{
				swap(array[i], array[newpi]);//newpi��ġ�� �̵�
				newpi++;
			}
		}
		
	}
	swap(array[newpi], array[right]);//���������� ���´� ���� �� newpi�� ��ġ��ȯ

	return newpi;
}


template <typename T,typename K>
void T_Array<T, K>::_quick_sort(T* array, int size, int left, int right, SortingOrder sortOrder, string keyName)
{
	int pi, newpi;

	if (left >= right)
		return;
	else
		pi = (left + right) / 2;//���ذ� 

	newpi = _partition(array, size, left, right, pi, sortOrder, keyName);//newpi����

	if (left < (newpi - 1))//���ʺκ� ����
		_quick_sort(array, size, left, newpi - 1, sortOrder, keyName);
	if((newpi+1)<right)//�����ʺκн���
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

	int i, j, k, mid = (left + right) / 2;//����
	_mergeSrot(array,temp_array, left, mid, keyName,sortOrder);//mid���� �����κ� ����
	_mergeSrot(array, temp_array, mid + 1, right, keyName,sortOrder);//mid���� ū �κ� ����

	for (i = mid; i >= left; i--)
		temp_array[i] = array[i];//���ʺκ� �����Ѱ͵��� temp�迭�� �־���
	for (j = 1; j <= right - mid; j++)
		temp_array[right - j + 1] = array[j + mid];//�����ʺκ� �����Ѱ͵��� temp�迭�� �־���


	for (i = left, j = right, k = left; k <= right; k++)
	{
		if (sortOrder == INCREASING)
		{
			temp_array[i].getKey(keyName, &key);//Ű�� ���� ������� ������ ����
			Lkey = (K)key;

			temp_array[j].getKey(keyName, &key);
			Rkey = (K)key;

			if (Lkey < Rkey)//ũ���
				array[k] = temp_array[i++];//������ ����
			else
				array[k] = temp_array[j--];//Ŭ��� ������
		}
		else
		{
			temp_array[i].getKey(keyName, &key);//Ű�� ���� ������� ������ ����
			Lkey = (K)key;

			temp_array[j].getKey(keyName, &key);
			Rkey = (K)key;

			if (Lkey > Rkey)
				array[k] = temp_array[i++];//Ŭ��� ����
			else
				array[k] = temp_array[j--];//������� ������
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