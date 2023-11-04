#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Cliente
{
    int numCuenta;
    char nombre[50];
    int password;
    float saldo;
    char estado[10];
};

int login (int *encontradoNroCuenta, int *encontradoPassword, struct Cliente array[10]);

int main() 
{

    struct Cliente clientes[10];
    char nombreingresado[50];
    int contraIngresada;
    int opcion, indiceEncontrado, indice;
    int intentoInicioSesion = 3;
    int encontradoNroCuenta = 0;
    int encontradoPassword = 0;

    strcpy(clientes[0].nombre, "Juan");
    clientes[0].password = 1234;
    clientes[0].numCuenta = 101;
    clientes[0].saldo = 150000;
    strcpy(clientes[0].estado, "activo");

    strcpy(clientes[1].nombre, "Juan");
    clientes[1].password = 1235;
    clientes[1].numCuenta = 110;
    clientes[1].saldo = 150000;
    strcpy(clientes[1].estado, " ");

    strcpy(clientes[2].nombre, "Juan");
    clientes[2].password = 1236;
    clientes[2].numCuenta = 120;
    clientes[2].saldo = 150000;
    strcpy(clientes[2].estado, "activo");

    strcpy(clientes[3].nombre, "Juan");
    clientes[3].password = 1237;
    clientes[3].numCuenta = 130;
    clientes[3].saldo = 150000;
    strcpy(clientes[3].estado, "activo");

    strcpy(clientes[4].nombre, "Juan");
    clientes[4].password = 1238;
    clientes[4].numCuenta = 140;
    clientes[4].saldo = 150000;
    strcpy(clientes[4].estado, "activo");

    strcpy(clientes[5].nombre, "Juan");
    clientes[5].password = 1239;
    clientes[5].numCuenta = 150;
    clientes[5].saldo = 150000;
    strcpy(clientes[5].estado, "activo");

    strcpy(clientes[6].nombre, "Juan");
    clientes[6].password = 1241;
    clientes[6].numCuenta = 160;
    clientes[6].saldo = 150000;
    strcpy(clientes[6].estado, "activo");

    strcpy(clientes[7].nombre, "Juan");
    clientes[7].password = 1242;
    clientes[7].numCuenta = 170;
    clientes[7].saldo = 150000;
    strcpy(clientes[7].estado, "activo");

    strcpy(clientes[8].nombre, "Juan");
    clientes[8].password = 1243;
    clientes[8].numCuenta = 180;
    clientes[8].saldo = 150000;
    strcpy(clientes[8].estado, "activo");

    strcpy(clientes[9].nombre, "Juan");
    clientes[9].password = 1244;
    clientes[9].numCuenta = 190;
    clientes[9].saldo = 150000;
    strcpy(clientes[9].estado, "activo");
    
    indiceEncontrado = (&encontradoNroCuenta, &encontradoPassword, clientes);

        if (encontradoPassword){
            do
            {
                printf("1. Realizar un Dep%csito\n", 162);
                printf("2. Realizar una Extracci%cn\n", 162);
                printf("3. Consultar el Saldo de la Cuenta\n");
                printf("4. Realizar una Transferencia entre Cuentas\n");
                printf("5. Mostrar cantidad de Operaciones Realizadas y Saldo Actual\n");
                printf("6. Salir de la Sesi%cn\n", 162);
                scanf("%i", &opcion);
                
                switch (opcion)
                {
                case 1:
                    printf("Realizar un Dep%csito\n", 162);
                    break;
                case 2:
                    printf(" Realizar una Extracci%cn\n", 162);
                    break;
                case 3:
                    printf("Consultar el Saldo de la Cuenta\n");
                    break;
                case 4:
                    printf("Realizar una Transferencia entre Cuentas\n");
                    break;
                case 5:
                    printf("Mostrar cantidad de Operaciones Realizadas y Saldo Actual\n");
                    break;
                case 6:
                    printf("Ha salido de la sesi%cn\n", 162);
                    break;
                }
            } while (opcion != 6);
        } else {
            printf("Contrase%ca incorrecta. Cuenta bloqueada", 164);
        }
   
    return 0;
}

int login (int *encontradoNroCuenta, int *encontradoPassword, struct Cliente array[10]){
    int contadorPassword, numCuentaIngresado, indice, contraIngresada;
    printf("Ingrese su n%cmero de cuenta:\n", 163);
    scanf("%i", &numCuentaIngresado);
    for (int i = 0; i < 10; i++)
    {
        if (array[i].numCuenta == numCuentaIngresado)
        {
            encontradoNroCuenta = 1;
            indice = i;
        } 
    }

    if (encontradoNroCuenta == 1)
    {
        printf("Ingrese la contrase%ca\n", 164);
        scanf("%i", &contraIngresada); 
        contadorPassword = 1;
        while (encontradoPassword == 0 && contadorPassword<3)
                {
                    if (array[indice].password == contraIngresada)
                    {
                        encontradoPassword = 1;    
                    }
                   
                   if(encontradoPassword == 0){
                    printf("Ingrese la contrase%ca\n",164);
                    scanf("%i", &contraIngresada); 
                    contadorPassword++;
                   }  
                }
    } 

    if (encontradoPassword == 0){
        strcpy(array[indice].estado, "bloqueado");
    }

        return indice;
}