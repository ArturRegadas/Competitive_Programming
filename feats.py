import os

def termination(string:str) -> str:
    ans = ""
    flag = False
    for i in string:
        if i == "." or flag:
            ans+=i
            flag=True
            
    return ans

def listar_arquivos(diretorio:str) -> dict:
    ans={}
    for raiz, _, arquivos in os.walk(diretorio):
        for arquivo in arquivos:
            caminho_completo = os.path.join(raiz, arquivo)
            caminho_completo+="\n"
            info = caminho_completo.split('/')
            if not info[1] in ans:
                ans[info[1]]={}
            if not info[2] in ans[info[1]]:
                ans[info[1]][info[2]] = []
            aux = info[-1]

            ans[info[1]][info[2]].append(termination(aux))
    return ans

def CreateCommand(ans:dict) -> str:
    command = "<h1>Resolvidos</h1>"
    for i in sorted(ans.keys()):
        command+=f"<ul><details><summary>{i}</summary>\n"
        for j in sorted(ans[i].keys()):
            command+=f"<ul><details><summary>{j}</summary>\n"
            command+=f"<ul><table><tr><th>C     </th><th>{"✅" if ".c\n" in ans[i][j] else "🟥"}</th></tr>\n"
            command+=f"<tr><th>C++              </th><th>{"✅" if ".cpp\n" in ans[i][j] else "🟥"}</th></tr>\n"
            command+=f"<tr><th>C#               </th><th>{"✅" if ".cs\n" in ans[i][j] else "🟥"}</th></tr>\n"
            command+=f"<tr><th>Python           </th><th>{"✅" if ".py\n" in ans[i][j] else "🟥"}</th></tr>\n"
            command+=f"<tr><th>Java             </th><th>{"✅" if ".java\n" in ans[i][j] else "🟥"}</th></tr></table></u>\n"
            command+="</details></ul>"
        command+="</details></ul>"
    return command

def FP() -> str:
    with open("README.md", 'r') as file:
        splited = file.read().split("<h1>Resolvidos</h1>")
        return splited[0]

def changeMD(command:str) -> None:
    with open("README.md", "w") as file:
        file.write(command)


diretorio_base = "Beecrowd/"  
changeMD(FP()+CreateCommand(listar_arquivos(diretorio_base)))
