#pragma once

#include "Macro.h"
#include "Utils.hpp"

#include <memory>

class Component;


/**
 * @brief 게임 오브젝트 클래스입니다.
 * 
 * @note 게임 내의 모든 오브젝트는 이 클래스를 상속 받아야 합니다.
 */
class GameObject
{
public:
	/**
	 * @brief 게임 오브젝트의 생성자입니다.
	 * 
	 * @param Signature 게임 오브젝트를 구분하기 위한 시그니처 문자열입니다.
	 */
	GameObject(const std::string& Signature);


	/**
	 * @brief 게임 오브젝트의 가상 소멸자입니다.
	 */
	virtual ~GameObject();


	/**
	 * @brief 게임 오브젝트의 복사 생성자 및 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(GameObject);


	/**
	 * @brief 게임 오브젝트를 업데이트합니다.
	 *
	 * @param DeltaSeconds 초단위 델타 시간값입니다.
	 */
	virtual void Tick(float DeltaSeconds) = 0;


	/**
	 * @brief 게임 오브젝트의 시그니처를 얻습니다.
	 * 
	 * @return 게임 오브젝트의 시그니처 값을 반환합니다.
	 */
	std::string GetSignature() const { return Signature_; }


	/**
	 * @brief 게임 오브젝트의 컴포넌트를 생성합니다.
	 * 
	 * @note 이름에 대응하는 컴포넌트가 존재한다면 아무런 동작도 수행하지 않습니다.
	 *
	 * @param Name 생성할 컴포넌트의 이름입니다.
	 * @param Args 컴포넌트에 필요한 가변 인자입니다.
	 * 
	 * @return 생성한 컴포넌트의 포인터 값을 반환합니다.
	 */
	template<typename T, typename... Types>
	T* CreateComponent(const std::string& Name, Types... Args)
	{
		if (IsValidComponent(Name)) return nullptr;

		std::unique_ptr<T> NewComponent = std::make_unique<T>(this, Args...);
		OwnComponents_.insert({ Name, std::move(NewComponent) });

		return reinterpret_cast<T*>(OwnComponents_[Name].get());
	}


	/**
	 * @brief 게임 오브젝트가 소유하고 있는 컴포넌트를 얻습니다.
	 *
	 * @param Name 게임 오브젝트가 소유하고 있는 컴포넌트의 이름입니다.
	 *
	 * @return 키 값에 대응하는 컴포넌트가 존재하면 주소 값을 반환, 그렇지 않으면 nullptr를 반환합니다.
	 */
	template<typename T>
	T* GetComponent(const std::string& Name)
	{
		if (!IsValidComponent(Name)) return nullptr;

		return reinterpret_cast<T*>(OwnComponents_.at(Name).get());
	}


	/**
	 * @brief 게임 오브젝트가 소유하고 있는 컴포넌트를 삭제합니다.
	 * 
	 * @note 키 값에 대응하는 컴포넌트가 존재하지 않는다면, 아무런 동작도 하지 않습니다.
	 *
	 * @param Name 게임 오브젝트가 소유하고 있는 컴포넌트의 이름입니다.
	 */
	template<typename T>
	void RemoveComponent(const std::string& Name)
	{
		if (IsValidComponent(Name))
		{
			RemoveValue<std::string, std::unique_ptr<Component>>(Name, OwnComponents_);
		}
	}


	/**
	 * @brief 컴포넌트의 키 값이 유효한지 검사합니다.
	 *
	 * @param Name 검사를 수행할 이름입니다.
	 *
	 * @return 키 값에 대응하는 컴포넌트가 존재하면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool IsValidComponent(const std::string& Name)
	{
		return IsExistKey<std::string, std::unique_ptr<Component>>(Name, OwnComponents_);
	}


protected:
	/**
	 * @brief 게임 오브젝트의 시그니처입니다.
	 */
	std::string Signature_;


	/**
	 * @brief 게임 오브젝트가 소유하고 있는 컴포넌트입니다.
	 */
	std::unordered_map<std::string, std::unique_ptr<Component>> OwnComponents_;
};