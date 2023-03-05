#pragma once

#include "Macro.h"
#include "Utils.hpp"

#include <vector>
#include <functional>

class GameObject;


/**
 * @brief ���� ���� �����մϴ�.
 */
class Scene
{
public:
	/**
	 * @brief ���� ���� �⺻ �������Դϴ�.
	 */
	Scene() = default;


	/**
	 * @brief ���� ���� ���� �Ҹ����Դϴ�.
	 */
	virtual ~Scene() = default;


	/**
	 * @brief ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Scene);


	/**
	 * @brief ���� ���� ������Ʈ�մϴ�.
	 * 
	 * @param DeltaSeconds �ʴ��� ��Ÿ �ð����Դϴ�.
	 */
	virtual void Update(float DeltaSeconds) = 0;

	
	/**
	 * @brief ���� ���� �����մϴ�.
	 */
	virtual void Reset() = 0;


	/**
	 * @brief �� ��ȯ�� �߻����� ��, ������ �̺�Ʈ�� �߰��մϴ�.
	 * 
	 * @note Ű ���� �����ϴ� �̺�Ʈ�� �����ϸ� ���� �����ϴ�.
	 * 
	 * @param Key �̺�Ʈ�� Ű ���Դϴ�.
	 * @param SwitchEvent �� ��ȯ�� �߻��� �� ������ �̺�Ʈ�Դϴ�.
	 */
	void AddSwitchEvent(const std::string& Key, const std::function<void()>& SwitchEvent) 
	{ 
		SwitchEvents_.insert({ Key, SwitchEvent });
	}


	/**
	 * @brief �� ��ȯ�� �߻����� ��, ������ �̺�Ʈ�� �����մϴ�.
	 * 
	 * @param Key �̺�Ʈ�� Ű ���Դϴ�.
	 */
	void RemoveSwitchEvent(const std::string& Key)
	{
		RemoveValue<std::string, std::function<void()>>(Key, SwitchEvents_);
	}


protected:
	/**
	 * @brief �� ��ȯ�� �߻����� ��, �̺�Ʈ�� �����մϴ�.
	 * 
	 * @param Key ������ �̺�Ʈ�� Ű ���Դϴ�.
	 */
	void RunSwitchEvent(const std::string& Key)
	{
		if (IsExistKey<std::string, std::function<void()>>(Key, SwitchEvents_))
		{
			SwitchEvents_.at(Key)();
		}
	}


private:
	/**
	 * @brief �� ��ȯ�� �߻����� ��, ������ �̺�Ʈ�Դϴ�.
	 */
	std::unordered_map<std::string, std::function<void()>> SwitchEvents_;
};