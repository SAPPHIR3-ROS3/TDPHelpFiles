# TDP Help Files

## Guida installazione compiler MinGW64 per C/C++ per Windows



## Guida installazione Make per Windows

### questa parte della guida è completamente opzionale ma consiglio comunque di seguirla per far si di non dover scrivere comandi lunghissimi in console.
### Sfortunamente Windows di default non ha la possibilità di usare i comandi di make che permettono di eseguire uno o più comandi lunghi se non scrivendoli, ma è possibile rimediare molto velocemente:

### 1. Cerca nella barra di Windows: Powershell e avvialo come amministratore (il comando non funziona se Powershell non è avviato con i permessi di amministratore)
![ricerca](https://imgur.com/a/nNQT9Ny)   
e digita
```cmd
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
```
### successivamente per verificare che non ci siano errori digitia
```cmd
choco -v
```
![choco](https://imgur.com/a/g5as12r)    
### poi make potrà essere installato tramite il comando
```cmd
choco install make
```
![make](https://imgur.com/a/s5jKGqo)    
### ed infine verificare che make funzioni tramite
```cmd
make
```
### per usare make vi basterà creare un file makefile all'interno della cartella dove vi sono i file .c (soprattutto il main), riempirlo con i vari comandi ed infine digitare il comando
```cmd 
make <azione>
```
### dove azione dovra essere un simile a

![action](https://imgur.com/a/pSueoJa)