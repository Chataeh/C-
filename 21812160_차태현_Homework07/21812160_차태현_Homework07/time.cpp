#include"Time.h"
#include<iomanip>

ostream& operator<<(ostream& cout, const Time& t)
{

	cout << "(" << setw(2) << t.hour << ":" << setw(2) << t.min << ":" << setw(2) << t.sec << ")";

	return cout;
}

Time::Time(int h, int m, int s)
	:hour(h), min(m), sec(s)
{

}
Time& Time::operator+(int s)
{
	
	sec = sec+s;
	while (sec >= 60)
	{
		
		sec = sec - 60;
		min++;
		if (min >= 60)
		{
			min = min - 60;
			hour++;
			if (hour >= 24)
				hour = hour % 24;
		}
		
	}
	return *this;
}

int Time::elasedSec()const//�ʷ� �ð� ��Ÿ����
{
	int second = 0;

	second += sec;
	second += min * 60;//���� �ʷ� ǥ��
	second += hour * 3600;//�ð��� �ʷ� ǥ��

	return second;
}

bool Time::operator<(const Time& t) const//�ð���
{
	if (elasedSec() < t.elasedSec())
		return true;
	else
		return false;
}

bool Time::operator<=(const Time& t) const//�ð���
{
	if (elasedSec() <= t.elasedSec())
		return true;
	else
		return false;
}

bool Time::operator>(const Time& t) const//�ð���
{
	if (elasedSec() > t.elasedSec())
		return true;
	else
		return false;
}

bool Time::operator>=(const Time& t) const//�ð���
{
	if (elasedSec() >= t.elasedSec())
		return true;
	else
		return false;
}

bool Time::operator==(const Time& t) const//�ð� ������ ��
{
	if (elasedSec() == t.elasedSec())
		return true;
	else
		return false;
}



bool Time::isValidTime(int h, int m, int s)//�ð��� ��������� �ִ��� �Ǻ�
{
	if ((h >= 0 || h <= 24) && (m >= 0 || m <= 60) && (s >= 0 || s <= 60))
		return true;
	else
		return false;
}