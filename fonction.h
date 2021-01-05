#include <gtk/gtk.h>

typedef struct 
{
char nom[20];
char prenom[10];
char cin[10];
char adresse[30];
 

} Client;

void ajouter_client(Client c);
void modifier(char cin6[],Client s);
void afficher_client(GtkWidget *liste); 
void supprimer(char cinsupp[]);

