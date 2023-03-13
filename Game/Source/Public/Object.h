#pragma once

#include "GameObject.h"
#include "Math.hpp"


class Object : public GameObject
{
public:
	Object(const std::string& Signature);
	virtual ~Object() {}
	DISALLOW_COPY_AND_ASSIGN(Object);

	virtual void Tick(float DeltaSeconds) override;
};