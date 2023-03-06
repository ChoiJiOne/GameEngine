#pragma once

#include <string>
#include <unordered_map>


/**
 * @brief Ŀ�ǵ� ������ �Ľ��ϰ� ���� ���� ������ �����ϴ� Ŭ�����Դϴ�.
 *
 * @note �� Ŭ������ ��� ��� �Լ��� ������ ������ ���� Ŭ�����Դϴ�.
 */
class CommandLine
{
public:
	/**
	 * @brief ����� ���� ���� �Ľ��մϴ�.
	 *
	 * @param ArgC ����� ������ ���Դϴ�.
	 * @param ArgV ����� �����Դϴ�.
	 */
	static void ParseFromArgV(int32_t ArgC, char* ArgV[]);


	/**
	 * @brief ���� ���� ��θ� ����ϴ�.
	 *
	 * @return ���� ���� ��θ� ��ȯ�մϴ�.
	 */
	static std::string GetExecutePath() { return ExecutePath_; }


	/**
	 * @brief Ű ���� ��ȿ���� �˻��մϴ�.
	 *
	 * @param Key ��ȿ���� �˻��� Ű ���Դϴ�.
	 *
	 * @return Ű ���� �����ϴ� ���� �ִٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	static bool IsValid(const std::string& Key);


	/**
	 * @brief Ű ���� �����ϴ� ���� ����ϴ�.
	 *
	 * @param Key �������� �ϴ� ����  Ű ���Դϴ�.
	 *
	 * @return Ű ���� �����ϴ� ���� ��ȯ�մϴ�.
	 */
	static std::string GetValue(const std::string& Key);


private:
	/**
	 * @brief ���� ���� ����Դϴ�.
	 */
	static std::string ExecutePath_;


	/**
	 * @brief ����� ������ Ű-�� ���Դϴ�.
	 */
	static std::unordered_map<std::string, std::string> ArgumentValues_;
};