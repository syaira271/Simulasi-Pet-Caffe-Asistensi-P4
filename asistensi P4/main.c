#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Mendefinisikan struct untuk karakter Employee dan Pet
typedef struct {
    char name [30];
    int energy;
    int loves;

}Employee;

typedef struct {
    char name [30];
    int energy;
    int loves;

} Pet;


//Mendeklarasikan karakter Employee dan Pet
Employee employee = {"Diane",60,80};
Pet pet = {"Caty",50,50};

//fungsi untuk menampilkan atribut karakter
void show_attributes(char *name){
    if (strcmp(name, employee.name)==0){
        printf("Atribut Employee %s:\n", employee.name);
        printf("Energy:%d\n", employee.energy);
        printf("Loves:%d\n", employee.loves);
    }else if (strcmp(name,pet.name)==0){
        printf("Atribut pet %s:\n", pet.name);
        printf("Energy:%d\n", pet.energy);
        printf("Loves:%d\n",pet.loves);
    }else {
        printf("Karakter dengan nama %s tidak dapat dikenali.\n", name);
    }
}

//Fungsi untuk menambah Loves pet ketika di-petting
void petting_pet(char*name){
    if(strcmp(name, pet.name)==0){
        pet.loves +=5;
        printf("yeay your pet gets more loves\n", pet.name);
    }else {
        printf("Karakter %s tidak dapat dikenali.\n", name);
    }
}

//Fungsi untuk menambah energy employee ketika diberi makan
void feed_employee(char*name){
    if (strcmp(name, employee.name)==0){
        employee.energy +=5;
        printf("yeay %s feels more energy!\n", employee.name);
    }else {
        printf("Karakter %s tidak dapat dikenali.\n",name);
    }
}


int main()
{
    char command[100];
    char action[30];
    char target [30];

    printf("Hi! welcome in Pet Cafe Simulation!\n");
    printf("Masukkan perintah aktivitas atau tampilkan atribut\n");
    printf("Berikut pilihan perintah yang tersedia:\n");
    printf("1. PETTING <NamaPet>\n");
    printf("2. FEED <NamaEmployee>\n");
    printf("3. ATTR <NamaKarakter>\n");
    printf("4. EXIT\n");

    while (1){
        printf("Masukkan perintah\n: ");
        fgets(command,sizeof(command),stdin);
        sscanf(command, "%s %s", action, target);

        if (strcmp(action,"PETTING")==0){
            petting_pet(target);
        }else if(strcmp(action,"FEED")==0){
            feed_employee(target);
        }else if(strcmp(action,"ATTR")==0){
            show_attributes(target);
        }else if(strcmp(action, "EXIT")==0){
            printf("Keluar dari simulasi. Thank you!\n");
            break;
        }else {
            printf("Perintah tidak sesuai. Try again please.\n");
        }
    }

    return 0;
}
