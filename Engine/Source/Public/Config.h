#pragma once

#include "Macro.h"

#include <unordered_map>


/**
 * @brief ���� ������ �Ľ� �� �����մϴ�.
 */
class Config
{
public:
	/**
	 * @brief ���� ������ �Ľ� �� �����ϴ� Ŭ������ �������Դϴ�.
	 * 
	 * @param ResourcePath ���� ������ ����Դϴ�.
	 * 
	 * @throws
	 * ���� �б⿡ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * ���� ���� �Ľ̿� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	Config(const std::string& ResourcePath);


	/**
	 * @brief ���� ������ �Ľ� �� �����ϴ� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~Config();


	/**
	 * @brief ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Config);


	/**
	 * @brief ���� ������Ʈ�� ���� ����ϴ�.
	 * 
	 * @param Key ���� ������Ʈ ���� �����ϴ� Ű ���Դϴ�.
	 * 
	 * @throws Ű ���� �����ϴ� ���� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @return ���� ������Ʈ Ű ���� �����ϴ� ���� ��ȯ�մϴ�.
	 */
	const std::string& GetValue(const std::string& Key);


	/**
	 * @brief ���� ������Ʈ�� Ű-�� ���� �����ڸ� ����ϴ�.
	 * 
	 * @return ���� ������Ʈ�� Ű-�� ���� �����ڸ� ��ȯ�մϴ�.
	 */
	const std::unordered_map<std::string, std::string>& GetConfigObject() const { return Config_; }


private:
	/**
	 * @brief ���� ������ ���۸� �Ľ��մϴ�.
	 * 
	 * @param Buffer ���� ������ �����Դϴ�.
	 * 
	 * @throws �Ľ̿� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @return Ű-�� �� ����� �Ľ� ����� ��ȯ�մϴ�.
	 */
	std::unordered_map<std::string, std::string> ParseConfigFromBuffer(const std::vector<uint8_t>& Buffer);


private:
	/**
	 * @brief Ű-�� ���� ���� ���� ����Դϴ�.
	 */
	std::unordered_map<std::string, std::string> Config_;
};