#include "stdio.h"
#include "stdio.h"
struct dict{
    struct dict*left,*right;
    char word[20],meaning[20];
}*root=NULL;
typedef struct dict dictionary;
void search();
void insert( dictionary *);
void view(dictionary *);
int check(char[],char[]);
int check(char a[],char b[]){
    int i,j,c;
    for(i=0,j=0;a[i]!='\0' && b[j]!='\0';i++,j++)
    {
    if(a[i]>b[j])
    {
        c=1;
        break;
    } else if(a[i]<b[j])
    {
        c=-1;
        break;
    }else
    {
        c=0;
    }
    }
    if(c==1)
    return 1;
    else if(c==-1)
    return -1;
    else
    return 0;
}

void search()
{
    char w[20];
    dictionary *ptr=root;
    int flag=0;
    printf("\n Enter the word  ", );
    scanf("%s\n",w );
    while(ptr!=NULL && flag==0)
    {
    if(check(w,ptr->word)==1)
    ptr=ptr->right;
    else if(check(w,ptr->word)==-1)
    ptr=ptr->left;
    else
    {
        flag=1;
        printf("\n Meaning  : %s",ptr->meaning );
        break;
    }
    }
    if(flag==0 && ptr==NULL)
    printf("\n Word not found ");
}

void insert(dictionary* temp)
{
    dictionary *ptr=root,*par;
    int flag=0;
    if(root==NULL)
    root=temp;
    else
    {
        while(ptr!=NULL)
        {
        if(check(temp->word,ptr->word)==1)
        {
        par=ptr;
        ptr=ptr->right;
        }
        else if(check(temp->word,ptr->word)==-1)
        {
            par=ptr;
            ptr=ptr->left;
        }
        else
        {
            flag=1;
            printf("\n Word exists" );
            break;
        }
        }
        if(flag==0)
        {
        if(check(par->word,temp->word)==1)
        par->left=temp;
        else if(check(par->word,temp->word)==-1)
        par->right=temp;
        }
    }
}

void veiw(dictionary *ptr)
{
    if(roo==NULL)
    {
        printf("\n Empty dictionary " );
    }
    else
    {
        if(ptr!=NULL)
        {
            view(ptr->left);
            printf("\n Word : %s",ptr->word);
            printf("\n Word : %s",ptr->meaning );
            veiw(ptr->right);
        }
    }
}



int main(int argc, char const *argv[]) {
    int ch;
    while(ch){
        printf("\n1.Search\n2.Insert\n3.View\n4.Quit\nYour choice please.. ", );
        scanf("%d",&ch );
        switch(ch)
        {
            case 1:search();break;
            case 2:
            temp=(dictionary *)malloc(sizeof(dictionary));
            temp->left=NULL;
            temp->right=NULL;
            printf("\nInsert word ");
            scanf("%s",temp->word );
            printf("\nInsert meaning ");
            scanf("%s",temp->meaning );
            insert(temp);break;
            case 3:view(root);break;
            case 4:exit(0);
        }
    }
    return 0;
}
