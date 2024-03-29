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
			//몬스터 삭제
		}
		return;
	}
	_deactiveTime = 0.f;
	//몬스터 로직 구동

}

void Cell::Destroy()
{
}

bool Cell::Load_Cell_Data()
{
	return false;
}
