#pragma once

#include "GameObject.h"
#include "Math.hpp"


class CircleObject : public GameObject
{
public:
	CircleObject(const std::string& Signature);
	virtual ~CircleObject() {}
	DISALLOW_COPY_AND_ASSIGN(CircleObject);
	virtual void Tick(float DeltaSeconds) override;

private:
	class InputComponent* InputComponent_ = nullptr;
	class CircleComponent* BoundComponent_ = nullptr;
	class BoundRenderComponent* RenderComponent_ = nullptr;
};