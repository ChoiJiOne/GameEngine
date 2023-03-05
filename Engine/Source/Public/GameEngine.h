#pragma once

#include "Macro.h"

#include <memory>

class Window;


/**
 * @brief ���� �����Դϴ�.
 * 
 * @note ������ �����Ǵ� Ŭ������ �� ������ �ݵ�� ��ӹ޾ƾ� �մϴ�.
 */
class GameEngine
{
public:
	/**
	 * @brief ���� ������ �⺻ �������Դϴ�.
	 * 
	 * @note ���� ������ �ʱ�ȭ �ϱ� ���ؼ��� �ݵ�� Initialize �޼��带 ȣ���ؾ� �մϴ�.
	 */
	GameEngine() = default;


	/**
	 * @brief ���� ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~GameEngine();


	/**
	 * @brief ���� ������ �ʱ�ȭ�մϴ�.
	 * 
	 * @note ������ Initialize �޼��忡�� �� �޼��带 ȣ���ؾ� �մϴ�.
	 * 
	 * @throws ���� ���� �ʱ�ȭ�� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	virtual void Initialize();


	/**
	 * @brief ���� ������ �����մϴ�.
	 * 
	 * @note ���� �Լ���, �ݵ�� ���� Ŭ�������� �����ؾ� �մϴ�.
	 */
	virtual void Run() = 0;


private:
	/**
	 * @brief ���� ���Ϸκ��� ������ â�� �����մϴ�.
	 * 
	 * @throws 
	 * ���� ���� �ε� �� �Ľ̿� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * ������ â ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void CreateWindowFromConfig();


	/**
	 * @brief ���� ���Ϸκ��� ��Ʈ ������ �ε��մϴ�.
	 * 
	 * @throws
	 * ���� ���� �ε� �� �Ľ̿� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * ��Ʈ ���ҽ� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void LoadFontFromConfig();


	/**
	 * @brief ���� ���Ϸκ��� �ؽ�ó ������ �ε��մϴ�.
	 * 
	 * @throws
	 * ���� ���� �ε� �� �Ľ̿� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * �ؽ�ó ���ҽ� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void LoadTextureFromConfig();


	/**
	 * @brief ���� ���Ϸκ��� ����� ������ �ε��մϴ�.
	 * 
	 * @throws
	 * ���� ���� �ε� �� �Ľ̿� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * ����� ���ҽ� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void LoadAudioFromConfig();


protected:
	/**
	 * @brief ���� ������ �����ϴ� ������ â�Դϴ�.
	 */
	std::unique_ptr<Window> Window_ = nullptr;


	/**
	 * @brief ���� ������ ������ �� Ȯ���մϴ�.
	 */
	bool bIsDone_ = false;
};