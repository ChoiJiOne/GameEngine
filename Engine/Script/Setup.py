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
        project_directory + "\\.gitignore",
        project_directory + "\\Game",
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

    premake5_source_file = open(project_directory + "\\Engine\\Script\\premake5.lua", 'rt', encoding="UTF-8")
    premake5_source = premake5_source_file.read()
    premake5_source_file.close()
    
    premake5_source = premake5_source.replace("BLANK", project_option["project"])

    generate_project_files_script_source = """@echo off
Engine\\\\Script\\\\GenerateProjectFiles.bat {0} {1}""".format(project_option["project"], project_option["visualstudio"])

    build_scipt_source = """@echo off
SET option=%1
Engine\\\\Script\\\\Build.bat {0} {1} %option%""".format(project_option["project"], project_option["visualstudio"])

    git_ignore_source = """{0}
*.dmp
.vs
""".format(project_option["project"])
    
    premake5_script_path = project_directory + "\\premake5.lua"
    create_script_file(premake5_script_path, premake5_source)

    generate_project_files_script_path = project_directory + "\\GenerateProjectFiles.bat"
    create_script_file(generate_project_files_script_path, generate_project_files_script_source)

    build_script_path = project_directory + "\\Build.bat"
    create_script_file(build_script_path, build_scipt_source)

    git_ignore_path = project_directory + "\\.gitignore"
    create_script_file(git_ignore_path, git_ignore_source)

    os.mkdir(project_directory + "\\Game")
    os.mkdir(project_directory + "\\Game\\Content")
    os.mkdir(project_directory + "\\Game\\Crash")
    os.mkdir(project_directory + "\\Game\\Source")
    os.mkdir(project_directory + "\\Game\\Source\\Private")
    os.mkdir(project_directory + "\\Game\\Source\\Public")

    application_source = """int main(int argc, char* argv[])
{
    return 0;
}
"""
    application_source_path = project_directory + "\\Game\\Source" + "\\Application.cpp"
    create_script_file(application_source_path, application_source)