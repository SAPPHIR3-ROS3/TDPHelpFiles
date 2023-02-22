# TDP Help Files
## Guida installazione compiler MinGW64 per C/C++ per Windows
### se sei qui significa che (comprensibilmente) non vuoi scaricare macchine virtuali di sorta per installare i compilatori di C/C++ per Windows; piccola premessa: tutto il contenuto che scaricherai e installerai tramite questa guida pesa pochi MB.
### 1. Scarica il pacchetto a questo [link](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/8.1.0/threads-win32/seh/x86_64-8.1.0-release-win32-seh-rt_v6-rev0.7z) ed estrailo dove vuoi (io consiglio in C:\\)
![Location](/Asset/Location.png)
### 2. Entra nella cartella appena estratta e poi entra nella cartella `/bin`
### 3.Copia il percorso
![Directory](/Asset/Directory.png)
### 4. Cerca su windows ```variabili di ambiente```e seleziona la voce ```Modifica le variabili di ambiente relative al sistema```
![Variabili](/Asset/Variabili.png)
### 5. Seleziona la voce ```Variabili d'ambiente...```
![Variabili di ambiente](/Asset/VariabiliAmbiente.png)
### 6. Nella sezione "Variabili di Sistema" seleziona la voce ```Path```o ```PATH``` e clicca ```Modifica...```
![Variabili di sistema](/Asset/VariabiliSistema.png)
### 7. Clicca ```Nuovo``` e incolla il percorso copiato in precedenza
![NuovoPath](/Asset/NuovoPath.png)
### 8. (facoltativo) Apri il terminale/Powershel/Prompt CMD e digita per verificare che tutto sia apposto
```cmd
gcc
```
![GCC](/Asset/GCC.png)

-----
## Guida installazione Make per Windows

### questa parte della guida è completamente opzionale ma consiglio comunque di seguirla per far si di non dover scrivere comandi lunghissimi in console.
### Sfortunamente Windows di default non ha la possibilità di usare i comandi di make che permettono di eseguire uno o più comandi lunghi se non scrivendoli, ma è possibile rimediare molto velocemente:

### 1. Cerca nella barra di Windows: Powershell e avvialo come amministratore (il comando non funziona se Powershell non è avviato con i permessi di amministratore)
![ricerca](/Asset/ricerca.png)
### e digita
```cmd
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
```
### successivamente per verificare che non ci siano errori digita
```cmd
choco -v
```
![choco](/Asset/choco.png)    
### poi make potrà essere installato tramite il comando
```cmd
choco install make
```
![make](/Asset/make.png)    
### ed infine verifica che make funzioni tramite
```cmd
make
```
![makeverify](/Asset/makeverify.png)
### per usare make vi basterà creare un file makefile all'interno della cartella dove vi sono i file .c (soprattutto il main), riempirlo con i vari comandi ed infine digitare il comando
```cmd 
make <azione>
```
### dove azione dovra essere un simile a

![action](/Asset/action.png)
