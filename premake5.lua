workspace "Development"
   -- ���� ���� ����Դϴ�.
   configurations { 
      "Debug",
      "Release",
      "Shipping",
   }

   -- ���� �÷����Դϴ�.
   platforms { "Win64" }

   -- �ַ�� ��θ� �����մϴ�.
   location "%{wks.name}"

   -- ���� ������Ʈ�� ��θ� �����մϴ�.
   engine="%{wks.location}/../Engine"

   -- ���� ������Ʈ�� ��θ� �����մϴ�.
   game="%{wks.location}/../Game"

   -- �ܺ� ���̺귯�� ��θ� �����մϴ�.
   thirdparty="%{engine}/ThirdParty"

   -- ���� ������ ��θ� �����մϴ�.
   content="%{game}/Content"

   startproject "Game"

   -- ���� ������Ʈ�Դϴ�.
   project "Engine"
        -- ���� ������Ʈ�� ������ �����մϴ�.
        kind "StaticLib"

        -- ���α׷��� �� �����մϴ�.
        language "C++"

        -- C++�� ǥ���� �����մϴ�.
        cppdialect "C++17"

        -- ���� �ҽ� �ڵ��� include ��θ� �߰��մϴ�.
        includedirs {
            "%{engine}",
            "%{engine}/Source",
            "%{engine}/Source/Private",
            "%{engine}/Source/Public",
            "%{engine}/Shader",
            "%{engine}/Script",

            "%{thirdparty}",
        }

        -- ���� �ҽ� �ڵ��� file�� �߰��մϴ�.
        files {
            "%{engine}/*",
            "%{engine}/Source/*",
            "%{engine}/Source/Private/*",
            "%{engine}/Source/Public/*",
            "%{engine}/Shader/*",
            "%{engine}/Script/*",

            "%{thirdparty}/json/*",
            "%{thirdparty}/miniaudio/*",
            "%{thirdparty}/stb/*",
        }
        
        -- ���� ���� �� ���̴� �������� ��Ȱ��ȭ�մϴ�.
        filter { "files:**.hlsl" }
            flags { "ExcludeFromBuild" }
        filter { }

        -- ���� ������ ���� ��Һ� ������ �����մϴ�.
        filter "configurations:Debug"
            defines { "DEBUG" }
            runtime  "Debug"
            optimize "Off"
            symbols "On"

            links {
                "Dbghelp.lib",
                "d3d11.lib",
                "dxgi.lib",
                "d3dcompiler.lib",
            }

        filter "configurations:Release"
            defines { "NDEBUG", "RELEASE" }
            runtime "Release"
            optimize "On"
            symbols "On"

            links {
                "Dbghelp.lib",
                "d3d11.lib",
                "dxgi.lib",
                "d3dcompiler.lib",
            }

        filter "configurations:Shipping"
            defines { "NDEBUG", "SHIPPING" }
            runtime "Release"
            optimize "Full"
            symbols "Off"

            links {
                "Dbghelp.lib",
                "d3d11.lib",
                "dxgi.lib",
                "d3dcompiler.lib",
            }

   -- ���� ������Ʈ�Դϴ�.
   project "Game"

        -- ���� ������Ʈ�� ������ �����մϴ�.
        kind "ConsoleApp"

        -- ���α׷��� �� �����մϴ�.
        language "C++"

        -- C++�� ǥ���� �����մϴ�.
        cppdialect "C++17"

        -- ������ �����մϴ�.
        links {"Engine"}

        -- ����� �μ��� �����մϴ�.
        debugargs {
            "Dump=%{wks.location}..\\Game\\Crash\\",
            "Content=%{wks.location}..\\Game\\Content\\",
            "Shader=%{wks.location}..\\Engine\\Shader\\",
        }

        -- ������ �ҽ� �ڵ��� include ��θ� �߰��մϴ�.
        includedirs {
            "%{engine}/Source/Private",
            "%{engine}/Source/Public",

            "%{game}/Source/",
            "%{game}/Source/Private",
            "%{game}/Source/Public",
        }

        -- ������ �ҽ� �ڵ��� file�� �߰��մϴ�.
        files {
            "%{game}/Source/*",
            "%{game}/Source/Private/*",
            "%{game}/Source/Public/*",

            "%{content}/Audio/*",
            "%{content}/Config/*",
            "%{content}/Font/*",
            "%{content}/Texture/*",
        }

        -- ������ ���� ��Һ� ������ �����մϴ�.
        filter "configurations:Debug"
            defines { "DEBUG" }
            runtime  "Debug"
            optimize "Off"
            symbols "On"

        filter "configurations:Release"
            defines { "NDEBUG", "RELEASE" }
            runtime "Release"
            optimize "On"
            symbols "On"

        filter "configurations:Shipping"
            defines { "NDEBUG", "SHIPPING" }
            runtime "Release"
            optimize "Full"
            symbols "Off"