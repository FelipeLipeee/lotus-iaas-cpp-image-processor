# Processador de Imagens C++ (Atividade IaaS)

Codigo em C++ para processamento de imagem (conversao para escala de cinza e filtro Sobel) rodando via socket HTTP na porta configurada por variavel de ambiente.

## Arquivos
- `main.cpp`: Codigo fonte do servidor e filtro de imagem.
- `provision.sh`: Script shell para instalar o `g++`, configurar as variaveis de ambiente (`PORT`, `IMG_WIDTH`, `IMG_HEIGHT`), compilar o codigo e iniciar o servico no Linux.
- `Dockerfile`: Container Ubuntu limpo caso queira testar via Docker.

## Como rodar na VM Ubuntu
```bash
chmod +x provision.sh
sudo ./provision.sh
```
