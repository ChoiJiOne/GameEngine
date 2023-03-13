#pragma once

#include "GameObject.h"
#include "Math.hpp"


class OBBObject : public GameObject
{
public:
	OBBObject(const std::string& Signature);
	virtual ~OBBObject() {}
	DISALLOW_COPY_AND_ASSIGN(OBBObject);
	virtual void Tick(float DeltaSeconds) override;

private:
	class InputComponent* InputComponent_ = nullptr;
	class OBBComponent* BoundComponent_ = nullptr;
	class BoundRenderComponent* RenderComponent_ = nullptr;
};