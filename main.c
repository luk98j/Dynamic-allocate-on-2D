#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int **create_array_2d(int width, int height);
void display_array_2d(int **ptr, int width, int height);
void destroy_array_2d(int **ptr, int height);
int main()
{
    int width, height;
    printf("Podaj szerokosc i wysokosc: ");
     if(scanf("%d",&width)!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(scanf("%d",&height)!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(width<1||height<1){
         printf("Incorrect input data");
        return 2;
    }
    int **ptr;
    ptr = create_array_2d(width,height);
    if (!ptr){
            destroy_array_2d(ptr,height);
            printf("Failed to allocate memory");

            return 8;
    }
    printf("Podaj liczby: ");
    for(int j=0;j<height;j++)
        {
            for(int i=0;i<width;i++)
            {
                int num=0;
                if(scanf("%d",&num)!=1)
                    {
                        destroy_array_2d(ptr,height);
                        printf("Incorrect input");

                        return 1;
                    }
                *(*(ptr+j)+i) = num;
            }

        }
    display_array_2d(ptr,width,height);
    destroy_array_2d(ptr,height);
    return 0;
}
int **create_array_2d(int width, int height){
    if(width<1){
    return NULL;
    }
    if(height<1){
    return NULL;
    }
    int **ptr =NULL;
    ptr = (int**)malloc(height * sizeof(int*));
     if(ptr==NULL)
    {
        free(ptr);
        return NULL;
    }
    else for(int i=0;i<height;i++)
        {
        *(ptr+i)= (int*)malloc(width * sizeof(int));
         if((*(ptr+i))==NULL)
        {
            for (int j=0; j<height; j++)
            {
                free(*(ptr+j));
            }
            free(ptr);
            return NULL;
        }
        }
    return ptr;
}
void display_array_2d(int **ptr, int width, int height){
    if(width<1){}
    else if(height<1){}
    else if(ptr!=NULL){
    for(int i=0;i<height;i++)
    {


            for (int j=0; j<width; j++)
            {
                printf("%d ",*(*(ptr+i)+j));
            }
    printf("\n");
        }
    }
}
void destroy_array_2d(int **ptr, int height){
    if(ptr!=NULL){
    for (int i=0; i<height; i++)
    {
        free(*(ptr+i));
    }

    free(ptr);
    ptr = NULL;
    }
}
