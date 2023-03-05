import os
import sys

# 명령행으로부터 프로젝트의 이름값을 얻습니다.
def get_project_name_from_commandline():
    argv = sys.argv

    if len(argv) == 2:
        project_name = argv[1]
        print("setup {0}...".format(project_name))
    else:
        project_name = ""
        print("please insert project name...")
    
    return project_name

if __name__ == "__main__":
    project_directory = os.getcwd()
    project_name = get_project_name_from_commandline()