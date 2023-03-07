#include "CrashHandler.h"
#include "CommandLine.h"
#include "RenderManager.h"
#include "Shader.h"
#include "InputManager.h"
#include "Window.h"

#include <memory>


/**
 * @brief ���ø����̼��� �����մϴ�.
 *
 * @param ArgC ����� ������ ���Դϴ�.
 * @param ArgV ����� �����Դϴ�.
 *
 * @throws ���� �߻� �� ���� ������ �����ϰ� ���α׷��� ����˴ϴ�.
 */
void RunApplication(int32_t ArgC, char* ArgV[])
{
	CommandLine::ParseFromArgV(ArgC, ArgV);

	CrashHandler::SetDumpFilePath(CommandLine::GetValue("Dump"));

	std::unique_ptr<Window> MainWindow = std::make_unique<Window>(L"Development",100, 100, 1000, 800, false);

	RenderManager::Get().Setup(MainWindow.get());
	InputManager::Get().Setup(MainWindow.get());

	RenderManager::Get().SetDepthBuffer(false);
	RenderManager::Get().SetAlphaBlend(true);
	RenderManager::Get().SetFillMode(true);

	bool bIsDone_ = false;
	std::function<void()> CloseEvent = [&]() { bIsDone_ = true; };
	std::function<void()> ResizeEvent = [&]() {
		RenderManager::Get().Resize();
		float Width = 0.0f, Height = 0.0f;
		RenderManager::Get().GetBackBufferSize(Width, Height);
		RenderManager::Get().SetViewport(0.0f, 0.0f, Width, Height);
	};

	const std::unordered_map<EWindowEvent, std::function<void()>> WindowEvents = {
			{ EWindowEvent::CLOSE,         CloseEvent    },
			{ EWindowEvent::MAXIMIZED,     ResizeEvent   },
			{ EWindowEvent::RESIZE,        ResizeEvent   },
	};

	for (const auto& WindowEvent : WindowEvents)
	{
		InputManager::Get().BindWindowEvent(WindowEvent.first, WindowEvent.second);
	}

	LinearColor ClearColor = LinearColor(0.0f, 0.0f, 0.0f, 1.0f);
	InputManager::Get().GetKeyboard().BindKeyAction(
		"LEFT",
		Keyboard::KeyAction{
			EVirtualKey::CODE_LEFT,
			EKeyPressState::PRESSED,
			[&]() {
				ClearColor = LinearColor(1.0f, 0.0f, 0.0f, 1.0f);
			}
		}
	);

	InputManager::Get().GetKeyboard().BindKeyAction(
		"RIGHT",
		Keyboard::KeyAction{
			EVirtualKey::CODE_RIGHT,
			EKeyPressState::PRESSED,
			[&]() {
				ClearColor = LinearColor(1.0f, 0.0f, 1.0f, 1.0f);
			}
		}
	);

	while (!bIsDone_)
	{
		InputManager::Get().Tick();

		RenderManager::Get().Clear(ClearColor);
		RenderManager::Get().Present();
	}

	RenderManager::Get().Cleanup();
	InputManager::Get().Cleanup();
	MainWindow.reset();
}


/**
 * @brief ���ø����̼��� �������Դϴ�.
 *
 * @param ArgC ����� ������ ���Դϴ�.
 * @param ArgV ����� �����Դϴ�.
 *
 * @return �ٸ� ���α׷��� ������ �� �ִ� ���� �ڵ带 ��ȯ�մϴ�.
 */
int main(int ArgC, char* ArgV[])
{
	__try
	{
		RunApplication(ArgC, ArgV);
	}
	__except (CrashHandler::DetectApplicationCrash(GetExceptionInformation()))
	{
		CrashHandler::ShowCrashMessageBox();
	}

	return 0;
}