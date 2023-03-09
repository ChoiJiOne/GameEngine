#include "CrashHandler.h"
#include "CommandLine.h"
#include "GameTimer.h"
#include "RenderManager.h"
#include "Shader.h"
#include "InputManager.h"
#include "Window.h"


/**
 * �׽�Ʈ�� ��� ���� �߰�
 */
#include "TTFont.h"
#include "Texture2D.h"

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

	std::string FontPath = CommandLine::GetValue("Content") + "Font\\SeoulNamsanEB.ttf";
	int32_t FontID = RenderManager::Get().CreateTTFont(FontPath, 32, 55203, 32.0f);

	std::string TexturePath = CommandLine::GetValue("Content") + "Texture\\GrayBlock.png";
	int32_t TextureID = RenderManager::Get().CreateTexture2D(TexturePath);

	GameTimer Timer;

	while (!bIsDone_)
	{
		Timer.Tick();
		InputManager::Get().Tick();

		RenderManager::Get().Clear(Color::BLACK);
		RenderManager::Get().DrawText2D(FontID, L"�ѱ� ��� Ȯ��", Vec2f(0.0f, 0.0f), Color::BLUE);
		RenderManager::Get().DrawFillQuad2D(Vec2f(0.0f, 0.0f), Color::RED, 200.0f, 200.0f, ToRadian(Timer.GetTotalSeconds() * 100.0f));
		RenderManager::Get().DrawWireframeQuad2D(Vec2f(0.0f, 0.0f), Color::BLUE, 200.0f, 200.0f, ToRadian(-Timer.GetTotalSeconds() * 100.0f));
		RenderManager::Get().DrawLine2D(Vec2f(-100.0f, -100.0f), Color::RED, Vec2f(100.0f, 100.0f), Color::GREEN);
		RenderManager::Get().DrawFillCircle(Vec2f(0.0f, 0.0f), Color::GREEN, 200.0f);
		//RenderManager::Get().DrawTexture2D(TextureID, Vec2f(0.0f, 100.0f), 100.0f, 100.0f);
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