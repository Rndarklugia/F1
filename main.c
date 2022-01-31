#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
int main(void)
{
    int entries, vueltas=0, vueltasB=0, vueltasM=0, vueltasA=0;
    printf("Ingrese cantidad de datos: ");
    printf("\n");
    scanf("%i",&entries);
    char cliente[30] = {0};
    char **nombres = NULL;
    nombres = (char*)malloc(entries*sizeof(char));
    long registro[entries][4];
    long precioA=0, precioM=0, precioB=0;
    float porcentajeA, porcentajeM, porcentajeB;
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

        printf("Ingrese el Año del modelo: ");
        printf("\n");
        scanf("%li",&registro[i][2]);

        printf("Ingrese el precio del cliente:  ");
        printf("\n");
        scanf("%li",&registro[i][3]);
    switch (registro[i][1])
    {
    case 1:
        vueltasA+=1;
        if(registro[i][2]<=2000)
        {
            precioA+=registro[i][3]-(registro[i][3]*0.15);
            printf("El precio a pagar por el vehiculo es: %d" , precioA);
            printf("\n");
        }
        else if(registro[i][2]<=2014){
            precioA+=registro[i][3]-(registro[i][3]*0.09);
            printf("El precio a pagar por el vehiculo es: %d" , precioA);
            printf("\n");
        }
        else{
            precioA+=registro[i][3]-(registro[i][3]*0.04);
            printf("El precio a pagar por el vehiculo es: %d" , precioA);
            printf("\n");
        }
        break;
    case 2:
    vueltasM+=1;
    if(registro[i][2]<=2000)
        {
            precioM+=registro[i][3]-(registro[i][3]*0.18);
            printf("El precio a pagar por el vehiculo es: %d" , precioM);
            printf("\n");
        }
        else if(registro[i][2]<=2014){
            precioM+=registro[i][3]-(registro[i][3]*0.13);
            printf("El precio a pagar por el vehiculo es: %d" , precioM);
            printf("\n");
        }
        else{
            precioM+=registro[i][3]-(registro[i][3]*0.07);
            printf("El precio a pagar por el vehiculo es: %d" , precioM);
            printf("\n");
        }
        break;
    case 3:
        vueltasB+=1;
        precioB=0;
        printf("No se compran vehiculos de baja Gamma");
        printf("\n");
        break;

    default:
        printf("Codigo de gamma no valido");
        break;
    } //sale del switch
    }//sale del for
    porcentajeA=(double)vueltasA/(double)entries*100.00;
    porcentajeM=(double)vueltasM/(double)entries*100.00;
    porcentajeB=(double)vueltasB/(double)entries*100.00;
    printf("Registros para gama alta: %d, Registros para gama media: %d, Registros para gama baja: %d", vueltasA, vueltasM, vueltasB);
    printf("\n");
    printf("Total para gama alta: %d, Total para gama media: %d, Total para gama baja: %d", precioA, precioM, precioB);
    printf("\n");
    printf("Porcentaje para gama alta: %0.2f, Porcentaje para gama media: %0.2f, Porcentaje para gama baja: %0.2f", porcentajeA, porcentajeM, porcentajeB);
    printf("\n");
    printf("Total de vueltas por ciclo: %d", vueltas);
    printf("\n");
    for(int i=0; i<entries;i++){
    printf("Nombre: %s, Cedula: %d, Gamma: %d, Año: %d , Precio ofrecido: %d\n", (char*)(nombres[i]), registro[i][0], registro[i][1], registro[i][2], registro[i][3]);
        printf("\n");
    }
}
