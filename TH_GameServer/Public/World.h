#pragma once
class World
{
public:
	bool Initialize();
	void Tick();
	void Destroy();

private:
	bool Load_World_Data();
};