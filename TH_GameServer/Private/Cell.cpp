#include "Cell.h"

#include "nlohmann/json.hpp"

bool Cell::Initialize()
{
	return false;
}

void Cell::Tick( float DeltaTime )
{
	if ( _activeCell == false )
	{
		_deactiveTime += DeltaTime;
		if ( _deactiveTime > 60.f )
		{
			//���� ����
		}
		return;
	}
	_deactiveTime = 0.f;
	//���� ���� ����

}

void Cell::Destroy()
{
}

bool Cell::Load_Cell_Data()
{
	return false;
}
