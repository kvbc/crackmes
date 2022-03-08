#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
 *
 * Reversed
 *
 */

char* hash_nick (const char* nick) {
    int hashlen = strlen("tryHarderToMakeAGoodKeyGen");
    int strl = strlen(nick);
    char* newstr = malloc(strl + 1);
    if (newstr == NULL) {
        fprintf(stderr, "%s \n", "Erreur d'allocation dynamique");
        exit(1);
    }
    for (int i = 0; i < strl; i++)
        newstr[i] = nick[(nick[i] ^ hashlen) % strl];
    newstr[strl] = '\0';
    return newstr;
}

// Function used to check if the password is "good" for the hashed nickname,
// in that case it just checks if those two are the same.
// So the final password is just the result of hash_nick()
int is_pass_good_for_hashed_nick (const char* pass, const char* hashed_nick) {
    int pass_len = strlen(pass);
    int hashed_nick_len = strlen(hashed_nick);

    if (pass_len != hashed_nick_len)
        return 0;

    for (int i = 0; i < pass_len; i++)
        if (pass[i] != hashed_nick[i])
            return 0;

    return 1;
}

/*
 *
 * KeyGen
 *
 */

int main (void) {
    char nick[100];
    printf("Enter username: ");
    scanf("%s", nick);
    char* pass = hash_nick(nick);
    printf("The password is: %s", pass);
    free(pass);
    return 0;
}
