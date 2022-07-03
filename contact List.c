#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void menu();
void add_contact();
void show_contact();
void search_contact();
void edit_contact();
void del_contact();
void exit_menu();
struct contact
{
    double ph;
    char name[20];
} list;
char query[20],name[20];
FILE *fp, *ft;
int i,n,ch,l,found;

int main()
{
    menu();
    exit_menu();
    return 0;
}

void menu()
{
    system("cls");
    printf("\n\t **** Welcome to Contact Management System ****");
    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n");
    printf("\t\t 1. Add a new Contact\n");
    printf("\t\t 2. List all Contacts\n");
    printf("\t\t 3. Search for contact\n");
    printf("\t\t 4. Edit a Contact\n");
    printf("\t\t 5. Delete a Contact\n");
    printf("\t\t 6. Exit\n\t\t=================\n\t\t");
    printf("Enter the choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        add_contact();
        break;
    case 2:
        show_contact();
        break;
    case 3:
        search_contact();
        break;
    case 4:
        edit_contact();
        break;
    case 5:
        del_contact();
        break;
    case 6:
        exit(0);
        break;
    default:
        printf("\n\tInvalid choice");
        getch();
        break;
    }
}

void add_contact()
{
    system("cls");
    fp=fopen("contact.bin","a");
    for (;;)
    {
        fflush(stdin);
        printf("To exit press spacebar and then press enter key in the name input\nName (Use identical):");
        scanf("%[^\n]",&list.name);
        if(stricmp(list.name," ")==0)
            break;
        fflush(stdin);
        printf("Phone:");
        scanf("%lf",&list.ph);
        fflush(stdin);
        printf("\n");
        fwrite(&list,sizeof(list),1,fp);
    }
    fclose(fp);
}

void show_contact()
{
    system("cls");
    printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n\n");
    printf("Name\t\tPhone No\t    \n=================================================================\n\n");
    for(i=97; i<=122; i=i+1)
    {
        fp=fopen("contact.bin","r");
        fflush(stdin);
        found=0;
        while(fread(&list,sizeof(list),1,fp)==1)
        {
            if(list.name[0]==i || list.name[0]==i-32)
            {
                printf("\nName\t: %s\nPhone\t: %.0lf\n",list.name,list.ph);
                found++;
            }
        }
        if(found!=0)
        {
            printf("===========================================================");
            getch();
        }
        fclose(fp);
    }
}

void search_contact()
{
    system("cls");
    do
    {
        found=0;
        printf("\n\n\t ->CONTACT SEARCH\n\t===========================\n\t->Name of contact to search: ");
        fflush(stdin);
        scanf("%[^\n]",&query);
        l=strlen(query);
        fp=fopen("contact.bin","r");
        system("cls");
        printf("\n\n->Search result for '%s' \n===================================================\n",query);
        while(fread(&list,sizeof(list),1,fp)==1)
        {
            for(i=0; i<=l; i++)
                name[i]=list.name[i];
            name[l]='\0';
            if(stricmp(name,query)==0)
            {
                printf("\n->Name\t: %s\n->Phone\t: %.0lf\n",list.name,list.ph);
                found++;
                printf("->Press any key to continue...");
                getch();
                exit_menu();
            }
            else
                {
                    printf("\n\t->No match found!");
                    getch();
                    exit_menu();
                }
        }
        fclose(fp);
    }
    while(ch);
}

void edit_contact()
{
    system("cls");
    fp=fopen("contact.bin","r");
    ft=fopen("temp.dat","w");
    fflush(stdin);
    printf("->Edit contact\n===============================\n\n\t->Enter the name of contact to edit : ");
    scanf("%[^\n]",name);
    if(stricmp(name,list.name)!=0)
        printf("\n\t NO Contact found by the name of %s",name);
    else
    {
        fflush(stdin);
        printf("\n\n->Editing '%s'\n\n",name);
        printf("->Name(Use identical):");
        scanf("%[^\n]",&list.name);
        fflush(stdin);
        printf("->Phone:");
        scanf("%ld",&list.ph);
        fflush(stdin);
        printf("\n");
        fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("contact.bin");
        rename("temp.dat","contact.bin");
    }
    getch();
}

void del_contact()
{
    system("cls");
    fflush(stdin);
    printf("\n\n\t->DELETE A CONTACT\n\t==========================\n\t->Enter the name of contact to delete:");
    scanf("%[^\n]",&name);
    fp=fopen("contact.bin","r");
    ft=fopen("temp.dat","w");
    while(fread(&list,sizeof(list),1,fp)!=0)
        if (stricmp(name,list.name)!=0)
            fwrite(&list,sizeof(list),1,ft);
    fclose(fp);
    fclose(ft);
    remove("contact.bin");
    rename("temp.dat","contact.bin");
    printf("\tcontact not found");
    getch();
}

void exit_menu()
{
    while(1)
    {
        system("cls");
        printf("\n\n\n->Enter the Choice:\n\n\t 1. Main Menu\t\t 2. Exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            menu();
            break;
        case 2:
            exit(0);
            break;
        default:
            printf("\n\tInvalid choice");
            getch();
            break;
        }
    }
}
