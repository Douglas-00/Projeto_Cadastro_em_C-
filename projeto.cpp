#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 200

char nome[SIZE][50];
char email[SIZE][50];
int cpf[SIZE];
int op;
void cadastro();
void pesquisa();
void lista();

int main(void){


do{
        system("cls");
        printf("\n----------MENU-----------\n1 - Cadastrar\n2 - Listar Todos\n3 - Pesquisar\n4 - Sair \n------------------------\nSelecione a opcao: ");
        scanf("%d", &op);
        switch(op){
                case 1:
                    cadastro();
                    break;
                case 2:
                    lista();
                    break;
                case 3:
                    pesquisa();
                    break;
                case 4:
                    system("exit");
                    break;
                default:
                    printf("Opcao invalida");
                    getchar();
                    getchar();
                    break;
        }

}while(op!=4);


}
void lista(){
    int i;
    for(i=0;i<SIZE;i++){
            if(cpf[i]>0){
        printf("\nNome: %s \nEmail: %s\nCPF: %d", nome[i],  email[i], cpf[i]);
            }else{
                break;
            }
    }
    getchar();
    getchar();



}
void cadastro(){
    static int linha;
    do{
        printf("\nDigite o Nome: ");
        scanf("%s", & nome[linha]);
        printf("\nDigite o E-mail:");
        scanf("%s", & email[linha]);
        printf("\nDigite o CPF: ");
        scanf("%d", & cpf[linha]);
        printf("\nDigite 1 para continuar ou outro valor para sair: ");
        scanf("%d", &op);
        linha++;
    }while(op==1);
}//Fim da Funçãp Cadastro

//Pesquisando Informações

void pesquisa(){

    int cpfPesquisa;
    char emailPesquisa[50];
    int i;
    do{
            printf("\nDigite 1 para pesquisar por CPF // ou 2 para pesquisar por E-mail: ");
            scanf("%d", &op);
            switch (op){
            case 1:
                printf("Digite o CPF: ");
                scanf("%d", &cpfPesquisa);
                for(i=0;i<SIZE;i++){
                    if(cpf[i]==cpfPesquisa){
                        printf("\nNome: %s \nEmail: %s\nCPF: %d", nome[i],  email[i], cpf[i]);
                    }
                }
                break;
            case 2:
                printf("\nDigite o E-mail: ");
                scanf("%s", emailPesquisa);
                for(i=0;i<SIZE;i++){
                    if(strcmp(email[i], emailPesquisa)==0){
                            printf("\nNome: %s\nEmail: %s\nCPF: %d",nome[i], email[i],cpf[i]);

                    }
                }
                break;
            default:
                printf("\n Opcao Invalida");
                break;
                }
                printf("\nDigite 1 para continuar Pesquisando: ");
                scanf("%d", &op);

    }while(op==1);
}
