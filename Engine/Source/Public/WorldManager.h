#pragma once

#include "Macro.h"
#include "Camera2D.h"
#include "GameObject.h"
#include "Utils.hpp"


/**
 * @brief ���� ������Ʈ�� ��ġ�� 2D �����Դϴ�.
 * 
 * @note �� Ŭ������ �̱������� ����� �߰��ϸ� �ٷ� ����� �� �ֽ��ϴ�.
 */
class WorldManager
{
public:
	/**
	 * @brief ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(WorldManager);


	/**
	 * @brief WorldManager�� �̱� �ν��Ͻ��� ����ϴ�.
	 *
	 * @return WorldManager�� �ν��Ͻ��� ��ȯ�մϴ�.
	 */
	static WorldManager& Get()
	{
		static WorldManager Instance;
		return Instance;
	}


	/**
	 * @brief 2D ������ ���� ������Ʈ�� �����մϴ�.
	 * 
	 * @param Signature ���� ������Ʈ�� �����ϴ� �ñ״�ó ���Դϴ�.
	 * @param Args ���� ������Ʈ�� �����ϱ� ���� ���� �����Դϴ�.
	 * 
	 * @thows ���� ������Ʈ ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @return ������ ���� ������Ʈ�� �����͸� ��ȯ�մϴ�.
	 */
	template <typename Object, typename... Types>
	Object* CreateGameObject(const std::string& Signature, Types... Args)
	{
		CHECK(!IsExistGameObject(Signature), "already exist game object or collision key value");

		std::unique_ptr<Object> NewObject = std::make_unique<Object>(Signature, Args...);
		GameObjects_.insert({ Signature, std::move(NewObject) });

		return reinterpret_cast<Object*>(GameObjects_.at(Signature).get());
	}

	
	/**
	 * 2D ���忡 ������Ʈ�� ��ϵǾ����� Ȯ���մϴ�.
	 *
	 * @param Key ��ϵǾ����� Ȯ���� ������Ʈ�� Ű ���Դϴ�.
	 *
	 * @return ���� ���忡 ��� �Ǿ��ٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsRegisterObject(const std::string& Key);


	/**
	 * Ű ���� �����ϴ� 2D ������ ������Ʈ�� ����ϴ�.
	 *
	 * @param Key ���� ���忡 �ִ� ������Ʈ�� Ű ���Դϴ�.
	 *  
	 * @return Ű ���� �����ϴ� ���� ������ ������Ʈ�� �����ϸ� �ּ� ���� ��ȯ, �׷��� ������ nullptr�� ��ȯ�մϴ�.
	 */
	template <typename Object>
	Object* GetGameObject(const std::string& Key)
	{
		if (!IsExistGameObject(Key)) return nullptr;
			 
		return reinterpret_cast<Object*>(GameObjects_.at(Key).get());
	}


	/**
	 * @brief 2D ���忡 ������Ʈ�� ��� �����մϴ�.
	 * 
	 * @note �ش� ������Ʈ�� �������� �ʴ´ٸ� �ƹ� ���۵� ���� �ʽ��ϴ�.
	 *
	 * @param Key ���� ���忡�� ��� ������ ������Ʈ�� Ű ���Դϴ�.
	 */
	void UnregisterObject(const std::string& Key);


	/**
	 * @brief 2D ������ ���� ī�޶� �����մϴ�.
	 * 
	 * @param Position 2D World�� ī�޶� ��ġ�Դϴ�.
	 * @param Width ī�޶��� ���� ũ���Դϴ�.
	 * @param Height ī�޶��� ���� ũ���Դϴ�.
	 * @param Rotate ī�޶��� �̵� �����Դϴ�. �̶� ȸ������ ���� ���� �����Դϴ�.
	 * @param Velocity ī�޶��� �̵� �ӷ��Դϴ�.
	 * 
	 * @return ������ 2D ���� ī�޶��� �����ڸ� ��ȯ�մϴ�.
	 */
	Camera2D& CreateMainCamera(
		const Vec2f& Position,
		const float& Width,
		const float& Height,
		const float& Rotate = 0.0f,
		const float& Velocity = 0.0f
	);


	/**
	 * @brief 2D ������ ī�޶� ����ϴ�.
	 * 
	 * @return 2D ������ ī�޶� ��ȯ�մϴ�.
	 */
	Camera2D& GetMainCamera();


	/**
	 * @brief 2D ������ ī�޶� �ı��մϴ�.
	 */
	void DestroyMainCamera();

	
private:
	/**
	 * @brief ���� ������ �������Դϴ�.
	 */
	WorldManager() = default;


	/**
	 * @brief ���� ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~WorldManager();


	/**
	 * @brief ���� ���尡 �����ϴ� ���� ������Ʈ�� �����ϴ��� �˻��մϴ�.
	 * 
	 * @param Key �˻縦 ������ Ű ���Դϴ�.
	 * 
	 * @return Ű ���� �����ϴ� ���� ������Ʈ�� �����ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool IsExistGameObject(const std::string& Key)
	{
		return IsExistKey<std::string, std::unique_ptr<GameObject>>(Key, GameObjects_);
	}


	/**
	 * @brief ���� ���尡 �����ϴ� ���� ������Ʈ�� �����մϴ�.
	 * 
	 * @note Ű ���� �����ϴ� ���� ������Ʈ�� �������� �ʴ´ٸ�, �ƹ��� ���۵� ���� �ʽ��ϴ�.
	 * 
	 * @param Key ���� ������Ʈ�� �����ϰ� �ִ� ������Ʈ�� Ű ���Դϴ�.
	 */
	void RemoveGameObject(const std::string& Key)
	{
		if (IsExistGameObject(Key))
		{
			RemoveValue<std::string, std::unique_ptr<GameObject>>(Key, GameObjects_);
		}
	}


private:
	/**
	 * @brief ���� ���� ���� ī�޶��Դϴ�.
	 */
	std::unique_ptr<Camera2D> MainCamera_ = nullptr;
	

	/**
	 * @brief ���� ���� ���� �����ϴ� ���� ������Ʈ�Դϴ�.
	 */
	std::unordered_map<std::string, std::unique_ptr<GameObject>> GameObjects_;
};