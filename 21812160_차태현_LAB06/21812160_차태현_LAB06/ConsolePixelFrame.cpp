#include "ConsolePixelDrawing.h"

ConsolePixelFrame::ConsolePixelFrame(int org_x, int org_y)//생성자
{
	console = GetConsoleWindow();
	console_DC = GetDC(console);
	pShapes = new Shape * [MAX_NUM_SHAPES];
	num_shapes = 0;
	capacity = MAX_NUM_SHAPES;
	
	pos_org_x = org_x;
	pos_org_y = org_y;
}

ConsolePixelFrame::~ConsolePixelFrame()//소멸자
{
	//delete[] shapes;
}

void ConsolePixelFrame::addShape(Shape* new_shape)
{
	if (num_shapes >= capacity)//용량보다 도형수가 많을경우
	{
		cout << "ConsolePixelFrame::addShape ==> Expanding capacity to" << capacity * 2 << "shapes" << endl;

		Shape** old_shapes = pShapes;

		pShapes = new Shape * [capacity * 2];//확장 
		if (pShapes == NULL)
		{
			cout << "Error in shapes capcity";
			exit;
		}
		for (int i = 0; i < num_shapes; i++)
		{
			pShapes[i] = old_shapes[i];//기존 도형들 확장된 배열에 복사
		}
		capacity = capacity * 2;
		delete[] old_shapes;
	}
	pShapes[num_shapes] = new_shape;//새로운 도형을 추가된위치에 추가
	num_shapes++;
}

void ConsolePixelFrame::drawShapes()//모든 도형들 그리기
{
	cout << "Drawing" << num_shapes << "shapes :" << endl;
	if (num_shapes > 0)
	{
		for (int i = 0; i < num_shapes; i++)
		{
			pShapes[i]->draw(*this);//반복문으로 각각의 draw함수 호출후 그리기
		}
	}
} 

bool ConsolePixelFrame::isValidIndex(int sub)//범위 확인
{
	if (sub > 0 && sub < num_shapes)//범위안에 들어왔을시 true
		return true;
	else
	{
		cout << "Erroe in ConsolePixelFrame :: isValidIndex";
		return false;
	}
		
}