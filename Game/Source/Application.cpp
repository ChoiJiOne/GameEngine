#include "AudioManager.h"
#include "CrashHandler.h"
#include "CommandLine.h"
#include "GameTimer.h"
#include "RenderManager.h"
#include "Shader.h"
#include "InputManager.h"
#include "Window.h"


/**
 * 테스트용 헤더 선언 추가
 */
#include "TTFont.h"
#include "Texture2D.h"
#include "AABBObject.h"
#include "OBBObject.h"
#include "CircleObject.h"

#include <memory>


/**
 * @brief 애플리케이션을 실행합니다.
 *
 * @param ArgC 명령행 인자의 수입니다.
 * @param ArgV 명령행 인자입니다.
 *
 * @throws 예외 발생 시 덤프 파일을 생성하고 프로그램이 종료됩니다.
 */
void RunApplication(int32_t ArgC, char* ArgV[])
{
	CommandLine::ParseFromArgV(ArgC, ArgV);

	CrashHandler::SetDumpFilePath(CommandLine::GetValue("Dump"));

	std::unique_ptr<Window> MainWindow = std::make_unique<Window>(L"Development",100, 100, 1000, 800, false);

	RenderManager::Get().Setup(MainWindow.get());
	InputManager::Get().Setup(MainWindow.get());
	AudioManager::Get().Setup();

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

	std::string AudioPath = CommandLine::GetValue("Content") + "Audio\\Play.mp3";
	int32_t SoundID = AudioManager::Get().CreateSound(AudioPath);

	std::unique_ptr<AABBObject> AABBObj = std::make_unique<AABBObject>("AABBObject");
	//std::unique_ptr<OBBObject> OBBObj = std::make_unique<OBBObject>("OBBObject");
	//std::unique_ptr<CircleObject> CircleObj = std::make_unique<CircleObject>("CircleObject");

	while (!bIsDone_)
	{
		InputManager::Get().Tick();

		RenderManager::Get().Clear(Color::BLACK);
		AABBObj->Tick(0.0f);
		//OBBObj->Tick(0.0f);
		//CircleObj->Tick(0.0f);
		RenderManager::Get().Present();
	}

	AudioManager::Get().Cleanup();
	RenderManager::Get().Cleanup();
	InputManager::Get().Cleanup();

	MainWindow.reset();
}


/**
 * @brief 애플리케이션의 진입점입니다.
 *
 * @param ArgC 명령행 인자의 수입니다.
 * @param ArgV 명령행 인자입니다.
 *
 * @return 다른 프로그램에 전달할 수 있는 상태 코드를 반환합니다.
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