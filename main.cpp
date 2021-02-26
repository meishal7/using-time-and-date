/*
main.cpp 
This program demonstrates how to work with dates and time in C++. This program prints date and time in different formats, does time math creating the struct tm for the particular date in the past and manipulates the info from struct tm.
Author: Elena Mudrakova
Module: 4
Project: Lab 4

Algorithm: 
Before main()
1. #include <iostream>
  #include <ctime> // for using date and time
  #include <string>
In main()
1. Set timezone using setenv().
2. Recognize timezone using tzset().
3. Get current time.
4. Break down current time using sttruct tm and localtime().
5. Create arrays for using it in strftime() to store info.
6. Format date and time using strftime().
7. Print out formatted date and time.
8. Set new tm structure and initialize it to particular event in the past.
9. Convert tm struct into number of seconds using mktime().
10. Print out number of seconds since 1900 year when event in the past happend.
11. Print out event using ctime().
12. Calculate number of seconds in one week.
13. Calculate number of seconds since 1900 year one week before event.
14. Convert int number of seconds one week before event in time_t type.
15. Print out one week before event using ctime() or strftime(). 
*/
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

int main() {
  // string days[] = {"Sunday", "Monday", "Tuesday", "Wednsday", "Thursday", "Friday", "Saturday"};

  // string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

  
  setenv("TZ", "PST8PST", 1);   // set TZ
  tzset();                      // recognize TZ
  time_t rawTime = time(NULL);  // epoch seconds 
  
  // Break down epoch seconds into struct tm
  struct tm *timeInfo = localtime(&rawTime); 
  
  // Array for using in strftime()
	char date_string[100]; 
	char date_string1[100]; 
  char date_string2[100]; 
  char time_string[100];
	char time_string1[100];
  
  // Formatting date and time 
	strftime(date_string, 100, "Today is %m/%d/%y", timeInfo);
  strftime(date_string1, 100, "Today is %B %d, %Y", timeInfo);
  strftime(date_string2, 100, "Today is %d-%b-%Y", timeInfo);
  strftime(time_string, 100, "Current time is %H:%M", timeInfo);
  strftime(time_string1, 100, "Current time is %I:%M%P", timeInfo);

  cout << date_string << endl;
	cout << date_string1 << endl;
	cout << date_string2 << "\n" << endl;
	cout << time_string << endl;
  cout << time_string1 << endl;
  
  // Set new tm structure
  struct tm myEvent;
  // Initialize tm struct to particular date in the past
  myEvent.tm_year = 88;
  myEvent.tm_mon = 1;
  myEvent.tm_mday = 7;
  myEvent.tm_hour = 6;
  myEvent.tm_min = 0;
  myEvent.tm_sec = 0; 
  myEvent.tm_isdst = -1;
  
  // Converting tm struct into number of seconds 
  time_t birthday = mktime(&myEvent);
  
  cout << "\nBirthday is " << birthday << " seconds since 1900 year" << endl;
  cout << "\nBirthday is " << ctime(&birthday) << endl;
  
  // Do time math
  int secondsInWeek = 7 * 24 * 60 * 60;
  cout << "Seconds in one week " << secondsInWeek << endl;
  
  int weekBeforeToday = rawTime - secondsInWeek;
  cout << "Seconds one week befor today " << weekBeforeToday << endl;
  
  // Calculate number of seconds since 1900 one week before event above
  int secWeekBeforeEvent = birthday - secondsInWeek;
  cout << "Seconds one week before event " << secWeekBeforeEvent << endl; 
  
  // Set time_t var equal amount of seconds one week bofore event
  time_t secondsWeekBeforeEvent = secWeekBeforeEvent;
  cout << "One week before event is " << ctime(&secondsWeekBeforeEvent) << endl;

  
  return 0;

  
}