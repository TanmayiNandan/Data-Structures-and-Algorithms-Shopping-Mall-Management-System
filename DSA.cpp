#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<conio.h>

int pdate;
int pmonth;
int pyear;


using namespace std;

struct date
{
    int dd;
    int mm;
    int yy;
};
struct product
{
    char name[20];
    int code;
    float price;
    int quantity;
    float totalprice;
    product *next=NULL;
};

class product_list
{
    product *head, *tail;
    public:
        float billprice=0;
        product_list()
        {
            head=NULL;
            tail=NULL;
        }

        void buy_product(int code)
        {

            product *product1=new product;
            if(head==NULL)
            {
                head=product1;
                tail=product1;
            }
            else
            {
                tail->next=product1;
                tail=product1;
            }
            product1->code=code;
            cout<<"                                                 "<<"ENTER THE PRODUCT NAME: ";
            cin>>product1->name;
            cout<<"                                                 "<<"ENTER THE PRICE OF PRODUCT: ";
            cin>>product1->price;
            cout<<"                                                 "<<"QUANTITY OF PRODUCT :";
            cin>>product1->quantity;
            product1->totalprice=product1->quantity*product1->price;

        }



        void modify_item()
        {
            int x,codefound,num;
            cout<<endl<<"                                                 "<<"ENTER THE CODE OF THE PRODUCT TO BE MODIFIED: ";
            cin>>x;
            product *index=head;
            while(index!=NULL)
            {
                   if(index->code==x)
                {
                    codefound=1;
                    cout<<endl<<"                                                 "<<"Enter the modified quantity: ";
                    cin>>num;
                    index->quantity=num;
                    index->totalprice=index->price*index->quantity;
                    cout<<endl<<"                                                 "<<"**** QUANTITY MODIFIED****"<<endl;
                    getch();
                }
                index=index->next;
            }

            if(codefound!=1)
            {
                cout<<endl<<"                                                 "<<"YOU HAVE ENTERED WRONG PRODUCT CODE"<<endl;
                getch();
            }
        }
        void delete_item()
        {
            int x,itemdelete;
            cout<<endl<<"                                                 "<<"ENTER THE CODE OF THE PRODUCT TO BE DELETED: ";
            cin>>x;
            product *index=head;
            product *index2;
            while(index!=NULL)
            {
                if(index->code==x)
                {
                    itemdelete=1;
                    if(index==head)
                    {
                        index->next=head;
                    }
                    else if(index->next==NULL)
                    {
                        index2->next=NULL;
                    }
                    else
                    {
                        *index2->next=*index->next;
                    }
                    cout<<endl<<"                                                     "<<"*** PRODUCT DELETED ***"<<endl;
                    getch();
                }
                index2=index;
                index=index->next;
            }
            if(itemdelete!=1)
            {
                cout<<endl<<"                                                 "<<"!!! YOU HAVE ENTERED THE WRONG CODE !!!"<<endl;
                getch();
            }

        }

        int display()
        {
            int x,temp;
            product *index=head;
            if(head==NULL)
            {
                temp=1;
                cout<<"                                                 "<<"!!!! THERE ARE NO PRODUCTS BOUGHT !!!!"<<endl;
            }
            else
            {
                temp=0;
                cout<<endl<<"                                                 "<<"YOUR PRODUCT LIST: "<<endl;
                while(index!=NULL)
                {
                    cout<<endl<<"                                                 "<<"NAME: "<<"\t"<<index->name<<endl;
                    cout<<"                                                 "<<"CODE: "<<"\t"<<index->code<<endl;
                    cout<<"                                                 "<<"PRICE: "<<"\t"<<index->price<<endl;
                    cout<<"                                                 "<<"QUANTITY: "<<"\t"<<index->quantity<<endl;
                    index=index->next;
                }
            }
            return temp;

        }

        int cal_bill()
        {
        	float finalprice;
        	product *index=head;
    		while(index!=NULL)
            {
               	finalprice+=index->totalprice;
            	index=index->next;
        	}
			return finalprice;
		}

        void billdetails()
        {
    	std::ofstream text;
        text.open("Bill.txt",std::ofstream::out | std::ofstream::app);
    	product *index=head;
    	while(index!=NULL)
            {
               	text<<index->name;
	            text<<"            		"<<index->price<<"\t\t"<<index->quantity<<"\t\t"<<index->price*index->quantity<<endl;
            	index=index->next;
        	}
			text.close();
		}
};



struct member
{
    char name[30];
    char name2[30];
    int ID;
    date joindate;
    long long int ph;
    char address[50];
    int no_years_member;
    float discount;
    int per_discount;
    date present_date;
    product_list items;
    member *next=NULL;

};
class member_list
{
    member *head, *tail;
public:
    int idfound;
    member_list()
    {
        head=NULL;
        tail=NULL;
    }

    void search_ID(int id)
    {
        member *index=head;
        while(index!=NULL)
        {
            if(index->ID==id)
            {
                cout<<"                                                 "<<"!!! THE ID ALREADY EXIST !!!"<<endl;
                cout<<"                                                 "<<"ENTER A DIFFERENT ID: ";
                idfound=1;
            }
            index=index->next;
        }
    }

    void add_member()
    {
        int ch;
        int num_days=0,num_years=0,discount_per=0;
        member *member1=new member;
        if(head==NULL)
        {
            head=member1;
            tail=member1;
        }
        else
        {
            tail->next=member1;
            tail=member1;
        }
        cout<<endl;
        cout<<endl;
        cout<<"                                                 "<<"ENTER THE MEMBER NAME: ";
        getchar();
        cin>>member1->name;
        cin>>member1->name2;
        cout<<"                                                 "<<"ENTER MEMBER ID: ";
        cin>>ch;
        search_ID(ch);
        if(idfound==1)
        {
            cin>>ch;
        }
        member1->ID=ch;
        cout<<"                                                 "<<"ENTER JOINING DATE: ";
        cout<<"Enter day: ";
        cin>>member1->joindate.dd;
        cout<<"                                                                     "<<"Enter month: ";
        cin>>member1->joindate.mm;
        cout<<"                                                                     "<<"Enter year: ";
        cin>>member1->joindate.yy;
        cout<<"                                                 "<<"ENTER YOUR ADDRESS: ";
        getchar();
        gets(member1->address);
        cout<<"                                                 "<<"ENTER YOUR PHONE NUMBER: ";
        cin>>member1->ph;
        cout<<endl<<"                                                  "<<"****MEMBER DETAILS UPDATED****";
        getch();
        if(pmonth<member1->joindate.mm)
        {
            pmonth=pmonth+12;
            pyear=pyear-1;
        }
        if(pdate<member1->joindate.dd)
        {
            pdate=pdate+30;
            pmonth=pmonth-1;
        }
        num_days=(pdate-member1->joindate.dd)+(pmonth-member1->joindate.mm)*30+(pyear-member1->joindate.yy)*365;
        num_years=num_days/365 +1;
        member1->no_years_member=num_years;
        if(num_years>=1 && num_years<3)
        {
            discount_per=5;
        }
        else if(num_years>=3 && num_years<7 )
        {
            discount_per=8;
        }
        else if(num_years>=7 && num_years<12)
        {
            discount_per=15;
        }
        else if(num_years>=12 && num_years<20)
        {
            discount_per=20;
        }
        else if(num_years>=20)
        {
            discount_per=30;
        }

        member1->per_discount=discount_per;


    }


    void modify_memdetails()
    {
        int userid,x=0,ch;
        cout<<endl;
        member *index=head;
        cout<<endl<<"                                                 "<<"ENTER THE MEMBER ID WHOSE DETAILS NEEDS TO BE MODIFIED: ";
        cin>>userid;
        cout<<endl<<"                                                 "<<"ENTER->  1.> TO MODIFY ADDRESS"<<endl;
        cout<<"                                                 "<<"         2.> TO MODIFY PHONE NUMBER"<<endl;;
        cout<<endl<<"                                                 "<<"ENTER YOUR CHOICE: ";
        cin>>ch;
        while(index!=NULL)
        {
            if(index->ID==userid)
            {
                x=1;
                switch(ch)
                {
                    case(1):
                        {
                            cout<<endl;
                            cout<<endl<<"                                                 "<<"ENTER THE NEW ADDRESS: ";
                            cin>>index->address;
                            cout<<endl;
                            cout<<endl<<"                                           "<<"==== MEMBER DETAILS MODIFIED ====";
                            break;
                        }
                    case(2):
                        {
                            cout<<endl<<"                                                 "<<"ENTER NEW PHONE NUMBER: ";
                            cin>>index->ph;
                            cout<<endl;
                            cout<<endl<<"                                           "<<"==== MEMBER DETAILS MODIFIED ====";
                            break;
                        }
                    default :
                        {
                            cout<<"                                                 "<<"INVALID INPUT"<<endl;
                            break;
                        }
                }
            }
            getch();
            index=index->next;
        }
        if(x==0)
        {
            cout<<"                                                 "<<"THERE IS NO MEMBER WITH MEMBER ID"<<endl;
        }
    }

    int search_memdetails(int id)
    {
        int x=0;
        member *index=head;
        while(index!=NULL)
        {
            if(index->ID==id)
            {
                x=1;
                return index->per_discount;
            }
            index=index->next;
        }
        if(x==0)
        {
            cout<<"                                                 "<<"THERE IS NO MEMBER WITH MEMBER ID"<<endl;
            return 0;
        }
    }


    void delete_member()
        {
            int x,temp=0;
            cout<<endl<<"                                           "<<"ENTER THE ID OF THE MEMBER TO BE DELETED: ";
            cin>>x;
            member *index=head;
            member *index2;
            while(index!=NULL)
            {
                if(index->ID==x)
                {
                    temp=1;
                    if(index==head)
                    {
                        index->next=head;
                    }
                    else if(index->next==NULL)
                    {
                        index2->next=NULL;
                    }
                    else
                    {
                        *index2->next=*index->next;
                    }
                     cout<<endl;
                    cout<<endl<<"                                           "<<"==== SUCCESFULLY DELETED ====";
                    getch();
                }
                index2=index;
                index=index->next;
            }
            if(temp!=1)
            {
                cout<<endl<<"                                           "<<"!!!! THERE IS NO MEMBER WITH THE GIVEN ID !!!!";
                getch();
            }


        }

    int display()
    {
        int userid,retval1,x=0,y;
        member *index=head;
        if(head==NULL)
        {
            retval1=1;
            cout<<endl<<"                                              "<<"**** THERE IS NO MEMBER IN THE LIST ****"<<endl;
            getch();
        }
        else
        {
            retval1=0;
            cout<<endl<<"                                                 "<<"ENTER THE ID OF THE MEMBER WHOSE DETAILS ARE REQUIRED:: ";
            cin>>userid;
            while(index!=NULL)
            {
                if(index->ID==userid)
                {
                    x=1;
                    cout<<endl<<"                                             "<<"**** MEMBER DETAILS ****"<<endl;
                    cout<<endl<<"                                                 "<<"NAME:: "<<index->name<<" "<<index->name2<<endl;
                    cout<<"                                                 "<<"MEMBER ID:: "<<index->ID<<endl;
                    cout<<"                                                 "<<"DATE OF JOINING:: "<<index->joindate.dd<<"/"<<index->joindate.mm<<"/"<<index->joindate.yy<<"\t"<<endl;
                    cout<<"                                                 "<<"ADDRESS:: "<<index->address<<endl;
                    cout<<"                                                 "<<"PHONE NUMBER:: "<<index->ph<<endl;
                    getch();
                }
                index=index->next;
            }
               if(x==0)
            {
                cout<<endl<<"                                             "<<"**** THERE IS NO MEMBER WITH THIS ID ****"<<endl;
                getch();
            }
        }
        return retval1;
    }

    void billdata(int n)
    {
    	std::ofstream text;
        text.open("Bill.txt",std::ofstream::out | std::ofstream::app);
    	member *index=head;
    	while(index!=NULL)
            {
                if(index->ID==n)
                {
            		text<<"Name           : "<<index->name<<" "<<index->name2<<endl;
					text<<"Member ID      : "<<index->ID<<endl;
					text<<"Phone Number   : "<<index->ph<<endl;
					text<<"No. Of Years   : "<<index->no_years_member<<endl;
            	}
            	index=index->next;
        	}
	}
};



int main()
{
	std::ofstream text;
	text.open("Bill.txt",std::ofstream::out | std::ofstream::app);
    cout<<endl<<"                                     ======   DSA SHOPPING MALL  ====="<<endl;
    cout<<endl<<"                                                *** GOOD MORNING ***"<<endl;
    cout<<endl<<"                                                  "<<"ENTER TODAYS DATE:"<<endl;
    cout<<endl<<"                                                         "<<"DAY: ";
    cin>>pdate;
    cout<<"                                                         "<<"MONTH: ";
    cin>>pmonth;
    cout<<"                                                         "<<"YEAR: ";
    cin>>pyear;
    cout<<endl;
          cout<<"                                                         THANK YOU"<<endl;
    cout<<endl<<"                                           *********  HAVE A GREAT DAY  ********* ";
    getch();
    system("CLS");
    int code;
    member_list a;
    product_list p;
    int choice,choice1,choice2;
    text<<"				DSA SHOPPING MALL"<<endl<<endl;
    text<<"DATE: "<<pdate<<"/"<<pmonth<<"/"<<pyear<<endl<<endl;
    text<<"YOUR SHOPPING CART"<<endl;
    text<<endl;
    text<<"PRODUCT NAME"<<"\t\t\t"<<"PRICE/QTY"<<"\t"<<"QUANTITY"<<"\t"<<"TOTAL"<<endl;

    while(true)
    {
        system("CLS");
        int temp=1,temp1=1;
        cout<<"                                     ====== DSA SHOPPING MALL ====="<<endl;
        cout<<endl;


        cout<<"************************************************************************************************************************"<<endl;
        cout<<"                                                    "<<"MAIN MENU"<<endl;
        cout<<endl<<"************************************************************************************************************************"<<endl;
        cout<<endl;

        cout<<"                                                "<<"ENTER YOUR CHOICE:"<<endl;
        cout<<endl<<"                                                "<<"1.> MEMBER SECTION"<<endl;
        cout<<"                                                "<<"2.> PRODUCT SECTION"<<endl;
        cout<<"                                                "<<"3.> EXIT"<<endl;
        cout<<endl<<"                                                "<<"ENTER YOUR CHOICE: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                {
                    while(temp)
                    {
                        system("CLS");
                        cout<<endl<<"                                           ====== MEMBER SECTION ====="<<endl;
                        cout<<endl<<"                                                 "<<"ENTER YOUR CHOICE:"<<endl;
                        cout<<endl<<"                                                 "<<"1.> NEW MEMBERSHIP"<<endl;
                        cout<<"                                                 "<<"2.> VIEWING EXISTING MEMBERSHIP"<<endl;
                        cout<<"                                                 "<<"3.> MODIFY MEMBER DETAILS"<<endl;
                        cout<<"                                                 "<<"4.> DELETE MEMBERSHIP"<<endl;
                        cout<<"                                                 "<<"5.> EXIT"<<endl;
                        cout<<endl;
                        cout<<"                                                 "<<"ENTER YOUR CHOICE: ";
                        cin>>choice1;
                        switch(choice1)
                        {
                            case(1):
                            {
                                a.add_member();
                                break;
                            }
                            case(2):
                            {
                                a.display();
                                break;
                            }
                            case (3):
                            {
                                a.modify_memdetails();
                                break;
                            }
                            case (4):
                            {
                                a.delete_member();
                                break;
                            }
                            case(5):
                            {system("CLS");
                                temp=0;
                                break;
                            }
                            default :
                            {
                                cout<<"							Invalid input"<<endl;
                                getch();
                            }
                        }
                    }
                    break;

                }
            case 2:
                {
                	float billprice=0;
                    while(temp1)
                    {
                        system("CLS");
                        cout<<endl<<"                                           ====== PRODUCT SECTION ====="<<endl;
                        cout<<endl<<"                                                 "<<"ENTER YOUR CHOICE:"<<endl;
                        cout<<endl;
                        cout<<"                                                 "<<"1.> BUYING PRODUCTS"<<endl;
                        cout<<"                                                 "<<"2.> VIEW THE BILL"<<endl;
                        cout<<"                                                 "<<"3.> MODIFY THE PRODUCTS BOUGHT"<<endl;
                        cout<<"                                                 "<<"4.> DELETE PRODUCTS BOUGHT"<<endl;
                        cout<<"                                                 "<<"5.> EXIT"<<endl;
                        cout<<endl<<"                                                 "<<"ENTER YOUR CHOICE: ";
                        cin>>choice2;
                        switch(choice2)
                        {
                            case 1:
                                {
                                    cout<<endl<<"                                              "<<"PRESS 0 to STOP BUYING PRODUCTS"<<endl;
                                    cout<<endl;
                                    while(true)
                                    {
                                        cout<<endl<<"                                                 "<<"ENTER THE PRODUCT CODE: ";
                                        cin>>code;
                                        if(code==0)
                                            break;
                                        else
                                            p.buy_product(code);
                                    }
                                    break;
                                }
                            case 2:
                                {
                                    system("CLS");
                                    cout<<endl<<"                                           ======YOUR SHOPPING CART ====="<<endl;
                                    int m,idno,dis,retval;
                                    retval=p.display();
                                    p.billdetails();
                                    text<<endl<<endl;
                                    text<<"The Total Bill Amount Of Your Shopping Cart is "<<p.cal_bill()<<endl;
                                    if(retval==0)
                                    {
                                        cout<<endl<<"                                                 "<<"DO YOU HAVE A MEMBERSHIP ??"<<endl;
                                        cout<<"                                                       "<<"1.> YES        2.> NO"<<endl;
                                        cout<<endl<<"                                                 "<<"ENTER YOUR CHOICE: ";
                                        cin>>m;
                                        if(m==1)
                                        {
                                        	text<<endl<<"You Have Membership"<<endl<<endl;
                                            cout<<endl<<"                                                 "<<"ENTER YOUR MEMBERSHIP ID: ";
                                            cin>>idno;
                                            dis=a.search_memdetails(idno);
                                            a.billdata(idno);
                                            if(dis!=0)
                                            {
                                                cout<<endl<<"                                           "<<"**** CONGRATULATIONS! ****"<<endl;
                                                      cout<<"                                           "<<"Your discount percentage is "<<dis<<endl;
                                                      getch();
                                                      text<<endl;
                                                    text<<"Your Discount Percentage is  "<<dis<<endl;
                                            }
                                            if(dis==0)
                                            {
                                                cout<<"                                                   "<<"*** SORRY! ***"<<endl;
                                                cout<<"                                               "<<"You don't have an year's membership yet."<<endl;
                                                getch();
                                            }
                                            billprice=p.cal_bill();
                                            billprice=billprice-billprice*dis/100;
                                            cout<<endl;
                                        	cout<<endl<<"                                              "<<"THE TOTAL BILL AMOUNT IS: ";
                                        	cout<<p.cal_bill()<<endl;
                                            text<<endl<<"The Total Bill Amount After Discount is :  "<<billprice<<endl<<endl;
											cout<<endl;
                                        	cout<<endl<<"                                              "<<"THE TOTAL BILL AMOUNT AFTER DISCOUNT IS: ";
                                        	cout<<billprice<<endl;
                                       	 	cout<<endl<<"                                            "<<"**** THANK YOU FOR SHOPPING WITH US ****";
                                        	cout<<endl;
                                        	getch();
									}
                                        else if(m==2)
                                        {
                                            cout<<endl<<"                                               "<<"You don't have any discount"<<endl;
                                            cout<<endl;
                                        	cout<<endl<<"                                              "<<"THE TOTAL BILL AMOUNT AFTER DISCOUNT IS: ";
                                        	cout<<p.cal_bill()<<endl;
                                       		 cout<<endl<<"                                            "<<"**** THANK YOU FOR SHOPPING WITH US ****";
                                        	cout<<endl;
                                            getch();
                                        }

                                    }

                                    break;
                                }
                            case 3:
                                {
                                    p.modify_item();
                                    break;
                                }
                            case 4:
                                {
                                    p.delete_item();
                                    break;
                                }
                            case 5:
                                {
                                    temp1=0;
                                    break;
                                }
                            default :
                                {
                                    cout<<"							Invalid input"<<endl;
                                    getch();
                                    }
                        }
                    }
                    break;
                }
            case 3:
                {
                    exit(0);
                }
            default:
            {
                cout<<"						Invalid input"<<endl;
                getch();
            }
        }
    }
    text.close();
}
