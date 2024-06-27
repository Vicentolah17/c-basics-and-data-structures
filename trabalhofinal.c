#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int ID,mtipo[2][10],quant[2][10],cdd[2][10],peso,n,frete[2][10],np[2],kg,pedmenor[2][10],i,j;
float media[2];

void relatoriogeral(){
    
    printf("Quilos de materiais vendidos: %d\n",kg);
    
     for(i=0;i<=1;i++){
      for(j=0;j<10;j++){
          if(pedmenor[i][j]!=0){
              printf("\nOs pedidos com menos de 1000kg foram: ");
              printf("\nCliente %d\t pedido %d ",i+1,j+1);         
          }     
      }
     } 
}
void relatorioclient(){
    printf(" Informe o ID (número do cliente)\n");
    scanf("%d",&ID);
    printf("A média de peso dos seus pedidos foi: %.2f\n",media[ID-1]/np[ID-1]);
    printf("O número de pedidos foi de: %d \n",np[ID-1]);
    
}
void relatorioped(){
  printf(" Informe o ID (número do cliente)\n");
  scanf("%d",&ID);
  printf("Informe o número do pedido\n");
  scanf("%d",&n);
    if(mtipo[ID-1][n-1]==1){
      printf(" Tipo do Produto: Argamassa AC3 20kg\n");        
    }
    else{
        if(mtipo[ID-1][n-1]==2){
          printf("Tipo do Produto: Argamassa AC2 20kg\n");
        }
        else{
          printf("Tipo de Produto : Rejunte 5kg\n");
        }
    }
      
  printf("Quantidade do produto: %d \n",quant[ID-1][n-1]);
  
  if(cdd[ID-1][n-1]==1){
  printf("Cidade de Palmas\n");
  }  
    else{
  printf("Cidade de Porto Nacional\n");
    }
  printf("Frete a ser pago $ %d ,00\n\n\n",frete[ID-1][n-1]);
    
}
    
int main() {
  setlocale(LC_ALL,"Portuguese");
  int op;
  kg=0;
  
  for(i=0;i<=1;i++){
      for(j=0;j<10;j++){
          media[i]=0;
          pedmenor[i][j]=0;
      }
  }
  
  for(ID=0;ID<2;ID++){
    printf("PEDIDOS DO CLIENTE %d\n",ID+1);
    n=1;
  
  do{  
    
    printf("Deseja realizar um pedido?\n");
    printf("1-SIM\t2-NÃO\n");
    scanf("%d",&op);
    
    switch(op){
      
    case 1:
    
    printf("(PEDIDO %d)",n);  
    printf("\nDigite o número correspondente ao tipo de produto\n");
    printf("1- Argamassa AC3 20kg\t2- Argamassa AC2 20kg\t3- Rejunte 5kg\n");
    scanf("%d",&mtipo[ID][n-1]);

    printf("Informe a quantidade de pacotes\n");
    scanf("%d",&quant[ID][n-1]);
    printf("Informe para onde será o seu pedido\n");
    printf("1- Palmas\t 2- Porto Nacional\n");
    scanf("%d",&cdd[ID][n-1]);

      switch(mtipo[ID][n-1]){
        
        case 1: 
        peso=20*quant[ID][n-1];
        
        break;

        case 2:
        peso=20*quant[ID][n-1];
        break;

        case 3:
        peso=5*quant[ID][n-1];
        break;
        
      }
      
      kg=kg+peso; 
      media[ID]=media[ID]+peso;
      
      if(peso<1000){
        frete[ID][n-1]= 0;
        pedmenor[ID][n-1]=1;
      }
      else{
        if(peso>1000&&peso<2000){
          if(cdd[ID][n-1]==1){
            frete[ID][n-1]= 100;
          }
          else{
            frete[ID][n-1]= 200;
          }
        }  
        else{ 
          frete[ID][n-1]=quant[ID][n-1]*2;
          
        }
      }

        
      n++;
    break;
    
    default:
      if(op!=2){
      printf("Opção inválida !\n");}
    break;
      
  }
    }while(n<=10&&op!=2);
    
      np[ID]=n-1;
  }
    
  do{
      printf("\nImpressão de Relatório\n");
      printf("1-Relatório por pedido\t2-Relatório por cliente\t3-Relatório geral\t4-SAIR.\n");
      scanf("%d",&op);

    switch(op){
      case 1:
      relatorioped();
      break;
      
      case 2:
      relatorioclient();
      break;
      
      case 3:
      relatoriogeral();
      break;
        
    }
    
    
  }while(op!=4);
  


  return 0;
}
