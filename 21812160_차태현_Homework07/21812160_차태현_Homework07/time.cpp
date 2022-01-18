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

int Time::elasedSec()const//초로 시간 나타내기
{
	int second = 0;

	second += sec;
	second += min * 60;//분을 초로 표현
	second += hour * 3600;//시간을 초로 표현

	return second;
}

bool Time::operator<(const Time& t) const//시간비교
{
	if (elasedSec() < t.elasedSec())
		return true;
	else
		return false;
}

bool Time::operator<=(const Time& t) const//시간비교
{
	if (elasedSec() <= t.elasedSec())
		return true;
	else
		return false;
}

bool Time::operator>(const Time& t) const//시간비교
{
	if (elasedSec() > t.elasedSec())
		return true;
	else
		return false;
}

bool Time::operator>=(const Time& t) const//시간비교
{
	if (elasedSec() >= t.elasedSec())
		return true;
	else
		return false;
}

bool Time::operator==(const Time& t) const//시간 같은지 비교
{
	if (elasedSec() == t.elasedSec())
		return true;
	else
		return false;
}



bool Time::isValidTime(int h, int m, int s)//시간이 정상범위에 있는지 판별
{
	if ((h >= 0 || h <= 24) && (m >= 0 || m <= 60) && (s >= 0 || s <= 60))
		return true;
	else
		return false;
}