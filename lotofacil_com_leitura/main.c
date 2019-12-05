#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define colunas 26
#define nj 15
#define np 25
int main(int argc,char *argv[])
{
int linhas,linha;
    printf("Jogo #: ");
    scanf("%d",&linhas);
    linha=linhas-1;
    printf("Estatistica ate o jogo %d \n",linha);
int i,j,erro,cont[colunas],atraso[colunas],N;
FILE* txtR;
float media,stddev[colunas],desvio,score[colunas];
int read[linhas][colunas];
int x[np],y[np],limite,num,k,l,n;
    srand(time(NULL));
    txtR=fopen("lotofacil_res.txt","rt");
    if(txtR)
    {
        erro=0;
        for(i=1;i<linhas;i++)
        {
            for(j=0;j<colunas;j++)
            {
                if(!fscanf(txtR,"%d",&read[i][j]))
                {
                    erro=1;
                    printf("erro ao ler a entrada (%d,%d) da matriz",i,j);
                    break;
                }
            }
            if(erro)
                break;
        }
        fclose(txtR);
    }
    else
    {
        printf("Verificar o arquivo lotofacil_res.txt na pasta!!!");
    }
    for(j=0;j<colunas;j++)
    {
        atraso[j]=0;
    }
    for(j=1;j<colunas;j++)
    {
        if(read[linha][j]==0)
        {
            if(read[linha-1][j]==0)
            {
                if(read[linha-2][j]==0)
                {
                    if(read[linha-3][j]==0)
                    {
                        if(read[linha-4][j]==0)
                        {
                            if(read[linha-5][j]==0)
                            {
                                atraso[j]=6;
                            }
                            else
                            {
                                atraso[j]=5;
                            }
                        }
                        else
                        {
                            atraso[j]=4;
                        }
                    }
                    else
                    {
                        atraso[j]=3;
                    }
                }
                else
                {
                    atraso[j]=2;
                }
            }
            else
            {
                atraso[j]=1;
            }
        }
        else
        {
            atraso[j]=0;
        }
    }


    media=linha*15/25;
    printf("Media: %5.1f\t\t",media);
    for(j=0;j<colunas;j++)
    {
        cont[j]=0;
    }
    for(j=1;j<colunas;j++)
    {
        for(i=0;i<linhas;i++)
        {
            if(read[i][j]!=0)
            {
                cont[j]++;
            }
        }
    }
    N=0;
    for(i=1;i<colunas;i++)
    {
        N=N+cont[i];
    }
    for(i=0;i<colunas;i++)
    {
        stddev[i]=0;
    }
    for(i=1;i<colunas;i++)
    {
        stddev[i]=cont[i]*(cont[i]-media)*(cont[i]-media)/N;
    }
    desvio=0.0;
    for(i=1;i<colunas;i++)
    {
        desvio=desvio+stddev[i];
    }
    stddev[0]=pow(desvio,.5);
    printf("Desvio Padrao: %5.2f\n\n",stddev[0]);

    for(i=1;i<colunas;i++)
    {
        score[i]=(cont[i]-media)/stddev[0];
    }

    for(i=1;i<colunas;i++)
    {
                printf("%4d %4d %5.2f %3d\n",i,cont[i],score[i],atraso[i]);
    }
    for(k=0;k<np;k++)
    {
        x[k]=0;
    }
    limite=rand();
    for(i=0;i<limite;i++)
    {
        num=1+rand()%np;
    }
    printf("LotoFacil\n--------------------\n");
    for(k=0; k<nj; k++)
    {
        x[k]=1+rand()%np;
        for(n=0;n<2;n++)
        {
            for(l=0; l<k; l++)
            {
                if(x[l] == x[k])
                {
                    x[k]=1+rand()%np;
                    l=0;
                }
            }
        }
    }
    for(k=0;k<np;k++)
    {
        y[k]=0;
    }
    for(k=0;k<np;k++)
    {
        for(l=0;l<np;l++)
        {
            if(x[k]==(l+1))
            {
                y[l]=x[k];
            }
        }
    }
    for(k=0;k<np;k++)
    {
        if(y[k]==0)
        {
            printf("    ");
        }
        else
        {
        printf("%4d",y[k]);
        }
        if(k%5==4)
        {
            printf("\n");
        }
    }
    printf("--------------------\n");



    system("PAUSE");
    return 0;
}
