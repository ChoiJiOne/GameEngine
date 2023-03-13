#pragma once

#include "Component.h"
#include "InputManager.h"


/**
 * @brief Ű ���� �Է� ���¿� ���� �����Դϴ�.
 */
struct KeyAction
{
	EVirtualKey VirtualKey;
	EPressState PressState;
	std::function<void()> Action;
};


/**
 * @brief �̺�Ʈ�� ���� �����Դϴ�.
 */
struct EventAction
{
	std::function<bool()> Condition;
	std::function<void()> Action;
};


/**
 * @brief ���� ������Ʈ�� �Է� ó���� �����ϴ� ������Ʈ�Դϴ�.
 */
class InputComponent : public Component
{
public:
	/**
	 * @brief ���� ������Ʈ�� �Է� ó���� �����ϴ� ������Ʈ�� �������Դϴ�.
	 * 
	 * @param Object �� ������Ʈ�� �����ϴ� ������Ʈ�� ������ ���Դϴ�.
	 */
	InputComponent(GameObject* Object)
		: Component(Object) {}


	/**
	 * @brief ���� ������Ʈ�� �Է� ó���� �����ϴ� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~InputComponent() {}


	/**
	 * @brief ���� ������Ʈ�� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(InputComponent);


	/**
	 * @brief ���� ������Ʈ�� �Է� ó�� ������Ʈ�� ������Ʈ�մϴ�.
	 */
	virtual void Tick();


	/**
	 * @brief Ű�� �Է� ���¿� ���� ������ ���ε��մϴ�.
	 *
	 * @note �̸��� �ߺ��Ǹ�, ������ �̺�Ʈ�� ���� �����ϴ�.
	 *
	 * @param Name ���ε��� Ű �׼��� �̸��Դϴ�.
	 * @param Action ���ε��� �׼��Դϴ�.
	 */
	void BindKeyAction(const std::string& Name, const KeyAction& Action);


	/**
	 * @brief �̺�Ʈ�� ���� ������ ���ε��մϴ�.
	 * 
	 * @note �̸��� �ߺ��Ǹ�, ������ �̺�Ʈ�� ���� �����ϴ�.
	 * 
	 * @param Name ���ε��� �̺�Ʈ �׼��� �̸��Դϴ�.
	 * @param Action ���ε��� �̺�Ʈ �׼��Դϴ�.
	 */
	void BindEventAction(const std::string& Name, const EventAction& Action);


	/**
	 * @brief ���ε��� Ű�� �Է� ���¿� ���� ������ ����ε��մϴ�.
	 *
	 * @param Name ���ε��� ������ �׼��� �̸��Դϴ�.
	 */
	void UnbindKeyAction(const std::string& Name);


	/**
	 * @brief ���ε��� �̺�Ʈ�� ���� ������ ����ε��մϴ�.
	 * 
	 * @param Name ���ε��� ������ �׼��� �̸��Դϴ�.
	 */
	void UnbindEventAction(const std::string& Name);


private:
	/**
	 * @brief Ű ���� �����ϴ� Ű �׼��Դϴ�.
	 */
	std::unordered_map<std::string, KeyAction> KeyActions_;


	/**
	 * @brief Ű ���� �����ϴ� �̺�Ʈ �׼��Դϴ�.
	 */
	std::unordered_map<std::string, EventAction> EventActions_;
};