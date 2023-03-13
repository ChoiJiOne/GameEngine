#pragma once

#include "Component.h"
#include "InputManager.h"


/**
 * @brief 키 값의 입력 상태에 따른 동작입니다.
 */
struct KeyAction
{
	EVirtualKey VirtualKey;
	EPressState PressState;
	std::function<void()> Action;
};


/**
 * @brief 이벤트에 따른 동작입니다.
 */
struct EventAction
{
	std::function<bool()> Condition;
	std::function<void()> Action;
};


/**
 * @brief 게임 오브젝트의 입력 처리를 수행하는 컴포넌트입니다.
 */
class InputComponent : public Component
{
public:
	/**
	 * @brief 게임 오브젝트의 입력 처리를 수행하는 컴포넌트의 생성자입니다.
	 * 
	 * @param Object 이 컴포넌트를 소유하는 오브젝트의 포인터 값입니다.
	 */
	InputComponent(GameObject* Object)
		: Component(Object) {}


	/**
	 * @brief 게임 오브젝트의 입력 처리를 수행하는 컴포넌트의 가상 소멸자입니다.
	 */
	virtual ~InputComponent() {}


	/**
	 * @brief 게임 오브젝트의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(InputComponent);


	/**
	 * @brief 게임 오브젝트의 입력 처리 컴포넌트를 업데이트합니다.
	 */
	virtual void Tick();


	/**
	 * @brief 키의 입력 상태에 따른 동작을 바인딩합니다.
	 *
	 * @note 이름이 중복되면, 기존의 이벤트는 덮어 써집니다.
	 *
	 * @param Name 바인딩할 키 액션의 이름입니다.
	 * @param Action 바인딩할 액션입니다.
	 */
	void BindKeyAction(const std::string& Name, const KeyAction& Action);


	/**
	 * @brief 이벤트에 따른 동작을 바인딩합니다.
	 * 
	 * @note 이름이 중복되면, 기존의 이벤트는 덮어 써집니다.
	 * 
	 * @param Name 바인딩할 이벤트 액션의 이름입니다.
	 * @param Action 바인딩할 이벤트 액션입니다.
	 */
	void BindEventAction(const std::string& Name, const EventAction& Action);


	/**
	 * @brief 바인딩된 키의 입력 상태에 따른 동작을 언바인딩합니다.
	 *
	 * @param Name 바인딩을 해제할 액션의 이름입니다.
	 */
	void UnbindKeyAction(const std::string& Name);


	/**
	 * @brief 바인딩된 이벤트에 따른 동작을 언바인딩합니다.
	 * 
	 * @param Name 바인딩을 해제할 액션의 이름입니다.
	 */
	void UnbindEventAction(const std::string& Name);


private:
	/**
	 * @brief 키 값에 대응하는 키 액션입니다.
	 */
	std::unordered_map<std::string, KeyAction> KeyActions_;


	/**
	 * @brief 키 값에 대응하는 이벤트 액션입니다.
	 */
	std::unordered_map<std::string, EventAction> EventActions_;
};