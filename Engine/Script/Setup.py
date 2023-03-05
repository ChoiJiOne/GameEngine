import os
import sys

# 명령행으로부터 프로젝트의 이름값을 얻습니다.
def get_project_name_from_commandline():
    argv = sys.argv

    if len(argv) == 2:
        return argv[1]
    else:
        return ""
    
# 프로젝트가 이미 초기화된 적이 있는지 확인합니다.
def is_already_setup_project(project_directory):
    project_elements = [
        project_directory + "\\premake5.lua",
        project_directory + "\\GenerateProjectFiles.bat",
        project_directory + "\\Build.bat",
        project_directory + "\\Game"
    ]

    for project_element in project_elements:
        if os.path.exists(project_element):
            return True

    return False


if __name__ == "__main__":
    project_directory = os.getcwd()
    project_name = get_project_name_from_commandline()

    if not project_name:
        print("usage Setup.bat <project-name>")
        exit(0)

    print("setup {0}...".format(project_name))

    is_already_setup = is_already_setup_project(project_directory)

    if is_already_setup:
        print("already setup project...")
        exit(0)