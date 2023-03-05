import tkinter
import os
import subprocess

# 셋업을 수행합니다.
def run_setup(project_name, visual_studio_version):
    if not project_name:
        project_name = "Unknow"
    
    project_directory = os.getcwd()
    setup_script= project_directory + "\\Engine\\Script\\Setup.bat"
    command = "{0} {1} {2}".format(setup_script, project_name, visual_studio_version)
    print(command)
    subprocess.Popen(command, shell=True)
    exit(0)

# 셋업 클라이언트를 실행합니다.
def run_setup_client():
    window=tkinter.Tk()
    window.title("Setup")
    window.geometry("300x150")
    window.resizable(False, False)

    project_name_label = tkinter.Label(window, text = "Project Name")
    project_name_label.pack()

    project_name_entry = tkinter.Entry(window)
    project_name_entry.pack()

    visual_studio_version_label = tkinter.Label(window, text = "Visual Studio")
    visual_studio_version_label.pack()

    visual_studio_versions = tkinter.Listbox(window, selectmode = "extended", height=0)
    visual_studio_versions.insert(0, "vs2019")
    visual_studio_versions.insert(1, "vs2022")
    visual_studio_versions.selection_set(0)
    visual_studio_versions.pack()

    button_action = lambda : run_setup(project_name_entry.get(), visual_studio_versions.get(visual_studio_versions.curselection()[0]))

    setup_button = tkinter.Button(window, text = "Generate Project Files", command = button_action)
    setup_button.pack()

    window.wm_attributes('-toolwindow', 'True')
    window.mainloop()

if __name__ == "__main__":
    run_setup_client()