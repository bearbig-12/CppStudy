#pragma once
class Character
{
protected:
	int mHp;
public:
	Character();
	virtual ~Character();

public:
	virtual void Attack() const;

};