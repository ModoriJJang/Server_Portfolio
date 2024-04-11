#pragma once
class GameObject abstract
{
public:
	int _NetworkID;
	int _HP;
	bool _Updated = true;
	std::string _onwer;
};

