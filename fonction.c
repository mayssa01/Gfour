#include "client.h"
#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
enum
 {
  ENOM,
  EPRENOM,
  ECIN,
  EADRESSE,
  COLUMNS
  };

void ajouter_client(Client c)
{
   
    FILE *fc=NULL;
    fc=fopen("utilisateur.txt","a+");
   
    fprintf(fc,"%s%s%s%s \n",c.nom,c.prenom,c.cin,c.adresse);
    fclose(fc);

}
void afficher_client(GtkWidget *liste) 
{
	GtkCellRenderer *renderer; 
	GtkTreeViewColumn *column; 
	GtkTreeIter	iter; 
	GtkListStore *store; 

	char nom[20];
	char prenom[10];
	char cin[10];
	char adresse[30];
 

	store=NULL;


FILE *f;

store=gtk_tree_view_get_model(liste);


if(store==NULL)
{
		renderer =gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Nom",renderer, "text",ENOM,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Prenom",renderer, "text",EPRENOM,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Cin",renderer, "text",ECIN,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


		renderer = gtk_cell_renderer_text_new (); 
		column = gtk_tree_view_column_new_with_attributes("adresse",renderer, "text",EADRESSE,NULL); 
		gtk_tree_view_append_column (GTK_TREE_VIEW(liste),column); 
}
	        store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	
	        f = fopen("utilisateur.txt", "r");

	if(f==NULL)
	{
		
		return ;
	} 
	else 
	{ f = fopen("utilisateur.txt", "a+");
		while(fscanf(f,"%s%s%s%s \n",nom,prenom,cin,adresse)!=EOF)
            {
	gtk_list_store_append (store, &iter); 
	gtk_list_store_set (store, &iter,ENOM,nom,EPRENOM,prenom,ECIN,cin,EADRESSE,adresse,-1);
             }
             fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
	}
 
       }
void modifier(char cin6[],Client s)
{
    FILE *f;
    FILE *ftemp;
    ftemp=NULL;
    Client c;
   
    f=fopen("utilisateur.txt","r+");
    ftemp=fopen("utilisateur.txt.temp","a+");
    if (f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s\n",c.nom,c.prenom,c.cin,c.adresse)!=EOF)
        {
            if(strcmp(cin6,c.cin)==0)
            {
      			strcpy(c.cin,s.cin);
      			strcpy(c.prenom,s.prenom);
      			strcpy(c.nom,s.nom);
			strcpy(c.adresse,s.adresse);

                       	
            fprintf(ftemp,"%s %s %s %s \n",c.nom,c.prenom,c.cin,c.adresse);
        }

    }
    fclose(ftemp);
    fclose(f);
    remove("utilisateur.txt");
    rename("utilisateur.txt.temp","utilisateur.txt");
}
}

void supprimer(char cinsupp[])
{
        char nom[20];
	char prenom[10];
	char cin[10];
	char adresse[30];
 
FILE *f,*h;
Client c;
f = fopen("utilisateur.txt", "r");
h = fopen("utilisateur2.txt", "w");

	if (f==NULL || h==NULL)
	{
	    return;
	}
	else
	   {
	
		while(fscanf(f,"%s %s %s %s \n",cin,nom,prenom,adresse)!=EOF)
			{
				if( strcmp(c.nom,nom)!=0 || strcmp(c.prenom,prenom)!=0 ||  strcmp(c.cin,cin)!=0 ||    	strcmp(c.adresse,adresse)!=0 ) 
				fprintf(h,"%s %s %s %s \n",nom,prenom,cin,adresse);
		         }
		         fclose(f);
		         fclose(h);
	remove("utilisateur.txt");
	rename("utilisateur2.txt","utilisateur.txt");

             }

        }




