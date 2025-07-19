import os
import subprocess

# Caminho para a pasta com os arquivos .in e .sol
test_folder = "C:/Users/ahlre/Documents/GitProjects/Competitive_Programming/Cases/2023f2p2_barcos/5"

# Caminho para o executável ou script da sua solução
solution_executable = "C:/Users/ahlre/Documents/GitProjects/Competitive_Programming/OBI/2023/2°fase/barcos.exe"  # Pode ser './a.sol', 'python solucao.py', etc.

# Iterar por todos os arquivos .in na pasta
for filename in os.listdir(test_folder):
    if filename.endswith(".in"):
        input_file = os.path.join(test_folder, filename)
        solput_file = input_file.replace(".in", ".sol")

        # Rodar sua solução com o arquivo .in como entrada
        with open(input_file, "r") as infile:
            process = subprocess.run(solution_executable.split(), stdin=infile, capture_output=True, text=True)

        # Ler a saída esperada do arquivo .sol (se existir)
        if os.path.exists(solput_file):
            with open(solput_file, "r") as solfile:
                expected_solput = solfile.read().strip()
            
            # Comparar a saída gerada com a esperada
            actual_solput = process.stdout.strip()
            if actual_solput == expected_solput:
                print(f"{filename}: ✅ Passou")
            else:
                print(f"{filename}: ❌ Falhou")
                print(f"    Esperado: {expected_solput}")
                print(f"    Obtido: {actual_solput}")
        else:
            print(f"{filename}: ⚠️ Arquivo .sol não encontrado")
