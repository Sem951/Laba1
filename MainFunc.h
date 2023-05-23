#ifndef LABA1_MAINFUNC_H
#define LABA1_MAINFUNC_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "HelperFuncs.h"


struct country
{
    char name[30];
    int gold;
    int silver;
    int bronze;
};


/**
 * @brief Add a country to the array of structures.
 *
 * @param c Pointer to the array of structures "country".
 * @param c_num Current number of countries in the array.
 *
 * @return 1 if the country was added successfully, 0 if the country was already in the array.
 */
int add_country(struct country **c, int c_num)
{
    char name_temp[30];
    struct country temp;
    int added_indicator = 0;
    printf("\nEnter the name of the country you want to add: ");
    scanf("%s", name_temp);
    while (getchar() != '\n');

    int i;
    for (i = 0; i < c_num; i++)
    {
        if (strcmp((*c)[i].name, name_temp) == 0)
        {
            printf("The country is already in the list\n");

            char choise;
            printf("\nWould you like to add medals to the country?"
                   "\nEnter 'y' to continue or 'n' to cancel: ");
            scanf("%s1", &choise);

            if (choise == 'y' || choise == 'Y')
            {
                printf("Enter the add gold (%s): ", name_temp);
                (*c)[i].gold += scan_safe_func();
                printf("Enter the add silver (%s): ", name_temp);
                (*c)[i].silver += scan_safe_func();
                printf("Enter the add bronze (%s): ", name_temp);
                (*c)[i].bronze += scan_safe_func();
            }

            break;
        }
    }

    if (i == c_num)
    {
        *c = (struct country *) realloc(*c, sizeof(struct country) * (c_num + 1));
        if (*c == NULL)
        {
            printf("Failed to allocate memory\n");
            exit(1);
        }

        strcpy((*c)[c_num].name, name_temp);
        printf("Enter the gold: ");
        (*c)[i].gold = scan_safe_func();
        printf("Enter the silver: ");
        (*c)[i].silver = scan_safe_func();
        printf("Enter the bronze: ");
        (*c)[i].bronze = scan_safe_func();

        added_indicator = 1;
    }

    for (; i > 0; i--)
    {
        if ((*c)[i].gold > (*c)[i - 1].gold)
        {
            temp = (*c)[i];
            (*c)[i] = (*c)[i - 1];
            (*c)[i - 1] = temp;
        } else if ((*c)[i].gold == (*c)[i - 1].gold)
        {
            if ((*c)[i].silver > (*c)[i - 1].silver)
            {
                temp = (*c)[i];
                (*c)[i] = (*c)[i - 1];
                (*c)[i - 1] = temp;
            } else if ((*c)[i].silver == (*c)[i - 1].silver)
            {
                if ((*c)[i].bronze > (*c)[i - 1].bronze)
                {
                    temp = (*c)[i];
                    (*c)[i] = (*c)[i - 1];
                    (*c)[i - 1] = temp;
                }
            }
        }
    }

    return added_indicator;
}


/**
 * @brief Adding multiple countries to the array.
 *
 * @param c Pointer to an array of structures "country".
 * @param c_num Current number of countries in the array.
 *
 * @return Updated number of countries in the array.
 */
int add_countries(struct country **c, int c_num)
{
    int additive, i;
    printf("Number of countries to add: ");
    additive = range_scan(0, 1000);

    for (i = 0; i < additive; i++)
        c_num += add_country(c, c_num);

    return c_num;
}


/**
 * @brief Display information about the country on the screen by the name of the country.
 *
 * @param c Pointer to the array of structures "country".
 * @param c_num The current number of countries in the array.
 *
 * @return Void.
 */
void print_country_of_name(struct country *c, int c_num)
{
    char name_temp[30];
    printf("\nEnter the name of the country you want to print: ");
    scanf("%s", name_temp);
    while (getchar() != '\n');

    int i;
    for (i = 0; i < c_num; i++)
    {
        if (strcmp(c[i].name, name_temp) == 0)
        {
            printf("place\tname\tgold\tsilver\tbronze\n");
            printf("%d\t%s\t%d\t%d\t%d\n", i + 1, c[i].name, c[i].gold, c[i].silver, c[i].bronze);
            return;
        }
    }
    printf("Country '%s' not found.\n", name_temp);
}


/**
 * @brief Display information about all countries on the screen.
 *
 * @param c Pointer to the array of structures "country".
 * @param c_num The current number of countries in the array.
 *
 * @return Void.
 */
void print_countries(struct country *c, int c_num)
{
    if (c_num > 0)
    {
        printf("place\tname\tgold\tsilver\tbronze\n");

        int i;
        for (i = 0; i < c_num; i++)
            printf("%d\t%s\t%d\t%d\t%d\n", i + 1, c[i].name, c[i].gold, c[i].silver, c[i].bronze);
    } else
        printf("No countries found.\n");
}


#endif //LABA1_MAINFUNC_H
