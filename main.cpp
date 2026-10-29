#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

using namespace std;

void processarImagem() {
    int tam = 1500;
    vector<vector<int>> img(tam, vector<int>(tam, 128));

    for(int i = 0; i < tam; i++) {
        for(int j = 0; j < tam; j++) {
            img[i][j] = (255 - img[i][j]) * 0.8;
        }
    }
}

int main() {
    int porta = 8080;
    if(getenv("PORT") != NULL) {
        porta = atoi(getenv("PORT"));
    }

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in end;
    end.sin_family = AF_INET;
    end.sin_addr.s_addr = INADDR_ANY;
    end.sin_port = htons(porta);

    bind(server_fd, (struct sockaddr*)&end, sizeof(end));
    listen(server_fd, 5);

    cout << "Rodando na porta " << porta << endl;

    while(true) {
        int cliente = accept(server_fd, NULL, NULL);
        if(cliente < 0) continue;

        processarImagem();

        string msg = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nImagem processada com sucesso!\n";
        send(cliente, msg.c_str(), msg.size(), 0);
        close(cliente);
    }

    return 0;
}
