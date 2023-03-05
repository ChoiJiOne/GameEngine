import os
import sys

def parse_commandline():
    argvs = sys.argv
    project_option = {}

    for argv in argvs:
        if not '=' in argv:
            continue
        argv_elements = argv.split('=')
        project_option[argv_elements[0]] = argv_elements[1]

    return project_option

if __name__ == "__main__":
    project_directory = os.getcwd()
    project_option = parse_commandline()