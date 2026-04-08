  GNU nano 3.2                                                        ejercicio3op.c                                                                    


    c = posix_memalign((void**)&x,8, X * Y * sizeof(unsigned char)); //Utilizamos unsigned char porque solo guardamos 0 y 1. No 
 //son necesarios 4 bytes por celda.

    if (c != 0) {
        printf("Error al reservar memoria para x\n");
        free(m);//Liberamos la memoria pedida en el puntero m.
        return 1;
    }

    for (i = 0; i < X; i++) {
        m[i] = &x[i * Y];
    }

    for (i = 0; i < X; i++) {
        for (j = 0; j < Y; j++) {
            m[i][j] = j % 2;
        }
    }

/*struct rusage usage;

getrusage(RUSAGE_SELF, &usage);

printf("Memoria usada: %ld KB\n", usage.ru_maxrss);
*/
free(x);
free(m);

 return 0;
}



