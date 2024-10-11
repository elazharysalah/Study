#include <stdio.h>
#include <string.h>
#include <pthread.h>

char login[50];
char password[50];
char reversed_login[50];

void *saisir() {
    printf("Enter login: ");
    scanf("%s", login);
    printf("Enter password: ");
    scanf("%s", password);
    return NULL;
}

void *inverse() {
    int len = strlen(login);
    for (int i = 0; i < len; i++) {
        reversed_login[i] = login[len - i - 1];
    }
    reversed_login[len] = '\0';
    return NULL;
}

void *affiche() {
    if (strcmp(reversed_login, password) == 0) {
        printf("authentication reussie\n");
    } else {
        printf("authentication refusé\n");
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3;
    pthread_create(&thread1, NULL, saisir, NULL);
    pthread_join(thread1, NULL);

    pthread_create(&thread2, NULL, inverse, NULL);
    pthread_join(thread2, NULL);

    pthread_create(&thread3, NULL, affiche, NULL);
    pthread_join(thread3, NULL);

    return 0;
}
