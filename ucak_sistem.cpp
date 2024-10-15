#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
// Yolcu veri yapisi 
struct Passenger { 
char name[50]; 
char destination[50]; 
struct Passenger* next; 
}; 
// Bagli liste yapisi 
struct LinkedList { 
struct Passenger* head; 
}; 
// Bagli liste fonksiyonlari 
struct LinkedList* createLinkedList(); 
void insertAtEnd(struct LinkedList* list, const char* name, const char* destination); 
void printFlights(struct LinkedList* list); 
void printPassengers(struct LinkedList* list); 
void printDestinations(struct LinkedList* list); 
int countFlights(struct LinkedList* list); 
void deleteFlight(struct LinkedList* list); 
int main() { 
struct LinkedList* flightList = createLinkedList(); 
int choice; 
do { 
printf("\n    Yapmak istediginiz islemi seciniz:\n"); 
printf("1 - Yeni ucus ekleme\n"); 
printf("2 - Tum ucuslari listeleme\n"); 
printf("3 - Tum yolcu isimlerini listeleme\n"); 
printf("4 - Gidilecek tum sehirleri listeleme\n"); 
printf("5 - Su andaki toplam ucus sayisi\n"); 
printf("6 - Ucus silme\n"); 
printf("7 - Cikis\n"); 
scanf("%d", &choice); 
switch (choice) { 
case 1: { 
char passengerName[50]; 
char destination[50]; 
printf("Yolcunun ismini giriniz: "); 
scanf("%s", passengerName); 
printf("Gidecegi sehri giriniz: "); 
scanf("%s", destination); 
insertAtEnd(flightList, passengerName, destination); 
break; 
} 
case 2: 
                printFlights(flightList); 
                break; 
            case 3: 
                printPassengers(flightList); 
                break; 
            case 4: 
                printDestinations(flightList); 
                break; 
            case 5: 
                printf("Su andaki toplam ucus sayisi: %d\n", countFlights(flightList)); 
                break; 
            case 6: 
                deleteFlight(flightList); 
                break; 
            case 7: 
                printf("Cikis yapiliyor...\n"); 
                break; 
            default: 
                printf("Gecersiz secim. Lutfen tekrar deneyin.\n"); 
        } 
  
    } while (choice != 7); 
  
    return 0; 
} 
  
// Bagli liste fonksiyonlari 
struct LinkedList* createLinkedList() { 
struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList)); 
list->head = NULL; 
return list; 
} 
void insertAtEnd(struct LinkedList* list, const char* name, const char* destination) { 
struct Passenger* newPassenger = (struct Passenger*)malloc(sizeof(struct Passenger)); 
strcpy(newPassenger->name, name); 
strcpy(newPassenger->destination, destination); 
newPassenger->next = NULL; 
if (list->head == NULL) { 
list->head = newPassenger; 
} else { 
struct Passenger* current = list->head; 
while (current->next != NULL) { 
current = current->next; 
} 
current->next = newPassenger; 
} 
printf("Yeni ucus eklendi: Yolcu ismi : %s , Rota : Istanbul --> %s\n", name, destination); 
} 
void printFlights(struct LinkedList* list) { 
struct Passenger* current = list->head; 
if (current == NULL) { 
printf("Su anda tum ucuslar bos.\n"); 
return; 
} 
printf("Su andaki tum ucus seferleri:\n"); 
int count = 1; 
while (current != NULL) { 
printf("%d - %s --> %s\n", count++, current->name, current->destination); 
current = current->next; 
} 
} 
void printPassengers(struct LinkedList* list) { 
struct Passenger* current = list->head; 
if (current == NULL) { 
printf("Su anda tum yolcular bos.\n"); 
return; 
} 
printf("Su andaki tum yolcu isimleri:\n"); 
int count = 1; 
while (current != NULL) { 
printf("%d - %s\n", count++, current->name); 
current = current->next; 
} 
} 
void printDestinations(struct LinkedList* list) { 
struct Passenger* current = list->head; 
if (current == NULL) { 
printf("Su anda tum destinasyonlar bos.\n"); 
return; 
} 
printf("Gidilecek tum sehirler:\n"); 
int count = 1; 
while (current != NULL) { 
printf("%d - %s\n", count++, current->destination); 
current = current->next; 
} 
} 
int countFlights(struct LinkedList* list) { 
int count = 0; 
struct Passenger* current = list->head; 
while (current != NULL) { 
count++; 
current = current->next; 
} 
return count; 
} 
void deleteFlight(struct LinkedList* list) { 
if (list->head == NULL) { 
printf("Su anda silecek ucus yok.\n"); 
return; 
} 
printf("Silmek istediginiz ucusu seciniz:\n"); 
printFlights(list); 
int choice; 
scanf("%d", &choice); 
if (choice < 1 || choice > countFlights(list)) { 
printf("Gecersiz secim.\n"); 
return; 
} 
struct Passenger* current = list->head; 
struct Passenger* previous = NULL; 
int count = 1; 
while (count < choice) { 
previous = current; 
current = current->next; 
count++; 
} 
if (previous == NULL) { 
list->head = current->next; 
} else { 
previous->next = current->next; 
} 
free(current); 
printf("Ucus silindi.\n"); 
}
