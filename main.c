#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
long preciodecompra(long gamma, long year,long precio);
float calcularporcentajeA(int vueltasA, int entradas);
float calcularporcentajeM(int vueltasM, int entradas);
float calcularporcentajeB(int vueltasB, int entradas);
long precioA=0, precioM=0, precioB=0;
void total();
int main()
{
    int entries, vueltas=0, vueltasB=0, vueltasM=0, vueltasA=0;
    printf("Ingrese cantidad de datos: ");
    printf("\n");
    scanf("%i",&entries);
    char cliente[30] = {0};
    char **nombres = NULL;
    nombres = (char**)malloc(entries*sizeof(char));
    long registro[entries][4];
    for(int i=0;i<entries;i++)
    {
        vueltas+=1;
        printf("Ingrese el nombre del cliente: ");
        printf("\n");
        scanf("%s",&cliente);
        nombres[i] = (char*)malloc(strlen(cliente)*sizeof(char) + 1);
        strcpy(nombres[i], cliente);

        printf("Ingrese el cedula del cliente: ");
        printf("\n");
        scanf("%li",&registro[i][0]);
        
        printf("Ingrese la gamma(1- Alta, 2- Media, 3- Baja): ");
        printf("\n");
        scanf("%li",&registro[i][1]);
        if(registro[i][1]==1){
            vueltasA+=1;
        } else if(registro[i][1]==2){
            vueltasM+=1;
        }else{
            vueltasB+=1;
        }

        printf("Ingrese el Año del modelo: ");
        printf("\n");
        scanf("%li",&registro[i][2]);

        printf("Ingrese el precio del cliente:  ");
        printf("\n");
        scanf("%li",&registro[i][3]);
        preciodecompra(registro[i][1], registro[i][2], registro[i][3]);
    }//sale del for
    printf("Registros para gama alta: %ld, Registros para gama media: %ld, Registros para gama baja: %d", vueltasA, vueltasM, vueltasB);
    printf("\n");
    total();
    printf("Porcentaje para gama alta: %0.2f, Porcentaje para gama media: %0.2f, Porcentaje para gama baja: %0.2f", calcularporcentajeA(vueltasA,entries), calcularporcentajeM(vueltasM,entries), calcularporcentajeB(vueltasB,entries));
    printf("\n");
    printf("Total de vueltas por ciclo: %d", vueltas);
    printf("\n");
    for(int i=0; i<entries;i++){
    printf("Nombre: %s, Cedula: %ld, Gamma: %ld, Año: %ld , Precio ofrecido: %ld\n", (char*)(nombres[i]), registro[i][0], registro[i][1], registro[i][2], registro[i][3]);
        printf("\n");
    }
    return 0;
}    

long preciodecompra(long gamma, long year,long precio)
    {
        long precioTA, precioTM;
        switch (gamma)
    {
    case 1:
        if(year<=2000)
        {
            precioTA=precio-(precio*0.15);
            precioA+=precioTA;
            printf("El precio a pagar por el vehiculo es: %d" , precioTA);
            printf("\n");
        }
        else if(year<=2014){
            precioTA=precio-(precio*0.09);
            precioA+=precioTA;
            printf("El precio a pagar por el vehiculo es: %d" , precioTA);
            printf("\n");
        }
        else{
            precioTA=precio-(precio*0.04);
            precioA+=precioTA;
            printf("El precio a pagar por el vehiculo es: %d" , precioTA);
            printf("\n");
        }
        break;
    case 2:
    if(year<=2000)
        {
            precioTM=precio-(precio*0.18);
            precioM+=precioTM;
            printf("El precio a pagar por el vehiculo es: %d" , precioTM);
            printf("\n");
        }
        else if(year<=2014){
            precioTM=precio-(precio*0.13);
            precioM+=precioTM;
            printf("El precio a pagar por el vehiculo es: %d" , precioTM);
            printf("\n");
        }
        else{
            precioTM=precio-(precio*0.07);
            precioM+=precioTM;
            printf("El precio a pagar por el vehiculo es: %d" , precioTM);
            printf("\n");
        }
        break;
    case 3:
        precioB=0;
        printf("No se compran vehiculos de baja Gamma");
        printf("\n");
        break;
    default:
        printf("Codigo de gamma no valido");
        break;
    } //sale del switch
    }//sale de la funcion
void total(){
    printf("Total para gama alta: %d, Total para gama media: %d, Total para gama baja: %d", precioA, precioM, precioB);
    printf("\n");
}
float calcularporcentajeA(int vueltasA, int entradas)
    {
        float porcentajeA;
        porcentajeA=(double)vueltasA/(double)entradas*100.00;
        return porcentajeA;
    }//sale funcion
float calcularporcentajeM(int vueltasM, int entradas)
    {
        float porcentajeM;
        porcentajeM=(double)vueltasM/(double)entradas*100.00;
        return porcentajeM;
    }//sale funcion
float calcularporcentajeB(int vueltasB, int entradas)
    {
        float porcentajeB;
        porcentajeB=(double)vueltasB/(double)entradas*100.00;
        return porcentajeB;
    }//sale funcion
