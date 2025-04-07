

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct {
    char customerName[50];
    char orderID[30];
    char productName[50];
    int quantity;
    float price;
} Order;


typedef struct {
    Order order;
    char action[10]; //addnew = created, updateOrder = updated, deleteOrder = deleted
    time_t timestamp;
} OrderHistory;  



Order *orders = {0};
OrderHistory *orderHistory = {0};
int orderCount = 0;
int historyCount = 0;


void logOrderHistory (Order *order, const char *action) {
    

    
    orderHistory = realloc(orderHistory, (historyCount + 1) * sizeof(OrderHistory));
    if (orderHistory == NULL) {
        return;
    }

    orderHistory[historyCount].order = *order;   //copy orderlist to historylist
    strcpy(orderHistory[historyCount].action, action);
    orderHistory[historyCount].timestamp = time(NULL);  //record current time

    historyCount ++;

}


int addOrder (const char *customerName, const char *orderID, const char *productName, int quantity, float price ) {
   
    
    orderCount ++;
    Order *temp = realloc(orders, orderCount * sizeof(Order));
    if (temp == NULL) {
        return -1;
    }
    
    orders = temp;

/*  
    orderCount ++;  
    if (orders == NULL) {
        orders = malloc(sizeof(Order));
        if (orders == NULL) {
        return -1;
        }
    }else {
        orders = realloc(orders, orderCount * sizeof(Order));
        if (orders == NULL) {
        return -1;
        }
    }
*/

        
    Order *newOrder = &orders[orderCount - 1];
    strcpy(newOrder->orderID, orderID);
    strcpy(newOrder->customerName, customerName);
    strcpy(newOrder->productName, productName);
    newOrder->quantity = quantity;
    newOrder->price = price;

    logOrderHistory(newOrder, "created");

    return 0;

}


Order *getOrderByID (char *orderID) {
   
   
    for (int idex = 0; idex < orderCount; idex++) {
        printf("check orderID: %s with %s\n", orders[idex].orderID, orderID);
        if (strcmp(orders[idex].orderID, orderID) == 0) {
            return &orders[idex];
        }
    }
    return NULL;
}


int updateOrder (char *orderID, int newQuantity, float newPrice) {

    Order *order = getOrderByID(orderID);
    if (order == NULL) {
        return -1;
    }

    order->quantity = newQuantity;
    order->price = newPrice;

    logOrderHistory(order, "updated");

    return 0;

}

    //[0] [chun] [A] [phone] [1] [2000]
    //[1] [Joe]  [B] [pad]   [2] [1000]   (delete)
    //[2] [Sun]  [C] [power] [12][1500]   (forward)
int deleteOrder (char *orderID) {

   
    Order *order = getOrderByID(orderID);
    if (order == NULL) {
        return -1;
    }
    
    logOrderHistory(order, "deleted"); 
    
    //find index of the order[]
    int index = order - orders;   //index = order[1] - orders[0] = 1
    
    //move the remaining elements forward      ( 3 - 1 - 1 = 1 [ramaining elements])
    memmove(&orders[index], &orders[index + 1],(orderCount - index - 1) * sizeof(Order));
    orderCount --;    

    //reallocate memory
    orders = realloc(orders, orderCount * sizeof(Order));

    

    return 0;

}

void displayOrderList (void) {
    
    if (orderCount == 0) {
        printf("No orders!\n");
        return;
    }

    for (int idex = 0; idex < orderCount; idex++) {
        printf("Order ID: %s\n", orders[idex].orderID);
        printf("Customer: %s\n", orders[idex].customerName);
        printf("Product: %s\n", orders[idex].productName);
        printf("Quantity: %d\n", orders[idex].quantity);
        printf("Price: %.2f\n", orders[idex].price);
        printf("----------------------------------\n");
    }

}

void displayOrderHistory (void) {

    if (historyCount == 0) {
        printf("No history order!\n");
        return;
    }

    for (int idex = 0; idex < historyCount; idex++) {
        printf("Order ID: %s\n", orderHistory[idex].order.orderID);
        printf("Customer: %s\n", orderHistory[idex].order.customerName);
        printf("Product: %s\n", orderHistory[idex].order.productName);
        printf("Quantity: %d\n", orderHistory[idex].order.quantity);
        printf("Price: %.2f\n", orderHistory[idex].order.price);
        printf("Action : %s\n", orderHistory[idex].action);
        printf("Timestamp: %s\n",ctime(&orderHistory[idex].timestamp)); //format
        printf("----------------------------------\n");
    }
}
       


int freeOrders (void) {

    if (orders != NULL) {
        free(orders);
        orders = NULL;
        orderCount = 0;
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
/*
    Order *odr = getOrderByID("C");
    printf("get order address: %p\n", odr);
*/
    displayOrderList();
    printf("--------------chack updata(C):%d --------------\n", updateOrder("C",12,5555.6));
    displayOrderList();

    printf("-------------check delete(B):%d---------------\n", deleteOrder("B"));
    displayOrderList();
   
    printf("-------------show history order---------------\n");
    displayOrderHistory();

    printf("%p\n",orders);
    printf("free result: %d\n",freeOrders());
    printf("%p\n",orders);
}

    

