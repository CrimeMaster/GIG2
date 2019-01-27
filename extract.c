#include<stdio.h>
#include<ctype.h>

int main(){
    /* take a string from the user and delete numbers
     * from the string
     */
    char line[100];
    int i, j;
    printf("Enter a string: ");
    scanf("%s",line);
    
    for(i = 0; line[i] != '\0'; i++)
    {
        while (!(isalpha(line[i]))|| line[i] == '\0')
        {
            for(j = i; line[j] != '\0'; j++)
            {
                line[j] = line[j+1];
            }
            line[j] = '\0';
        }
    }
    printf("Output String: %s",line);
    printf("\n");
    
    return 0;
}

