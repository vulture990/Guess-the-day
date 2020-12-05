/*
############################################################################################################################################ 
#   
                        THIS PROGRAM TAKES AS INPUT , FOR INSTANCE  DD/MM/YY                                                               #         
#

#                           & IT RETURNS AS OUTPUT THE DAY OF THAT DATE.                                                                   # 
############################################################################################################################################
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
enum days{Sunday,Monday,Tuesday,Wednsday,Thirsday,Friday,Saturday};
enum days anchordaysofcentury(int y);
int twelveyearrulecheck(int  years);
int difference(int quotient,int year);
int costofleapyears(int remainder);
char *convertnumbertostrings(enum days date);
int isleapyear(int year);
int doomsdaymonth(int month,int year);
enum days howfarfromdoomday(int date,int s,enum days doomsd);
int main(void)
{
  int year;
  int month;
  int dateofthemonth;
  int sum=0;
  int quotient;
  int remainder;
  int s;
  enum days enumdoomsday;
  enum days d;
  int doomsdaymont;
  char *day;
  printf("Please Enter any Year between 1400 and 2500 : ");
  scanf("%d",&year);
  system("cls");
  printf("Please Enter the Month: ");
  scanf("%d",&month);
  system("cls");
  printf("Enter your day's date: ");
  scanf("%d",&dateofthemonth);
  system("cls");
  printf("PRESS A KEY TO GET THE DAY\n");
  getch();
  quotient=twelveyearrulecheck(year);
  remainder=difference(quotient,year);
//by adding up the four numbers and seeking for his modulo 7 we're going to find the doomsday it's our first big milestoon
  sum=anchordaysofcentury(year)+quotient+remainder+costofleapyears(remainder);
  enumdoomsday=sum%7;
  s=doomsdaymonth(month,year);
  d=howfarfromdoomday(dateofthemonth,s,enumdoomsday);
  day=convertnumbertostrings(d);
  //now that the doomsday is determined we have a reference in each year and what's left is to compute adding 7 to the doomsday's date close to the date inputed 
  printf("IT'S: %s",day);
  return 0;
}
  
enum days anchordaysofcentury(int year)//this one is just a demo for the closest 400 years to get the big picture .
{
  enum days returnday;
  if ((1800<=year && year<=1899)||(1400<=year && year<=1499)||(2200<=year && year<=2299))
  {
    returnday=Friday;
  }
  else if((1900<=year && year<=1999)||2300<=year && year<=2399||1500<=year && year<=1599)
  {
    returnday=Wednsday;
  }
  else if((2000<=year && year<=2099)||(2400<=year && year<=2499)||(1600<=year && year<=1699))
  {
    returnday=Tuesday;
  }
  else if((2100<=year && year<=2199)||(2500<=year && year<=2699)||(1700<=year && year<=1799))
  {
    returnday=Sunday;
  }
  else
  {
    printf("Try inputing a date that is between 1400 and 2500");
  }
  return returnday;
}
int twelveyearrulecheck(int year)//the output represents how many times does the number 12 fit as a whole into the two last digits of the year number
{
  int num1;
  int num2;//it wil store the two digits of the year
  int q;//q is going to be quotion of those two digits on 12(why 12 due to corollary of the twelve years rule on which the doomsday moves by one day)
  num1=year%10;
  num2=(year-num1)%100;
  num2+=num1;
  q=num2/12;
  return q;
}
int difference(int quotient,int year)//the output is the difference between the two last digits of the year number and the product of the multiples of 12
{
  int remainder;
  remainder=(year%10)+((year-year%10)%100)-quotient*12;
  return remainder;
}
int costofleapyears(int remainder)//the output of this function is going to add up to give the doomsday, here the remainder is year%12
{
  int cost;
  cost=remainder/4;
  return cost;//& by cost i mean what's going to be added
}
char *convertnumbertostrings(enum days date)
{
  char *string;
  switch(date)
  {
    case 0 :
      string="Sunday";
      break;
    case 1:
      string="Monday";
      break;
    case 2:
      string="Tuesday";
      break;
    case 3:
      string="Wednsday";
      break;
    case 4:
      string="Thirsday";
      break;
    case 5:
      string="Friday";
      break;

    default:

      string="Saturday";
  }

  return string;
}
int isleapyear(int year)
{
  return (year%4==0) ? 1 : (0);
}
int doomsdaymonth(int month,int year)//this function main soul inlife is to identifie for each month &year where the doomsday are 
{
  int d;

  switch(month)
  {
    case 1:
      d=(isleapyear(year)==1) ? 4 : 3;
      break;
    case 2:
      d=(isleapyear(year)==1) ? 29 : 28;
      break;
    case 3:
      d=(isleapyear(year)==1) ? 7 : 6;
      break;
    case 4:
      d=4;
      break;
    case 5:
      d=9;
      break;
    case 6:
      d=6;
      break;
    case 7:
      d=11;
      break;
    case 8:
      d=8;
      break;
    case 9:
      d=5;
      break;
    case 10:
      d=10;
      break;
    case 11:
      d=7;
      break;
    default:
      d=12;
      break;
  }

  return d;
}
//all of these date represents each a doomsday
enum days howfarfromdoomday(int date,int s,enum days doomsd)//s is the doomsday of the month
{
  enum days d;
  int distance;
  int left;
  enum days day;
  distance=(date-s);
  left=distance%7;
  d=(left+doomsd)%7;
  return d;
  
}