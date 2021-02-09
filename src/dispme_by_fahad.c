#include <unistd.h>

size_t my_strlen(const char *str)
{
    size_t i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

int dump_word_n_times(const int beg, int n, char *str)
{
    while (n-- > 0) {
        for (int i = beg; str[i] != '\0'; i++) {
            if (str[i] != ' ' && write(1, &str[i], 1) != 1)
               return 84; 
        }
        if (write(1, "\n", 1) == -1) 
            return 84;
    }
    return 0;
}

/*
 * Cette version du code remplace simplement les chiffres par des \0
 * je rajoute que cette methode est conseiller seulement si vous avez
 * une matrise complete de la string que vous manipulez
 */
int dumper(char *str)
{
    int num = 0; // va hold le nombre trouver apres le mot
    int l_counter = 0; // conteur de lettres dans ma substring
    const size_t len = my_strlen(str);

    for (size_t index = 0; index < len; index++) {
        if (str[index] >= '0' && str[index] <= '9') {
            num = str[index] - '0';
            str[index] = '\0';
            if (dump_word_n_times(index-l_counter, num, str) != 0)
                return 84;
            l_counter=0;
            ++index;
        }
        if (str[index] == ' ') {
            if (write(1, "\n", 1) != 1)
                return 84;
            l_counter=0;
        }
        ++l_counter;
    }
    return 0;
}
