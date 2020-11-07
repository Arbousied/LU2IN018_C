#include <stdio.h>
#include <stdlib.h>
int compte_mots_chaine(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

int compte_mots(char **str){
    int i = 0;
    int j = 0;
    int mots = 0;
    while (str[i] != NULL)
    {

        while (str[i][j] != '\0')
        {
            if (j > 2){
                mots++;
                break; 
            }
            j++;
            
        }
        j = 0;
        i++;
    }
    return mots;
}

void affichagemots(char **str){
	int i = 0;
	printf("[");
	while (str[i] != NULL)
	{
		printf("%s, ", str[i]);
		i++;
	}
	printf("]");
}

char *compose_chaine(char **str){
	int i = 0;
	while (str[i] != NULL)
	{
		i++;
	}
	char *phrase = malloc(sizeof(char) * i);
	int j = 0;
	while (str[j] != NULL)
	{
		*phrase + *str[j];
		*phrase += " ";
		j++;
	}
	i = 0;
	while (phrase[i] != '\0')
	{
		printf("%c", phrase[i]);
		i++;
	}
	return phrase;
}

int main()
{
    char *str[] = {"mot1", "et", "mot2", "et", "mot3", NULL};
    //printf("%d", compte_mots_chaine(str));
    affichagemots(str);
    printf("\nnombre de mots : %d", compte_mots(str));
    free(compose_chaine(str));
    return 0;
}
