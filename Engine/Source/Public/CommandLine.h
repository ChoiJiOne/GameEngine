#pragma once

#include "Macro.h"

#include <vector>
#include <unordered_map>


/**
 * @brief Ŀ�ǵ� ������ �Ľ��ϰ�, ���ڸ� �����մϴ�.
 * 
 * @note �� Ŭ������ �̱������� ����� �߰��ϸ� �ٷ� ����� �� �ֽ��ϴ�.
 */
class CommandLineManager
{
public:
	/**
	 * @brief ���� �����ڿ� ���� �����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(CommandLineManager);


	/**
	 * @brief CommandLineManager�� �ν��Ͻ��� ����ϴ�.
	 *
	 * @return CommandLineManager�� �ν��Ͻ��� �����ڸ� ��ȯ�մϴ�.
	 */
	static CommandLineManager& Get()
	{
		static CommandLineManager Instance;
		return Instance;
	}


	/**
	 * @brief UTF-8 ����� ��ü Ŀ�ǵ� ������ ����ϴ�.
	 *
	 * @return UTF-8 ����� ��ü Ŀ�ǵ� ���� ���ڿ��� ��ȯ�մϴ�.
	 */
	const std::string& GetFullCommanLineA() { return CommandLineA_; }


	/**
	 * @brief UTF-16 ����� ��ü Ŀ�ǵ� ������ ����ϴ�.
	 *
	 * @return UTF-16 ����� ��ü Ŀ�ǵ� ���� ���ڿ��� ��ȯ�մϴ�.
	 */
	const std::wstring& GetFullCommanLineW() { return CommandLineW_; }


	/**
	 * @brief UTF-8 ����� Ŀ�ǵ� ���ο� �ɼ��� �����ϴ��� Ȯ���մϴ�.
	 *
	 * @param Option �����ϴ��� Ȯ���� �ɼ��Դϴ�.
	 *
	 * @return �ɼ��� �����ϸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool HaveOption(const std::string& Option);



	/**
	 * @brief UTF-16 ����� Ŀ�ǵ� ���ο� �ɼ��� �����ϴ��� Ȯ���մϴ�.
	 *
	 * @param Option �����ϴ��� Ȯ���� �ɼ��Դϴ�.
	 *
	 * @return �ɼ��� �����ϸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool HaveOption(const std::wstring& Option);


	/**
	 * @brief UTF-8 ����� �ɼǿ� �ش��ϴ� ���� ����ϴ�.
	 *
	 * @param Option �ɼ��Դϴ�.
	 *
	 * @return �ɼǿ� �����ϴ� ���� ��ȯ�մϴ�. �ɼǿ� �����ϴ� ���� �������� �ʴ´ٸ�, �� ���ڿ��� ��ȯ�մϴ�.
	 */
	std::string GetValue(const std::string& Option);


	/**
	 * @brief UTF-16 ����� �ɼǿ� �ش��ϴ� ���� ����ϴ�.
	 *
	 * @param Option �ɼ��Դϴ�.
	 *
	 * @return �ɼǿ� �����ϴ� ���� ��ȯ�մϴ�. �ɼǿ� �����ϴ� ���� �������� �ʴ´ٸ�, �� ���ڿ��� ��ȯ�մϴ�.
	 */
	std::wstring GetValue(const std::wstring& Option);


private:
	/**
	 * @brief Ŀ�ǵ� ������ �Ľ��ϰ�, ���ڸ� �����ϴ� Ŭ������ �������Դϴ�.
	 */
	CommandLineManager();


	/**
	 * @brief Ŀ�ǵ� ������ �Ľ��ϰ�, ���ڸ� �����ϴ� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~CommandLineManager() = default;


	/**
	 * @brief UTF-8 ����� �ʱ�ȭ�� �����մϴ�. 
	 */
	void ParseCommandLineA();


	/**
	 * @brief UTF-16 ����� �ʱ�ȭ�� �����մϴ�.
	 */
	void ParseCommandLineW();


private:
	/**
	 * @brief ���� ���� �� ���� ���� UTF-8 Ŀ�ǵ� �����Դϴ�.
	 */
	std::string CommandLineA_;


	/**
	 * @brief ���� ���� �� ���� ���� UTF-16 Ŀ�ǵ� �����Դϴ�.
	 */
	std::wstring CommandLineW_;


	/**
	 * @brief ���� ���� �� ���� ���� UTF-8 Ŀ�ǵ� ���� �����Դϴ�.
	 */
	std::vector<std::string> ArgumentsA_;


	/**
	 * @brief ���� ���� �� ���� ���� UTF-16 Ŀ�ǵ� ���� �����Դϴ�.
	 */
	std::vector<std::wstring> ArgumentsW_;


	/**
	 * @brief Ŀ�ǵ� ���� �Է����� ���� UTF-8 �ɼ��Դϴ�.
	 */
	std::unordered_map<std::string, std::string> OptionsA_;


	/**
	 * @brief Ŀ�ǵ� ���� �Է����� ���� UTF-16 �ɼ��Դϴ�.
	 */
	std::unordered_map<std::wstring, std::wstring> OptionsW_;
};