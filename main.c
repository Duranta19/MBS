#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct userData{
    int mobNum;
    int pass;
    int balance;
};
int menu(struct userData data[], int size, int id);
void resetPin(struct userData data[], int size, int id){
    system("cls");
    printf("==================================================\n");
    int pin, nPin, cPin;
    printf("Enter your pin:\n");
    printf(">>  ");
    scanf("%d", &pin);

    if(pin == data[id].pass){
        printf("Enter New Pin\n");
        printf(">> ");
        scanf("%d", &nPin);
        printf("Confirm New Pin\n");
        printf(">> ");
        scanf("%d", &cPin);
        if(nPin == cPin){
            printf("Pin reset successfully\n");
            data[id].pass = cPin;
        }
        else{
            printf("Confirm Your pin again\n");
        }
    }
    else{
        printf("Please try with correct pin");
    }
    FILE *temp;
    temp = fopen("Data.txt", "w");
    for (int i = 0; i < 10; i++){
        fprintf(temp, "%d %d %d\n", data[i].mobNum, data[i].pass, data[i].balance );
    }
    fclose(temp);
    //system("cls");
    printf("\n");
    printf("1. Menu\n");
    printf("2. Exit\n");
    int ch;
    printf(">> ");
    scanf("%d", &ch);
    if(ch == 1){
        menu(data, size ,id);
    }
    else{
        exit(0);
    }

}
void checkBalance(struct userData data[], int size, int id){
    system("cls");
    printf("==================================================\n");
    printf("Your Balance is %d taka ",data[id].balance);
    printf("\n");
    printf("1. Menu\n");
    printf("2. Exit\n");
    int ch;
    printf(">> ");
    scanf("%d", &ch);
    if(ch == 1){
        menu(data, size ,id);
    }
    else{
        exit(0);
    }

}
void cashOut(struct userData data[], int size, int id){
    system("cls");
    printf("==================================================\n");
    int AmN, amnt, pin;
    printf("Enter Agent Mobile Number:\n");
    printf(">> ");
    scanf("%d", &AmN);
    printf("Enter Amount:\n");
    printf(">> ");
    scanf("%d", &amnt);

    if(amnt <= data[id].balance){
        printf("Enter Pin:\n");
        printf(">> ");
        scanf("%d", &pin);
        if(pin == data[id].pass){
            printf("Csah out Successfully.");
        }
        else{
            printf("Transation failed. Please try with correct pin");
            printf("\n");
            printf("1. Menu\n");
            printf("2. Exit\n");
            int ch;
            scanf("%d", &ch);
            if(ch == 1){
                menu(data, size ,id);
            }
            else{
                exit(0);
            }    
        }
    }
    else{
        printf("Insufficient Ammount\n");
        printf("\n");
        printf("1. Menu\n");
        printf("2. Exit\n");
        int ch;
        printf(">> ");
        scanf("%d", &ch);
        if(ch == 1){
           menu(data, size ,id);
        }
        else{
           exit(0);
        }    
    }    

    data[id].balance = data[id].balance - amnt;
    FILE *temp;
    temp = fopen("Data.txt", "w");
    for (int i = 0; i < 10; i++){
        fprintf(temp, "%d %d %d\n", data[i].mobNum, data[i].pass, data[i].balance );
    }
    fclose(temp);
    //system("cls");
    printf("\n");
    printf("1. Menu\n");
    printf("2. Exit\n");
    int ch;
    printf(">> ");
    scanf("%d", &ch);
    if(ch == 1){
        menu(data, size ,id);
    }
    else{
        exit(0);
    }    
}
void pay(struct userData data[], int size, int id){
    system("cls");
    printf("==================================================\n");
    int MmN, amnt, pin;
    printf("Enter Merchant Mobile Number:\n");
    printf(">> ");
    scanf("%d", &MmN);
    printf("Enter Amount:\n");
    printf(">> ");
    scanf("%d", &amnt);
    if(amnt <= data[id].balance){
        printf("Enter Pin:\n");
        printf(">> ");
        scanf("%d", &pin);
            if(pin == data[id].pass){
                printf("Transation Succesfull.");
            }
            else{
                printf("Transation failed. Please try with correct pin");
                printf("\n");
                printf("1. Menu\n");
                printf("2. Exit\n");
                int ch;
                printf(">> ");
                scanf("%d", &ch);
                if(ch == 1){
                    menu(data, size ,id);
                }
                else{
                    exit(0);
                }          
            }
    }
    else{
        printf("Insufficient Ammount\n");
        printf("\n");
        printf("1. Menu\n");
        printf("2. Exit\n");
        int ch;
        printf(">> ");
        scanf("%d", &ch);
        if(ch == 1){
            menu(data, size ,id);
        }
        else{
            exit(0);
        }  
    }
    data[id].balance = data[id].balance - amnt;
    FILE *temp;
    temp = fopen("Data.txt", "w");
    for (int i = 0; i < 10; i++){
        fprintf(temp, "%d %d %d\n", data[i].mobNum, data[i].pass, data[i].balance );
    }
    fclose(temp);
    //system("cls");
    printf("\n");
    printf("1. Menu\n");
    printf("2. Exit\n");
    int ch;
    printf(">> ");
    scanf("%d", &ch);
    if(ch == 1){
        menu(data, size ,id);
    }
    else{
        exit(0);
    }
}

void mobRecharge(struct userData data[], int size, int id){
    system("cls");
    printf("==================================================\n");
    int oCh, mN, amnt, pin;
    printf("Choose Operator:\n1.Grameen Phone\n2.Banglalink\n3.Robi\n4.Airtel\n5.Teletalk\n");
    printf(">> ");
    scanf("%d", &oCh);
    system("cls");
    printf("Enter Mobile Number:\n");
    printf(">> ");
    scanf("%d", &mN);
    printf("Enter Amount:\n");
    printf(">> ");
    scanf("%d", &amnt);
    if(amnt <= data[id].balance){
        printf("Enter Pin:\n");
        printf(">> ");
        scanf("%d", &pin);
            if(pin == data[id].pass){
                printf("Transation Succesfull.");
            }
            else{
                printf("Transation failed. Please try with correct pin");
                printf("\n");
                printf("1. Menu\n");
                printf("2. Exit\n");
                int ch;
                printf(">> ");
                scanf("%d", &ch);
                if(ch == 1){
                    menu(data, size ,id);
                }
                else{
                    exit(0);
                }  
            }
    }
    else{
        printf("Insufficient Ammount\n");
        printf("\n");
        printf("1. Menu\n");
        printf("2. Exit\n");
        int ch;
        printf(">> ");
        scanf("%d", &ch);
        if(ch == 1){
            menu(data, size ,id);
        }
        else{
            exit(0);
        }  
    }
    data[id].balance = data[id].balance - amnt;
    FILE *temp;
    temp = fopen("Data.txt", "w");
    for (int i = 0; i < 10; i++){
        fprintf(temp, "%d %d %d\n", data[i].mobNum, data[i].pass, data[i].balance );
    }
    fclose(temp);
    printf("\n");
    printf("1. Menu\n");
    printf("2. Exit\n");
    int ch;
    printf(">> ");
    scanf("%d", &ch);
    if(ch == 1){
        menu(data, size ,id);
    }
    else{
        exit(0);
    }        
}

void sendMoney(struct userData data[], int size, int id){
    system("cls");
    printf("==================================================\n");
    int rMb, flag =0, amnt, pin, rid;
    //printf("%d", data[5].mobNum);
    printf("Mobile Number :\n");
    printf(">> ");
    scanf("%d", &rMb);

    for (int i = 0; i < 10; i++){
        if(rMb == data[i].mobNum){
            rid = i;
            flag++;
        }
    }
    if(flag > 0){
        printf("Enter ammount(Taka):\n");
        printf(">> ");
        scanf("%d", &amnt);
        if(amnt <= data[id].balance){
            printf("Enter Pin:\n");
            printf(">> ");
            scanf("%d", &pin);
            if(pin == data[id].pass){
                printf("Transation Succesfull.");
            }
            else{
                printf("Transation failed. Please try with correct pin");
            }
            }
            else{
                printf("Invalid Ammount");
            }
        }
    else{
        printf("User Not Found");
        printf("\n");
        printf("1. Menu\n");
        printf("2. Exit\n");
        int ch;
        printf(">> ");
        scanf("%d", &ch);
        if(ch == 1){
            menu(data, size ,id);
        }
        else{
            exit(0);
        }   
    }
    data[id].balance = data[id].balance - amnt;
    data[rid].balance = data[rid].balance + amnt;
    FILE *temp;
    temp = fopen("Data.txt", "w");
    for (int i = 0; i < 10; i++){
        fprintf(temp, "%d %d %d\n", data[i].mobNum, data[i].pass, data[i].balance );
    }
    fclose(temp);

    printf("\n");
    printf("1. Menu\n");
    printf("2. Exit\n");
    int ch;
    printf(">> ");
    scanf("%d", &ch);
    if(ch == 1){
        menu(data, size ,id);
    }
    else{
        exit(0);
    }
}


int menu(struct userData data[], int size, int id){
    //int id = id;
    system("cls");
    //printf("%d\n", id+1);
    int choice=0;
    printf("==================================================\n");
    printf("1. Send Money\n");
    printf("2. Mobile Recharge\n");
    printf("3. Payments\n");
    printf("4. Cash Out\n");
    printf("5. Check Balance\n");
    printf("6. Reset Pin\n");
    printf("0. Exit\n\n");
    printf("--------------------------------------------------\n");
    printf(">> ");
    scanf("%d", &choice);
    do{
        if(choice ==1){
            sendMoney(data, size, id);
        }
        if(choice ==2){
            mobRecharge(data, size, id);
        }
        if(choice ==3){
            pay(data, size, id);
        }
        if(choice ==4){
            cashOut(data, size, id);            
        }
        if(choice ==5){
            checkBalance(data, size, id);            
        }
        if(choice ==6){
            resetPin(data, size, id);            
        }
        if(choice ==0){
            printf("Exit Successfully");
            //break;
            exit(0);
        }
        printf(">> ");
        scanf("%d", &choice);
    } while (choice != 0);
    
}

void login(struct userData data[], int size){
    int mn, pin, i=0, id =0, flag =0;
    printf("\t\t================== Welcome to Akash Mobile Banking System ==================\t\t\n");
    printf("Enter Your Mobile Number :\n");
    printf(">> ");
    scanf("%d", &mn);
    for ( i = 0; i < 10; i++){
        if(mn == data[i].mobNum){
            id = i;
            flag++;
        }
        
    }
    if(flag > 0){
        printf("Enter Your PIN(4 Digites) :\n");
        printf(">> ");
        scanf("%d", &pin);
    }
    if(flag==0){
        system("cls");
        printf("User Not Found.\n");
        login(data, 100);

    }
    if(pin == data[id].pass){
        menu(data, size, id);
    }
    else{
        system("cls");
        printf("Wrong Pin.\n");
        login(data, 100);
    }
}


int main(){
    int i=0, j=0;
    FILE *in;
    struct userData data[100];
    int arr[100][3];

    in = fopen("Data.txt", "r");
    for(i=0; i<10; i++){
        for(j=0; j<3; j++){
            fflush(stdin);
            fscanf(in, "%d", &arr[i][j]);
            fflush(stdin);
        }
    }
    for(i=0; i<10; i++){
        data[i].mobNum = arr[i][0];
        data[i].pass = arr[i][1];
        data[i].balance = arr[i][2];
    }
    //User Guide
    // printf("\n\nMobile number   Pin  \t\tBalance\n");
    // for(i=0; i<10; i++){
    //     printf("%d \t\t%d \t\t %d\t\n", data[i].mobNum, data[i].pass, data[i].balance);
    // }
    login(data,100);
}