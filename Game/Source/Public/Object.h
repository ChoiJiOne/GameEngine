#pragma once

#include "GameObject.h"


class Object : public GameObject
{
public:
	Object(const std::string& Signature);
	virtual ~Object() {}
	DISALLOW_COPY_AND_ASSIGN(Object);

	virtual void Tick(float DeltaSeconds) override;

private:
	
};