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
#include<ctype.h>
#include<math.h>


//! STRUCTS OF THE PROJECT
struct Student
{
    int matricula;
    char nome[50];
    int serie;
    char turma;
    char sexo[50];
    float media;
    bool aprovado;
    int anoNascimento;
    char naturalidade[50];
};

//! MESSAGES OF THE SYSTEM
void messageTitleOfTheSyste();
void messageMenuOfTheSystem();
void messageInputData(int option, int index);
void messageExitInput();
void messageExit();


//! ERROR MESSAGES OF THE PROJECT
void errorOption(int numberOfErrors);


//! FUNCTIONS OF THE SYSTEM
int functionInputOption();
bool functionExit();
void functionInputData(struct Student *student, int index);
void functionShowAllRegistrations(struct Student *student, int index);
void functionShowApprovedStudentsByGrade(struct Student *student, int index);
void functionShowStudentsByGender(struct Student *student, int index);
void functionShowStudentsAgeAverage(struct Student *student, int index);


int main()
{
    int option, quantityOfErrors = 0, index = 0;
    bool validation = false;
    struct Student student[500];

    student[0].matricula = 1;
    strcpy(student[0].nome, "rafael");
    student[0].serie = 1;
    student[0].turma = 'A';
    strcpy(student[0].sexo, "masculino");
    student[0].media = 7.0;
    student[0].aprovado = 1;
    student[0].anoNascimento = 1995;
    strcpy(student[0].naturalidade, "brasilia");

    student[1].matricula = 2;
    strcpy(student[1].nome, "aa");
    student[1].serie = 1;
    student[1].turma = 'A';
    strcpy(student[1].sexo, "feminino");
    student[1].media = 5.0;
    student[1].aprovado = 0;
    student[1].anoNascimento = 1997;
    strcpy(student[1].naturalidade, "brasilia");
    index = 2;

    do
    {
        messageTitleOfTheSyste();
        option = functionInputOption();

        switch (option)
        {
        case 1:
            system("cls");
            functionInputData(student, index);
            index++;
            break;
        
        case 2:
            system("cls");
            functionShowAllRegistrations(student, index);
            break;

        case 3:
            system("cls");
            functionShowApprovedStudentsByGrade(student, index);
            break;

        case 4:
            system("cls");
            functionShowStudentsByGender(student, index);
            break;

        case 5:
            system("cls");
            functionShowStudentsAgeAverage(student, index);
            break;

        case 6:
            system("cls");
            validation = functionExit();
            break;

        default:
            system("cls");
            quantityOfErrors++;
            errorOption(quantityOfErrors);
            break;
        }
    }while (validation == false);
    
    
    sleep(5);
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
        printf("DIGITE O NOME DO ALUNO: ");
        break;

    case 2:
        printf("CADASTRO DO ALUNO %d\n\n", (index + 1));
        printf("DIGITE A S\220RIE: ");
        break;

    case 3:
        printf("CADASTRO DO ALUNO %d\n\n", (index + 1));
        printf("DIGITE A TURMA: ");
        break;

    case 4:
        printf("CADASTRO DO ALUNO %d\n\n", (index + 1));
        printf("DIGITE O SEXO: ");
        break;

    case 5:
        printf("CADASTRO DO ALUNO %d\n\n", (index + 1));
        printf("DIGITE A M\220DIA: ");
        break;

    case 6:
        printf("CADASTRO DO ALUNO %d\n\n", (index + 1));
        printf("O ALUNO EST\265 APROVADO?\n");
        printf("DIGITE [SIM] OU [N\306O]\n");
        break;

    case 7:
        printf("CADASTRO DO ALUNO %d\n\n", (index + 1));
        printf("DIGITE O ANO DO NASCIMENTO: ");
        break;

    case 8:
        printf("CADASTRO DO ALUNO %d\n\n", (index + 1));
        printf("DIGITE A NATURALIDADE: ");
        break;
    default:
        break;
    }
}

//  MESSAGE TO AKS USER IF WANTS TO EXIT THE PROGRAM
void messageExitInput()
{
    printf("DESEJA SAIR DO SISTEMA?\n");
    printf("-----------------------------\n");
    printf("[1] SIM\n");
    printf("[2] N\307O\n");
    printf("-----------------------------\n");
    printf("DIGITE UMA OP\200\307O: ");
}

//  MESSAGE SHOW EXIT THE PROGRAM
void messageExit()
{
    printf("O SISTEMA IR\265 FINALIZAR\n\n\n");
}

//! ERROR MESSAGES OF THE PROJECT

//  ERROR IF USER INPUT INCORRET OPTION
void errorOption(int numberOfErrors)
{
    printf("ERRO %d de 3!\n", numberOfErrors);
    printf("DIGITE UMA OP\200\307O V\265LIDA!\n\n\n");

    if (numberOfErrors == 3)
    {
        printf("QUANTIDADE M\265XIMA DE ERROS ATINGIDO!\n");
        printf("O SISTEMA IR\265 FINALIZAR\n\n\n");
        exit(EXIT_FAILURE);
    }
}

//! FUNCTIONS OF THE SYSTEM

//  FUNCTION PRINTS THE MENU AND RETURN THE INPUT THE OPTION NUMBER
int functionInputOption()
{
    int option;

    messageMenuOfTheSystem();
    fflush(stdin);
    scanf("%d", &option);
    return option;
}

//  FUNCTION TO PRINTS MENU IF USER WANTS EXIT THE SYSTEM
bool functionExit()
{
    int option, quantityOfErrors = 0;
    bool validation = false;

    do
    {
        messageExit();
        fflush(stdin);
        scanf("%d", &option);

        if (option == 1 || option == 2)
        {
            validation = true;
        }
        else
        {
            quantityOfErrors++;
            errorOption(quantityOfErrors);
        }

    } while (validation == false);
    
    if (option == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//  FUNCTION TO INPUT STUDENT DATA
void functionInputData(struct Student *student, int index)
{  
    //  INPUT STUDENT REGISTRATION NUMBER
    student[index].matricula = (index+1);
    system("cls");


    //  INPUT STUDENT NAME
    messageInputData(1, index);
    fflush(stdin);
    fgets(student[index].nome, 50, stdin);
    system("cls");

    //  INPUT STUDENT GRADE
    messageInputData(2, index);
    fflush(stdin);
    scanf("%d", &student[index].serie);
    system("cls");

    //  INPUT STUDENT CLASS
    messageInputData(3, index);
    fflush(stdin);
    scanf("%c", &student[index].turma);
    system("cls");

    //  INPUT STUDENT GENDER
    messageInputData(4, index);
    fflush(stdin);
    fgets(student[index].sexo, 50, stdin);
    system("cls");

    //  INPUT STUDENT AVERAGE GRADE
    messageInputData(5, index);
    fflush(stdin);
    scanf("%f", &student[index].media);
    system("cls");

    //  INPUT STUDENT APPROVAL
    if (student[index].media >= 6)
    {
        student->aprovado == 1;
    }
    else
    {
        student[index].aprovado == 0;
    }    

    //  INPUT STUDENT DAY BIRTHDAY
    messageInputData(7, index);
    fflush(stdin);
    scanf("%d",&student[index].anoNascimento);
    system("cls");

    //  INPUT STUDENT IS FROM
    messageInputData(8, index);
    fflush(stdin);
    fgets(student[index].naturalidade, 50, stdin);
    system("cls");
}

//  FUNCTION TO SHOW ALL STUDENTS
void functionShowAllRegistrations(struct Student *student, int index)
{
    for (int i = 0; i < index; i++)
    {
        printf("ESTUDANTE N\351MERO: %d\n", i+1);
        printf("MATR\326CULA: %d\n", student[i].matricula);
        printf("NOME: %s\n", student[i].nome);
        printf("S\220RIE: %d\n", student[i].serie);
        printf("TURMA: %c\n", student[i].turma);
        printf("SEXO: %s\n", student[i].sexo);
        printf("M\220DIA: %.2f\n", student[i].media);
        if (student[i].aprovado == 1)
        {
            printf("APROVADO: SIM\n");
        }
        else
        {
            printf("APROVADO: N\307O\n");
        }
        printf("ANO DE NASCIMENTO: %d\n", student[i].anoNascimento);
        printf("NATURALIDADE: %s\n", student[i].naturalidade);
        printf("-------------------------------------------\n\n\n");
    }
    system("PAUSE");
}

//  FUNCTION TO SHOW APPROVED STUDENTS BY GRADE AND BY CLASS
void functionShowApprovedStudentsByGrade(struct Student *student, int index)
{
    int totalStudentPerGrade1[2][2], totalStudentPerGrade2[2][2], totalStudentPerGrade3[2][2], totalStudentPerGrade4[2][2];

    for (int i = 0; i < 2; i++) //GRADE
    {
        for (int j = 0; j < 2; j++) //APPROVAL
        {
            totalStudentPerGrade1[i][j] = 0;
            totalStudentPerGrade2[i][j] = 0;
            totalStudentPerGrade3[i][j] = 0;
            totalStudentPerGrade4[i][j] = 0;
        }
    }

    for (int i = 0; i < index; i++)
    {
        switch (student[i].serie)
        {
        case 1:
            switch (student[i].turma)
            {
            case 'A':
                if (student[i].aprovado == 1)
                {
                    totalStudentPerGrade1[0][0]++;
                }
                else
                {
                    totalStudentPerGrade1[0][1]++;
                }
                break;
            
            case 'B':
                if (student[i].aprovado == 1)
                {
                    totalStudentPerGrade1[1][0]++;
                }
                else
                {
                    totalStudentPerGrade1[1][1]++;
                }
                break;

            default:
                break;
            }
            break;

        case 2:
            switch (student[i].turma)
            {
            case 'A':
                if (student[i].aprovado == 1)
                {
                    totalStudentPerGrade2[0][0]++;
                }
                else
                {
                    totalStudentPerGrade2[0][1]++;
                }
                break;
            
            case 'B':
                if (student[i].aprovado == 1)
                {
                    totalStudentPerGrade2[0][0]++;
                }
                else
                {
                    totalStudentPerGrade2[0][1]++;
                }
                break;
                
            default:
                break;
            }
            break;
        
        case 3:
            switch (student[i].turma)
            {
            case 'A':
                if (student[i].aprovado == 1)
                {
                    totalStudentPerGrade3[0][0]++;
                }
                else
                {
                    totalStudentPerGrade3[0][1]++;
                }
                break;
            
            case 'B':
                if (student[i].aprovado == 1)
                {
                    totalStudentPerGrade3[1][0]++;
                }
                else
                {
                    totalStudentPerGrade3[1][1]++;
                }
                break;
                
            default:
                break;
            }
            break;

        case 4:
            switch (student[i].turma)
            {
            case 'A':
                if (student[i].aprovado == 1)
                {
                    totalStudentPerGrade4[0][0]++;
                }
                else
                {
                    totalStudentPerGrade4[0][1]++;
                }
                break;
            
            case 'B':
                if (student[i].aprovado == 1)
                {
                    totalStudentPerGrade4[1][0]++;
                }
                else
                {
                    totalStudentPerGrade4[1][1]++;
                }
                break;
                
            default:
                break;
            }
            break;

        default:
            break;
        }
    }

    printf("RELAT\340RIO ALUOS POR S\220RIE POR TURMA POR APROVA\200\307O\n\n");
    printf("APROVADOS DA TURMA A: %.2f%%\n", ((float)totalStudentPerGrade1[0][0]/(float)(totalStudentPerGrade1[0][0] + (float)totalStudentPerGrade1[0][1])) * 100);
    printf("REPROVADO DA TURMA A: %.2f%%\n", ((float)totalStudentPerGrade1[0][1]/(float)(totalStudentPerGrade1[0][0] + (float)totalStudentPerGrade1[0][1])) * 100);
    printf("APROVADOS DA TURMA B: %.2f%%\n", ((float)totalStudentPerGrade1[1][0]/(float)(totalStudentPerGrade1[1][0] + (float)totalStudentPerGrade1[1][1])) * 100);
    printf("REPROVADO DA TURMA B: %.2f%%\n", ((float)totalStudentPerGrade1[1][1]/(float)(totalStudentPerGrade1[1][0] + (float)totalStudentPerGrade1[1][1])) * 100);
    printf("TOTAL DE ALUNOS POR S\220RIE 1: %d\n\n", totalStudentPerGrade1[0][0] + totalStudentPerGrade1[0][1] + totalStudentPerGrade1[1][0] + totalStudentPerGrade1[1][1]);

    printf("APROVADOS DA TURMA A: %.2f%%\n", ((float)totalStudentPerGrade2[0][0]/(float)(totalStudentPerGrade2[0][0] + (float)totalStudentPerGrade2[0][1])) * 100);
    printf("REPROVADO DA TURMA A: %.2f%%\n", ((float)totalStudentPerGrade2[0][1]/(float)(totalStudentPerGrade2[0][0] + (float)totalStudentPerGrade2[0][1])) * 100);
    printf("APROVADOS DA TURMA B: %.2f%%\n", ((float)totalStudentPerGrade2[1][0]/(float)(totalStudentPerGrade2[1][0] + (float)totalStudentPerGrade2[1][1])) * 100);
    printf("REPROVADO DA TURMA B: %.2f%%\n", ((float)totalStudentPerGrade2[1][1]/(float)(totalStudentPerGrade2[1][0] + (float)totalStudentPerGrade2[1][1])) * 100);
    printf("TOTAL DE ALUNOS POR S\220RIE 2: %d\n\n", totalStudentPerGrade2[0][0] + totalStudentPerGrade2[0][1] + totalStudentPerGrade2[1][0] + totalStudentPerGrade2[1][1]);

    printf("APROVADOS DA TURMA A: %.2f%%\n", ((float)totalStudentPerGrade3[0][0]/(float)(totalStudentPerGrade3[0][0] + (float)totalStudentPerGrade3[0][1])) * 100);
    printf("REPROVADO DA TURMA A: %.2f%%\n", ((float)totalStudentPerGrade3[0][1]/(float)(totalStudentPerGrade3[0][0] + (float)totalStudentPerGrade3[0][1])) * 100);
    printf("APROVADOS DA TURMA B: %.2f%%\n", ((float)totalStudentPerGrade3[1][0]/(float)(totalStudentPerGrade3[1][0] + (float)totalStudentPerGrade3[1][1])) * 100);
    printf("REPROVADO DA TURMA B: %.2f%%\n", ((float)totalStudentPerGrade3[1][1]/(float)(totalStudentPerGrade3[1][0] + (float)totalStudentPerGrade3[1][1])) * 100);
    printf("TOTAL DE ALUNOS POR S\220RIE 3: %d\n\n", totalStudentPerGrade3[0][0] + totalStudentPerGrade3[0][1] + totalStudentPerGrade3[1][0] + totalStudentPerGrade3[1][1]);

    printf("APROVADOS DA TURMA A: %.2f%%\n", ((float)totalStudentPerGrade4[0][0]/(float)(totalStudentPerGrade4[0][0] + (float)totalStudentPerGrade4[0][1])) * 100);
    printf("REPROVADO DA TURMA A: %.2f%%\n", ((float)totalStudentPerGrade4[0][1]/(float)(totalStudentPerGrade4[0][0] + (float)totalStudentPerGrade4[0][1])) * 100);
    printf("APROVADOS DA TURMA B: %.2f%%\n", ((float)totalStudentPerGrade4[1][0]/(float)(totalStudentPerGrade4[1][0] + (float)totalStudentPerGrade4[1][1])) * 100);
    printf("REPROVADO DA TURMA B: %.2f%%\n", ((float)totalStudentPerGrade4[1][1]/(float)(totalStudentPerGrade4[1][0] + (float)totalStudentPerGrade4[1][1])) * 100);
    printf("TOTAL DE ALUNOS POR S\220RIE 4: %d\n\n", totalStudentPerGrade4[0][0] + totalStudentPerGrade4[0][1] + totalStudentPerGrade4[1][0] + totalStudentPerGrade4[1][1]);
    system("PAUSE");
    system("cls");
}

//  FUNCTION TO SHOW STUDENTS BY GRADE AND BY CLASS BY GENDER
void functionShowStudentsByGender(struct Student *student, int index)
{
    int totalStudentPerGender1[2][2], totalStudentPerGender2[2][2], totalStudentPerGender3[2][2], totalStudentPerGender4[2][2];
    float percentage;

    for (int i = 0; i < 2; i++) //GRADE
    {
        for (int j = 0; j < 2; j++) //APPROVAL
        {
            totalStudentPerGender1[i][j] = 0;
            totalStudentPerGender2[i][j] = 0;
            totalStudentPerGender3[i][j] = 0;
            totalStudentPerGender4[i][j] = 0;
        }
    }

    for (int i = 0; i < index; i++)
    {
        switch (student[i].serie)
        {
        case 1:
            switch (student[i].turma)
            {
            case 'A':
                if (strcmp(student[i].sexo, "MASCULINO") == 0 || strcmp(student[i].sexo, "masculino") == 0)
                {
                    totalStudentPerGender1[0][0]++;
                }
                else
                {
                    totalStudentPerGender1[0][1]++;
                }
                break;
            
            case 'B':
                if (strcmp(student[i].sexo, "MASCULINO") == 0 || strcmp(student[i].sexo, "masculino") == 0)
                {
                    totalStudentPerGender1[1][0]++;
                }
                else
                {
                    totalStudentPerGender1[1][1]++;
                }
                break;

            default:
                break;
            }
            break;

        case 2:
            switch (student[i].turma)
            {
            case 'A':
                if (strcmp(student[i].sexo, "MASCULINO") == 0 || strcmp(student[i].sexo, "masculino") == 0)
                {
                    totalStudentPerGender2[0][0]++;
                }
                else
                {
                    totalStudentPerGender2[0][1]++;
                }
                break;
            
            case 'B':
                if (strcmp(student[i].sexo, "MASCULINO") == 0 || strcmp(student[i].sexo, "masculino") == 0)
                {
                    totalStudentPerGender2[0][0]++;
                }
                else
                {
                    totalStudentPerGender2[0][1]++;
                }
                break;
                
            default:
                break;
            }
            break;
        
        case 3:
            switch (student[i].turma)
            {
            case 'A':
                if (strcmp(student[i].sexo, "MASCULINO") == 0 || strcmp(student[i].sexo, "masculino") == 0)
                {
                    totalStudentPerGender3[0][0]++;
                }
                else
                {
                    totalStudentPerGender3[0][1]++;
                }
                break;
            
            case 'B':
                if (strcmp(student[i].sexo, "MASCULINO") == 0 || strcmp(student[i].sexo, "masculino") == 0)
                {
                    totalStudentPerGender3[1][0]++;
                }
                else
                {
                    totalStudentPerGender3[1][1]++;
                }
                break;
                
            default:
                break;
            }
            break;

        case 4:
            switch (student[i].turma)
            {
            case 'A':
                if (strcmp(student[i].sexo, "MASCULINO") == 0 || strcmp(student[i].sexo, "masculino") == 0)
                {
                    totalStudentPerGender4[0][0]++;
                }
                else
                {
                    totalStudentPerGender4[0][1]++;
                }
                break;
            
            case 'B':
                if (strcmp(student[i].sexo, "MASCULINO") == 0 || strcmp(student[i].sexo, "masculino") == 0)
                {
                    totalStudentPerGender4[1][0]++;
                }
                else
                {
                    totalStudentPerGender4[1][1]++;
                }
                break;
                
            default:
                break;
            }
            break;

        default:
            break;
        }
    }

    
    printf("RELAT\340RIO ALUNOS POR S\220RIE POR TURMA POR SEXO\n\n");
    //A
    percentage = ((float)totalStudentPerGender1[0][0]/(float)(totalStudentPerGender1[0][0] + (float)totalStudentPerGender1[0][1])) * 100;
    !isnan(percentage)? printf("ALUNOS DO SEXO MASCULINO DA TURMA A: %.2f%%\n", percentage) : printf("");
    
    percentage = ((float)totalStudentPerGender1[0][1]/(float)(totalStudentPerGender1[0][0] + (float)totalStudentPerGender1[0][1])) * 100;
    !isnan(percentage)?  printf("ALUNOS DO SEXO FEMININO DA TURMA A: %.2f%%\n", percentage) : printf("");
    
    percentage = ((float)totalStudentPerGender1[1][0]/(float)(totalStudentPerGender1[1][0] + (float)totalStudentPerGender1[1][1])) * 100;
    !isnan(percentage)?  printf("ALUNOS DO SEXO MASCULINO DA TURMA B: %.2f%%\n", percentage) : printf("");
    
    percentage = ((float)totalStudentPerGender1[1][1]/(float)(totalStudentPerGender1[1][0] + (float)totalStudentPerGender1[1][1])) * 100;
    !isnan(percentage)?  printf("ALUNOS DO SEXO FEMININO DA TURMA B: %.2f%%\n", percentage) : printf("");
    printf("TOTAL DE ALUNOS POR S\220RIE 1: %d\n\n", totalStudentPerGender1[0][0] + totalStudentPerGender1[0][1] + totalStudentPerGender1[1][0] + totalStudentPerGender1[1][1]);
    //B
    percentage = ((float)totalStudentPerGender2[0][0]/(float)(totalStudentPerGender2[0][0] + (float)totalStudentPerGender2[0][1])) * 100;
    !isnan(percentage)? printf("ALUNOS DO SEXO MASCULINO DA TURMA A: %.2f%%\n", percentage) : printf("");

    percentage = ((float)totalStudentPerGender2[0][1]/(float)(totalStudentPerGender2[0][0] + (float)totalStudentPerGender2[0][1])) * 100;
    !isnan(percentage)? printf("ALUNOS DO SEXO FEMININO DA TURMA A: %.2f%%\n", percentage) : printf("");

    percentage = ((float)totalStudentPerGender2[1][0]/(float)(totalStudentPerGender2[1][0] + (float)totalStudentPerGender2[1][1])) * 100;
    !isnan(percentage)? printf("ALUNOS DO SEXO MASCULINO DA TURMA B: %.2f%%\n", percentage) : printf("");

    percentage = ((float)totalStudentPerGender2[1][1]/(float)(totalStudentPerGender2[1][0] + (float)totalStudentPerGender2[1][1])) * 100;
    !isnan(percentage)? printf("ALUNOS DO SEXO FEMININO DA TURMA B: %.2f%%\n", percentage) : printf("");
    printf("TOTAL DE ALUNOS POR S\220RIE 2: %d\n\n", totalStudentPerGender2[0][0] + totalStudentPerGender2[0][1] + totalStudentPerGender2[1][0] + totalStudentPerGender2[1][1]);
    //C
    percentage = ((float)totalStudentPerGender3[0][0]/(float)(totalStudentPerGender3[0][0] + (float)totalStudentPerGender3[0][1])) * 100;
    !isnan(percentage)? printf("ALUNOS DO SEXO MASCULINO DA TURMA A: %.2f%%\n", percentage) : printf("");

    percentage = ((float)totalStudentPerGender3[0][1]/(float)(totalStudentPerGender3[0][0] + (float)totalStudentPerGender3[0][1])) * 100;
    !isnan(percentage)? printf("ALUNOS DO SEXO FEMININO DA TURMA A: %.2f%%\n", percentage) : printf("");

    percentage = ((float)totalStudentPerGender3[1][0]/(float)(totalStudentPerGender3[1][0] + (float)totalStudentPerGender3[1][1])) * 100;
    !isnan(percentage)? printf("ALUNOS DO SEXO MASCULINO DA TURMA B: %.2f%%\n", percentage) : printf("");

    percentage = ((float)totalStudentPerGender3[1][1]/(float)(totalStudentPerGender3[1][0] + (float)totalStudentPerGender3[1][1])) * 100;
    !isnan(percentage)? printf("ALUNOS DO SEXO FEMININO DA TURMA B: %.2f%%\n", percentage) : printf("");
    printf("TOTAL DE ALUNOS POR S\220RIE 2: %d\n\n", totalStudentPerGender3[0][0] + totalStudentPerGender3[0][1] + totalStudentPerGender3[1][0] + totalStudentPerGender3[1][1]);
    //D
    percentage = ((float)totalStudentPerGender4[0][0]/(float)(totalStudentPerGender4[0][0] + (float)totalStudentPerGender4[0][1])) * 100;
    !isnan(percentage)? printf("ALUNOS DO SEXO MASCULINO DA TURMA A: %.2f%%\n", percentage) : printf("");

    percentage = ((float)totalStudentPerGender4[0][1]/(float)(totalStudentPerGender4[0][0] + (float)totalStudentPerGender4[0][1])) * 100;
    !isnan(percentage)? printf("ALUNOS DO SEXO FEMININO DA TURMA A: %.2f%%\n", percentage) : printf("");

    percentage = ((float)totalStudentPerGender4[1][0]/(float)(totalStudentPerGender4[1][0] + (float)totalStudentPerGender4[1][1])) * 100;
    !isnan(percentage)? printf("ALUNOS DO SEXO MASCULINO DA TURMA B: %.2f%%\n", percentage) : printf("");

    percentage = ((float)totalStudentPerGender4[1][1]/(float)(totalStudentPerGender4[1][0] + (float)totalStudentPerGender4[1][1])) * 100;
    !isnan(percentage)? printf("ALUNOS DO SEXO FEMININO DA TURMA B: %.2f%%\n", percentage) : printf("");
    printf("TOTAL DE ALUNOS POR S\220RIE 2: %d\n\n", totalStudentPerGender4[0][0] + totalStudentPerGender4[0][1] + totalStudentPerGender4[1][0] + totalStudentPerGender4[1][1]);
    
    system("PAUSE");
    system("cls");
}

//  FUNCTION TO SHOW APPROVED STUDENTS BY GRADE AND BY CLASS  
void functionShowStudentsAgeAverage(struct Student *student, int index)
{
    float totalStudent1 = 0, totalStudent2 = 0, totalStudent3 = 0, totalStudent4 = 0, averageAgeStudent1 = 0, averageAgeStudent2 = 0, averageAgeStudent3 = 0, averageAgeStudent4 = 0, temp;

    for (int i = 0; i < index; i++)
    {
        switch (student[i].serie)
        {
        case 1:
            totalStudent1++;
            temp = (2021 - student[i].anoNascimento);
            averageAgeStudent1 += temp;
            break;

        case 2:
            totalStudent2++;
            temp = (2021 - student[i].anoNascimento);
            averageAgeStudent2 += temp;
            break;
        
        case 3:
            totalStudent3++;
            temp = (2021 - student[i].anoNascimento);
            averageAgeStudent3 += temp;
            break;

        case 4:
            totalStudent4++;
            temp = (2021 - student[i].anoNascimento);
            averageAgeStudent4 += temp;
            break;

        default:
            break;
        }
    }

    averageAgeStudent1 = averageAgeStudent1/totalStudent1;  
    averageAgeStudent2 = averageAgeStudent2/totalStudent2;
    averageAgeStudent3 = averageAgeStudent3/totalStudent3;
    averageAgeStudent4 = averageAgeStudent4/totalStudent4;



    printf("RELAT\340RIO ALUNOS POR S\220RIE POR M\220DIA DE IDADE\n\n");
    !isnan(averageAgeStudent1) ? printf("M\220DIA DE IDADE POR S\220RIE 1: %.2f\n", averageAgeStudent1) : printf("M\220DIA DE IDADE POR S\220RIE 1: 0\n");
    !isnan(averageAgeStudent2) ? printf("M\220DIA DE IDADE POR S\220RIE 2: %.2f\n", averageAgeStudent2) : printf("M\220DIA DE IDADE POR S\220RIE 2: 0\n");
    !isnan(averageAgeStudent3) ? printf("M\220DIA DE IDADE POR S\220RIE 3: %.2f\n", averageAgeStudent3) : printf("M\220DIA DE IDADE POR S\220RIE 3: 0\n");
    !isnan(averageAgeStudent4) ? printf("M\220DIA DE IDADE POR S\220RIE 4: %.2f\n", averageAgeStudent4): printf("M\220DIA DE IDADE POR S\220RIE 4: 0\n");
    system("PAUSE");
    system("cls");
}