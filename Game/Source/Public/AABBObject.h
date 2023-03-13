#pragma once

#include "GameObject.h"
#include "Math.hpp"


class AABBObject : public GameObject
{
public:
	AABBObject(const std::string& Signature);
	virtual ~AABBObject() {}
	DISALLOW_COPY_AND_ASSIGN(AABBObject);
	virtual void Tick(float DeltaSeconds) override;

private:
	class InputComponent* InputComponent_ = nullptr;
	class AABBComponent* BoundComponent_ = nullptr;
	class BoundRenderComponent* RenderComponent_ = nullptr;
};