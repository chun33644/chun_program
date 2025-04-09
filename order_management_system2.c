

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



typedef struct _Order {
    char customerName[50];
    char orderID[30];
    char productName[50];
    int quantity;
    float price;
    char action[10]; //addnew = created, updateOrder = updated, deleteOrder = deleted
    time_t timestamp;
    struct _Order *next;
} Order;




static Order *orders = {0};
static Order *history = {0};


int addOrder (const char *customerName, const char *orderID, const char *productName, int quantity, float price ) {
   
    // (true)
    if (!orders) {

        // orders -> NULL

        orders = malloc(sizeof(Order));
        memset(orders, 0, sizeof(Order));

        strcpy(orders->orderID, orderID);
        strcpy(orders->customerName, customerName);
        strcpy(orders->productName, productName);
        orders->quantity = quantity;
        orders->price = price;
        strcpy(orders->action, "created");
        orders->timestamp = time(NULL);

    } else {
        //         curr 
        //-----------   
        //          |
        // orders -> order1.next -> NULL
        // orders -> order1.next -> order2.next -> NULL
        // orders -> order1.next -> order2.next -> order3.next -> NULL
        // orders -> order1.next -> order2.next -> order3.next -> order4.next -> NULL

        Order *curr = orders;

        // next is a pointer , point to Order
        //    (!NULL)--> curr = curr->next
        //    (NULL )--> jump out
        while (curr->next) {
            curr = curr->next;
        }

        curr->next = malloc(sizeof(Order));
        memset(curr->next, 0, sizeof(Order));

        strcpy(curr->next->orderID, orderID);
        strcpy(curr->next->customerName, customerName);
        strcpy(curr->next->productName, productName);
        curr->next->quantity = quantity;
        curr->next->price = price;
        strcpy(curr->next->action, "created");
        curr->next->timestamp = time(NULL);
    }

    return 0;

}

/*

Order *getOrderByID (char *orderID) {
   
   
    for (int idex = 0; idex < orderCount; idex++) {
        printf("check orderID: %s with %s\n", orders[idex].orderID, orderID);
        if (strcmp(orders[idex].orderID, orderID) == 0) {
            return &orders[idex];
        }
    }
    return NULL;
}

*/


int updateOrder (char *orderID, int newQuantity, float newPrice) {

    Order *curr = orders;


    while (curr) {

        if (strcmp(curr->orderID, orderID) == 0) {
        
            curr->quantity = newQuantity;
            curr->price = newPrice;
            strcpy(curr->action, "updated");
            curr->timestamp = time(NULL);
            return 0;

        }

        curr = curr->next;
        
    }

    return -1;

}


int deleteOrder (char *orderID) {

    Order *curr = orders;

    while (curr != NULL) {
        

        if (strcmp(curr->next->orderID, orderID) == 0) {
           
            Order *newHistory = malloc(sizeof(Order));
            memset(newHistory, 0, sizeof(Order));  
            if (!newHistory) {
                return -1;
            }
                
            strcpy(newHistory->orderID, curr->next->orderID);
            strcpy(newHistory->customerName, curr->next->customerName);
            strcpy(newHistory->productName, curr->next->productName);
            newHistory->quantity = curr->next->quantity;
            newHistory->price = curr->next->price;
            strcpy(newHistory->action, "deleted");
            newHistory->timestamp = time(NULL);

            newHistory->next = history;
            history = newHistory;
            
            Order *temp = curr->next;
            curr->next = temp->next;
            
            free(temp);

            return 0;

        }

    curr = curr->next;

    }

    return -1;
}


void displayCurrentOrder (void) {
    
    Order *curr = orders;

    if (!curr) {
        printf("No orders!\n");
        return;
    }

    while (curr != NULL) {

        printf("Order ID: %s\n", curr->orderID);
        printf("Customer: %s\n", curr->customerName);
        printf("Product: %s\n", curr->productName);
        printf("Quantity: %d\n", curr->quantity);
        printf("Price: %.2f\n", curr->price);
        printf("Action: %s\n", curr->action);
        printf("Timestamp: %s\n", ctime(&curr->timestamp));
        printf("----------------------------------\n");

        curr = curr->next;
    }

}

void displayHistoryOrder (void) {
    
    Order *curr = history;

    if (!curr) {
        printf("No orders!\n");
        return;
    }

    while (curr != NULL) {

        printf("Order ID: %s\n", curr->orderID);
        printf("Customer: %s\n", curr->customerName);
        printf("Product: %s\n", curr->productName);
        printf("Quantity: %d\n", curr->quantity);
        printf("Price: %.2f\n", curr->price);
        printf("Action: %s\n", curr->action);
        printf("Timestamp: %s\n", ctime(&curr->timestamp));
        printf("----------------------------------\n");

        curr = curr->next;
    }

}

      


int freeOrders (void) {

    if (orders != NULL) {
        free(orders);
        orders = NULL;
        return 0;
    }else {
        return -1;
    }

}

int main (int argc, char *argv[]) {
    
    
    int add1 = addOrder("Chun","A","phone",1,20000.5);
    if (add1 == -1){
        printf("add Chun error!\n");
    }
    
    int add2 = addOrder("Joe","B","pad",2,66666.5);
    if (add2 == -1){
        printf("add Joe error!\n");
    }
    
    int add3 = addOrder("Sun","C","power",12,1500);
    if (add3 == -1){
        printf("add Sun error!\n");
    }
    displayCurrentOrder();
    
    
    printf("--------------chack updata(C):%d --------------\n", updateOrder("C",12,5555.6));
    displayCurrentOrder();

    
    printf("-------------check delete(B):%d---------------\n", deleteOrder("B"));
    displayCurrentOrder();
   

    printf("-------------show history order---------------\n");
    displayHistoryOrder();

    printf("%p\n",orders);
    printf("free result: %d\n",freeOrders());
    printf("%p\n",orders);
}

    

