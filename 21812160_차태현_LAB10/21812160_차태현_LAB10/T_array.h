#ifndef T_A_H
#define T_A_H

#include<iomanip>
#include<iostream>
#include<string>

using namespace std;

enum SortingOrder { INCREASING, DECREASING };

template<typename V>
class T_Array//Ŭ���� ���ø�
{
public:
	T_Array(int n, string nm);//������
	~T_Array();//�Ҹ���
	string getName() { return name; }//�̸� ��ȯ
	void reserve(int new_capacity);//Ȯ��
	void insert( V element);//����
	void remove(int i);//����
	void shuffle();//��ġ ����
	V& at(int i);//�μ� ��ȯ
	void set(int i, V& elemnet);//i��° �� ����
	void selection_sort(SortingOrder sortOrder);//��������
	void fprint(ostream& fout, int elements_per_line);//�� ����ŭ ���
	bool isValidIndex(int i);//�ε��� ������ �ִ��� �Ǻ�
	V& operator[](int index) { return t_array[index]; }//�迭���·� ����
	void quick_sort(SortingOrder sortOrder);//������
	void _mergeSrot(V* array, V* temp_array, int left, int right, SortingOrder sortOrder);
	void mergeSort(SortingOrder sortOrder);//��������
	int size() const { return num_elements; }//ũ�� ��ȯ
private:
	V* t_array;
	int num_elements;//���� ��
	int capacity;//�뷮
	string name;
};

template <typename V>//���ø� ����

T_Array<V>::T_Array(int new_capacity, string nm)//������
{
	t_array = (V*)new V[new_capacity];//�־��� ũ�⿡ ���� �����迭����

	//�ʱ�ȭ
	capacity = new_capacity;
	num_elements = 0;
	name = nm;
}

template <typename V>//���ø� ����
T_Array<V>::~T_Array()//�Ҹ���
{
	if (t_array != NULL)
	{
		delete[] t_array; //���������� �߱⿡ ��ȯ
	}
}

template <typename V>//���ø� ����
bool T_Array<V>::isValidIndex(int index)
{
	if ((index >= 0) && (index <= num_elements))
		return true;
	else
		return false;
}

template <typename V>//���ø� ����
void T_Array<V>::reserve(int new_capacity)//Ȯ��
{
	if (capacity >= new_capacity)
		return;//����� ū�뷮
	V* t_newGA = (V*) new V[new_capacity];//�����Ҵ�
	cout << getName() << "expands capacity to" << setw(3) << new_capacity << endl;

	for (int i = 0; i < num_elements; i++)
		t_newGA[i] = t_array[i];//Ȯ���� �迭�� ���Ҵ�

	delete[] t_array;
	t_array = t_newGA;
	capacity = new_capacity;
}

template <typename V>
void T_Array<V>::remove(int i)//i��° ���� ����
{
	if (isValidIndex(i))
	{
		for (int j = i + 1; j < num_elements; j++)
			t_array[j - 1] = t_array[j];//������ ���ڸ��� �ڸ��ű� i�����ϰ�
		num_elements--;

	}
	if (num_elements < (capacity / 2))//�뷮�� �۾������� �ٿ��ش�
	{
		int new_capacity = capacity / 2;
		V* t_newGA = (V*) new V[new_capacity];//�����Ҵ�

		for (int i = 0; i < num_elements; i++)
			t_newGA[i] = t_array[i];//i������ �迭�� ����

		delete[] t_array;
		t_array = t_newGA;
		capacity = new_capacity;
	}
}


template<typename V>
void T_Array<V>::shuffle()//��ġ����
{
	srand(time(NULL));
	int index1, index2;
	int rand1, rand2;

	for (int i = 0; i < num_elements; i++)
	{
		rand1 = rand();
		rand2 = rand();
		index1 = ((rand1 << 15) | rand2) % num_elements;//���Ҽ� ���� ���� ��������

		rand1 = rand();
		rand2 = rand();
		index2 = ((rand1 << 15) | rand2) % num_elements;//���Ҽ� ���� ���� ��������

		swap(t_array[index1], t_array[index2]);//��ġ ��ȯ
	}
}

template<typename V>
V& T_Array<V>::at(int i)//i��° �� �о ��ȯ
{
	if (isValidIndex(i))
		return t_array[i];
}

template<typename V>
void T_Array<V>::set(int i, V& element)//i��° ���� �μ��� ����
{
	if (isValidIndex(i))
		t_array[i] = element;
}


template <typename V>//���ø� ����
void T_Array<V>::insert(V new_element)//i��ġ�� ����
{
	
		/*for (int j = num_elements - 1; j >= num_elements; j--)
		{
			t_array[j + 1] = t_array[j];//i���� ���ڸ��� ��ġ�� �÷��� �Ű���
		}
		t_array[new_element] = new_element;//����ִ� i �ڸ��� ����
		num_elements++;//���� �� �� �þ�Ƿ� ������*/
	if (num_elements >= capacity)
	{
		int new_capa;
		new_capa = ((2 * capacity) > 1) ? 2 * capacity : 1;
		reserve(new_capa);
	}

	t_array[num_elements] = new_element;
	num_elements++;
}


template <typename V>//���ø� ����
void T_Array<V>::selection_sort(SortingOrder sortOrder)
{
	int min_index, max_index;

	for (int i = 0; i < num_elements - 1; i++)
	{
		if (sortOrder == INCREASING)
		{
			min_index = i;//�ּ���ġ ����
			{
				for (int j = i + 1; j < num_elements; j++)
				{
					if (t_array[j] < t_array[min_index])//�ּ� ������ �� ���� ���ϰ��
					{
						min_index = j;

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
			{
				{
					for (int j = i + 1; j < num_elements; j++)
					{

						if (t_array[j] > t_array[max_index])//�ִ� ������ �� ū ���ϰ��
						{
							max_index = j;
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

template <typename V>//���ø� ����
void T_Array<V>::fprint(ostream& fout, int elements_per_line)
{
	int count = 0;
	while (count < num_elements)
	{
		for (int i = 0; i < elements_per_line; i++)//���� �� ��ŭ ���
		{
			fout << t_array[count] << " ";
			count++;
			if (count % elements_per_line == 0)//���� �� ��ŭ��� �� 
				fout << endl;//�� �ٲ�
		}
	}
	fout << endl;
}

template<typename V>
int _partition(V* array, int size, int left, int right, int pivotIndex, SortingOrder sortOrder)
{

	int newpi;
	V pivotValue;

	pivotValue = array[pivotIndex];

	swap(array[pivotIndex], array[right]);//������ġ�� �ǿ����� ��ġ ��ȯ

	newpi = left;//�ʱ�newpi left�� ����


	for (int i = left; i <= right - 1; i++)
	{
		if (sortOrder == INCREASING)//��������
		{

			if (array[i] <= pivotValue)//���ذ����� minkey���� ���������
			{
				swap(array[i], array[newpi]);//i��°��ġ�� newpi�� ��ġ�� ��ȯ
				newpi++;
			}
		}

		else
		{
			if (array[i] > pivotValue)//���ذ����� ū ����
			{
				swap(array[i], array[newpi]);//newpi��ġ�� �̵�
				newpi++;
			}
		}

	}
	swap(array[newpi], array[right]);//���������� ���´� ���� �� newpi�� ��ġ��ȯ

	return newpi;
}


template <typename V>
void _quick_sort(V* array, int size, int left, int right, SortingOrder sortOrder)
{
	int pi, newpi;

	if (left >= right)
		return;
	else
		pi = (left + right) / 2;//���ذ� 

	newpi = _partition(array, size, left, right, pi, sortOrder);//newpi����

	if (left < (newpi - 1))//���ʺκ� ����
		_quick_sort(array, size, left, newpi - 1, sortOrder);
	if ((newpi + 1) < right)//�����ʺκн���
		_quick_sort(array, size, newpi + 1, right, sortOrder);
}

template <typename V>
void T_Array<V>::quick_sort(SortingOrder sortOrder)
{
	int pi, newpi;

	_quick_sort(t_array, num_elements, 0, num_elements - 1, sortOrder);
}

template<typename V>
void T_Array<V> ::_mergeSrot(V* array, V* temp_array, int left, int right, SortingOrder sortOrder)
{

	if (left >= right)
		return;

	int i, j, k, mid = (left + right) / 2;//����
	_mergeSrot(array, temp_array, left, mid, sortOrder);//mid���� �����κ� ����
	_mergeSrot(array, temp_array, mid + 1, right, sortOrder);//mid���� ū �κ� ����

	for (i = mid; i >= left; i--)
		temp_array[i] = array[i];//���ʺκ� �����Ѱ͵��� temp�迭�� �־���
	for (j = 1; j <= right - mid; j++)
		temp_array[right - j + 1] = array[j + mid];//�����ʺκ� �����Ѱ͵��� temp�迭�� �־���


	for (i = left, j = right, k = left; k <= right; k++)
	{
		if (sortOrder == INCREASING)
		{


			if (temp_array[i] < temp_array[j])//ũ���
				array[k] = temp_array[i++];//������ ����
			else
				array[k] = temp_array[j--];//Ŭ��� ������
		}
		else
		{

			if (temp_array[i] > temp_array[j])
				array[k] = temp_array[i++];//Ŭ��� ����
			else
				array[k] = temp_array[j--];//������� ������
		}

	}

}

template<typename V>
void T_Array<V>::mergeSort(SortingOrder sortOrder)
{
	V* temp_array = (V*)new V[num_elements];

	_mergeSrot(t_array, temp_array, 0, num_elements - 1, sortOrder);
}

#endif