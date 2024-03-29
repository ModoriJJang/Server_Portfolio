#pragma once
class Cell
{
public:
	bool Initialize();
	void Tick( float DeltaTime );
	void Destroy();

private:
	bool Load_Cell_Data();

private:
	bool _activeCell = false;
	float _deactiveTime = 0.f;
};