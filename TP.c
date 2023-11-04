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

int login(struct Cliente array[10]);
void deposito(int indiceEncontrado, struct Cliente array[10]);
void extraccion(int indiceEncontrado, struct Cliente array[10]);
void consultarSaldo(int indiceEncontrado, struct Cliente array[10]);
void transferencia(int indiceEncontrado, struct Cliente array[10]);
void mostrarOpYSaldo(int indiceEncontrado, struct Cliente array[10], int cantidadOperaciones);

int main()
{

    struct Cliente clientes[10];
    char nombreingresado[50];
    int opcion, indiceEncontrado, indice, cantidadOperaciones;
    bool bucleCajero = true;

    strcpy(clientes[0].nombre, "Juan");
    clientes[0].password = 1234;
    clientes[0].numCuenta = 101;
    clientes[0].saldo = 150000;
    strcpy(clientes[0].estado, "activo");

    strcpy(clientes[1].nombre, "Jorge");
    clientes[1].password = 1235;
    clientes[1].numCuenta = 110;
    clientes[1].saldo = 910000;
    strcpy(clientes[1].estado, "activo");

    strcpy(clientes[2].nombre, "Guts");
    clientes[2].password = 1236;
    clientes[2].numCuenta = 120;
    clientes[2].saldo = 1350000;
    strcpy(clientes[2].estado, "activo");

    strcpy(clientes[3].nombre, "Griffith");
    clientes[3].password = 1237;
    clientes[3].numCuenta = 130;
    clientes[3].saldo = 80000;
    strcpy(clientes[3].estado, "activo");

    strcpy(clientes[4].nombre, "Casca");
    clientes[4].password = 1238;
    clientes[4].numCuenta = 140;
    clientes[4].saldo = 450000;
    strcpy(clientes[4].estado, "activo");

    strcpy(clientes[5].nombre, "Mario");
    clientes[5].password = 1239;
    clientes[5].numCuenta = 150;
    clientes[5].saldo = 15000000;
    strcpy(clientes[5].estado, "activo");

    strcpy(clientes[6].nombre, "Juana");
    clientes[6].password = 1241;
    clientes[6].numCuenta = 160;
    clientes[6].saldo = 10000;
    strcpy(clientes[6].estado, "activo");

    strcpy(clientes[7].nombre, "Francisco");
    clientes[7].password = 1242;
    clientes[7].numCuenta = 170;
    clientes[7].saldo = 15;
    strcpy(clientes[7].estado, "activo");

    strcpy(clientes[8].nombre, "Máximo");
    clientes[8].password = 1243;
    clientes[8].numCuenta = 180;
    clientes[8].saldo = 15000000;
    strcpy(clientes[8].estado, "activo");

    strcpy(clientes[9].nombre, "Puck");
    clientes[9].password = 1244;
    clientes[9].numCuenta = 190;
    clientes[9].saldo = 250000;
    strcpy(clientes[9].estado, "activo");

    do
    {
        cantidadOperaciones = 0;
        indiceEncontrado = login(clientes);

        if (strcmp(clientes[indiceEncontrado].estado, "activo") == 0)
        {
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
                    deposito(indiceEncontrado, clientes);
                    cantidadOperaciones++;
                    break;
                case 2:
                    printf(" Realizar una Extracci%cn\n", 162);
                    extraccion(indiceEncontrado, clientes);
                    cantidadOperaciones++;
                    break;
                case 3:
                    printf("Consultar el Saldo de la Cuenta\n");
                    consultarSaldo(indiceEncontrado, clientes);
                    cantidadOperaciones++;
                    break;
                case 4:
                    printf("Realizar una Transferencia entre Cuentas\n");
                    transferencia(indiceEncontrado, clientes);
                    break;
                case 5:
                    printf("Mostrar cantidad de Operaciones Realizadas y Saldo Actual\n");
                    mostrarOpYSaldo(indiceEncontrado, clientes, cantidadOperaciones);
                    break;
                case 6:
                    printf("Ha salido de la sesi%cn\n", 162);
                    break;
                }
            } while (opcion != 6 && cantidadOperaciones < 10);
        }

        if (cantidadOperaciones == 10)
        {
            printf("Superaste el l%cmite de operacionesk. Se ha cerrado la sesi%cn\n\n", 161, 162);
        }

    } while (bucleCajero);

    return 0;
}

int login(struct Cliente array[10])
{
    int contadorPassword, numCuentaIngresado, indice, contraIngresada, i;
    bool encontradoNroCuenta = false;
    bool encontradoPassword = false;
    bool encontradoCuentaActivo = false;

    do
    {
        printf("Ingrese su n%cmero de cuenta:\n", 163);
        scanf("%i", &numCuentaIngresado);
        for (i = 0; i < 10; i++)
        {
            if (array[i].numCuenta == numCuentaIngresado)
            {
                encontradoNroCuenta = true;
                indice = i;
                if (strcmp(array[i].estado, "activo") == 0)
                {
                    encontradoCuentaActivo = true;
                }
                else
                {
                    printf("Esa cuenta est%c bloqueada. Ingrese con otra:\n", 160);
                }
            }
        }
    } while (!encontradoNroCuenta && !encontradoCuentaActivo);

    if (encontradoNroCuenta && encontradoCuentaActivo)
    {
        printf("Ingrese la contrase%ca\n", 164);
        scanf("%i", &contraIngresada);
        contadorPassword = 1;
        while (!encontradoPassword && contadorPassword < 3)
        {
            if (array[indice].password == contraIngresada)
            {
                encontradoPassword = true;
            }

            if (!encontradoPassword)
            {
                printf("Ingrese la contrase%ca\n", 164);
                scanf("%i", &contraIngresada);
                contadorPassword++;
            }
        }
    }

    if (!encontradoPassword && encontradoCuentaActivo)
    {
        strcpy(array[indice].estado, "bloqueado");
        printf("Contrase%ca incorrecta. Cuenta bloqueada\n", 164);
    }

    return indice;
}

void deposito(int indiceEncontrado, struct Cliente array[10])
{
    float monto;
   
    printf("Ingrese el monto del dep%csito\n", 162);
    scanf("%f", &monto);
    while (monto <= 0)
    {
        printf("Ingrese un monto mayor a 0 para el dep%csito\n", 162);
        scanf("%f", &monto);
    }

    array[indiceEncontrado].saldo += monto;
}

void extraccion(int indiceEncontrado, struct Cliente array[10])
{
    float monto;
   
    printf("Ingrese el monto del extracci%cn\n", 162);
    scanf("%f", &monto);
    while (monto > array[indiceEncontrado].saldo)
    {
        printf("El monto que ingres%c supera su saldo. Ingrese otro por favor\n", 162);
        scanf("%f", &monto);
    }

    array[indiceEncontrado].saldo -= monto;
}

void consultarSaldo(int indiceEncontrado, struct Cliente array[10])
{
    printf("Su saldo actual es de %.2f\n", array[indiceEncontrado].saldo);
}

void transferencia(int indiceEncontrado, struct Cliente array[10])
{
    int numCuentaTransferido, indiceTransferencia;
    float monto;
    bool encontradoNroCuenta = false;

    do
    {
        printf("Ingrese el n%cmero de cuenta a quien vaya a transferirle\n", 163);
        scanf("%i", &numCuentaTransferido);
        for (int i = 0; i < 10; i++)
        {
            if (array[i].numCuenta == numCuentaTransferido)
            {
                encontradoNroCuenta = true;
                indiceTransferencia = i;
            }
        }
    } while (!encontradoNroCuenta);

    printf("Ingrese el monto a transferirle\n");
    scanf("%f", &monto);
    while (monto <= 0 || monto > array[indiceEncontrado].saldo)
    {
        printf("Ingrese un monto mayor a 0 y que no supere su saldo \n");
        scanf("%f", &monto);
    }
    array[indiceTransferencia].saldo += monto;
    array[indiceEncontrado].saldo -= monto;
}

void mostrarOpYSaldo(int indiceEncontrado, struct Cliente array[10], int cantidadOperaciones)
{
    printf("La cantidad de operaciones fueron: %i\n", cantidadOperaciones);
    printf("Su saldo actual es de %.2f\n", array[indiceEncontrado].saldo);
}