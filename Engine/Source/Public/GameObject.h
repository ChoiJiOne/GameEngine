#pragma once

#include "Macro.h"
#include "Utils.hpp"

#include <memory>

class Component;


/**
 * @brief ���� ������Ʈ Ŭ�����Դϴ�.
 * 
 * @note ���� ���� ��� ������Ʈ�� �� Ŭ������ ��� �޾ƾ� �մϴ�.
 */
class GameObject
{
public:
	/**
	 * @brief ���� ������Ʈ�� �������Դϴ�.
	 * 
	 * @param Signature ���� ������Ʈ�� �����ϱ� ���� �ñ״�ó ���ڿ��Դϴ�.
	 */
	GameObject(const std::string& Signature);


	/**
	 * @brief ���� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~GameObject();


	/**
	 * @brief ���� ������Ʈ�� ���� ������ �� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(GameObject);


	/**
	 * @brief ���� ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param DeltaSeconds �ʴ��� ��Ÿ �ð����Դϴ�.
	 */
	virtual void Tick(float DeltaSeconds) = 0;


	/**
	 * @brief ���� ������Ʈ�� �ñ״�ó�� ����ϴ�.
	 * 
	 * @return ���� ������Ʈ�� �ñ״�ó ���� ��ȯ�մϴ�.
	 */
	std::string GetSignature() const { return Signature_; }


	/**
	 * @brief ���� ������Ʈ�� ������Ʈ�� �����մϴ�.
	 * 
	 * @note �̸��� �����ϴ� ������Ʈ�� �����Ѵٸ� �ƹ��� ���۵� �������� �ʽ��ϴ�.
	 *
	 * @param Name ������ ������Ʈ�� �̸��Դϴ�.
	 * @param Args ������Ʈ�� �ʿ��� ���� �����Դϴ�.
	 * 
	 * @return ������ ������Ʈ�� ������ ���� ��ȯ�մϴ�.
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
	 * @brief ���� ������Ʈ�� �����ϰ� �ִ� ������Ʈ�� ����ϴ�.
	 *
	 * @param Name ���� ������Ʈ�� �����ϰ� �ִ� ������Ʈ�� �̸��Դϴ�.
	 *
	 * @return Ű ���� �����ϴ� ������Ʈ�� �����ϸ� �ּ� ���� ��ȯ, �׷��� ������ nullptr�� ��ȯ�մϴ�.
	 */
	template<typename T>
	T* GetComponent(const std::string& Name)
	{
		if (!IsValidComponent(Name)) return nullptr;

		return reinterpret_cast<T*>(OwnComponents_.at(Name).get());
	}


	/**
	 * @brief ���� ������Ʈ�� �����ϰ� �ִ� ������Ʈ�� �����մϴ�.
	 * 
	 * @note Ű ���� �����ϴ� ������Ʈ�� �������� �ʴ´ٸ�, �ƹ��� ���۵� ���� �ʽ��ϴ�.
	 *
	 * @param Name ���� ������Ʈ�� �����ϰ� �ִ� ������Ʈ�� �̸��Դϴ�.
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
	 * @brief ������Ʈ�� Ű ���� ��ȿ���� �˻��մϴ�.
	 *
	 * @param Name �˻縦 ������ �̸��Դϴ�.
	 *
	 * @return Ű ���� �����ϴ� ������Ʈ�� �����ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool IsValidComponent(const std::string& Name)
	{
		return IsExistKey<std::string, std::unique_ptr<Component>>(Name, OwnComponents_);
	}


protected:
	/**
	 * @brief ���� ������Ʈ�� �ñ״�ó�Դϴ�.
	 */
	std::string Signature_;


	/**
	 * @brief ���� ������Ʈ�� �����ϰ� �ִ� ������Ʈ�Դϴ�.
	 */
	std::unordered_map<std::string, std::unique_ptr<Component>> OwnComponents_;
};