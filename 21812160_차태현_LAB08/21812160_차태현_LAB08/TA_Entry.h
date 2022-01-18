#ifndef TA_H
#define TA_H

#include<iostream>
#include<iomanip>
#include"T_Entry.h"
#include<time.h>
#include<string>

using namespace std;

enum SortingDirection{INCREASING,DECREASING};

template<typename K,typename V>
class TA_Entry
{
public:
	TA_Entry(int n, string nm);//������
	~TA_Entry();//�Ҹ���
	int size() { return num_elements; }//ũ�� ��ȯ
	bool empty() { return num_elements == 0; }//����°� Ȯ��
	string getName() { return name; }//�̸� ��ȯ
	void reserve(int new_capcity);//Ȯ��
	void insert(int i, T_Entry<K, V> element);//i��° ���� ����
	void remove(int i);//i��° ����
	T_Entry<K, V>& at(int i);//i��° �� �޾ƿ���
	void set(int i, T_Entry<K, V>& element);//�� ����
	T_Entry<K, V> getMin(int begin, int end);//�ּҰ� ã��
	T_Entry<K, V> getMax(int begin, int end);//�ִ밪 ã��
	void shuffle();//����
	int sequential_search(T_Entry<K, V> search_key);//����Ž��
	int binary_search(T_Entry<K, V> search_key);//����Ž��
	void selection_srot(SortingDirection sd);//��������
	void quick_sort(SortingDirection sd);//������
	void fprint(ofstream& fout, int elements_per_line);//���
	void fprintSample(ofstream& fout, int elements_per_line, int num_sample_lines);//�������
	bool isValidIndex(int i);//�ε��� ������ �ִ��� �Ǻ�
	T_Entry<K, V>& operator[](int index) { return t_GA[index]; }//�迭���·� ��ȯ
protected:
	T_Entry<K, V>* t_GA;
	int num_elements;//���� ��
	int capacity;//�뷮
	string name;//�̸�
};

template<typename K, typename V>
TA_Entry<K, V>::TA_Entry(int n, string nm)//������
{
	t_GA = (T_Entry<K, V>*)new T_Entry<K, V>[n];//�����Ҵ�

	//�ʱ�ȭ
	capacity = n;
	name = nm;
	num_elements = 0;
}

template<typename K, typename V>
TA_Entry<K, V>::~TA_Entry()
{
	if (t_GA != NULL)
	{
		delete[] t_GA;//�����迭 ����� ��ȯ
	}
}

template<typename K, typename V>
void TA_Entry<K, V>::reserve(int new_capacity)//�뷮Ȯ��
{
	if (capacity >= new_capacity)//�����뷮�� �� Ŭ��
		return;
	T_Entry<K, V>* t_newGA = (T_Entry<K, V>*) new T_Entry<K, V>[new_capacity];//��������
	cout << getName() << "expands capacity to" << setw(3) << new_capacity << endl;

	for (int i = 0; i < num_elements; i++)
	{
		t_newGA[i] = t_GA[i];//���������� �޸𸮿� ������ ������
	}
	delete[] t_GA;//������ ��ȯ
	t_GA = t_newGA;//���� �����Ҵ��� �迭�� ������ �迭�� ����
	capacity = new_capacity;//�뷮 ����

}
template<typename K, typename V>
bool TA_Entry<K, V>::isValidIndex(int index)
{
	if ((index >= 0) && (index <= num_elements))// index���� �Ǻ�
		return true;
	else
		return false;
}

template<typename K, typename V>
void TA_Entry<K, V>::insert(int i, T_Entry<K, V> element)//����
{
	if (isValidIndex(i))
	{
		for (int j = num_elements - 1; j >= i; j--)
		{
			t_GA[j + 1] = t_GA[j];//i��ġ������ ������ ��ġ�� ���ڸ��� ������
		}
		t_GA[i] = element;//i��°�� ���һ���
		num_elements++;//�� ũ�� ����
	}
	
}

template<typename K, typename V>
void TA_Entry<K, V>::remove(int i)
{
	if (isValidIndex(i))
	{
		for (int j = i + 1; j < num_elements; j++)
		{
			t_GA[j - 1] = t_GA[j];//i�ڸ����� �������ڸ����� -1�����༭ ����
		}
		num_elements--;//ũ�� -1
	}
	if (num_elements < (capacity / 2))//ũ�Ⱑ �뷮�� �ݺ��� �������
	{
		int new_capacity = capacity / 2;//���ο� �뷮����
		T_Entry<K, V>* t_newGA = (T_Entry<K, V>*)new T_Entry<K, V>[new_capacity];//�����Ҵ�

		for (int i = 0; i < num_elements; i++)
			t_newGA[i] = t_GA[i];//���ο� �����迭�� ���� �� ����

		delete[] t_GA;//�����迭 ���� ��ȯ
		t_GA = t_newGA;//�����迭�� ���ο� �����迭 ����
		capacity = new_capacity;//�뷮 ����
	}
}

template<typename K, typename V>
T_Entry<K, V>& TA_Entry<K, V>::at(int i)
{
	if (isValidIndex(i))//��������Ͻ�
		return t_GA[i];//i��° ����ȯ
}

template<typename K, typename V>
void TA_Entry<K, V>::set(int i, T_Entry<K, V>& element)
{
	if (isValidIndex(i))//��������Ͻ�
		t_GA[i]=element;//i��° element�� ����
}

template<typename K, typename V>
void TA_Entry<K, V>::shuffle()
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

		swap(t_GA[index1], t_GA[index2]);//��ġ ��ȯ
	}
}
template<typename K, typename V>
T_Entry<K, V> TA_Entry<K, V>::getMin(int begin, int end)
{
	T_Entry<K, V>* min;
	
	min = t_GA[0];//�ʱ⼳��
	for (int i = begin; i < end; i++)//��ü�� �ݺ�
	{
		if (t_GA[i] < min)//�ִ밪 ã��
			min = t_GA[i];
	}
	return min;//�ּҰ� ��ȯ
}

template<typename K, typename V>
T_Entry<K, V> TA_Entry<K, V>::getMax(int begin, int end)
{
	T_Entry<K, V>* max;

	max = t_GA[0];//�ʱ⼳��
	for (int i = begin; i < end; i++)//��ü�� �ݺ�
	{
		if (t_GA[i] > max)//�ִ밪 ã��
			max = t_GA[i];
	}
	return max;//�ִ밪 ��ȯ
}

template<typename K, typename V>
int TA_Entry<K, V>::sequential_search(T_Entry<K, V> search_key)
{
	for (int i = 0; i < num_elements; i++)
	{
		if (t_GA[i] == search_key)
			return i;//ã����� i ��ȯ
	}
	return -1;//�� ã�� ��� -1��ȯ
}

template<typename K, typename V>
int TA_Entry<K, V>::binary_search(T_Entry<K, V> search_key)
{
	int low, mid, high, loop = 1;
	low = 0;
	high = num_elements - 1;

	while (low <= high)
	{
		cout << setw(2) << loop << "-th loop: current search range [" << setw(3) << low << "," << high << "]" << endl;

		mid = (low + high) / 2;//�߰��� mid�� ����
		if (t_GA[mid] == search_key)//mid��ġ�� search_key���� ������ 
			return mid;//��ġ��ȯ
		else if (t_GA[mid] > search_key)//�� Ŭ��� ������ mid���� �� ������ġ�⶧����
			high = mid - 1;//high��ġ����
		else
			low = mid + 1;//mid���� �� ū��ġ�� ������ �ִ°��
		loop++;//����Ƚ�� �߰�
	}
	return -1;
}

template<typename K, typename V>
void TA_Entry<K, V>::selection_srot(SortingDirection sd)
{
	int min_index, max_index;

	for (int i = 0; i < num_elements - 1; i++)
	{
		if (sd == INCREASING)
		{
			min_index = i;//�ּ���ġ ����
			{
				for (int j = i + 1; j < num_elements; j++)
				{
					if (t_GA[j] < t_GA[min_index])//�ּ� ������ �� ���� ���ϰ��
					{
						min_index = j;
					}

				}
				if (min_index != i)//�ּ���ġ�� ó�����ǿ� �ٸ���� ��ġ��ȯ
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
						if (t_GA[i] > t_GA[max_index])//�ִ� ������ �� ū ���ϰ��
						{
							max_index = j;
						}

					}
					if (max_index != i)//�ִ���ġ�� ó�����ǿ� �ٸ���� ��ġ��ȯ
					{
						swap(t_GA[max_index], t_GA[i]);
					}
				}
			}
		}
	}
}

template<typename K,typename V>
int partition(T_Entry<K, V>* array, int size, int left, int right, int pivotIndex, SortingDirection sd)
{
	int newpi;
	T_Entry<K, V> pivotValue;

	pivotValue = array[pivotIndex];//���ذ� ����

	swap(array[pivotIndex], array[right]);//������ġ�� �ǿ����� ��ġ ��ȯ

	newpi = left;//�ʱ�newpi left�� ����

	for (int i = left; i <= right - 1; i++)
	{
		if (sd == INCREASING)//��������
		{
			if (array[i] <= pivotValue)
			{
				swap(array[i], array[newpi]);//i��°��ġ�� newpi�� ��ġ�� ��ȯ
				newpi++;
			}
		}
		else
			if (array[i] > pivotValue)
			{
				swap(array[i], array[newpi]);//newpi��ġ�� �̵�
				newpi++;
			}

	}
	swap(array[newpi], array[right]);//���������� ���´� ���� �� newpi�� ��ġ��ȯ
}

template<typename K,typename V>
void _quick_sort(T_Entry<K, V>* array, int size, int left, int right, SortingDirection sd)
{
	int pi, newpi;

	if (left >= right)
		return;
	else
		pi = (left + right) / 2;//���ذ� ����

	newpi = partition(array, size, left, right, pi, sd);//��Ƽ�������� newpi ����
	
	if (left < (newpi - 1))//���ʺκ� ����
		quick_sort(array, size, left, newpi - 1, sd);
	if ((newpi + 1) < right)//�����ʺκн���
		quick_sort(array, size, newpi + 1, right, sd);

}

template<typename K, typename V>
void TA_Entry<K, V>::quick_sort(SortingDirection sd)
{
	int pi, newpi;
	
	_quick_sort(t_GA, num_elements, 0, num_elements - 1, sd);
}

template<typename K, typename V>
void TA_Entry<K, V>::fprint(ofstream& fout, int elements_per_line)
{
	int count = 0;

	while (count < num_elements)//���Ҽ� ��ŭ �ݺ�
	{
		for (int i = 0; i < elements_per_line; i++)//���μ� ��ŭ���
		{
			fout << t_GA[count]<<" ";//���
			count++;
			if (count % elements_per_line == 0)//���� ����ŭ ��� �� �ٹٲ�
				fout << endl;
		}
	}
	fout << endl;
}

template<typename K, typename V>
void TA_Entry<K, V>::fprintSample(ofstream& fout, int elements_per_line, int num_sample_lines)
{
	int count = 0;

	for (int i = 0; i < num_sample_lines; i++)//���� �������
	{
		for (int j = 0; j < elements_per_line; j++)
		{
			fout << t_GA[count] << " ";
			count++;
			if (count % elements_per_line == 0)//���� ����ŭ ��� �� �ٹٲ�
				fout << endl;
		}
		fout << endl;
	}

	count = num_elements - (elements_per_line * num_sample_lines);//���� ������ ���� count ������
	fout << " . . . . . " << endl;

	for (int i = count; i < num_elements; i++)//���� �������
	{
		for (int j = 0; j < elements_per_line; j++)
		{
			fout << t_GA[count] << " ";
			count++;
			if (count % elements_per_line == 0)//���� ����ŭ ��� �� �ٹٲ�
				fout << endl;
		}
		fout << endl;
	}
}
#endif