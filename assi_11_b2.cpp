// The ticket booking system of Cinemax theatre has to be implemented using C++ program. There are 15
// rows and 10 seats in each row. Doubly linked lists have to be maintained to keep track of free seats in rows.
// Assume some random booking to start with. Use an array to store pointers (Head pointer) to each row. On
// demand
// a. The list of available
// b. seats is to be displayed
// c. The seats are to be booked
// d. The booking can be cancelled

#include <iostream>
using namespace std;

class node
{

public:
    int status;
    int seatNo;
    node *prev;
    node *next;
    node(int No, int sts)
    {
        status = sts;
        seatNo = No;
        next = NULL;
        prev = NULL;
    }
};

class show
{
public:
    node *head, *temp, *tail;
    show()
    {
        head = NULL;
    }
    void create();
    void book();
    void cancel();
    void display();
    void chkAvail();
};

void show::create()
{
    int i = 1;
    temp = new node(1, 0);
    tail = head = temp;
    for (int i = 2; i <= 150; i++)
    {
        node *p;
        p = new node(i, 0);
        tail->next = p;
        p->prev = tail;
        tail = p;
        tail->next = head;
        head->prev = tail;
    }
}
void show::display()
{
    {
        int r = 1;
        node *temp;
        temp = head;
        int count = 0;
        cout << "Check Below Seats" << endl;
        while (temp->next != head)
        {
            if (temp->seatNo / 10 == 0)
                cout << "00" << temp->seatNo << " :";
            else if (temp->seatNo / 100 == 0)
                cout << "0" << temp->seatNo << " :";
            else
                cout << "" << temp->seatNo << " :";
            if (temp->status == 0)
                cout << "| | ";
            else
                cout << "|B| ";
            count++;
            if (count % 10 == 0)
            {
                cout << endl;
                r++;
            }
            temp = temp->next;
        }
        cout << temp->seatNo << " :";
        if (temp->status == 0)
            cout << "| | ";
        else
            cout << "|B| ";
    }
}

void show::book()
{
    int x;
    string y;
label:
    cout << "\n\n\nEnter seat number to be booked\n";
    cin >> x;
    if (x < 1 && x > 150)
    {
        cout << "Enter correct seat number to book (1-70)\n";
        goto label;
    }
    node *temp;
    temp = new node(200, 0);
    temp = head;
    while (temp->seatNo != x)
    {
        temp = temp->next;
    }
    if (temp->status == 1)
        cout << "Seat already booked!\n";
    else
    {
        temp->status = 1;
        cout << "Seat " << x << " booked!\n";
    }
}

void show::cancel()
{
    int x;
    string y;
label1:
    cout << "Enter seat number to cancel booking\n";
    cin >> x;
    if (x < 1 && x > 150)
    {
        cout << "Enter correct seat number to cancel (1-150)\n";
        goto label1;
    }
    node *temp;
    temp = new node(200, 1);
    temp = head;
    while (temp->seatNo != x)
    {
        temp = temp->next;
    }
    if (temp->status == 0)
    {
        cout << "Seat not booked yet!!\n";
    }
    else
    {
        if (temp->seatNo == x)
        {
            temp->status = 0;
            cout << "Seat Cancelled!\n";
        }
        else
            cout << "Wrong User ID !!! Seat cannot be cancelled!!!\n";
    }
}

void show::chkAvail()
{
    int r = 1;
    node *temp;
    temp = head;
    int count = 0;
    cout << "\n\n\n";
    cout << "Check out below seats" << endl;
    while (temp->next != head)
    {
        {
            if (temp->seatNo / 10 == 0)
                cout << "00" << temp->seatNo << " :";
            else if (temp->seatNo / 100 == 0)
                cout << "0" << temp->seatNo << " :";
            else
                cout << "" << temp->seatNo << " :";
            if (temp->status == 0)
                cout << "| | ";
            else if (temp->status == 1)
                cout << "|B|" <<" ";
            count++;
            if (count % 10 == 0)
            {
                cout << endl;
            }
        }
        temp = temp->next;
    }
    if (temp->status == 0)
    {
        cout << temp->seatNo << " :";
        if (temp->status == 0)
            cout << "| | ";
    }
}

int main()
{
    show obj;
    obj.create();
    int ch;
    char c = 'y';
    while (c == 'y')
    {
        obj.display();
        cout << "\nMOVIE THEATRE\n";
        cout << "***************\n";
        cout << "\nEnter Choice\nEnter 1 to check current SeatStatus\nEnter 2 to Book Seat \nEnter 3 to check AvailableSeat\nEnter 4 to CancelSeat\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.display();
            break;
        case 2:
            obj.book();
            break;
        case 3:
            obj.chkAvail();
            break;
        case 4:
            obj.cancel();
            break;
        default:
            cout << "Wrong choice input\n";
        }
        cout << "\nDo you want to perform any other operation :(y/n)\n";
        cin >> c;
    }
    return 0;
}



// #include <iostream>
// using namespace std;

// struct node{
//     string status;
//     node *next;
//     node *prev;
// };

// class cinema{
//     public:
//     node *head[15], *tail[15];

//     cinema(){

//         for(int i=1; i<=15; i++){
//             head[i]=NULL;
//             tail[i]=NULL;
//             for(int j=1; j<=10; j++){
//             node *cur_node;
//             if(head[i] == NULL){
//                 node *newnode = new node();
//                 newnode->status = "a";
//                 newnode->next = NULL;
//                 newnode ->prev = NULL;
//                 head[i]=newnode;
//                 cur_node=newnode;
//             }
//             else{
//                 node *newnode = new node();
//                 newnode->status = "a";
//                 newnode->prev=cur_node;
//                 cur_node->next=newnode;
//                 cur_node=newnode;
//             }
//             }
//         }
//     }

//     void display(){
//         for(int i=1;i<=15;i++){
//             for(node *crt=head[i];crt!=NULL;crt = crt->next){
//                 cout<<crt->status<<"  ";
//             }
//             cout<<endl;
//         }
//     }

//     void book(){
//         cout<<"Enter the row number and seat number that you want to book";
//         int x;
//         cin>>x;
//             for(node *crt=head[x-1];crt!=NULL;crt = crt->next){
//                 if(crt->status == "a")
//                 crt->status = "B";
//                 else
//                 cout<<"already booked"<<endl;
//             }

//     }

// };

// int main()
// {
//     cinema obj;
//     obj.display();
//     obj.book();
//     obj.display();

//     return 0;
// }
