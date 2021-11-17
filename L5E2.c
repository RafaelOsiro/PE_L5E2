/*
UNIVERSIDADE CATÓLICA DE BRASÍLIA
CURSO: ANÁLISE E DESENVOLVIMENTO DE SISTEMAS
DISCIPLINA: PROGRAMAÇÃO ESTRUTURADA
DOCENTE: JOYCE SIQUEIRA
DISCENTE: RAFAEL RIKI OGAWA OSIRO (UC21100716)

Exercício: 2. Desenvolva uma estrutura em C conforme o modelo abaixo e após crie as funções solicitadas:
a) Cadastrar os dados.
b) Apresentar todos os dados.
c) Exibir a porcentagem de alunos aprovados e reprovados por turma, totalizados por série.
d) Exibir a porcentagem de alunos do sexo masculino e do sexo feminino por turma, totalizados por série.
e) Apresentar a média das idades de cada uma das séries.
*/

//! LIBRARIES OF THE PROJECT
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<stdbool.h>


//! STRUCTS OF THE PROJECT
struct Aluno
{
    int matricula;
    char nome[50];
    int serie;
    char turma;
    char sexo[50];
    float media;
    bool aprovado;
    int nascimento;
    char naturalidade[50];
};

//! MESSAGES OF THE SYSTEM
void messageTitleOfTheSyste();
void messageMenuOfTheSystem();
void messageInputData(int option, int index);





int main()
{
    int option;
    bool validation = false;

    do
    {
        messageTitleOfTheSyste();
        option = ;

        switch (option)
        {
        case 1:
            //TODO: CADASTRAR
            break;
        
        case 2:
            //TODO: APRESENTAR
            break;

        case 3:
            //TODO: EXIBIR PERCENTUAL APROVADOS E REPROVADOS POR TURMA TOTALIZADO POR SÉRIE
            break;

        case 4:
            //TODO: EXIBIR PERCENTUAL DE MASCULINO E FEMININO POR TURMA TOTALIZADO POR SÉRIE
            break;
        case 5:
            //TODO: EXIBIR MEDIA DE IDADE POR SÉRIE
            break;

        case 6:
            //TODO: SAIR
            break;

        default:
            //TODO: ERRO
            break;
        }



    }while (validation == true);
    
    

    exit(EXIT_SUCCESS);
}

//! MESSAGES OF THE SYSTEM

//  MESSAGE SHOW THE TITLE
void messageTitleOfTheSyste()
{
    printf("SISTEMA PARA CADASTRAR ALUNOS\n\n\n");
}

//  MESSAGE SHOW THE MENU
void messageMenuOfTheSystem()
{
    printf("MENU\n");
    printf("-----------------------------\n");
    printf("[1] CADASTRAR ALUNOS\n");
    printf("[2] EXIBIR TODOS OS ALUNOS\n");
    printf("[3] EXIBIR PERCENTUAL DE APROVADOS E REPROVADOS POR TURMA TOTALIZADO POR S\220RIE\n");
    printf("[4] EXIBIR PERCENTUAL DE ALUNOS MASCULINO E FEMININO POR TURMA TOTALIZADO POR S\220RIE\n");
    printf("[5] EXIBIR A M\220DIA DE IDADE POR S\220RIE\n");
    printf("[6] SAIR DO SISTEMA\n");
    printf("-----------------------------\n");
    printf("DIGITE UMA OP\200\307O: ");
}

//  MESSAGE INPUT DATA
void messageInputData(int option, int index)
{
    switch (option)
    {
    case 1:
        printf("CADASTRO DO ALUNO %d\n\n", (index + 1));
        printf("DIGITE O N\351MERO DE MATR\326CULA: ");
        break;

    case 2:
        printf("CADASTRO DO ALUNO %d\n\n", (index + 1));
        printf("DIGITE O NOME DO ALUNO: ");
        break;

    case 3:
        printf("CADASTRO DO ALUNO %d\n\n", (index + 1));
        printf("DIGITE A S\220RIE: ");
        break;

    case 4:
        printf("CADASTRO DO ALUNO %d\n\n", (index + 1));
        printf("DIGITE A TURMA: ");
        break;

    case 5:
        printf("CADASTRO DO ALUNO %d\n\n", (index + 1));
        printf("DIGITE O SEXO: ");
        break;

    case 6:
        printf("CADASTRO DO ALUNO %d\n\n", (index + 1));
        printf("DIGITE A M\220DIA: ");
        break;

    case 7:
        printf("CADASTRO DO ALUNO %d\n\n", (index + 1));
        printf("O ALUNO EST\265 APROVADO?\n");
        printf("DIGITE [SIM] OU [N\306O]\n");
        break;

    case 8:
        printf("CADASTRO DO ALUNO %d\n\n", (index + 1));
        printf("DIGITE A DATA DE NASCIMENTO: ");
        break;

    case 9:
        printf("CADASTRO DO ALUNO %d\n\n", (index + 1));
        printf("DIGITE A NATURALIDADE: ");
        break;
    default:
        break;
    }
}

//! FUNCTIONS OF THE SYSTEM

int functionInputOption()
{
    int option;

    messageMenuOfTheSystem();
    return scanf("%d", &option);
}