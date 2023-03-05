import os
import sys

# 커맨드 라인 인자의 옵션을 파싱합니다.
def parse_commandline():
    argvs = sys.argv
    project_option = {}

    for argv in argvs:
        if not '=' in argv:
            continue
        argv_elements = argv.split('=')
        project_option[argv_elements[0]] = argv_elements[1]

    return project_option

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

# 스크립트 파일을 생성합니다.
def create_script_file(script_file_path, script_content):
    file = open(script_file_path, "w")
    file.write(script_content)
    file.close()

if __name__ == "__main__":
    project_directory = os.getcwd()
    project_option = parse_commandline()

    is_already_setup = is_already_setup_project(project_directory)
    if is_already_setup:
        exit(0)

    print("setup {0}...".format(project_option["project"]))
