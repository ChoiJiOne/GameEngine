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
	 * @brief ���� ������Ʈ�� ������Ʈ�� �߰��մϴ�.
	 * 
	 * @note Ű ���� �����ϴ� ������Ʈ�� �����Ѵٸ� �ƹ��� ���۵� �������� �ʽ��ϴ�.
	 *
	 * @param Key �߰��� ������Ʈ�� Ű���Դϴ�.
	 * @param Args ������Ʈ�� �ʿ��� ���� �����Դϴ�.
	 * 
	 * @return �߰��� ������Ʈ�� ������ ���� ��ȯ�մϴ�.
	 */
	template<typename T, typename... Types>
	T* AddComponent(const std::string& Key, Types... Args)
	{
		if (IsValidComponent(Key)) return nullptr;

		std::unique_ptr<T> NewComponent = std::make_unique<T>(this, Args...);
		Components_.insert({ Key, std::move(NewComponent) });

		return reinterpret_cast<T*>(Components_[Key].get());
	}


	/**
	 * @brief ���� ������Ʈ�� �����ϰ� �ִ� ������Ʈ�� ����ϴ�.
	 *
	 * @param Key ���� ������Ʈ�� �����ϰ� �ִ� ������Ʈ�� Ű ���Դϴ�.
	 *
	 * @return Ű ���� �����ϴ� ������Ʈ�� �����ϸ� �ּ� ���� ��ȯ, �׷��� ������ nullptr�� ��ȯ�մϴ�.
	 */
	template<typename T>
	T* GetComponent(const std::string& Key)
	{
		if (!IsValidComponent(Key)) return nullptr;

		return reinterpret_cast<T*>(Components_.at(Key).get());
	}


	/**
	 * @brief ���� ������Ʈ�� �����ϰ� �ִ� ������Ʈ�� �����մϴ�.
	 * 
	 * @note Ű ���� �����ϴ� ������Ʈ�� �������� �ʴ´ٸ�, �ƹ��� ���۵� ���� �ʽ��ϴ�.
	 *
	 * @param Key ���� ������Ʈ�� �����ϰ� �ִ� ������Ʈ�� Ű ���Դϴ�.
	 */
	template<typename T>
	void RemoveComponent(const std::string& Key)
	{
		if (IsValidComponent(Key))
		{
			RemoveValue<std::string, std::unique_ptr<Component>>(Key, Components_);
		}
	}


	/**
	 * @brief ������Ʈ�� Ű ���� ��ȿ���� �˻��մϴ�.
	 *
	 * @param Key �˻縦 ������ Ű ���Դϴ�.
	 *
	 * @return Ű ���� �����ϴ� ������Ʈ�� �����ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool IsValidComponent(const std::string& Key)
	{
		return IsExistKey<std::string, std::unique_ptr<Component>>(Key, Components_);
	}


protected:
	/**
	 * @brief ���� ������Ʈ�� �ñ״�ó�Դϴ�.
	 */
	std::string Signature_;


	/**
	 * @brief ���� ������Ʈ�� �����ϰ� �ִ� ������Ʈ�Դϴ�.
	 */
	std::unordered_map<std::string, std::unique_ptr<Component>> Components_;
};