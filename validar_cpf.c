//Autor:https://gist.github.com/eduardoedson
//Retorno: [1] - Se for válido | [0] - Se for inválido
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"


int validarCPF(char cpf[15])
{
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11)
        return 0;
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0))
        return 0; ///se o CPF tiver todos os números iguais ele é inválido.
    else
    {
        ///digito 1---------------------------------------------------
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        else
        ///digito 2--------------------------------------------------
        {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2)
            return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
    }
    return 1;
}


int lerLetras(char nome[])
{

  int tamanho = strlen(nome);

  if (tamanho < 1) {
      return 0; 
  } else {
      for (int i = 0; i <= (tamanho - 1); i++) 
        if ((nome[i] <= 'z') && (nome[i] >= 'A'))
        {
           if (((nome[i] <= 'a') && (nome[i] <= 'Z')) || (nome[i] == ' ')) {
            return 1;
           }
              if((nome[i] == '@') || (nome[i] == 0) || (nome[i] <= 9)) {
                return 0;
              }
            } else{  
              return 0;
      
              }          
      }
      return 1;    
  }

//baseado em: https://rafaelomarques.wordpress.com/2010/08/28/validacao-de-data-em-cc/
int validarData(int *dia,int *mes,int *ano){
  if((32>*dia && *dia>0) && (13>*mes && *mes>0) && (*ano>1900))
  {
    if(*mes==2 && *ano%4==1){
      if(*dia==29){
        return 1;
      } 
    }
    if(*mes>7 && *mes%2==1){
      if(*dia==31){
        return 1;
      }
    }
    if(*mes<=6 && *mes%2==0){
      if(*dia==31){
        return 1;
      }
    }
  }else{
    return 1;
    }
  return 0;
}

// baseado em : https://www.clubedohardware.com.br/profile/941265-lucca-rodrigues/
int validarTelefone(int *DDD,int *celular){
  if((*celular < 900000000 || *celular > 999999999) && (*DDD<100 || *DDD>10)){
    return 1;
  }else{return 0;}
}
