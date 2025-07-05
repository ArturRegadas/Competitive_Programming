import os

def termination(string: str) -> str:
    ans = ""
    flag = False
    for i in string:
        if i == "." or flag:
            ans += i
            flag = True
    return ans

def listar_arquivos(diretorio: str) -> dict:
    ans = {}
    for raiz, _, arquivos in os.walk(diretorio):
        for arquivo in arquivos:
            caminho_completo = os.path.join(raiz, arquivo)
            caminho_completo += "\n"
            info = os.path.normpath(caminho_completo).split(os.sep)  

            if len(info) < 3:  
                continue

            if info[1] not in ans:
                ans[info[1]] = {}

            if info[2] not in ans[info[1]]:
                ans[info[1]][info[2]] = []

            aux = info[-1]
            ans[info[1]][info[2]].append(termination(aux))

    return ans

def CreateCommand(ans: dict) -> str:
    command = "<h1>Resolvidos</h1>"
    for i in sorted(ans.keys()):
        command += f"<ul><details><summary>{i}</summary>\n"
        for j in sorted(ans[i].keys()):
            command += f"<ul><details><summary>{j}</summary>\n"
            c = ".c\n" in ans[i][j]
            cpp = ".cpp\n" in ans[i][j]
            py = ".py\n" in ans[i][j]
            cs = ".cs\n" in ans[i][j]
            java = ".java\n" in ans[i][j]
            js = ".js\n" in ans[i][j]
            command += f"<ul><table><tr><th>C     </th><th>{'✅' if c else '🟥'}</th></tr>\n"
            command += f"<tr><th>C++              </th><th>{'✅' if cpp else '🟥'}</th></tr>\n"
            command += f"<tr><th>C#               </th><th>{'✅' if cs else '🟥'}</th></tr>\n"
            command += f"<tr><th>Python           </th><th>{'✅' if py else '🟥'}</th></tr>\n"
            command += f"<tr><th>Java             </th><th>{'✅' if java else '🟥'}</th></tr>\n"
            command += f"<tr><th>JavaScript       </th><th>{'✅' if js else '🟥'}</th></tr></table></ul>\n"
            command += "</details></ul>"
        command += "</details></ul>"
    return command

def FP() -> str:
    with open("README.md", 'r', encoding="utf-8") as file:
        splited = file.read().split("<h1>Resolvidos(Beecrowd)</h1>")
        return splited[0]

def changeMD(command: str) -> None:
    with open("README.md", "w", encoding="utf-8") as file:
        file.write(command)

diretorio_base = "Beecrowd/"
changeMD(CreateCommand(listar_arquivos(diretorio_base)))
