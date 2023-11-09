#include <iostream>
using namespace std;

void display_menu(){
         cout<<"---------------------------------\n";
         cout<<"metro train ticket booking system\n";
         cout<<"1. Book ticket\n";
         cout<<"2. Cancel ticket\n";
         cout<<"3. View ticket\n";
         cout<<"4. Exit\n";
         cout<<"---------------------------------\n";
         }

class ticketbooking{
    protected:
    string Origin, Destination;
    int numTickets, fare,choice, choice1, choice2, totalFare,ticketType;
    
    public: 
    void booking_details(){
    
    cout<<"enter your choice:\n";
    cin>>choice;

    switch(choice){
    case 1:
    cout<<"============================\n";
    cout<<"Select your origin point: \n";
    cout<<"1. Airport\n";
    cout<<"2. Nandanam\n";
    cout<<"3. Washermanpet\n";
    cout<<"============================\n";
    cout<<"Enter your origin number: \n";
    cin>>choice1;
    switch(choice1){
    case 1:
    Origin="Airport";
    break;
    case 2:
    Origin="Nandanam";
    break;
    case 3:
    Origin="Washermanpet";
    break;
    default:
    cout<<"invalid choice";
    break;
    }
    cout<<"============================\n";
    cout<<"Select your destination point: \n";
    cout<<"1. Airport\n";
    cout<<"2. Nandanam\n";
    cout<<"3. Washermanpet\n";
    cout<<"============================\n";
    cout<<"Enter your destination number: \n";
    cin>>choice2;
    switch(choice2){
    case 1:
    Destination="Airport";
    break;
    case 2:
    Destination="Nandanam";
    break;
    case 3:
    Destination="Washermanpet";
    break;
    default:
    cout<<"invalid choice";
    break;
    }
    if(Origin==Destination){
        cout<<"invalid orgin or destination";
    }

     cout << "Enter the ticket type (1. single/2. return): ";
     cin >> ticketType;
    switch(ticketType) {
         case 1:
         ticketType = 1;
         break;
         case 2:
         ticketType = 2;
         break;
    }
     cout << "Enter the number of tickets: ";
     cin >> numTickets;
    }
    }
    int calculateFare(string origin, string destination) {
    if (choice1 == 1 && choice2 == 3) {
        fare= 20;
    } else if (choice1 == 2 && choice2 == 3) {
        fare= 10;
    } 
    else if (choice1 == 2 && choice2 == 1) {
        fare= 10;
    } else if (choice1 == 3 && choice2 == 2) {
        fare= 10;
    } else if (choice1 == 3 && choice2 == 1) {
        fare= 20;
    } else {
        fare= -1;
    }
     if (fare == -1) {
                        cout << "Invalid origin or destination point.\n";
                    } else {
                        totalFare = (ticketType == 2) ? fare * numTickets * 2 : fare * numTickets;
                        cout << "Total fare is " << totalFare << "Rs. Please make the payment.\n";
                        
                    }
}
    };

class payment{
        protected:
            int choice3,bank,bank1,card,cvv,user_id;
            string date;
            char password[30];
        public:
            void payment_details()
           {
                
                cout << "\nMode of payment\n";
                cout << "\n1.Debit Card(1) \n2.Credit Card(2) \n3.Net Banking(3)";
                cout << "\nEnter your choice :";
                cin >> choice3;
                switch(choice3)
                {
                case 1:
                    cout << "Enter card number:";
                    cin >> card;
                    cout << "Enter expiry date:";
                    cin >> date;
                    cout << "Enter CVV number:";
                    cin >> cvv;
                    cout << "Transaction Successful\n";
                    break;
                case 2:
                    cout << "Enter card number:";
                    cin >> card;
                    cout << "Enter expiry date:";
                    cin >> date;
                    cout << "Transaction Successful\n";
                    break;
                case 3:
                    cout << "\nBanks Available:\n----------- \n1.State bank of India(1) \n2.ICICI(2) \n3.Axis Bank(3) \n4.HDFC(4)";
                    cout << "\nSelect your bank:";
                    cin >> bank;
                    cout << "\nYou have selected:" << bank;
                    cout << "\nEnter user id:";
                    cin >> user_id;
                    cout << "Enter password:";
                    cin >> password;
                    cout<<"-----------------------------";
                    cout << "\nTransaction Successful\n";
                    cout<<"-----------------------------";
                    break;
                default:
                    cout << "\nWrong input entered.\nTry again\n";
                    return payment_details();
                }
            }
        };

         
int main()
{
    string origin, destination;
    int numTickets, fare, choice,totalFare ,ticketType;
    bool ticketBooked = false;
    ticketbooking x;
    payment p;
    
    while(true){
    display_menu();
    
    x.booking_details();
   
                    
                    x.calculateFare(origin, destination);
                    ticketBooked = true;
                   

                p.payment_details();
                break;
                
                switch(choice) {
                
                case 1: // Cancel Ticket
                if (ticketBooked) {
                    cout << "Your ticket has been cancelled. The amount " << totalFare << "Rs has been refunded.\n";
                    ticketBooked = false;
                } else {
                    cout << "No ticket has been booked yet.\n";
                }
                break;
                
               case 2: // View Ticket
                if (ticketBooked) {
                    cout << "\n========== Ticket Details ==========\n";
                    cout << "Origin: " << origin << "\n";
                    cout << "Destination: " << destination << "\n";
                    cout << "Ticket Type: ";
                        if(ticketType=1)
                        {
                            cout<<"single";
                            
                        }
                        else{
                        cout<<"return";
                        }
                    cout << "Number of Tickets: " << numTickets << "\n";
                    cout << "Total Fare: " << totalFare << "Rs\n";
                } else {
                    cout << "No ticket has been booked yet.\n";
                }
                break;
    }
            
            
        }
}