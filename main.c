#include <stdio.h>

#include "MainFunc.h"
#include "HelperFuncs.h"


int main()
{
    struct country *countries = NULL;
    int size = 0, menubar;
    countries = (struct country *) calloc(size, sizeof(struct country));


    while (1)
    {
        system("cls");
        printf("1 - adding countries \n"
               "2 - country data \n"
               "3 - general table\n"
               "0 - Exit \n"
               "Make a choice: ");

        menubar = range_scan(0, 3);
        switch (menubar)
        {
            case 1:
                size = add_countries(&countries, size);
                break;
            case 2:
                print_country_of_name(countries, size);
                break;
            case 3:
                print_countries(countries, size);
                break;
            case 0:
                return 0;
        }
        printf("\n\n");
        system("pause");
    }
}
