#include "ConsolePixelDrawing.h"

ConsolePixelFrame::ConsolePixelFrame(int org_x, int org_y)//������
{
	console = GetConsoleWindow();
	console_DC = GetDC(console);
	pShapes = new Shape * [MAX_NUM_SHAPES];
	num_shapes = 0;
	capacity = MAX_NUM_SHAPES;
	
	pos_org_x = org_x;
	pos_org_y = org_y;
}

ConsolePixelFrame::~ConsolePixelFrame()//�Ҹ���
{
	//delete[] shapes;
}

void ConsolePixelFrame::addShape(Shape* new_shape)
{
	if (num_shapes >= capacity)//�뷮���� �������� �������
	{
		cout << "ConsolePixelFrame::addShape ==> Expanding capacity to" << capacity * 2 << "shapes" << endl;

		Shape** old_shapes = pShapes;

		pShapes = new Shape * [capacity * 2];//Ȯ�� 
		if (pShapes == NULL)
		{
			cout << "Error in shapes capcity";
			exit;
		}
		for (int i = 0; i < num_shapes; i++)
		{
			pShapes[i] = old_shapes[i];//���� ������ Ȯ��� �迭�� ����
		}
		capacity = capacity * 2;
		delete[] old_shapes;
	}
	pShapes[num_shapes] = new_shape;//���ο� ������ �߰�����ġ�� �߰�
	num_shapes++;
}

void ConsolePixelFrame::drawShapes()//��� ������ �׸���
{
	cout << "Drawing" << num_shapes << "shapes :" << endl;
	if (num_shapes > 0)
	{
		for (int i = 0; i < num_shapes; i++)
		{
			pShapes[i]->draw(*this);//�ݺ������� ������ draw�Լ� ȣ���� �׸���
		}
	}
} 

bool ConsolePixelFrame::isValidIndex(int sub)//���� Ȯ��
{
	if (sub > 0 && sub < num_shapes)//�����ȿ� �������� true
		return true;
	else
	{
		cout << "Erroe in ConsolePixelFrame :: isValidIndex";
		return false;
	}
		
}